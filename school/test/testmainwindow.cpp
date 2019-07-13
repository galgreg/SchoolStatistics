#include "testmainwindow.h"
#include "confirmdialogmock.h"
#include "datarepositorymock.h"
#include "studentclass.h"
#include "studentdatawidgetmock.h"
#include "studentfactory.h"
#include "ui_mainwindow.h"

TestMainWindow::TestMainWindow(
        unsigned &passed,
        unsigned &failed) :
                TestExecutionCounter(passed, failed),
                mMainWindow(nullptr),
                mStudentClassData(nullptr) {

}

TestMainWindow::~TestMainWindow() {
    QFile testFile(mPathToTestRepository);
    if (testFile.exists()) {
        testFile.remove();
    }
}

void TestMainWindow::init() {
    mStudentClassData.reset(new StudentClass);
    mStudentClassData->addStudent(StudentFactory::create(
            1, "Jan", "Kowalski", MALE, {5.0, 3.0, 4.0}));
    mStudentClassData->addStudent(StudentFactory::create(
            2, "Maria", "Nowak", FEMALE, {3.0, 3.0, 3.0}));
    mStudentClassData->addStudent(StudentFactory::create(
            3, "Gal", "Anonim", UNKNOWN, {2.0, 2.0, 2.0}));

    IDataRepository *dataRepository = new DataRepositoryMock;
    dataRepository->write(*mStudentClassData);

    mMainWindow.reset(
            new MainWindow(
                    dataRepository,
                    new StudentDataWidgetMock,
                    new ConfirmDialogMock));
}

void TestMainWindow::cleanup() {
    if (QTest::currentTestFailed()) {
        incrementFailCounter();
    } else {
        incrementPassCounter();
    }
}

void TestMainWindow::testReadDataFromRepository() {
    mMainWindow->readDataFromRepository();
    const IStudentClass& expectedStudentClass = *mStudentClassData;
    const IStudentClass& actualStudentClass = *mMainWindow->mStudentClass;

    QCOMPARE(actualStudentClass, expectedStudentClass);

    QString expectedStudentNumberValueText = "3";
    QString actualStudentNumberValueText =
            mMainWindow->ui->studentsNumberValue->text();
    QCOMPARE(actualStudentNumberValueText, expectedStudentNumberValueText);

    QString expectedClassAverageValue = "3.0";
    QString actualClassAverageValue =
            mMainWindow->ui->classAverageValue->text();
    QCOMPARE(actualClassAverageValue, expectedClassAverageValue);

    QList<QString> expectedStudentListContent =
            {"Jan Kowalski", "Maria Nowak", "Gal Anonim"};
    QList<QString> actualStudentListContent;
    const auto& studentList = *(mMainWindow->ui->studentList);


    for (int i = 0; i < studentList.count(); ++i) {
        const auto& item = studentList.item(i);
        actualStudentListContent.append(item->text());
    }
    QCOMPARE(actualStudentListContent, expectedStudentListContent);
}

void TestMainWindow::testDeleteStudent() {
    size_t studentIndex = 1;
    const auto& expectedStudentClassBeforeDelete = *mStudentClassData;
    const auto& actualStudentClassBeforeDelete = *mMainWindow->mStudentClass;
    QCOMPARE(actualStudentClassBeforeDelete, expectedStudentClassBeforeDelete);

    mStudentClassData->removeStudent(studentIndex);
    mMainWindow->deleteStudent(studentIndex);

    const auto& expectedStudentClassAfterDelete = *mStudentClassData;
    const auto& actualStudentClassAfterDelete = *mMainWindow->mStudentClass;
    QCOMPARE(actualStudentClassAfterDelete, expectedStudentClassAfterDelete);
}

void TestMainWindow::testPrepareStudentDataWidgetToDisplay() {
    size_t studentIndex = 1;
    mMainWindow->prepareStudentDataWidgetToDisplay(studentIndex);
    QString expectedStudentID = "2";
    QString actualStudentID = mMainWindow->mStudentDataWidget->getID();
    QCOMPARE(actualStudentID, expectedStudentID);

    QString expectedFirstName = "Maria";
    QString actualFirstName = mMainWindow->mStudentDataWidget->getFirstName();
    QCOMPARE(actualFirstName, expectedFirstName);

    QString expectedLastName = "Nowak";
    QString actualLastName = mMainWindow->mStudentDataWidget->getLastName();
    QCOMPARE(actualLastName, expectedLastName);

    QString expectedGender = "Female";
    QString actualGender = mMainWindow->mStudentDataWidget->getGender();
    QCOMPARE(actualGender, expectedGender);

    QString expectedGrades = "3.0, 3.0, 3.0";
    QString actualGrades = mMainWindow->mStudentDataWidget->getGrades();
    QCOMPARE(actualGrades, expectedGrades);

    QString expectedGradesAverage = "3.0";
    QString actualGradesAverage =
            mMainWindow->mStudentDataWidget->getGradesAverage();
    QCOMPARE(actualGradesAverage, expectedGradesAverage);
}

void TestMainWindow::testPrepareConfirmDialogToDisplay_data() {
    QTest::addColumn<ConfirmAction>("actionToConfirm");
    QTest::addColumn<QString>("studentName");
    QTest::addColumn<QString>("expectedActionString");

    QTest::newRow("add_jan_kowalski")
            << ADD_STUDENT << "Jan Kowalski" << "add";
    QTest::newRow("edit_maria_nowak")
            << EDIT_STUDENT << "Maria Nowak" << "edit";
    QTest::newRow("delete_gal_anonim")
            << DELETE_STUDENT << "Gal Anonim" << "delete";
}

void TestMainWindow::testPrepareConfirmDialogToDisplay() {
    QFETCH(ConfirmAction, actionToConfirm);
    QFETCH(QString, studentName);
    mMainWindow->prepareConfirmDialogToDisplay(actionToConfirm, studentName);

    QFETCH(QString, expectedActionString);
    QString actualActionString =
            mMainWindow->mConfirmDialog->getCurrentActionString();
    QCOMPARE(actualActionString, expectedActionString);

    QString expectedStudentName = studentName;
    QString actualStudentName =
            mMainWindow->mConfirmDialog->getCurrentStudentName();
    QCOMPARE(actualStudentName, expectedStudentName);
}
