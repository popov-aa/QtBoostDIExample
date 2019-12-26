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
        PermissionsModel* permissionsModel,
        const QString& username);
    virtual ~UserWidget();

private:
    Ui::UserWidget* ui;
    PermissionsModel* m_permissionsModel;
};
