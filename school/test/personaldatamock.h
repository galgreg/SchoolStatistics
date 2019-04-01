#ifndef PERSONALDATAMOCK_H
#define PERSONALDATAMOCK_H

#include "ipersonaldata.h"

class PersonalDataMock : public IPersonalData
{
    std::string getFirstName() const override;
    std::string getLastName() const override;
    Gender getGender() const override;

    void setFirstName(const std::string &firstName) override;
    void setLastName(const std::string &lastName) override;
    void setGender(Gender gender) override;
};

#endif // PERSONALDATAMOCK_H
