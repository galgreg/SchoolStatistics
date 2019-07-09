#ifndef STUDENTMOCK_H
#define STUDENTMOCK_H
#include "istudent.h"
#include "personaldatamock.h"
#include "gradesmock.h"
#include <memory>

class StudentMock : public IStudent
{
public:
    StudentMock();
    unsigned getID() const override;
    const IPersonalData& getPersonalData() const override;
    const IGrades& getGrades() const override;
    void setPersonalData(const IPersonalData& newData) override;
    void setGrades(const IGrades& newGrades) override;
private:
    std::unique_ptr<PersonalDataMock> mPersonalData;
    std::unique_ptr<GradesMock> mGrades;
};

#endif // STUDENTMOCK_H
