#pragma once

#include <QHash>

enum class Permission {
    ControlObjectReading,
    ControlObjectManaging,
    EquipmentReading,
    EquipmentManaging
};

inline uint qHash(Permission key, uint seed = 0)
{
    return qHash(int(key), seed);
}
