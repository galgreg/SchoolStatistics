#ifndef TESTIDGENERATOR_H
#define TESTIDGENERATOR_H
#include "testexecutioncounter.h"
#include <QtTest>

class TestIdGenerator : public QObject, public TestExecutionCounter
{
    Q_OBJECT

public:
    TestIdGenerator(unsigned &passed, unsigned &failed);

private slots:
    void testInstanceReturnsNotNull();
    void testInstanceIsAlwaysSame();
    void testGeneratedValuesAreUnique();
    void cleanup();
};

#endif // TESTIDGENERATOR_H
