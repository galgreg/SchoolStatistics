#ifndef CLASSSTATISTICS_H
#define CLASSSTATISTICS_H

#include "istudentclass.h"

class ClassStatistics
{
public:
    double getClassAverage(IStudentClass *studentClass);
    double getStudentAverage(IStudentClass *studentClass, size_t whichStudent);
};

#endif // CLASSSTATISTICS_H
