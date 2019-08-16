#ifndef TESTGRADES_H
#define TESTGRADES_H

#include "testexecutioncounter.h"
#include "grades.h"
#include <QtTest>

class TestGrades : public QObject, public TestExecutionCounter
{
    Q_OBJECT

public:
    TestGrades(unsigned &passed, unsigned &failed) noexcept;

private slots:
    void init();
    void cleanup() noexcept;
    void testDefaultState() noexcept;
    void testAddGrade_OK() noexcept;
    void testAddGrade_GradesOverflow() noexcept;
    void testRemoveGrade_OK() noexcept;
    void testRemoveGrade_Error_NoSuchGrade() noexcept;
    void testEditGrade_OK() noexcept;
    void testEditGrade_Error_NoSuchGrade() noexcept;
private:
    std::unique_ptr<Grades> grades;
};

#endif // TESTGRADES_H
