#include "gradesmock.h"

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
    return grades.at(whichGrade);
}

size_t GradesMock::maxAllowedCount() const {
    return 3;
}




