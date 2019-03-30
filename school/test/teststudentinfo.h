#ifndef TESTSTUDENTINFO_H
#define TESTSTUDENTINFO_H

#include <QtTest>
#include "testexecutioncounter.h"

class TestStudentInfo : public QObject, public TestExecutionCounter
{
    Q_OBJECT

public:
    TestStudentInfo(unsigned &passed, unsigned &failed);

private slots:
    void testCreate();
    void cleanup();
};

#endif // TESTSTUDENTINFO_H
