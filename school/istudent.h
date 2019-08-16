#ifndef ISTUDENT_H
#define ISTUDENT_H

#include "ipersonaldata.h"
#include "igrades.h"
#include <memory>

class IStudent {
public:
    virtual ~IStudent() = default;
    bool operator==(const IStudent& studentToCompare) const noexcept;
    bool operator!=(const IStudent& studentToCompare) const noexcept;

    virtual unsigned getID() const = 0;
    virtual const IPersonalData& getPersonalData() const = 0;
    virtual const IGrades& getGrades() const = 0;
    virtual void setPersonalData(std::unique_ptr<IPersonalData> newData) = 0;
    virtual void setGrades(std::unique_ptr<IGrades> newGrades) = 0;
};

#endif // ISTUDENT_H
