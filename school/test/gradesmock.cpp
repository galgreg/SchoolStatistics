#include "gradesmock.h"

void GradesMock::add(double) {
}

void GradesMock::remove(size_t) {
}

void GradesMock::edit(size_t, double) {
}

size_t GradesMock::count() const {
    return 0;
}

double GradesMock::getGrade(unsigned) const {
    return 4.0;
}

size_t GradesMock::maxAllowedCount() const {
    return 0;
}




