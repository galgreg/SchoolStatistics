#include "mainwindow.h"
#include "classstatistics.h"
#include "ui_mainwindow.h"
#include "studentclass.h"
#include "textfilestorage.h"

MainWindow::MainWindow(
        IDataRepository *dataRepository,
        QWidget *parent) :
            QWidget(parent),
            mDataRepository(dataRepository),
            mStudentClass(nullptr) {
    ui.reset(new Ui::MainWindow);
    ui->setupUi(this);
    readDataFromRepository();
}

MainWindow::~MainWindow() {
}

void MainWindow::readDataFromRepository() {
    mStudentClass.reset(mDataRepository->read(20, 3));
    size_t studentClassCount = mStudentClass->count();
    ui->studentsNumberValue->setText(QString::number(studentClassCount));
    double studentClassAverage =
            ClassStatistics::getClassAverage(*mStudentClass);
    ui->classAverageValue->setText(QString::number(studentClassAverage, 'f', 1));

    auto& studentList = ui->studentList;
    for (size_t i = 0; i < mStudentClass->count(); ++i) {
        const auto& student = mStudentClass->getStudent(i);
        const auto& personalData = student.getPersonalData();
        std::string studentFullName =
                personalData.getFirstName() + " " + personalData.getLastName();
        studentList->addItem(QString::fromStdString(studentFullName));
    }
}
