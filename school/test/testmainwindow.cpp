#include "testmainwindow.h"
#include "datarepositorymock.h"
#include "studentclass.h"
#include "studentfactory.h"

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

    if (mMainWindow) {
        delete mMainWindow;
    }
    mMainWindow = new MainWindow(dataRepository, new StudentClass);
}

void TestMainWindow::cleanup() {
    if (QTest::currentTestFailed()) {
        incrementFailCounter();
    } else {
        incrementPassCounter();
    }
}

void TestMainWindow::testReadDataFromRepository() {

}
