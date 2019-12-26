#include "PermissionsContainer.h"

#include <QDebug>

PermissionsContainer::PermissionsContainer()
    : QObject()
{
    qDebug() << __FILE__ << "created" << long(this);
    m_permissions.append(Permission::ControlObjectReading);
    m_permissions.append(Permission::ControlObjectManaging);
    m_permissions.append(Permission::EquipmentReading);
    m_permissions.append(Permission::EquipmentManaging);
}

PermissionsContainer::~PermissionsContainer()
{
    qDebug() << __FILE__ << "destroyed" << long(this);
}

QList<Permission> PermissionsContainer::permissions() const
{
    return m_permissions;
}

QString PermissionsContainer::title(Permission permission) const
{
    switch (permission) {
    case Permission::ControlObjectReading:
        return tr("Control object reading");
    case Permission::ControlObjectManaging:
        return tr("Control object managing");
    case Permission::EquipmentReading:
        return tr("Equipment reading");
    case Permission::EquipmentManaging:
        return tr("Equipment managing");
    }
}
