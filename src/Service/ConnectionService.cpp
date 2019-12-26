#include "ConnectionService.h"

#include <QDebug>

ConnectionService::ConnectionService()
{
    qDebug() << __FILE__ << "created" << long(this);
}

ConnectionService::~ConnectionService()
{
    qDebug() << __FILE__ << "destroyed" << long(this);
}

QString ConnectionService::interface() const
{
    return "eth0";
}

QString ConnectionService::speed() const
{
    return "100 M/Bit";
}
