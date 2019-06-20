#ifndef STUDENTFACTORY_H
#define STUDENTFACTORY_H
#include "gender.h"
#include "istudent.h"
#include <string>
#include <vector>

class StudentFactory
{
public:
    static IStudent* create(
        unsigned ID,
        const std::string &firstName,
        const std::string &lastName,
        Gender gender,
        const std::vector<double> &grades);
};

#endif // STUDENTFACTORY_H
