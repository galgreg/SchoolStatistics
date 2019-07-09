#include "testmainwindow.h"

TestMainWindow::TestMainWindow(
        unsigned &passed, unsigned &failed) :
            TestExecutionCounter(passed, failed), mMainWindow(nullptr) {
    prepareTestFile();
}

void TestMainWindow::prepareTestFile() {
    QString fileContent = "1 Jan Kowalski M 5.0 3.0 4.0 \n"
            "2 Maria Nowak F 3.0 3.0 3.0 \n"
            "3 Gal Anonim U 2.0 2.0 2.0 \n";
    QFile testFile(mPathToTestFile);
    if (testFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream outputStream(&testFile);
        outputStream << fileContent;
    } else {
        throw std::ios_base::failure(
                "Cannot open file " + mPathToTestFile.toStdString());
    }
}

TestMainWindow::~TestMainWindow() {
    QFile testFile(mPathToTestFile);
    if (testFile.exists()) {
        testFile.remove();
    }
}

void TestMainWindow::init() {
    mMainWindow.reset(new MainWindow);
}

void TestMainWindow::cleanup() {
    if (QTest::currentTestFailed()) {
        incrementFailCounter();
    } else {
        incrementPassCounter();
    }
}
