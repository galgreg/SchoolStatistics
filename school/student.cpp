#include "student.h"

Student::Student(unsigned ID, IPersonalData *personalData, IGrades *grades) :
    mID(ID), mPersonalData(personalData), mGrades(grades) {
}

unsigned Student::getID() const {
    return mID;
}

IPersonalData *Student::getPersonalData() const {
    return mPersonalData.get();
}

IGrades *Student::getGrades() const {
    return mGrades.get();
}

void Student::setPersonalData(IPersonalData *newData) {
    mPersonalData.reset(newData);
}

void Student::setGrades(IGrades *newGrades) {
    mGrades.reset(newGrades);
}
