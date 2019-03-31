#ifndef GRADES_H
#define GRADES_H

#include <vector>

class Grades
{
public:
    explicit Grades(size_t count = 3);

    void add(double grade);
    size_t count() const;
    double getGrade(unsigned whichGrade) const;
    size_t maxAllowedCount() const;
    void remove(size_t whichGrade);
    void edit(size_t whichGrade, double newValue);
private:
    std::vector<double> grades;
    const size_t maxCount;
};

#endif // GRADES_H
