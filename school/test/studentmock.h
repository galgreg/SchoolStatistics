#ifndef STUDENTMOCK_H
#define STUDENTMOCK_H

#include "istudent.h"

class StudentMock : public IStudent
{
public:
    unsigned getID() const override;
    IPersonalData *getPersonalData() const override;
    IGrades *getGrades() const override;
    void setPersonalData(IPersonalData *newData) override;
    void setGrades(IGrades *newGrades) override;
};

#endif // STUDENTMOCK_H
