#include "confirmdialog.h"
#include "ui_confirmdialog.h"

ConfirmDialog::ConfirmDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConfirmDialog)
{
    ui->setupUi(this);
}

ConfirmDialog::~ConfirmDialog()
{
    delete ui;
}
