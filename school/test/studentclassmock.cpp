#include "studentclassmock.h"
#include "studentmock.h"

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

IStudent *StudentClassMock::getStudent(size_t) const {
    return new StudentMock;
}

void StudentClassMock::editStudent(size_t, IStudent *) {
}

void StudentClassMock::removeAll() {
}


