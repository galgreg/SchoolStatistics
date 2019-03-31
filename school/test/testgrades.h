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
    void testAddGrade_OK();
private:
    std::unique_ptr<Grades> grades;
};

#endif // TESTGRADES_H
