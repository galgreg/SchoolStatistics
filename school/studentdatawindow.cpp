#include "studentdatawindow.h"
#include "ui_studentdatawindow.h"

StudentDataWindow::StudentDataWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentDataWindow)
{
    ui->setupUi(this);
}

StudentDataWindow::~StudentDataWindow()
{
    delete ui;
}
