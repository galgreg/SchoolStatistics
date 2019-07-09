#ifndef STUDENT_H
#define STUDENT_H
#include "istudent.h"
#include "igrades.h"
#include "grades.h"
#include "ipersonaldata.h"
#include "personaldata.h"
#include <memory>

class Student : public IStudent
{
public:
    explicit Student(
        unsigned ID,
        const IPersonalData& personalData = PersonalData("", "", UNKNOWN),
        const IGrades& grades = Grades(3));

    unsigned getID() const override;
    const IPersonalData& getPersonalData() const override;
    const IGrades& getGrades() const override;
    void setPersonalData(const IPersonalData& newData) override;
    void setGrades(const IGrades& newGrades) override;

private:
    unsigned mID;
    std::unique_ptr<IPersonalData> mPersonalData;
    std::unique_ptr<IGrades> mGrades;
};

#endif // STUDENT_H
