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
    QString gradeString = QString::number(newGrade, 'f', 1);
    ui->gradesList->addItem(gradeString);
}

void StudentDataForm::editGrade(size_t whichGrade, double newGrade) {
    QString gradeString = QString::number(newGrade, 'f', 1);
    ui->gradesList->item(static_cast<int>(whichGrade))->setText(gradeString);
}

void StudentDataForm::deleteGrade(size_t whichGrade) {
    ui->gradesList->takeItem(static_cast<int>(whichGrade));
}

void StudentDataForm::deleteAllGrades() {
    ui->gradesList->clear();
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
    QList<double> gradesFromUiList;
    const auto& gradesList = *(ui->gradesList);

    for (int i = 0; i < gradesList.count(); ++i) {
        QString gradeString = gradesList.item(i)->text();
        double newGrade = gradeString.toDouble();
        gradesFromUiList.append(newGrade);
    }
    return gradesFromUiList;
}
