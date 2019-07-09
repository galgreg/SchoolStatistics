#ifndef CLASSSTATISTICS_H
#define CLASSSTATISTICS_H

#include "istudentclass.h"

class ClassStatistics
{
public:
    double getClassAverage(const IStudentClass& studentClass);
    double getStudentAverage(const IStudentClass& studentClass, size_t whichStudent);
};

#endif // CLASSSTATISTICS_H
