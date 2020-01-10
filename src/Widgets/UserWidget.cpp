#include "UserWidget.h"
#include "ui_UserWidget.h"

#include "Models/PermissionsModel.h"

#include <QDebug>

UserWidget::UserWidget(
    PermissionsModel* permissionsModel,
    const QString& username)
    : QWidget()
    , ui(new Ui::UserWidget)
    , m_permissionsModel(permissionsModel)
{
    qDebug() << __FILE__ << "created" << long(this);
    ui->setupUi(this);
    ui->tableView->setModel(m_permissionsModel);
    ui->lineEditUsername->setText(username);
}

UserWidget::UserWidget(
    PermissionsModel* permissionsModel,
    int value,
    const QString& username)
    : UserWidget(permissionsModel, username)
{
    ui->lineEditValue->setText(QString::number(value));
}

UserWidget::~UserWidget()
{
    qDebug() << __FILE__ << "destroyed" << long(this);
    delete ui;
    delete m_permissionsModel;
}
