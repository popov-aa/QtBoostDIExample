#pragma once

class PermissionsModel;

#include "boost/di/extension/injections/named_parameters.hpp"
#include <QWidget>
#include <memory>

namespace Ui {
class UserWidget;
}

class UserWidget : public QWidget {
    Q_OBJECT

public:
    explicit UserWidget(
        PermissionsModel* permissionsModel,
        const QString& username);

    $inject(UserWidget,
        PermissionsModel* permissionsModel,
        [[named("toto")]] int value,
        const QString& username);

    virtual ~UserWidget();

private:
    Ui::UserWidget* ui;
    PermissionsModel* m_permissionsModel;
};
