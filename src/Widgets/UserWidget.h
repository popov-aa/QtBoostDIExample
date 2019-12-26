#pragma once

class PermissionsModel;

#include <QWidget>
#include <memory>

namespace Ui {
class UserWidget;
}

class UserWidget : public QWidget {
    Q_OBJECT

public:
    explicit UserWidget(
        PermissionsModel* permissionsModel);
    virtual ~UserWidget();

private:
    Ui::UserWidget* ui;
    PermissionsModel* m_permissionsModel;
};
