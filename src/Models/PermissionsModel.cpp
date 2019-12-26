#include "PermissionsModel.h"

#include "DataSources/PermissionsContainer.h"

#include <QDebug>

PermissionsModel::PermissionsModel(std::shared_ptr<PermissionsContainer> permissionsContainer)
    : QAbstractTableModel()
    , m_permissionsContainer(permissionsContainer)
{
    qDebug() << __FILE__ << "created" << long(this);
}

PermissionsModel::~PermissionsModel()
{
    qDebug() << __FILE__ << "destroyed" << long(this);
}

int PermissionsModel::columnCount(const QModelIndex& parent) const
{
    if (parent.isValid()) {
        return 0;
    } else {
        return 1;
    }
}

QVariant PermissionsModel::data(const QModelIndex& index, int role) const
{
    Permission permission = m_permissionsContainer->permissions()[index.row()];

    if (role == Qt::DisplayRole) {
        return m_permissionsContainer->title(permission);
    } else if (role == Qt::CheckStateRole) {
        return m_checkedPermissions.contains(permission) ? Qt::Checked : Qt::Unchecked;
    } else {
        return QVariant();
    }
}

QModelIndex PermissionsModel::index(int row, int column, const QModelIndex& parent) const
{
    if (parent.isValid()) {
        return QModelIndex();
    } else {
        return createIndex(row, column);
    }
}

int PermissionsModel::rowCount(const QModelIndex& parent) const
{
    if (parent.isValid()) {
        return 0;
    } else {
        return m_permissionsContainer->permissions().size();
    }
}

Qt::ItemFlags PermissionsModel::flags(const QModelIndex& index) const
{
    Q_UNUSED(index);
    return Qt::ItemFlag::ItemIsEnabled | Qt::ItemFlag::ItemIsUserCheckable | Qt::ItemFlag::ItemIsSelectable;
}

bool PermissionsModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    Permission permission = m_permissionsContainer->permissions()[index.row()];
    if (role == Qt::CheckStateRole) {
        if (value.toInt() == Qt::Checked) {
            m_checkedPermissions.insert(permission);
        } else {
            m_checkedPermissions.remove(permission);
        }
        return true;
    }
    return false;
}

QSet<Permission> PermissionsModel::checkedPermissions() const
{
    return m_checkedPermissions;
}

void PermissionsModel::setCheckedPermissions(const QSet<Permission>& checkedPermissions)
{
    beginResetModel();
    m_checkedPermissions = checkedPermissions;
    endResetModel();
}
