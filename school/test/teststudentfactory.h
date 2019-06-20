#ifndef TESTSTUDENTFACTORY_H
#define TESTSTUDENTFACTORY_H
#include "testexecutioncounter.h"
#include <QtTest>

class TestStudentFactory: public QObject, public TestExecutionCounter
{
    Q_OBJECT

public:
    TestStudentFactory(unsigned &passed, unsigned &failed);
private slots:
    void cleanup();
    void test_createStudent();
};

#endif // TESTSTUDENTFACTORY_H
