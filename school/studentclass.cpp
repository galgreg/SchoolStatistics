#include "studentclass.h"

StudentClass::StudentClass(size_t maximumCount) : mMaxCount(maximumCount) {

}

size_t StudentClass::maxAllowedCount() const {
    return mMaxCount;
}

size_t StudentClass::count() const {
    return mStudents.size();
}

void StudentClass::addStudent(std::unique_ptr<IStudent> newStudent) {
    if (newStudent == nullptr) {
        throw std::bad_alloc();
    } else if(count() >= maxAllowedCount()) {
        throw std::out_of_range(
                "StudentClass::addStudent() error: StudentClass overflow");
    }
    mStudents.push_back(std::move(newStudent));
}

void StudentClass::removeStudent(size_t whichStudent) {
    if (whichStudent >= count()) {
        throw std::out_of_range(
                "StudentClass::removeStudent() error: "
                "whichStudent is out of range!");
    }
    long position = static_cast<long>(whichStudent);
    mStudents.erase(mStudents.cbegin() + position);
}

const IStudent& StudentClass::getStudent(size_t whichStudent) const {
    return *mStudents.at(whichStudent);
}

void StudentClass::editStudent(
        size_t whichStudent,
        std::unique_ptr<IStudent> newValue) {
    if (newValue == nullptr) {
        throw std::bad_alloc();
    }
    mStudents.at(whichStudent).swap(newValue);
}

void StudentClass::removeAll() {
    mStudents.clear();
}
