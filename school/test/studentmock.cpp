#include "studentmock.h"
#include "gradesmock.h"

StudentMock::StudentMock(const std::initializer_list<double>& grades) :
        mPersonalData(new PersonalDataMock),
        mGrades(new GradesMock(grades)) {
}

unsigned StudentMock::getID() const {
    return 0;
}

const IPersonalData& StudentMock::getPersonalData() const {
    return *mPersonalData;
}

const IGrades& StudentMock::getGrades() const {
    return *mGrades;
}

void StudentMock::setPersonalData(const IPersonalData &) {
}

void StudentMock::setGrades(const IGrades&) {

}
