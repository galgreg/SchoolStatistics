#ifndef STUDENTFACTORY_H
#define STUDENTFACTORY_H
#include "gender.h"
#include "student.h"
#include <string>
#include <vector>

class StudentFactory
{
public:
    static Student* create(
        unsigned ID,
        const std::string &firstName,
        const std::string &lastName,
        Gender gender,
        const std::vector<double> &grades);
    static Student* copy(const IStudent &studentToCopy);
};

#endif // STUDENTFACTORY_H
