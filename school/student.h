#ifndef STUDENT_H
#define STUDENT_H
#include "istudent.h"
#include "igrades.h"
#include "ipersonaldata.h"
#include <memory>

class Student : public IStudent
{
public:
    explicit Student(
        unsigned ID,
        IPersonalData *personalData = nullptr,
        IGrades *grades = nullptr);

    unsigned getID() const override;
    IPersonalData *getPersonalData() const override;
    IGrades *getGrades() const override;
    void setPersonalData(IPersonalData *newData) override;
    void setGrades(IGrades *newGrades) override;

private:
    unsigned mID;
    std::unique_ptr<IPersonalData> mPersonalData;
    std::unique_ptr<IGrades> mGrades;
};

#endif // STUDENT_H
