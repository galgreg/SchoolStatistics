#ifndef STUDENT_H
#define STUDENT_H
#include "studentinterface.h"
#include "gender.h"
#include <QList>
#include <QString>

class Student : public StudentInterface
{
public:
    Student();
    Student(QString firstName, QString lastName, Gender gender);

    unsigned getID() const override;
    QString getFullName() const override;
    Gender getGender() const  override;
    GradesRange getGrades() const  override;
    double getGradesAverage() const override;

    void addGrade(double grade) override;
    void editGrade(int whichGrade, double newGrade) override;
    void removeGrade(int whichGrade) override;
private:
    unsigned ID;
    QString hisFirstName, hisLastName;
    Gender hisGender;
    QList<double> hisGrades;
};

Q_DECLARE_METATYPE(Student)

#endif // STUDENT_H
