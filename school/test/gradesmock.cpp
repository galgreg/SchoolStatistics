#include "gradesmock.h"
#include <stdexcept>

GradesMock::GradesMock(const std::initializer_list<double> &grades) :
        mGrades(grades) {
    if (mGrades.size() != 3) {
        throw std::length_error("GradesMock constructor error: mGrades.size() "
                "must be equal to 3!");
    }
}

void GradesMock::add(double) {
}

void GradesMock::remove(size_t) {
}

void GradesMock::edit(size_t, double) {
}

size_t GradesMock::count() const {
    return 3;
}

double GradesMock::getGrade(unsigned whichGrade) const {
    return mGrades.at(whichGrade);
}

size_t GradesMock::maxAllowedCount() const {
    return 3;
}




