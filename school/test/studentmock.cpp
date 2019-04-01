#include "studentmock.h"

unsigned StudentMock::getID() const {
    return 0;
}

IPersonalData *StudentMock::getPersonalData() const {
    return nullptr;
}

IGrades *StudentMock::getGrades() const {
    return nullptr;
}

void StudentMock::setPersonalData(IPersonalData *) {
}

void StudentMock::setGrades(IGrades *) {

}
