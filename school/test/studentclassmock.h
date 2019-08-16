#ifndef STUDENTCLASSMOCK_H
#define STUDENTCLASSMOCK_H

#include "istudentclass.h"
#include "studentmock.h"
#include <vector>

class StudentClassMock : public IStudentClass
{
public:
    StudentClassMock(const std::initializer_list<double> &studentGrades = {});
    size_t maxAllowedCount() const noexcept override;
    size_t count() const noexcept override;
    void addStudent(std::unique_ptr<IStudent> newStudent) noexcept override;
    void removeStudent(size_t whichStudent) noexcept override;
    const IStudent& getStudent(size_t whichStudent) const noexcept override;
    void editStudent(
        size_t whichStudent,
        std::unique_ptr<IStudent> newValue) noexcept override;
    void removeAll() noexcept override;
private:
    std::vector<StudentMock> mStudents;
};

#endif // STUDENTCLASSMOCK_H
