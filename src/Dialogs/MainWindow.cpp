#include "MainWindow.h"
#include "Dialogs/AboutDialog.h"
#include "Dialogs/ConnectionDialog.h"
#include "Widgets/UserWidget.h"
#include "ui_MainWindow.h"

#include <QDebug>

MainWindow::MainWindow(
    const boost::di::extension::ifactory<AboutDialog>& aboutDialog,
    const boost::di::extension::ifactory<ConnectionDialog>& connectionDialogFactory,
    const boost::di::extension::ifactory<UserWidget, QString>& userWidgetFactory)
    : QMainWindow()
    , ui(new Ui::MainWindow)
    , m_aboutDialog(aboutDialog)
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
    QString username = QString("User #%1").arg(ui->tabWidget->count() + 1);
    QWidget* widget = m_userWidgetFactory.create(std::move(username)).release();
    ui->tabWidget->addTab(widget, username);
    ui->tabWidget->setCurrentWidget(widget);
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
    Q_UNUSED(index)
    on_actionRemoveUser_triggered();
}

void MainWindow::on_actionAbout_triggered()
{
    auto dialog = m_aboutDialog.create();
    dialog->setParent(this, Qt::Dialog);
    dialog->exec();
}
