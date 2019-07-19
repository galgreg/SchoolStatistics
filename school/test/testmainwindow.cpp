#include "testmainwindow.h"
#include "confirmdialogmock.h"
#include "datarepositorymock.h"
#include "studentclass.h"
#include "studentdataformmock.h"
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

    std::unique_ptr<IDataRepository> dataRepository(new DataRepositoryMock);
    dataRepository->write(*mStudentClassData);

    mMainWindow.reset(
            new MainWindow(
                    std::move(dataRepository),
                    std::make_unique<StudentDataWidgetMock>(),
                    std::make_unique<ConfirmDialogMock>(),
                    std::make_unique<StudentDataFormMock>(),
                    std::make_shared<SignalTransmitter>()));
}

void TestMainWindow::cleanup() {
    if (QTest::currentTestFailed()) {
        incrementFailCounter();
    } else {
        incrementPassCounter();
    }
}

void TestMainWindow::testMaxCounts_Default() {
    std::unique_ptr<MainWindow> tempWindow(
            new MainWindow(
                std::make_unique<DataRepositoryMock>(),
                std::make_unique<StudentDataWidgetMock>(),
                std::make_unique<ConfirmDialogMock>(),
                std::make_unique<StudentDataFormMock>(),
                std::make_shared<SignalTransmitter>()));

    size_t expectedStudentMaxCount = 20;
    size_t actualStudentMaxCount = tempWindow->mMaxStudentCount;
    QCOMPARE(actualStudentMaxCount, expectedStudentMaxCount);

    size_t expectedGradesMaxCount = 3;
    size_t actualGradesMaxCount_1 = tempWindow->mMaxGradesCount;
    QCOMPARE(actualGradesMaxCount_1, expectedGradesMaxCount);

    size_t actualGradesMaxCount_2 =
            tempWindow->mStudentDataForm->getMaxGradesCount();
    QCOMPARE(actualGradesMaxCount_2, expectedGradesMaxCount);
}

void TestMainWindow::testMaxCounts_SetValues() {
    size_t windowStudentMaxCount = 13;
    size_t windowGradesMaxCount = 5;

    std::unique_ptr<MainWindow> tempWindow(
            new MainWindow(
                std::make_unique<DataRepositoryMock>(),
                std::make_unique<StudentDataWidgetMock>(),
                std::make_unique<ConfirmDialogMock>(),
                std::make_unique<StudentDataFormMock>(),
                std::make_shared<SignalTransmitter>(),
                windowStudentMaxCount,
                windowGradesMaxCount));

    size_t expectedStudentMaxCount = windowStudentMaxCount;
    size_t actualStudentMaxCount = tempWindow->mMaxStudentCount;
    QCOMPARE(actualStudentMaxCount, expectedStudentMaxCount);

    size_t expectedGradesMaxCount = windowGradesMaxCount;
    size_t actualGradesMaxCount_1 = tempWindow->mMaxGradesCount;
    QCOMPARE(actualGradesMaxCount_1, expectedGradesMaxCount);

    size_t actualGradesMaxCount_2 =
            tempWindow->mStudentDataForm->getMaxGradesCount();
    QCOMPARE(actualGradesMaxCount_2, expectedGradesMaxCount);
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
    QTest::addColumn<StudentDataAction>("actionToConfirm");
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
    QFETCH(StudentDataAction, actionToConfirm);
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

void TestMainWindow::testDoAction_DeleteStudent() {
    size_t studentIndex = 1;
    mMainWindow->ui->studentList->setCurrentRow(static_cast<int>(studentIndex));

    const auto& expectedStudentClassBeforeDelete = *mStudentClassData;
    const auto& actualStudentClassBeforeDelete = *mMainWindow->mStudentClass;
    QCOMPARE(actualStudentClassBeforeDelete, expectedStudentClassBeforeDelete);

    mStudentClassData->removeStudent(studentIndex);
    mMainWindow->doAction(DELETE_STUDENT);

    const auto& expectedStudentClassAfterDelete = *mStudentClassData;
    const auto& actualStudentClassAfterDelete = *mMainWindow->mStudentClass;
    QCOMPARE(actualStudentClassAfterDelete, expectedStudentClassAfterDelete);
}

void TestMainWindow::testPrepareStudentDataFormToDisplay_AddStudent() {
    StudentDataAction actionToPerform = ADD_STUDENT;
    mMainWindow->prepareStudentDataFormToDisplay(actionToPerform);

    QString expectedHeader = "Add Student";
    QString actualHeader = mMainWindow->mStudentDataForm->getHeader();
    QCOMPARE(actualHeader, expectedHeader);

    QString expectedFirstName = "";
    QString actualFirstName = mMainWindow->mStudentDataForm->getFirstName();
    QCOMPARE(actualFirstName, expectedFirstName);

    QString expectedLastName = "";
    QString actualLastName = mMainWindow->mStudentDataForm->getLastName();
    QCOMPARE(actualLastName, expectedLastName);

    Gender expectedGender = UNKNOWN;
    Gender actualGender = mMainWindow->mStudentDataForm->getGender();
    QCOMPARE(actualGender, expectedGender);

    QList<double> expectedGrades = {};
    QList<double> actualGrades = mMainWindow->mStudentDataForm->getGrades();
    QCOMPARE(actualGrades, expectedGrades);
}
