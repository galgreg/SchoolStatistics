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

    QString actualHeader_2 = mStudentDataForm->mHeader;
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

void TestStudentDataForm::testAddGrade() {
    QList<double> gradesToAdd = {3.5, 4.5, 5.0};

    for(int i = 0; i < gradesToAdd.size(); ++i) {
        mStudentDataForm->addGrade(gradesToAdd.at(i));
    }

    auto expectedGrades = gradesToAdd;
    auto actualGrades_1 = mStudentDataForm->getGrades();
    QCOMPARE(actualGrades_1, expectedGrades);

    auto actualGrades_2 = getGradesFromUiGradesList();
    QCOMPARE(actualGrades_2, expectedGrades);
}

void TestStudentDataForm::testEditGrade() {
    QList<double> gradesToAdd = {3.5, 4.5, 5.0};

    for(int i = 0; i < gradesToAdd.size(); ++i) {
        QString gradeString = QString::number(gradesToAdd.at(i), 'f', 1);
        mStudentDataForm->ui->gradesList->addItem(gradeString);
    }

    auto expectedGrades_BeforeEdit = gradesToAdd;
    auto actualGrades_BeforeEdit_1 = mStudentDataForm->getGrades();
    QCOMPARE(actualGrades_BeforeEdit_1, expectedGrades_BeforeEdit);

    auto actualGrades_BeforeEdit_2 = getGradesFromUiGradesList();
    QCOMPARE(actualGrades_BeforeEdit_2, expectedGrades_BeforeEdit);

    size_t indexOfEditedGrade = 1;
    double newGrade = 2.0;

    mStudentDataForm->editGrade(indexOfEditedGrade, newGrade);
    gradesToAdd[static_cast<int>(indexOfEditedGrade)] = newGrade;

    auto expectedGrades_AfterEdit = gradesToAdd;
    auto actualGrades_AfterEdit_1 = mStudentDataForm->getGrades();
    QCOMPARE(actualGrades_AfterEdit_1, expectedGrades_AfterEdit);

    auto actualGrades_AfterEdit_2 = getGradesFromUiGradesList();
    QCOMPARE(actualGrades_AfterEdit_2, expectedGrades_AfterEdit);
}

void TestStudentDataForm::testDeleteGrade() {
    QList<double> gradesList = {3.5, 4.5, 5.0};

    for(int i = 0; i < gradesList.size(); ++i) {
        QString gradeString = QString::number(gradesList.at(i), 'f', 1);
        mStudentDataForm->ui->gradesList->addItem(gradeString);
    }

    auto expectedGrades_BeforeDelete = gradesList;
    auto actualGrades_BeforeDelete_1 = mStudentDataForm->getGrades();
    QCOMPARE(actualGrades_BeforeDelete_1, expectedGrades_BeforeDelete);

    auto actualGrades_BeforeDelete_2 = getGradesFromUiGradesList();
    QCOMPARE(actualGrades_BeforeDelete_2, expectedGrades_BeforeDelete);

    size_t indexOfDeletedGrade = 1;

    mStudentDataForm->deleteGrade(indexOfDeletedGrade);
    gradesList.removeAt(static_cast<int>(indexOfDeletedGrade));

    auto expectedGrades_AfterDelete = gradesList;
    auto actualGrades_AfterDelete_1 = mStudentDataForm->getGrades();
    QCOMPARE(actualGrades_AfterDelete_1, expectedGrades_AfterDelete);

    auto actualGrades_AfterDelete_2 = getGradesFromUiGradesList();
    QCOMPARE(actualGrades_AfterDelete_2, expectedGrades_AfterDelete);
}

void TestStudentDataForm::testDeleteAllGrades() {
    QList<double> gradesList = {3.5, 4.5, 5.0};

    for(int i = 0; i < gradesList.size(); ++i) {
        QString gradeString = QString::number(gradesList.at(i), 'f', 1);
        mStudentDataForm->ui->gradesList->addItem(gradeString);
    }

    auto expectedGrades_BeforeDelete = gradesList;
    auto actualGrades_BeforeDelete_1 = mStudentDataForm->getGrades();
    QCOMPARE(actualGrades_BeforeDelete_1, expectedGrades_BeforeDelete);

    auto actualGrades_BeforeDelete_2 = getGradesFromUiGradesList();
    QCOMPARE(actualGrades_BeforeDelete_2, expectedGrades_BeforeDelete);

    mStudentDataForm->deleteAllGrades();

    QList<double> expectedGrades_AfterDelete = {};
    auto actualGrades_AfterDelete_1 = mStudentDataForm->getGrades();
    QCOMPARE(actualGrades_AfterDelete_1, expectedGrades_AfterDelete);

    auto actualGrades_AfterDelete_2 = getGradesFromUiGradesList();
    QCOMPARE(actualGrades_AfterDelete_2, expectedGrades_AfterDelete);
}

void TestStudentDataForm::testStudentNameValidation_data() {
    QTest::addColumn<QString>("inputString");
    QTest::addColumn<bool>("expectedValidationResult");

    QTest::newRow("input_numbers") << "0123456789" << false;
    QTest::newRow("input_lower_case") << "jan" << false;
    QTest::newRow("input_upper_case") << "JAN" << false;
    QTest::newRow("input_too_short") << "Ja" << false;
    QTest::newRow("input_with_special_chars") << "J@n" << false;
    QTest::newRow("input_inverted_case") << "jAN" << false;
    QTest::newRow("input_valid_string") << "Jan" << true;
}

void TestStudentDataForm::testStudentNameValidation() {
    const QValidator *expectedValidator =
            mStudentDataForm->mStudentNameValidator.get();

    const QValidator* actualValidator_FirstName =
            mStudentDataForm->ui->firstNameLineEdit->validator();
    QCOMPARE(actualValidator_FirstName, expectedValidator);

    const QValidator* actualValidator_LastName =
            mStudentDataForm->ui->lastNameLineEdit->validator();
    QCOMPARE(actualValidator_LastName, expectedValidator);

    QFETCH(QString, inputString);
    QFETCH(bool, expectedValidationResult);

    const auto& validatorRegex =
            mStudentDataForm->mStudentNameValidator->regExp();

    bool actualValidationResult = validatorRegex.exactMatch(inputString);
    QCOMPARE(actualValidationResult, expectedValidationResult);
}

void TestStudentDataForm::testAddGradeToList_data() {
    QTest::addColumn<int>("gradesSliderValue");
    QTest::addColumn<double>("expectedGrade");

    QTest::newRow("add 2.0") << 4 << 2.0;
    QTest::newRow("add 3.5") << 7 << 3.5;
    QTest::newRow("add 5.0") << 10 << 5.0;
}

void TestStudentDataForm::testAddGradeToList() {
    QFETCH(int, gradesSliderValue);
    mStudentDataForm->ui->gradesSlider->setValue(gradesSliderValue);
    mStudentDataForm->addGradeToList();

    const auto *gradesList = mStudentDataForm->ui->gradesList;
    QString gradeString = gradesList->item(0)->text();

    double actualGrade = gradeString.toDouble();
    QFETCH(double, expectedGrade);
    QCOMPARE(actualGrade, expectedGrade);
}

void TestStudentDataForm::testEditGradeOnGradesList_data() {
    QTest::addColumn<QList<double>>("expectedGradesListBeforeEdit");
    QTest::addColumn<int>("indexOfSelectedGrade");
    QTest::addColumn<int>("gradesSliderValue");
    QTest::addColumn<QList<double>>("expectedGradesListAfterEdit");

    QTest::newRow("Empty gradelist") << QList<double>({}) << -1 << 7
                            << QList<double>({});
    QTest::newRow("case 2") << QList<double>({2.5, 3.5, 4.5}) << 0 << 10
                            << QList<double>({5.0, 3.5, 4.5});
    QTest::newRow("case 3") << QList<double>({5.0, 3.5, 2.0}) << 2 << 5
                            << QList<double>({5.0, 3.5, 2.5});
}

void TestStudentDataForm::testEditGradeOnGradesList() {
    QFETCH(QList<double>, expectedGradesListBeforeEdit);

    for (int i = 0; i < expectedGradesListBeforeEdit.size(); ++i) {
        double gradeValue = expectedGradesListBeforeEdit.at(i);
        QString gradeString = QString::number(gradeValue, 'f', 1);
        mStudentDataForm->ui->gradesList->addItem(gradeString);
    }
    QList<double> actualGradesListBeforeEdit = getGradesFromUiGradesList();
    QCOMPARE(actualGradesListBeforeEdit, expectedGradesListBeforeEdit);

    QFETCH(int, indexOfSelectedGrade);
    mStudentDataForm->ui->gradesList->setCurrentRow(indexOfSelectedGrade);
    QFETCH(int, gradesSliderValue);
    mStudentDataForm->ui->gradesSlider->setValue(gradesSliderValue);

    mStudentDataForm->editGradeOnGradesList();

    QFETCH(QList<double>, expectedGradesListAfterEdit);
    QList<double> actualGradesListAfterEdit = getGradesFromUiGradesList();
    QCOMPARE(actualGradesListAfterEdit, expectedGradesListAfterEdit);
}

void TestStudentDataForm::testDeleteGradeFromGradesList() {
    QList<double> expectedGradesListBeforeDelete = {5.0, 4.0, 3.5};

    for (int i = 0; i < expectedGradesListBeforeDelete.size(); ++i) {
        double gradeValue = expectedGradesListBeforeDelete.at(i);
        QString gradeString = QString::number(gradeValue, 'f', 1);
        mStudentDataForm->ui->gradesList->addItem(gradeString);
    }
    QList<double> actualGradesListBeforeDelete = getGradesFromUiGradesList();
    QCOMPARE(actualGradesListBeforeDelete, expectedGradesListBeforeDelete);

    int indexOfSelectedGrade = 2;
    mStudentDataForm->ui->gradesList->setCurrentRow(indexOfSelectedGrade);
    mStudentDataForm->deleteGradeFromGradesList();

    QList<double> expectedGradesListAfterDelete = {5.0, 4.0};
    QList<double> actualGradesListAfterDelete = getGradesFromUiGradesList();
    QCOMPARE(actualGradesListAfterDelete, expectedGradesListAfterDelete);
}

QList<double> TestStudentDataForm::getGradesFromUiGradesList() {
    QList<double> gradesFromUiList;
    const auto& gradesList = *(mStudentDataForm->ui->gradesList);

    for (int i = 0; i < gradesList.count(); ++i) {
        double newGrade = gradesList.item(i)->text().toDouble();
        gradesFromUiList.append(newGrade);
    }
    return gradesFromUiList;
}
