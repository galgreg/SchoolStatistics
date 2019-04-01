#ifndef STUDENTCLASSMOCK_H
#define STUDENTCLASSMOCK_H

#include "istudentclass.h"

class StudentClassMock : public IStudentClass
{
public:
    size_t maxAllowedCount() const override;
    size_t count() const override;
    void addStudent(IStudent *newStudent) override;
    void removeStudent(size_t whichStudent) override;
    IStudent *getStudent(size_t whichStudent) override;
    void editStudent(size_t whichStudent, IStudent *newValue) override;
    void removeAll() override;
};

#endif // STUDENTCLASSMOCK_H
