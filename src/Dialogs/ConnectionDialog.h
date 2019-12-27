#pragma once

class ConnectionService;

#include <QDialog>
#include <memory>

namespace Ui {
class ConnectionDialog;
}

class ConnectionDialog : public QDialog {
    Q_OBJECT

public:
    explicit ConnectionDialog(
        std::shared_ptr<ConnectionService> connectionService,
        QWidget* parent);
    ~ConnectionDialog();

private:
    Ui::ConnectionDialog* ui;
    std::shared_ptr<ConnectionService> m_connectionService;
};
