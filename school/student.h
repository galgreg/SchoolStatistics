#ifndef STUDENT_H
#define STUDENT_H
#include "gender.h"
#include <QList>
#include <QString>

class Student
{
public:
    using GradesRange = std::pair<QList<double>::const_iterator, QList<double>::const_iterator>;

    Student(QString firstName, QString lastName, Gender gender);
    void addGrade(double grade);
    void editGrade(int whichGrade, double newGrade);
    void removeGrade(int whichGrade);

    GradesRange getGrades() const;
    double getGradesAverage() const;
    QString getFullName() const;
    Gender getGender() const;
    unsigned getID() const;
private:
    unsigned ID;
    QString hisFirstName, hisLastName;
    Gender hisGender;
    QList<double> hisGrades;
    double hisFinalGrade;
};

#endif // STUDENT_H
