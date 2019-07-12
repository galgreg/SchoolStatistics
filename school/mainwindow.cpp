#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "studentclass.h"
#include "textfilestorage.h"

MainWindow::MainWindow(
        IDataRepository *dataRepository,
        IStudentClass *studentClass,
        QWidget *parent) :
            QWidget(parent),
            mDataRepository(dataRepository),
            mStudentClass(studentClass) {
    ui.reset(new Ui::MainWindow);
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
}
