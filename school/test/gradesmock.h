#ifndef GRADESMOCK_H
#define GRADESMOCK_H

#include "igrades.h"

class GradesMock : public IGrades
{
public:
    void add(double grade) override;
    void remove(size_t whichGrade) override;
    void edit(size_t whichGrade, double newValue) override;
    size_t count() const override;
    double getGrade(unsigned whichGrade) const override;
    size_t maxAllowedCount() const override;
};

#endif // GRADESMOCK_H
