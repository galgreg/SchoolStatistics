#ifndef TESTSTUDENT_H
#define TESTSTUDENT_H

#include "testexecutioncounter.h"
#include "igrades.h"
#include "ipersonaldata.h"
#include "student.h"
#include <QtTest>

class TestStudent : public QObject, public TestExecutionCounter
{
    Q_OBJECT

public:
    TestStudent(unsigned &passed, unsigned &failed);
private slots:
    void cleanup();
    void testState_DefaultInitialized();
    void testState_DataInitialized();
    void testChangeStateBySetters();
private:
    void checkObjectState(
        const Student &actualStudent,
        unsigned expectedID,
        IPersonalData *expectedPersonalData,
        IGrades *expectedGrades);
};

#endif // TESTSTUDENT_H
