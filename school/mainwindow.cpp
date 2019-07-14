#include "mainwindow.h"
#include "classstatistics.h"
#include "ui_mainwindow.h"
#include "studentclass.h"
#include "textfilestorage.h"

MainWindow::MainWindow(
        IDataRepository *dataRepository,
        IStudentDataWidget *studentDataWidget,
        IConfirmDialog *confirmDialog,
        QWidget *parent) :
            QWidget(parent),
            ui(new Ui::MainWindow),
            mDataRepository(dataRepository),
            mStudentClass(nullptr),
            mStudentDataWidget(studentDataWidget),
            mConfirmDialog(confirmDialog) {
    ui->setupUi(this);

    connect(ui->showStudentButton, &QPushButton::clicked,
            this, &MainWindow::showStudentDataWidget);
    connect(ui->deleteStudentButton, &QPushButton::clicked,
            this, &MainWindow::beginDeleteTransaction);
    readDataFromRepository();
}

MainWindow::~MainWindow() {
}

void MainWindow::showStudentDataWidget() {
    int studentIndex = ui->studentList->currentRow();

    if (studentIndex > -1) {
        prepareStudentDataWidgetToDisplay(static_cast<size_t>(studentIndex));
        mStudentDataWidget->showWidget();
    }
}

void MainWindow::beginDeleteTransaction() {
    DialogAction actionToConfirm = DELETE_STUDENT;
    QString studentName = ui->studentList->currentItem()->text();
    prepareConfirmDialogToDisplay(actionToConfirm, studentName);
    mConfirmDialog->showDialog();
}

void MainWindow::readDataFromRepository() {
    try {
        mStudentClass.reset(mDataRepository->read(20, 3));
        ui->errorLabel->setText("");
    } catch (...) {
        mStudentClass.reset(new StudentClass(20));
        ui->studentsNumberValue->setText("0");
        ui->classAverageValue->setText("0.0");
        ui->studentList->clear();
        ui->errorLabel->setText(
                "<html><head/><body>"
                "<p><span style=\" font-weight:600; color:#cc0000;\">"
                "Cannot open data storage!</span></p>"
                "</body></html>");
        return;
    }
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

void MainWindow::deleteStudent(size_t studentIndex) {
    mStudentClass->removeStudent(studentIndex);
    mDataRepository->write(*mStudentClass);
    readDataFromRepository();
}

void MainWindow::prepareStudentDataWidgetToDisplay(size_t studentIndex) {
    const auto& student = mStudentClass->getStudent(studentIndex);
    QString studentID = QString::number(student.getID());
    mStudentDataWidget->setID(studentID);
    const auto& studentPersonalData = student.getPersonalData();
    QString studentFirstName =
            QString::fromStdString(studentPersonalData.getFirstName());
    mStudentDataWidget->setFirstName(studentFirstName);
    QString studentLastName =
            QString::fromStdString(studentPersonalData.getLastName());
    mStudentDataWidget->setLastName(studentLastName);

    Gender studentGenderEnum = studentPersonalData.getGender();
    QString studentGender;

    if (studentGenderEnum == MALE) {
        studentGender = "Male";
    } else if (studentGenderEnum == FEMALE) {
        studentGender = "Female";
    } else {
        studentGender = "Unknown";
    }
    mStudentDataWidget->setGender(studentGender);

    const auto& studentGrades = student.getGrades();
    QString gradesString = "";

    for (unsigned i = 0; i < studentGrades.count(); ++i) {
        QString tempString = QString::number(studentGrades.getGrade(i), 'f', 1);
        gradesString += tempString;
        if (i < (studentGrades.count() - 1)) {
            gradesString += ", ";
        }
    }
    mStudentDataWidget->setGrades(gradesString);

    QString gradesAverage = QString::number(
            ClassStatistics::getStudentAverage(*mStudentClass, studentIndex),
            'f',
            1);
    mStudentDataWidget->setGradesAverage(gradesAverage);
}

void MainWindow::prepareConfirmDialogToDisplay(
        DialogAction actionToConfirm,
        QString studentName) {
    QString actionString;

    if (actionToConfirm == ADD_STUDENT) {
        actionString = "add";
    } else if (actionToConfirm == EDIT_STUDENT) {
        actionString = "edit";
    } else if (actionToConfirm == DELETE_STUDENT) {
        actionString = "delete";
    }
    mConfirmDialog->customizeDialogMessage(actionString, studentName);
}

