#ifndef STUDENT_H
#define STUDENT_H

#include "igrades.h"
#include "ipersonaldata.h"

class Student
{
public:
    explicit Student(
        unsigned ID,
        IPersonalData *personalData = nullptr,
        IGrades *grades = nullptr);

    unsigned getID() const;
    IPersonalData *getPersonalData() const;
    IGrades *getGrades() const;

private:
    unsigned mID;
    IPersonalData *mPersonalData;
    IGrades *mGrades;
};

#endif // STUDENT_H
