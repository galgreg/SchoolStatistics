#ifndef STUDENTMOCK_H
#define STUDENTMOCK_H
#include "istudent.h"
#include "personaldatamock.h"
#include "gradesmock.h"
#include <memory>

class StudentMock : public IStudent
{
public:
    explicit StudentMock(
        const std::initializer_list<double> &grades = {3.5, 4.0, 4.5});
    StudentMock(const IStudent &originalStudentObject);
    unsigned getID() const override;
    const IPersonalData& getPersonalData() const override;
    const IGrades& getGrades() const override;
    void setPersonalData(std::unique_ptr<IPersonalData> newData) override;
    void setGrades(std::unique_ptr<IGrades> newGrades) override;
private:
    std::unique_ptr<PersonalDataMock> mPersonalData;
    std::unique_ptr<GradesMock> mGrades;
};

#endif // STUDENTMOCK_H
