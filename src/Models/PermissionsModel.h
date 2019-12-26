#pragma once

class PermissionsContainer;
enum class Permission;

#include <QAbstractTableModel>
#include <QSet>
#include <memory>

class PermissionsModel : public QAbstractTableModel {
public:
    explicit PermissionsModel(std::shared_ptr<PermissionsContainer> permissionsContainer);
    virtual ~PermissionsModel();

    virtual int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    virtual QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    virtual QModelIndex index(int row, int column, const QModelIndex& parent = QModelIndex()) const override;
    virtual int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;
    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;

    QSet<Permission> checkedPermissions() const;
    void setCheckedPermissions(const QSet<Permission>& checkedPermissions);

private:
    std::shared_ptr<PermissionsContainer> m_permissionsContainer;
    QSet<Permission> m_checkedPermissions;
};
