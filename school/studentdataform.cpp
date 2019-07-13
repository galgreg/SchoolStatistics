#include "studentdataform.h"
#include "ui_studentdataform.h"

StudentDataForm::StudentDataForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentDataForm)
{
    ui->setupUi(this);
}

StudentDataForm::~StudentDataForm()
{
    delete ui;
}
