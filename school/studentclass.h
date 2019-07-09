#ifndef STUDENTCLASS_H
#define STUDENTCLASS_H

#include "istudent.h"
#include "istudentclass.h"
#include <cstddef>
#include <memory>
#include <vector>

class StudentClass : public IStudentClass
{
public:
    StudentClass(size_t maximumCount = 20);

    size_t maxAllowedCount() const override;
    size_t count() const override;
    void addStudent(IStudent *newStudent) override;
    void removeStudent(size_t whichStudent) override;
    const IStudent& getStudent(size_t whichStudent) const override;
    void editStudent(size_t whichStudent, IStudent *newValue) override;
    void removeAll() override;

private:
    const size_t maxCount;
    std::vector<std::unique_ptr<IStudent>> students;
};

#endif // STUDENTCLASS_H
