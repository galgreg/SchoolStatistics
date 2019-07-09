#ifndef PERSONALDATA_H
#define PERSONALDATA_H

#include "ipersonaldata.h"
#include "gender.h"
#include <string>

class PersonalData : public IPersonalData
{
public:
    PersonalData(
        const std::string &firstName,
        const std::string &lastName,
        Gender gender);
    PersonalData(const IPersonalData &);
    std::string getFirstName() const override;
    std::string getLastName() const override;
    Gender getGender() const override;

    void setFirstName(const std::string &firstName) override;
    void setLastName(const std::string &lastName) override;
    void setGender(Gender gender) override;

private:
    std::string mFirstName, mLastName;
    Gender mGender;
};

#endif // PERSONALDATA_H
