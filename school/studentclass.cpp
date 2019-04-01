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
    students.push_back(std::move(tempPtr));
}
