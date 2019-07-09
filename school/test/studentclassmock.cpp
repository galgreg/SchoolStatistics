#include "studentclassmock.h"

StudentClassMock::StudentClassMock() : mStudent(new StudentMock) {

}

size_t StudentClassMock::maxAllowedCount() const {
    return 100;
}

size_t StudentClassMock::count() const {
    return 10;
}

void StudentClassMock::addStudent(IStudent *) {
}

void StudentClassMock::removeStudent(size_t) {
}

const IStudent& StudentClassMock::getStudent(size_t) const {
    return *mStudent;
}

void StudentClassMock::editStudent(size_t, IStudent *) {
}

void StudentClassMock::removeAll() {
}


