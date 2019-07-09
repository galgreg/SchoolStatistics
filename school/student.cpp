#include "student.h"

Student::Student(
        unsigned ID,
        const IPersonalData& personalData,
        const IGrades& grades) :
                mID(ID),
                mPersonalData(new PersonalData(personalData)),
                mGrades(new Grades(grades)) {
}

unsigned Student::getID() const {
    return mID;
}

const IPersonalData& Student::getPersonalData() const {
    return *mPersonalData;
}

const IGrades& Student::getGrades() const {
    return *mGrades;
}

void Student::setPersonalData(const IPersonalData& newData) {
    mPersonalData.reset(new PersonalData(newData));
}

void Student::setGrades(const IGrades& newGrades) {
    mGrades.reset(new Grades(newGrades));
}
