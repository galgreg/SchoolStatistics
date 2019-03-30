#include "studentmock.h"

unsigned StudentMock::getID() const {
    return 1;
}

QString StudentMock::getFullName() const {
    return "Jan Kowalski";
}

Gender StudentMock::getGender() const {
    return MALE;
}

StudentInterface::GradesRange StudentMock::getGrades() const {
    return std::make_pair(nullptr, nullptr);
}

double StudentMock::getGradesAverage() const {
    return 5.0;
}

void StudentMock::addGrade(double /*grade*/) {

}

void StudentMock::editGrade(int /*whichGrade*/, double /*newGrade*/) {

}

void StudentMock::removeGrade(int /*whichGrade*/) {

}


