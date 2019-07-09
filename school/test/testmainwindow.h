#ifndef TESTMAINWINDOW_H
#define TESTMAINWINDOW_H

#include <QtTest>
#include "testexecutioncounter.h"
#include "mainwindow.h"

class TestMainWindow : public QObject, public TestExecutionCounter
{
    Q_OBJECT
public:
    TestMainWindow(unsigned &passed, unsigned &failed);
    ~TestMainWindow();
private slots:
    void init();
    void cleanup();
private:
    void prepareTestFile();

    std::unique_ptr<MainWindow> mMainWindow;
    QString mPathToTestFile = "TEST_MAIN_WINDOW_FILE.txt";
};

#endif // TESTMAINWINDOW_H
