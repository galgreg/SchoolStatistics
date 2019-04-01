#include "studentclass.h"

StudentClass::StudentClass(size_t maximumCount) : maxCount(maximumCount) {

}

size_t StudentClass::maxAllowedCount() const {
    return maxCount;
}

size_t StudentClass::count() const {
    return students.size();
}

void StudentClass::addStudent(IStudent *newStudent) {
    if (newStudent == nullptr) {
        throw std::bad_alloc();
    }

    std::unique_ptr<IStudent> tempPtr(newStudent);

    if(count() >= maxAllowedCount()) {
        throw std::out_of_range(
                "StudentClass::addStudent() : StudentClass overflow");
    }

    students.push_back(std::move(tempPtr));
}

void StudentClass::removeStudent(size_t whichStudent) {
    if (whichStudent >= count()) {
        throw std::out_of_range(
                "StudentClass::removeStudent() : No such element");
    }
    long position = static_cast<long>(whichStudent);
    students.erase(students.cbegin() + position);
}

IStudent *StudentClass::getStudent(size_t whichStudent) {
    return students.at(whichStudent).get();
}

void StudentClass::editStudent(size_t whichStudent, IStudent *newValue) {
    students.at(whichStudent).reset(newValue);
}

void StudentClass::removeAll() {
    students.clear();
}
