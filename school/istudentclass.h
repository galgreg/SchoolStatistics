#ifndef ISTUDENTCLASS_H
#define ISTUDENTCLASS_H

#include "istudent.h"
#include <cstddef>
#include <memory>

class IStudentClass {
public:
    virtual ~IStudentClass() = default;
    bool operator==(const IStudentClass &classToCompare) const noexcept ;
    virtual size_t maxAllowedCount() const = 0;
    virtual size_t count() const = 0;
    virtual void addStudent(std::unique_ptr<IStudent> newStudent) = 0;
    virtual void removeStudent(size_t whichStudent) = 0;
    virtual const IStudent& getStudent(size_t whichStudent) const = 0;
    virtual void editStudent(
        size_t whichStudent,
        std::unique_ptr<IStudent> newValue) = 0;
    virtual void removeAll() = 0;
};

#endif // ISTUDENTCLASS_H
