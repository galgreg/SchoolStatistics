#include "grades.h"
#include <stdexcept>

Grades::Grades(size_t count) : maxCount(count) {

}

void Grades::add(double grade) {
    if (count() == maxAllowedCount()) {
        throw std::out_of_range("Cannot add new grade!");
    }
    grades.push_back(grade);
}

size_t Grades::maxAllowedCount() const {
    return maxCount;
}

void Grades::remove(size_t whichGrade) {
    if(whichGrade >= count()) {
        std::string index = std::to_string(whichGrade);
        throw std::out_of_range("Cannot remove grade, no such index: " + index);
    }
    long index = static_cast<long>(whichGrade);
    grades.erase(grades.cbegin() + index);
}

void Grades::edit(size_t whichGrade, double newValue) {
    grades.at(whichGrade) = newValue;
}

size_t Grades::count() const {
    return grades.size();
}

double Grades::getGrade(unsigned whichGrade) const {
    return grades.at(whichGrade);
}
