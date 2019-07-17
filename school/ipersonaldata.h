#ifndef IPERSONALDATA_H
#define IPERSONALDATA_H

#include "gender.h"
#include <string>

class IPersonalData {
public:
    virtual ~IPersonalData() = default;
    bool operator==(const IPersonalData &dataToCompare) const;

    virtual std::string getFirstName() const = 0;
    virtual std::string getLastName() const = 0;
    virtual Gender getGender() const = 0;

    virtual void setFirstName(const std::string &firstName) = 0;
    virtual void setLastName(const std::string &lastName) = 0;
    virtual void setGender(Gender gender) = 0;
};

#endif // IPERSONALDATA_H
