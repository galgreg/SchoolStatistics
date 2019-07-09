#ifndef ISTUDENTCLASS_H
#define ISTUDENTCLASS_H

#include "istudent.h"
#include <cstddef>

class IStudentClass
{
public:
    virtual ~IStudentClass() = default;
    virtual size_t maxAllowedCount() const = 0;
    virtual size_t count() const = 0;
    virtual void addStudent(IStudent *newStudent) = 0;
    virtual void removeStudent(size_t whichStudent) = 0;
    virtual const IStudent& getStudent(size_t whichStudent) const = 0;
    virtual void editStudent(size_t whichStudent, IStudent *newValue) = 0;
    virtual void removeAll() = 0;
};

#endif // ISTUDENTCLASS_H
