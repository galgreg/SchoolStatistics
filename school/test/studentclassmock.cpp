#include "studentclassmock.h"

StudentClassMock::StudentClassMock(
        const std::initializer_list<double> &studentGrades) {
    mStudents.push_back(StudentMock(studentGrades));
}

size_t StudentClassMock::maxAllowedCount() const {
    return 100;
}

size_t StudentClassMock::count() const {
    return mStudents.size();
}

void StudentClassMock::addStudent(IStudent *) {
}

void StudentClassMock::removeStudent(size_t) {
}

const IStudent& StudentClassMock::getStudent(size_t) const {
    return mStudents.at(0);
}

void StudentClassMock::editStudent(size_t, IStudent *) {
}

void StudentClassMock::removeAll() {
    mStudents.clear();
}


