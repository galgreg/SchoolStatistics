#ifndef TESTSTUDENTDATAMANAGER_H
#define TESTSTUDENTDATAMANAGER_H

#include <QtTest>
#include "testexecutioncounter.h"

class TestStudentDataManager : public QObject, public TestExecutionCounter
{
    Q_OBJECT

public:
    TestStudentDataManager(unsigned &passed, unsigned &failed);
private slots:
    void cleanup();
};

#endif // TESTSTUDENTDATAMANAGER_H
