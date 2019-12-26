#pragma once

#include <QString>

class VersionInformation {
public:
    VersionInformation();
    virtual ~VersionInformation();

    QString version() const;
    QString revision() const;
};
