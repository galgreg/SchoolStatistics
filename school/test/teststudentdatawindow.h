#ifndef TESTSTUDENTDATAWINDOW_H
#define TESTSTUDENTDATAWINDOW_H

#include "testexecutioncounter.h"
#include "studentdatawindow.h"
#include <QtTest>

class TestStudentDataWindow : public QObject, public TestExecutionCounter
{
    Q_OBJECT

public:
    TestStudentDataWindow(unsigned &passed, unsigned &failed);

private slots:
    void init();
    void cleanup();
    void testInitialState();
    void testSetters();
    void testShowWidget();
    void testHideWidget();

private:
    std::unique_ptr<StudentDataWindow> mStudentDataWindow;
};

#endif // TESTSTUDENTDATAWINDOW_H
