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
    std::unique_ptr<IStudent> tempPtr(newStudent);

    if(count() >= maxAllowedCount()) {
        throw std::out_of_range("StudentClass overflow exception");
    }

    students.push_back(std::move(tempPtr));
}

void StudentClass::removeStudent(size_t whichStudent) {
    long position = static_cast<long>(whichStudent);
    students.erase(students.cbegin() + position);
}
