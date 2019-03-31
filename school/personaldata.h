#ifndef PERSONALDATA_H
#define PERSONALDATA_H

#include "gender.h"
#include <string>

class PersonalData
{
public:
    PersonalData(
        const std::string &firstName,
        const std::string &lastName,
        Gender gender);

    std::string getFirstName() const;
    std::string getLastName() const;
    Gender getGender() const;

    void setFirstName(const std::string &firstName);
    void setLastName(const std::string &lastName);
    void setGender(Gender gender);

private:
    std::string mFirstName, mLastName;
    Gender mGender;
};

#endif // PERSONALDATA_H
