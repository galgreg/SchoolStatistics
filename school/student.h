#ifndef STUDENT_H
#define STUDENT_H
#include "gender.h"
#include <QList>
#include <QString>

class Student
{
public:
    using GradesRange = std::pair<QList<double>::const_iterator, QList<double>::const_iterator>;

    Student();
    Student(QString firstName, QString lastName, Gender gender);

    unsigned getID() const;
    QString getFullName() const;
    Gender getGender() const;
    GradesRange getGrades() const;
    double getGradesAverage() const;

    void addGrade(double grade);
    void editGrade(int whichGrade, double newGrade);
    void removeGrade(int whichGrade);
private:
    unsigned ID;
    QString hisFirstName, hisLastName;
    Gender hisGender;
    QList<double> hisGrades;
};

Q_DECLARE_METATYPE(Student)

#endif // STUDENT_H
