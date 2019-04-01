#ifndef STUDENT_H
#define STUDENT_H

#include "igrades.h"
#include "ipersonaldata.h"
#include <memory>

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
    void setPersonalData(IPersonalData *newData);
    void setGrades(IGrades *newGrades);

private:
    unsigned mID;
    std::unique_ptr<IPersonalData> mPersonalData;
    std::unique_ptr<IGrades> mGrades;
};

#endif // STUDENT_H
