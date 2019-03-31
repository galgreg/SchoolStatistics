#ifndef TESTGRADES_H
#define TESTGRADES_H

#include "testexecutioncounter.h"
#include <QtTest>

class TestGrades : public QObject, public TestExecutionCounter
{
    Q_OBJECT

public:
    TestGrades(unsigned &passed, unsigned &failed);

private slots:
    void cleanup();
};

#endif // TESTGRADES_H
