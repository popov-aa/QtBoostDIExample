#pragma once

#include <QString>

class ConnectionService {
public:
    ConnectionService();
    virtual ~ConnectionService();

    QString interface() const;
    QString speed() const;
};
