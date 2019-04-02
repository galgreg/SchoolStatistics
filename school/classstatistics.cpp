#include "classstatistics.h"

double ClassStatistics::getClassAverage(IStudentClass *studentClass) {
    const size_t classCount = studentClass->count();
    double gradesSum = 0.0;

    for (size_t i = 0; i != classCount; ++i) {
        gradesSum += getStudentAverage(studentClass, i);
    }
    return static_cast<double>(gradesSum / classCount);
}

double ClassStatistics::getStudentAverage(
        IStudentClass *studentClass,
        size_t whichStudent) {
    auto student = studentClass->getStudent(whichStudent);
    auto grades = student->getGrades();
    double gradesSum = 0.0;
    const size_t gradesCount = grades->count();

    for (unsigned i = 0; i != gradesCount; ++i) {
        gradesSum += grades->getGrade(i);
    }
    return static_cast<double>(gradesSum / gradesCount);
}
