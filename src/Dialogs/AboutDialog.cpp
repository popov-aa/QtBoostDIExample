#include "AboutDialog.h"
#include "ui_AboutDialog.h"

#include <QDebug>

AboutDialog::AboutDialog(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::AboutDialog)
{
    qDebug() << __FILE__ << "created" << long(this);
    ui->setupUi(this);
}

AboutDialog::~AboutDialog()
{
    qDebug() << __FILE__ << "destroyed" << long(this);
    delete ui;
}
