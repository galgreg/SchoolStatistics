#include "studentdataform.h"
#include "ui_studentdataform.h"
#include <QRegExp>
#include <QRegExpValidator>

StudentDataForm::StudentDataForm() :
        QWidget(nullptr),
        ui(new Ui::StudentDataForm),
        mStudentNameValidator(nullptr),
        mGender(UNKNOWN) {
    ui->setupUi(this);
    QRegExp studentNameRegex("^[A-Z][a-z]{2,}$");
    mStudentNameValidator.reset(new QRegExpValidator(studentNameRegex, nullptr));

    ui->firstNameLineEdit->setValidator(mStudentNameValidator.get());
    ui->lastNameLineEdit->setValidator(mStudentNameValidator.get());

    connect(ui->addGradeButton, &QPushButton::clicked,
            this, &StudentDataForm::addGradeToList);
    connect(ui->editGradeButton, &QPushButton::clicked,
            this, &StudentDataForm::editGradeOnGradesList);
    connect(ui->deleteGradeButton, &QPushButton::clicked,
            this, &StudentDataForm::deleteGradeFromGradesList);
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
    mHeader = newHeader;
    QString formattedNewHeader = QString(
                "<html><head/><body><p align=\"center\">"
                "<span style=\" font-size:16pt; font-weight:600; "
                    "color:#ef2929;\"> %1 </span>"
                "</p></body></html>").arg(newHeader);
    ui->headerLabel->setText(formattedNewHeader);
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
    return mHeader;
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

void StudentDataForm::addGradeToList() {
    double newGrade = ui->gradesSlider->value() / 2.0;
    addGrade(newGrade);
}

void StudentDataForm::editGradeOnGradesList() {
    int indexOfSelectedGrade = ui->gradesList->currentRow();
    if (indexOfSelectedGrade > -1) {
        double newGrade = ui->gradesSlider->value() / 2.0;
        editGrade(static_cast<size_t>(indexOfSelectedGrade), newGrade);
    }
}

void StudentDataForm::deleteGradeFromGradesList() {
    int indexOfSelectedGrade = ui->gradesList->currentRow();
    if (indexOfSelectedGrade > -1) {
        deleteGrade(static_cast<size_t>(indexOfSelectedGrade));
    }
}
