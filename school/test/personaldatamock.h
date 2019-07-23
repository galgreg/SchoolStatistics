#ifndef PERSONALDATAMOCK_H
#define PERSONALDATAMOCK_H

#include "ipersonaldata.h"

class PersonalDataMock : public IPersonalData
{
public:
    PersonalDataMock() = default;
    PersonalDataMock(const IPersonalData &originalPersonalData);
    QString getFirstName() const override;
    QString getLastName() const override;
    Gender getGender() const override;

    void setFirstName(const QString &firstName) override;
    void setLastName(const QString &lastName) override;
    void setGender(Gender gender) override;
};

#endif // PERSONALDATAMOCK_H
