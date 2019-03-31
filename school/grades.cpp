#include "grades.h"

void Grades::add(double grade) {
    grades.push_back(grade);
}

size_t Grades::count() {
    return grades.size();
}

double Grades::getGrade(unsigned whichGrade) {
    return grades.at(whichGrade);
}
