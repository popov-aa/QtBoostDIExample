#include "VersionInformation.h"

#include <QDebug>

VersionInformation::VersionInformation()
{
    qDebug() << __FILE__ << "created" << long(this);
}

VersionInformation::~VersionInformation()
{
    qDebug() << __FILE__ << "destroyed" << long(this);
}

QString VersionInformation::version() const
{
    return "v1.1.3";
}

QString VersionInformation::revision() const
{
    return "666";
}
