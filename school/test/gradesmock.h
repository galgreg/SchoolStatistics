#ifndef GRADESMOCK_H
#define GRADESMOCK_H

#include "igrades.h"
#include <vector>

class GradesMock : public IGrades
{
public:
    explicit GradesMock(
        const std::initializer_list<double> &grades = {0.0, 0.0, 0.0});
    GradesMock(const IGrades &originalGrades);
    void add(double grade) override;
    void remove(size_t whichGrade) override;
    void edit(size_t whichGrade, double newValue) override;
    size_t count() const override;
    double getGrade(unsigned whichGrade) const override;
    size_t maxAllowedCount() const override;
private:
    std::vector<double> mGrades;
};

#endif // GRADESMOCK_H
