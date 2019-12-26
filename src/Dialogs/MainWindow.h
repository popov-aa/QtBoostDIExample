#pragma once

class AboutDialog;
class ConnectionDialog;
class UserWidget;

#include <QMainWindow>
#include <boost/di/extension/injections/factory.hpp>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(
        const boost::di::extension::ifactory<AboutDialog, QWidget*>& aboutDialog,
        const boost::di::extension::ifactory<ConnectionDialog>& connectionDialogFactory,
        const boost::di::extension::ifactory<UserWidget>& userWidgetFactory);
    ~MainWindow();

private slots:
    void on_actionAddUser_triggered();
    void on_actionRemoveUser_triggered();
    void on_actionReloadUsers_triggered();

    void on_actionConnection_triggered();

    void on_actionQuit_triggered();

    void on_tabWidget_tabCloseRequested(int index);

    void on_actionAbout_triggered();

private:
    Ui::MainWindow* ui;

    const boost::di::extension::ifactory<AboutDialog, QWidget*>& m_aboutDialog;
    const boost::di::extension::ifactory<ConnectionDialog>& m_connectionDialogFactory;
    const boost::di::extension::ifactory<UserWidget>& m_userWidgetFactory;
};
