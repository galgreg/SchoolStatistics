#include "studentdataform.h"
#include "ui_studentdataform.h"

StudentDataForm::StudentDataForm(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::StudentDataForm),
        mGender(UNKNOWN) {
    ui->setupUi(this);
}

StudentDataForm::~StudentDataForm() {

}

void StudentDataForm::showForm() {
    this->show();
}

void StudentDataForm::hideForm() {
    this->hide();
}

void StudentDataForm::setHeader(const QString &newHeader) {
    ui->headerLabel->setText(newHeader);
}

void StudentDataForm::setFirstName(const QString &newFirstName) {
    ui->firstNameLineEdit->setText(newFirstName);
}

void StudentDataForm::setLastName(const QString &newLastName) {
    ui->lastNameLineEdit->setText(newLastName);
}

void StudentDataForm::setGender(Gender newGender) {
    mGender = newGender;

    if (newGender == MALE) {
        ui->maleButton->setChecked(true);
    } else if (newGender == FEMALE) {
        ui->femaleButton->setChecked(true);
    } else if (newGender == UNKNOWN) {
        ui->unknownGenderButton->setChecked(true);
    }
}

void StudentDataForm::addGrade(double newGrade) {
    // TODO
}

void StudentDataForm::editGrade(size_t whichGrade, double newGrade) {
    // TODO
}

void StudentDataForm::deleteGrade(size_t whichGrade) {
    // TODO
}

QString StudentDataForm::getHeader() {
    return ui->headerLabel->text();
}

QString StudentDataForm::getFirstName() {
    return ui->firstNameLineEdit->text();
}

QString StudentDataForm::getLastName() {
    return ui->lastNameLineEdit->text();
}

Gender StudentDataForm::getGender() {
    return mGender;
}

QList<double> StudentDataForm::getGrades() {
    // TODO
    return {};
}
