#ifndef IGRADES_H
#define IGRADES_H

#include <cstddef>

class IGrades {
public:
    virtual ~IGrades() = default;
    bool operator==(const IGrades &gradesToCompare) const;

    virtual void add(double grade) = 0;
    virtual void remove(size_t whichGrade) = 0;
    virtual void edit(size_t whichGrade, double newValue) = 0;
    virtual size_t count() const = 0;
    virtual double getGrade(unsigned whichGrade) const = 0;
    virtual size_t maxAllowedCount() const = 0;
};

#endif // IGRADES_H
