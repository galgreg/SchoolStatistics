#ifndef TESTSTUDENT_H
#define TESTSTUDENT_H

#include <QtTest>
#include "student.h"

class TestStudent : public QObject
{
    Q_OBJECT

private slots:
    void testCreateStudent();
    void testCreateStudent_data();
    void testAddGrades();
    void testEditGrades();
    void testRemoveGrades();
private:
    void checkGrades(
            const Student &student,
            int expectedGradesCount,
            double expectedGradesAverage);
};

#endif // TESTSTUDENT_H
