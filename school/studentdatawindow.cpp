#include "studentdatawindow.h"
#include "ui_studentdatawindow.h"

StudentDataWindow::StudentDataWindow(
        std::shared_ptr<SignalTransmitter> signalTransmitter) :
            QWidget(nullptr),
            ui(new Ui::StudentDataWindow),
            mSignalTransmitter(signalTransmitter) {
    ui->setupUi(this);
    connect(ui->editButton, &QPushButton::clicked,
            mSignalTransmitter.get(), &SignalTransmitter::showEditForm);
}

StudentDataWindow::~StudentDataWindow() {

}

void StudentDataWindow::showWidget() {
    this->show();
}

void StudentDataWindow::hideWidget() {
    this->hide();
}

QString StudentDataWindow::getID() {
    return ui->studentIDValue->text();
}

QString StudentDataWindow::getFirstName() {
    return ui->firstNameValue->text();
}

QString StudentDataWindow::getLastName() {
    return ui->lastNameValue->text();
}

QString StudentDataWindow::getGender() {
    return ui->genderValue->text();
}

QString StudentDataWindow::getGrades() {
    return ui->gradesValue->text();
}

QString StudentDataWindow::getGradesAverage() {
    return ui->gradesAverageValue->text();
}

void StudentDataWindow::setID(const QString &newStudentID) {
    ui->studentIDValue->setText(newStudentID);
}

void StudentDataWindow::setFirstName(const QString &newFirstName) {
    ui->firstNameValue->setText(newFirstName);
}

void StudentDataWindow::setLastName(const QString &newLastName) {
    ui->lastNameValue->setText(newLastName);
}

void StudentDataWindow::setGender(const QString &newGender) {
    ui->genderValue->setText(newGender);
}

void StudentDataWindow::setGrades(const QString &newGrades) {
    ui->gradesValue->setText(newGrades);
}

void StudentDataWindow::setGradesAverage(const QString &newGradesAverage) {
    ui->gradesAverageValue->setText(newGradesAverage);
}




