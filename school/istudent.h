#ifndef ISTUDENT_H
#define ISTUDENT_H

#include "ipersonaldata.h"
#include "igrades.h"

class IStudent {
public:
    virtual ~IStudent() = default;
    bool operator==(const IStudent& studentToCompare) const {
        return this->getID() == studentToCompare.getID() &&
                this->getPersonalData() == studentToCompare.getPersonalData() &&
                this->getGrades() == studentToCompare.getGrades();
    }
    bool operator!=(const IStudent& studentToCompare) const {
        return !(*this == studentToCompare);
    }

    virtual unsigned getID() const = 0;
    virtual const IPersonalData& getPersonalData() const = 0;
    virtual const IGrades& getGrades() const = 0;
    virtual void setPersonalData(const IPersonalData& newData) = 0;
    virtual void setGrades(const IGrades& newGrades) = 0;
};

#endif // ISTUDENT_H
