#include "grades.h"
#include <stdexcept>

Grades::Grades(const IGrades& originalGrades) :
        mMaxCount(originalGrades.maxAllowedCount()) {
    for(size_t i = 0; i < originalGrades.count(); ++i) {
        mGrades.push_back(originalGrades.getGrade(i));
    }
}

Grades::Grades(size_t maximumCount, const QList<double> &grades) :
        mGrades(grades), mMaxCount(maximumCount) {
}

void Grades::add(double grade) {
    if (count() >= maxAllowedCount()) {
        throw std::out_of_range("Grades::add() error: Cannot add new grade!");
    }
    mGrades.push_back(grade);
}

void Grades::remove(size_t whichGrade) {
    if(whichGrade >= count()) {
        std::string index = std::to_string(whichGrade);
        throw std::out_of_range("Grades::remove() error: Cannot remove grade, "
                                "no such index: " + index);
    }
    mGrades.removeAt(static_cast<int>(whichGrade));
}

void Grades::edit(size_t whichGrade, double newValue) {
    int indexOfEditedGrade = static_cast<int>(whichGrade);
    if (indexOfEditedGrade >= mGrades.size()) {
        throw std::out_of_range(
                "Grades::edit() error: whichGrade is out of range!");
    }
    mGrades.replace(indexOfEditedGrade, newValue);
}

size_t Grades::count() const {
    size_t gradesCount = static_cast<size_t>(mGrades.size());
    return gradesCount;
}

double Grades::getGrade(size_t whichGrade) const {
    return mGrades.at(static_cast<int>(whichGrade));
}

size_t Grades::maxAllowedCount() const {
    return mMaxCount;
}
