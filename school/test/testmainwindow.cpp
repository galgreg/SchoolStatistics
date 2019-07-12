#include "testmainwindow.h"
#include "datarepositorymock.h"
#include "studentclass.h"
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

    mMainWindow.reset(new MainWindow(dataRepository));
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
