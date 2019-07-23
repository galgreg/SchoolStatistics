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
    mGrades.removeAt(static_cast<int>(whichGrade));
}

void Grades::edit(size_t whichGrade, double newValue) {
    int listIndex = static_cast<int>(whichGrade);
    if (listIndex >= mGrades.size()) {
        throw std::out_of_range(
                "Grades::edit() error: whichGrade is out of range!");
    }

    mGrades.replace(listIndex, newValue);
}

size_t Grades::count() const {
    size_t gradesCount = static_cast<size_t>(mGrades.size());
    return gradesCount;
}

double Grades::getGrade(size_t whichGrade) const {
    return mGrades.at(static_cast<int>(whichGrade));
}
