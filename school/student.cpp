#include "student.h"

Student::Student(
        unsigned ID,
        std::unique_ptr<IPersonalData> personalData,
        std::unique_ptr<IGrades> grades) :
                mID(ID),
                mPersonalData(std::move(personalData)),
                mGrades(std::move(grades)) {
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

void Student::setPersonalData(std::unique_ptr<IPersonalData> newData) {
    mPersonalData.swap(newData);
}

void Student::setGrades(std::unique_ptr<IGrades> newGrades) {
    mGrades.swap(newGrades);
}
