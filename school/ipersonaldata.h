#ifndef IPERSONALDATA_H
#define IPERSONALDATA_H

#include "gender.h"
#include <QString>

class IPersonalData {
public:
    virtual ~IPersonalData() = default;
    bool operator==(const IPersonalData &dataToCompare) const;

    virtual QString getFirstName() const = 0;
    virtual QString getLastName() const = 0;
    virtual Gender getGender() const = 0;

    virtual void setFirstName(const QString &firstName) = 0;
    virtual void setLastName(const QString &lastName) = 0;
    virtual void setGender(Gender gender) = 0;
};

#endif // IPERSONALDATA_H
