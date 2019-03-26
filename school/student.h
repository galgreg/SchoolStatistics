#ifndef STUDENT_H
#define STUDENT_H
#include "gender.h"
#include <QList>
#include <QString>

class Student
{
public:
    Student(QString firstName, QString lastName, Gender gender);
    void addGrade(double grade);
    void editGrade(int whichGrade, double newGrade);
    void removeGrade(int whichGrade);
private:
    unsigned ID;
    QString hisFirstName, hisLastName;
    Gender hisGender;
    QList<double> hisGrades;
    double hisFinalGrade;
};

#endif // STUDENT_H
