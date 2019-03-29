#ifndef TESTSTUDENT_H
#define TESTSTUDENT_H

#include <QtTest>
#include "student.h"

class TestStudent : public QObject
{
    Q_OBJECT

private slots:
    void testCreateDefaultStudent();
    void testCreateStudent();
private:
    void verifyStudentData(
        const Student &student,
        unsigned expectedID,
        const QString &expectedFullName,
        Gender expectedGender,
        int expectedGradesNumber,
        double expectedGradesAverage);
};

#endif // TESTSTUDENT_H
