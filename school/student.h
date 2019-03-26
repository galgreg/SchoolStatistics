#ifndef STUDENT_H
#define STUDENT_H
#include "gender.h"
#include <QList>
#include <QString>

class Student
{
public:
    Student(QString firstName, QString lastName, Gender gender);
private:
    unsigned ID;
    QString hisFirstName, hisLastName;
    Gender hisGender;
    QList<double> hisTestGrades;
    double hisFinalGrade;
};

#endif // STUDENT_H
