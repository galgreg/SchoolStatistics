#ifndef GRADESMOCK_H
#define GRADESMOCK_H

#include "igrades.h"
#include <QList>

class GradesMock : public IGrades
{
public:
    explicit GradesMock(
        const std::initializer_list<double> &grades = {0.0, 0.0, 0.0}) noexcept;
    GradesMock(const IGrades &originalGrades);
    void add(double grade) noexcept override;
    void remove(size_t whichGrade) noexcept override;
    void edit(size_t whichGrade, double newValue) noexcept override;
    size_t count() const noexcept override;
    double getGrade(size_t whichGrade) const noexcept override;
    size_t maxAllowedCount() const noexcept override;
private:
    QList<double> mGrades;
};

#endif // GRADESMOCK_H
