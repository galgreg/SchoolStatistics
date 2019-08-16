#include "gradesmock.h"
#include <stdexcept>

GradesMock::GradesMock(const std::initializer_list<double> &grades) noexcept :
        mGrades(grades) {

}

GradesMock::GradesMock(const IGrades &originalGrades) {
    for (unsigned i = 0; i < originalGrades.count(); ++i) {
        mGrades.push_back(originalGrades.getGrade(i));
    }
}

void GradesMock::add(double) noexcept {
}

void GradesMock::remove(size_t) noexcept {
}

void GradesMock::edit(size_t, double) noexcept {
}

size_t GradesMock::count() const noexcept {
    return static_cast<size_t>(mGrades.size());
}

double GradesMock::getGrade(size_t whichGrade) const noexcept {
    return mGrades.at(static_cast<int>(whichGrade));
}

size_t GradesMock::maxAllowedCount() const noexcept {
    return static_cast<size_t>(mGrades.size());
}




