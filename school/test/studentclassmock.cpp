#include "studentclassmock.h"

StudentClassMock::StudentClassMock(
        const std::initializer_list<double> &studentGrades) {
    mStudents.push_back(StudentMock(studentGrades));
}

size_t StudentClassMock::maxAllowedCount() const noexcept {
    return 100;
}

size_t StudentClassMock::count() const noexcept {
    return mStudents.size();
}

void StudentClassMock::addStudent(std::unique_ptr<IStudent>) noexcept {
}

void StudentClassMock::removeStudent(size_t) noexcept {
}

const IStudent& StudentClassMock::getStudent(size_t) const noexcept {
    return mStudents.at(0);
}

void StudentClassMock::editStudent(size_t, std::unique_ptr<IStudent>) noexcept {
}

void StudentClassMock::removeAll() noexcept {
    mStudents.clear();
}


