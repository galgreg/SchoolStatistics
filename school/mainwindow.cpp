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
    studentList->clear();
    for (size_t i = 0; i < mStudentClass->count(); ++i) {
        const auto& student = mStudentClass->getStudent(i);
        const auto& personalData = student.getPersonalData();
        std::string studentFullName =
                personalData.getFirstName() + " " + personalData.getLastName();
        studentList->addItem(QString::fromStdString(studentFullName));
    }
}

void MainWindow::prepareStudentDataWidgetToDisplay(
        IStudentDataWidget *dataWidget,
        size_t studentIndex) {
    const auto& student = mStudentClass->getStudent(studentIndex);
    QString studentID = QString::number(student.getID());
    dataWidget->setID(studentID);
    const auto& studentPersonalData = student.getPersonalData();
    QString studentFirstName =
            QString::fromStdString(studentPersonalData.getFirstName());
    dataWidget->setFirstName(studentFirstName);
    QString studentLastName =
            QString::fromStdString(studentPersonalData.getLastName());
    dataWidget->setLastName(studentLastName);

    Gender studentGenderEnum = studentPersonalData.getGender();
    QString studentGender;

    if (studentGenderEnum == MALE) {
        studentGender = "Male";
    } else if (studentGenderEnum == FEMALE) {
        studentGender = "Female";
    } else {
        studentGender = "Unknown";
    }
    dataWidget->setGender(studentGender);

    const auto& studentGrades = student.getGrades();
    QString gradesString = "";

    for (unsigned i = 0; i < studentGrades.count(); ++i) {
        QString tempString = QString::number(studentGrades.getGrade(i), 'f', 1);
        gradesString += tempString;
        if (i < (studentGrades.count() - 1)) {
            gradesString += ", ";
        }
    }
    dataWidget->setGrades(gradesString);

    QString gradesAverage = QString::number(
            ClassStatistics::getStudentAverage(*mStudentClass, studentIndex),
            'f',
            1);
    dataWidget->setGradesAverage(gradesAverage);
}
