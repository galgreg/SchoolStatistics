#include "gradesmock.h"
#include <stdexcept>

GradesMock::GradesMock(const std::initializer_list<double> &grades) :
        mGrades(grades) {

}

GradesMock::GradesMock(const IGrades &originalGrades) {
    for (unsigned i = 0; i < originalGrades.count(); ++i) {
        mGrades.push_back(originalGrades.getGrade(i));
    }
}

void GradesMock::add(double) {
}

void GradesMock::remove(size_t) {
}

void GradesMock::edit(size_t, double) {
}

size_t GradesMock::count() const {
    return static_cast<size_t>(mGrades.size());
}

double GradesMock::getGrade(size_t whichGrade) const {
    return mGrades.at(static_cast<int>(whichGrade));
}

size_t GradesMock::maxAllowedCount() const {
    return static_cast<size_t>(mGrades.size());
}




