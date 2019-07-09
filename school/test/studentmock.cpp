#include "studentmock.h"
#include "gradesmock.h"

StudentMock::StudentMock() :
        mPersonalData(new PersonalDataMock),
        mGrades(new GradesMock({3.5, 4.0, 4.5})) {
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
