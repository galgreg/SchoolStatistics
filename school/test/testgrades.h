#ifndef TESTGRADES_H
#define TESTGRADES_H

#include "testexecutioncounter.h"
#include "grades.h"
#include <QtTest>

class TestGrades : public QObject, public TestExecutionCounter
{
    Q_OBJECT

public:
    TestGrades(unsigned &passed, unsigned &failed);

private slots:
    void init();
    void cleanup();
    void testDefaultState();
    void testAddGrade_OK();
    void testAddGrade_GradesOverflow();
    void testRemoveGrade_OK();
    void testRemoveGrade_ErrorNoSuchGrade();
    void testEditGrade_OK();
private:
    std::unique_ptr<Grades> grades;
};

#endif // TESTGRADES_H
