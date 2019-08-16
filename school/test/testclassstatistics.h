#ifndef TESTCLASSSTATISTICS_H
#define TESTCLASSSTATISTICS_H

#include "testexecutioncounter.h"
#include <QtTest>

class TestClassStatistics : public QObject, public TestExecutionCounter
{
    Q_OBJECT

public:
    TestClassStatistics(unsigned &passed, unsigned &failed) noexcept;
private slots:
    void cleanup() noexcept;
    void testGetStudentAverage() noexcept;
    void testGetStudentAverage_NoGrades() noexcept;
    void testGetClassAverage() noexcept;
    void testGetClassAverage_EmptyClass() noexcept;
};

#endif // TESTCLASSSTATISTICS_H
