#ifndef TESTSTUDENT_H
#define TESTSTUDENT_H

#include "testexecutioncounter.h"
#include <QtTest>

class TestStudent : public QObject, public TestExecutionCounter
{
public:
    TestStudent(unsigned &passed, unsigned &failed);
private slots:
    void cleanup();
};

#endif // TESTSTUDENT_H
