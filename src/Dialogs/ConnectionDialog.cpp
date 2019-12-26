#include "ConnectionDialog.h"
#include "ui_ConnectionDialog.h"

#include "Service/ConnectionService.h"

#include <QDebug>

ConnectionDialog::ConnectionDialog(std::shared_ptr<ConnectionService> connectionService)
    : QDialog(nullptr)
    , ui(new Ui::ConnectionDialog)
    , m_connectionService(connectionService)
{
    qDebug() << __FILE__ << "created" << long(this);
    ui->setupUi(this);
    ui->labelInterface->setText(m_connectionService->interface());
    ui->labelSpeed->setText(m_connectionService->speed());
}

ConnectionDialog::~ConnectionDialog()
{
    qDebug() << __FILE__ << "destroyed" << long(this);
    delete ui;
}
