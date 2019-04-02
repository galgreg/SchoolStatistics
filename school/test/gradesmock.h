#ifndef GRADESMOCK_H
#define GRADESMOCK_H

#include "igrades.h"
#include <array>

class GradesMock : public IGrades
{
public:
    void add(double grade) override;
    void remove(size_t whichGrade) override;
    void edit(size_t whichGrade, double newValue) override;
    size_t count() const override;
    double getGrade(unsigned whichGrade) const override;
    size_t maxAllowedCount() const override;
private:
    std::array<double, 3> grades = {3.5, 4.0, 4.5};
};

#endif // GRADESMOCK_H
