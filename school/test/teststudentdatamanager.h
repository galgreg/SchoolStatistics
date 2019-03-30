#ifndef TESTSTUDENTDATAMANAGER_H
#define TESTSTUDENTDATAMANAGER_H

#include <QtTest>
#include "testexecutioncounter.h"
#include "studentdatamanager.h"

class TestStudentDataManager : public QObject, public TestExecutionCounter
{
    Q_OBJECT

public:
    TestStudentDataManager(unsigned &passed, unsigned &failed);
private slots:
    void init();
    void cleanup();
    //void testRead();
    //void testWrite();
private:
    QString fileName;
    StudentDataManager *dataManager;
};

#endif // TESTSTUDENTDATAMANAGER_H
