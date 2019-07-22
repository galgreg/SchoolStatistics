#include "teststudentdatawindow.h"
#include "ui_studentdatawindow.h"

TestStudentDataWindow::TestStudentDataWindow(
        unsigned &passed,
        unsigned &failed) :
            TestExecutionCounter(passed, failed),
            mStudentDataWindow(nullptr) {

}

void TestStudentDataWindow::init() {
    mStudentDataWindow.reset(
            new StudentDataWindow(std::make_shared<SignalTransmitter>()));
}

void TestStudentDataWindow::cleanup() {
    if (QTest::currentTestFailed()) {
        incrementFailCounter();
    } else {
        incrementPassCounter();
    }
}

void TestStudentDataWindow::testInitialState() {
    QString expectedInitialID = "None";
    QString actualInitialID = mStudentDataWindow->getID();
    QCOMPARE(actualInitialID, expectedInitialID);

    QString expectedInitialFirstName = "None";
    QString actualInitialFirstName = mStudentDataWindow->getFirstName();
    QCOMPARE(actualInitialFirstName, expectedInitialFirstName);

    QString expectedInitialLastName = "None";
    QString actualInitialLastName = mStudentDataWindow->getLastName();
    QCOMPARE(actualInitialLastName, expectedInitialLastName);

    QString expectedInitialGender = "None";
    QString actualInitialGender = mStudentDataWindow->getGender();
    QCOMPARE(actualInitialGender, expectedInitialGender);

    QString expectedInitialGrades = "None";
    QString actualInitialGrades = mStudentDataWindow->getGrades();
    QCOMPARE(actualInitialGrades, expectedInitialGrades);

    QString expectedInitialGradesAverage = "None";
    QString actualInitialGradesAverage = mStudentDataWindow->getGradesAverage();
    QCOMPARE(actualInitialGradesAverage, expectedInitialGradesAverage);
}

void TestStudentDataWindow::testSetters() {
    QString expectedID = "10";
    mStudentDataWindow->setID(expectedID);
    QString actualID = mStudentDataWindow->ui->studentIDValue->text();
    QCOMPARE(actualID, expectedID);

    QString expectedFirstName = "Jan";
    mStudentDataWindow->setFirstName(expectedFirstName);
    QString actualFirstName = mStudentDataWindow->ui->firstNameValue->text();
    QCOMPARE(actualFirstName, expectedFirstName);

    QString expectedLastName = "Kowalski";
    mStudentDataWindow->setLastName(expectedLastName);
    QString actualLastName = mStudentDataWindow->ui->lastNameValue->text();
    QCOMPARE(actualLastName, expectedLastName);

    QString expectedGender = "Female";
    mStudentDataWindow->setGender(expectedGender);
    QString actualGender = mStudentDataWindow->ui->genderValue->text();
    QCOMPARE(actualGender, expectedGender);

    QString expectedGrades = "5.0, 4.5, 4.0";
    mStudentDataWindow->setGrades(expectedGrades);
    QString actualGrades = mStudentDataWindow->ui->gradesValue->text();
    QCOMPARE(actualGrades, expectedGrades);

    QString expectedGradesAverage = "4.5";
    mStudentDataWindow->setGradesAverage(expectedGradesAverage);
    QString actualGradesAverage =
            mStudentDataWindow->ui->gradesAverageValue->text();
    QCOMPARE(actualGradesAverage, expectedGradesAverage);
}

void TestStudentDataWindow::testShowWidget() {
    mStudentDataWindow->showWidget();
    bool isWindowVisible = mStudentDataWindow->isVisible();
    QVERIFY(isWindowVisible == true);
}

void TestStudentDataWindow::testHideWidget() {
    mStudentDataWindow->hideWidget();
    bool isWindowVisible = mStudentDataWindow->isVisible();
    QVERIFY(isWindowVisible == false);
}
