#ifndef GRADES_H
#define GRADES_H

#include <vector>

class Grades
{
public:
    void add(double grade);
    size_t count();
    double getGrade(unsigned whichGrade);
private:
    std::vector<double> grades;
};

#endif // GRADES_H
