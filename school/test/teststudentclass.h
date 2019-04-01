#ifndef TESTSTUDENTCLASS_H
#define TESTSTUDENTCLASS_H

#include "testexecutioncounter.h"
#include <QtTest>

class TestStudentClass : public QObject, TestExecutionCounter
{
    Q_OBJECT

public:
    TestStudentClass(unsigned &passed, unsigned &failed);
private slots:
    void cleanup();
    void testStateAfterInitialization();
    void testAddStudent_OK();
    void testAddStudent_ClassOverflow();
};

#endif // TESTSTUDENTCLASS_H
