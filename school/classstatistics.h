#ifndef CLASSSTATISTICS_H
#define CLASSSTATISTICS_H

#include "istudentclass.h"

class ClassStatistics
{
public:
    static double getClassAverage(
        const IStudentClass& studentClass);
    static double getStudentAverage(
        const IStudentClass& studentClass,
        size_t whichStudent);
};

#endif // CLASSSTATISTICS_H
