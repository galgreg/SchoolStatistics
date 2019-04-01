#ifndef PERSONALDATAMOCK_H
#define PERSONALDATAMOCK_H

#include "ipersonaldata.h"

class PersonalDataMock : public IPersonalData
{
public:
    PersonalDataMock(
            const std::string &firstName,
            const std::string &lastName,
            Gender gender);

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

#endif // PERSONALDATAMOCK_H
