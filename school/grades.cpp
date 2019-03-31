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

size_t Grades::count() const {
    return grades.size();
}

double Grades::getGrade(unsigned whichGrade) const {
    return grades.at(whichGrade);
}
