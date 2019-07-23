#include "classstatistics.h"

double ClassStatistics::getClassAverage(const IStudentClass& studentClass) {
    double classAverage = 0.0;
    const size_t classCount = studentClass.count();

    if (classCount > 0) {
        double studentAveragesSum = 0.0;
        for (size_t i = 0; i != classCount; ++i) {
            studentAveragesSum += getStudentAverage(studentClass, i);
        }
        classAverage = studentAveragesSum / classCount;
    }
    return classAverage;
}

double ClassStatistics::getStudentAverage(
        const IStudentClass& studentClass,
        size_t whichStudent) {    
    const IStudent& student = studentClass.getStudent(whichStudent);
    const IGrades& grades = student.getGrades();

    double studentAverage = 0.0;
    const size_t gradesCount = grades.count();

    if (gradesCount > 0) {
        double gradesSum = 0.0;
        for (unsigned i = 0; i != gradesCount; ++i) {
            gradesSum += grades.getGrade(i);
        }
        studentAverage = gradesSum / gradesCount;
    }    
    return studentAverage;
}
