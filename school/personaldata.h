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
private:
    std::string mFirstName, mLastName;
    Gender mGender;
};

#endif // PERSONALDATA_H
