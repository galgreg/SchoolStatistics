#ifndef STUDENTCLASSMOCK_H
#define STUDENTCLASSMOCK_H

#include "istudentclass.h"
#include "studentmock.h"
#include <memory>

class StudentClassMock : public IStudentClass
{
public:
    StudentClassMock();
    size_t maxAllowedCount() const override;
    size_t count() const override;
    void addStudent(IStudent *newStudent) override;
    void removeStudent(size_t whichStudent) override;
    const IStudent& getStudent(size_t whichStudent) const override;
    void editStudent(size_t whichStudent, IStudent *newValue) override;
    void removeAll() override;
private:
    std::unique_ptr<StudentMock> mStudent;
};

#endif // STUDENTCLASSMOCK_H
