#include "studentmock.h"
#include "gradesmock.h"

StudentMock::StudentMock(const std::initializer_list<double> &grades) :
        mPersonalData(new PersonalDataMock),
        mGrades(new GradesMock(grades)) {
}

StudentMock::StudentMock(const IStudent &originalStudentObject) :
    mPersonalData(new PersonalDataMock(originalStudentObject.getPersonalData())),
    mGrades(new GradesMock(originalStudentObject.getGrades())) {

}

unsigned StudentMock::getID() const noexcept {
    return 0;
}

const IPersonalData& StudentMock::getPersonalData() const noexcept {
    return *mPersonalData;
}

const IGrades& StudentMock::getGrades() const noexcept {
    return *mGrades;
}

void StudentMock::setPersonalData(std::unique_ptr<IPersonalData>) noexcept {
}

void StudentMock::setGrades(std::unique_ptr<IGrades>) noexcept {

}
