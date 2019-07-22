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
    void testInitialState_WhenRepositoryIsEmpty();
    void testMaxCounts_Default();
    void testMaxCounts_SetValues();
    void testReadDataFromRepository();
    void testDeleteStudent();
    void testPrepareStudentDataWidgetToDisplay();
    void testPrepareConfirmDialogToDisplay_data();
    void testPrepareConfirmDialogToDisplay();
    void testDoAction_DeleteStudent();
    void testDoAction_AddStudent();
    void testDoDeleteAction();
    void testDoAddAction();

    void testBeginAddTransaction();

    void testPrepareStudentDataFormToDisplay_AddStudent();
private:
    std::unique_ptr<MainWindow> mMainWindow;
    std::unique_ptr<IStudentClass> mStudentClassData;
    QString mPathToTestRepository = "TEST_MAIN_WINDOW_FILE.txt";
};

#endif // TESTMAINWINDOW_H
