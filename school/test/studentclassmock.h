#ifndef STUDENTCLASSMOCK_H
#define STUDENTCLASSMOCK_H

#include "istudentclass.h"
#include "studentmock.h"
#include <vector>

class StudentClassMock : public IStudentClass
{
public:
    StudentClassMock(const std::initializer_list<double> &studentGrades = {});
    size_t maxAllowedCount() const override;
    size_t count() const override;
    void addStudent(IStudent *newStudent) override;
    void removeStudent(size_t whichStudent) override;
    const IStudent& getStudent(size_t whichStudent) const override;
    void editStudent(size_t whichStudent, IStudent *newValue) override;
    void removeAll() override;
private:
    std::vector<StudentMock> mStudents;
};

#endif // STUDENTCLASSMOCK_H
