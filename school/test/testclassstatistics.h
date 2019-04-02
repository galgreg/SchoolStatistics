#ifndef TESTCLASSSTATISTICS_H
#define TESTCLASSSTATISTICS_H

#include "testexecutioncounter.h"
#include <QtTest>

class TestClassStatistics : public QObject, public TestExecutionCounter
{
    Q_OBJECT

public:
    TestClassStatistics(unsigned &passed, unsigned &failed);
private slots:
    void cleanup();
    void testGetStudentAverage();
    void testGetClassAverage();
};

#endif // TESTCLASSSTATISTICS_H
