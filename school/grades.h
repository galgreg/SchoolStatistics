#ifndef GRADES_H
#define GRADES_H

#include "igrades.h"
#include <vector>

class Grades : public IGrades
{
public:
    explicit Grades(size_t maximumCount = 3);

    void add(double grade) override;
    void remove(size_t whichGrade) override;
    void edit(size_t whichGrade, double newValue) override;
    size_t count() const override;
    double getGrade(unsigned whichGrade) const override;
    size_t maxAllowedCount() const override;
private:
    std::vector<double> grades;
    const size_t maxCount;
};

#endif // GRADES_H
