#ifndef STUDENT_H
#define STUDENT_H
#include "istudent.h"
#include "igrades.h"
#include "ipersonaldata.h"

class Student : public IStudent
{
public:
    Student(
        unsigned ID,
        std::unique_ptr<IPersonalData> personalData,
        std::unique_ptr<IGrades> grades);

    unsigned getID() const override;
    const IPersonalData& getPersonalData() const override;
    const IGrades& getGrades() const override;
    void setPersonalData(std::unique_ptr<IPersonalData> newData) override;
    void setGrades(std::unique_ptr<IGrades> newGrades) override;

private:
    unsigned mID;
    std::unique_ptr<IPersonalData> mPersonalData;
    std::unique_ptr<IGrades> mGrades;
};

#endif // STUDENT_H
