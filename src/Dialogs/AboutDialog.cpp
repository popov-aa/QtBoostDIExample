#include "AboutDialog.h"
#include "ui_AboutDialog.h"

AboutDialog::AboutDialog()
    : QDialog(nullptr)
    , ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
}

AboutDialog::~AboutDialog()
{
    delete ui;
}
