#ifndef TESTPERSONALDATA_H
#define TESTPERSONALDATA_H

#include "testexecutioncounter.h"
#include <QtTest>

class TestPersonalData : public QObject, public TestExecutionCounter
{
    Q_OBJECT
public:
    TestPersonalData(unsigned &passed, unsigned &failed);
private slots:
    void cleanup();
    void testGetters();
};

#endif // TESTPERSONALDATA_H
