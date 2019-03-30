#ifndef TESTSTUDENT_H
#define TESTSTUDENT_H

#include <QtTest>
#include "student.h"
#include "testexecutioncounter.h"

class TestStudent : public QObject, public TestExecutionCounter
{
    Q_OBJECT

public:
    TestStudent(unsigned &passed, unsigned &failed);

private slots:
    void testCreateStudent();
    void testCreateStudent_data();
    void testAddGrades();
    void testEditGrades();
    void testRemoveGrades();
    void cleanup();
private:
    void checkGrades(
            const Student &student,
            int expectedGradesCount,
            double expectedGradesAverage);
};

#endif // TESTSTUDENT_H
