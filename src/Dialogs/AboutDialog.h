#pragma once

#include <QDialog>

namespace Ui {
class AboutDialog;
}

class AboutDialog : public QDialog {
    Q_OBJECT

public:
    explicit AboutDialog();
    ~AboutDialog();

private:
    Ui::AboutDialog* ui;
};
