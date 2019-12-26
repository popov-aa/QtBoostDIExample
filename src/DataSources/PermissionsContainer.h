#pragma once

#include "DataTypes/Permission.h"

#include <QList>
#include <QObject>

class PermissionsContainer : public QObject {
public:
    explicit PermissionsContainer();
    virtual ~PermissionsContainer();

    QList<Permission> permissions() const;

    QString title(Permission permission) const;

private:
    QList<Permission> m_permissions;
};
