#ifndef TESTSTUDENT_H
#define TESTSTUDENT_H

#include "testexecutioncounter.h"
#include <QtTest>

class TestStudent : public QObject, public TestExecutionCounter
{
    Q_OBJECT

public:
    TestStudent(unsigned &passed, unsigned &failed);
private slots:
    void cleanup();
    void testState_DefaultInitialized();
};

#endif // TESTSTUDENT_H
