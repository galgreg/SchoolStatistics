#include "grades.h"
#include <stdexcept>

Grades::Grades(const IGrades& originalGrades) :
        mMaxCount(originalGrades.maxAllowedCount()) {
    for(unsigned i = 0; i < originalGrades.count(); ++i) {
        mGrades.push_back(originalGrades.getGrade(i));
    }
}

Grades::Grades(size_t maximumCount, const std::initializer_list<double> &grades) :
        mGrades(grades), mMaxCount(maximumCount) {
}

void Grades::add(double grade) {
    if (count() >= maxAllowedCount()) {
        throw std::out_of_range("Cannot add new grade!");
    }
    mGrades.push_back(grade);
}

size_t Grades::maxAllowedCount() const {
    return mMaxCount;
}

void Grades::remove(size_t whichGrade) {
    if(whichGrade >= count()) {
        std::string index = std::to_string(whichGrade);
        throw std::out_of_range("Cannot remove grade, no such index: " + index);
    }
    long index = static_cast<long>(whichGrade);
    mGrades.erase(mGrades.cbegin() + index);
}

void Grades::edit(size_t whichGrade, double newValue) {
    mGrades.at(whichGrade) = newValue;
}

size_t Grades::count() const {
    return mGrades.size();
}

double Grades::getGrade(unsigned whichGrade) const {
    return mGrades.at(whichGrade);
}
