#include "teststudentdataform.h"
#include "ui_studentdataform.h"

TestStudentDataForm::TestStudentDataForm(
        unsigned &passed,
        unsigned &failed) :
            TestExecutionCounter(passed, failed) {

}

void TestStudentDataForm::init() {
    mStudentDataForm.reset(new StudentDataForm);
}

void TestStudentDataForm::cleanup() {
    if (QTest::currentTestFailed()) {
        incrementFailCounter();
    } else {
        incrementPassCounter();
    }
}

void TestStudentDataForm::testShowAndHideForm() {
    mStudentDataForm->showForm();
    bool isFormVisible = mStudentDataForm->isVisible();
    QVERIFY(isFormVisible == true);
    mStudentDataForm->hideForm();
    isFormVisible = mStudentDataForm->isVisible();
    QVERIFY(isFormVisible == false);
}

void TestStudentDataForm::testSetHeader() {
    QString expectedHeader = "Add Student";
    mStudentDataForm->setHeader(expectedHeader);

    QString actualHeader_1 = mStudentDataForm->getHeader();
    QCOMPARE(actualHeader_1, expectedHeader);

    QString actualHeader_2 = mStudentDataForm->ui->headerLabel->text();
    QCOMPARE(actualHeader_2, expectedHeader);
}

void TestStudentDataForm::testSetFirstName() {
    QString expectedFirstName = "Jan";
    mStudentDataForm->setFirstName(expectedFirstName);

    QString actualFirstName_1 = mStudentDataForm->getFirstName();
    QCOMPARE(actualFirstName_1, expectedFirstName);

    QString actualFirstName_2 = mStudentDataForm->ui->firstNameLineEdit->text();
    QCOMPARE(actualFirstName_2, expectedFirstName);
}

void TestStudentDataForm::testSetLastName() {
    QString expectedLastName = "Kowalski";
    mStudentDataForm->setLastName(expectedLastName);

    QString actualLastName_1 = mStudentDataForm->getLastName();
    QCOMPARE(actualLastName_1, expectedLastName);

    QString actualLastName_2 = mStudentDataForm->ui->lastNameLineEdit->text();
    QCOMPARE(actualLastName_2, expectedLastName);
}

void TestStudentDataForm::testSetGender_data() {
    QTest::addColumn<Gender>("newGender");
    QTest::addColumn<bool>("expectedMaleButtonValue");
    QTest::addColumn<bool>("expectedFemaleButtonValue");
    QTest::addColumn<bool>("expectedUnknownGenderButtonValue");

    QTest::newRow("set_male_gender") << MALE << true << false << false;
    QTest::newRow("set_female_gender") << FEMALE << false << true << false;
    QTest::newRow("set_unknown_gender") << UNKNOWN << false << false << true;
}

void TestStudentDataForm::testSetGender() {
    QFETCH(Gender, newGender);

    mStudentDataForm->setGender(newGender);
    Gender expectedGender = newGender;
    Gender actualGender = mStudentDataForm->getGender();
    QCOMPARE(actualGender, expectedGender);

    QFETCH(bool, expectedMaleButtonValue);
    bool actualMaleButtonValue = mStudentDataForm->ui->maleButton->isChecked();
    QCOMPARE(actualMaleButtonValue, expectedMaleButtonValue);

    QFETCH(bool, expectedFemaleButtonValue);
    bool actualFemaleButtonValue = mStudentDataForm->ui->femaleButton->isChecked();
    QCOMPARE(actualFemaleButtonValue, expectedFemaleButtonValue);

    QFETCH(bool, expectedUnknownGenderButtonValue);
    bool actualUnknownGenderButtonValue =
            mStudentDataForm->ui->unknownGenderButton->isChecked();
    QCOMPARE(actualUnknownGenderButtonValue, expectedUnknownGenderButtonValue);
}
