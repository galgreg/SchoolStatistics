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
    void addStudent(IStudent *newStudent);
    void removeStudent(size_t whichStudent);
    IStudent *getStudent(size_t whichStudent);
    void editStudent(size_t whichStudent, IStudent *newValue);
    void removeAll();

private:
    const size_t maxCount;
    std::vector<std::unique_ptr<IStudent>> students;
};

#endif // STUDENTCLASS_H
