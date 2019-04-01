#ifndef STUDENTCLASS_H
#define STUDENTCLASS_H

#include "istudent.h"
#include <cstddef>
#include <memory>
#include <vector>

class StudentClass
{
public:
    StudentClass(size_t maximumCount);

    size_t maxAllowedCount() const;
    size_t count() const;

private:
    const size_t maxCount;
    std::vector<std::unique_ptr<IStudent>> students;
};

#endif // STUDENTCLASS_H
