#ifndef GRADES_H
#define GRADES_H

#include <vector>

class Grades
{
public:
    explicit Grades(size_t maximumCount = 3);

    void add(double grade);
    void remove(size_t whichGrade);
    void edit(size_t whichGrade, double newValue);
    size_t count() const;
    double getGrade(unsigned whichGrade) const;
    size_t maxAllowedCount() const;
private:
    std::vector<double> grades;
    const size_t maxCount;
};

#endif // GRADES_H
