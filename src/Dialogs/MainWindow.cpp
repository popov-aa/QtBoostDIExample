#include "MainWindow.h"
#include "Dialogs/ConnectionDialog.h"
#include "Widgets/UserWidget.h"
#include "ui_MainWindow.h"

#include <QDebug>

MainWindow::MainWindow(
    const boost::di::extension::ifactory<ConnectionDialog>& connectionDialogFactory,
    const boost::di::extension::ifactory<UserWidget>& userWidgetFactory)
    : QMainWindow()
    , ui(new Ui::MainWindow)
    , m_connectionDialogFactory(connectionDialogFactory)
    , m_userWidgetFactory(userWidgetFactory)
{
    qDebug() << __FILE__ << "created" << long(this);
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    qDebug() << __FILE__ << "destroyed" << long(this);
    delete ui;
}

void MainWindow::on_actionAddUser_triggered()
{
    ui->tabWidget->addTab(m_userWidgetFactory.create().release(), "User");
}

void MainWindow::on_actionRemoveUser_triggered()
{
    if (ui->tabWidget->currentWidget() != nullptr) {
        delete ui->tabWidget->currentWidget();
    }
}

void MainWindow::on_actionReloadUsers_triggered()
{
}

void MainWindow::on_actionConnection_triggered()
{
    auto connectionDialog = m_connectionDialogFactory.create();
    connectionDialog->setParent(this, Qt::Dialog);
    connectionDialog->exec();
}

void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    Q_UNUSED(index);
    on_actionRemoveUser_triggered();
}
