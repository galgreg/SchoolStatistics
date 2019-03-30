#ifndef STUDENTMOCK_H
#define STUDENTMOCK_H

#include "studentinterface.h"

class StudentMock : public StudentInterface
{
public:
    unsigned getID() const override;
    QString getFullName() const override;
    Gender getGender() const  override;
    GradesRange getGrades() const  override;
    double getGradesAverage() const override;

    void addGrade(double grade) override;
    void editGrade(int whichGrade, double newGrade) override;
    void removeGrade(int whichGrade) override;
};

#endif // STUDENTMOCK_H
