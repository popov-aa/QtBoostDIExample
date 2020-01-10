#pragma once

enum class Permission;

#include <QList>
#include <QString>

class PermissionsContainer {
public:
    virtual QList<Permission> permissions() const = 0;
    virtual QString title(Permission permission) const = 0;
};
