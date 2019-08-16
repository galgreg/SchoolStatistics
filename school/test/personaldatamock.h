#ifndef PERSONALDATAMOCK_H
#define PERSONALDATAMOCK_H

#include "ipersonaldata.h"

class PersonalDataMock : public IPersonalData
{
public:
    PersonalDataMock() = default;
    PersonalDataMock(const IPersonalData &originalPersonalData) noexcept;
    QString getFirstName() const noexcept override;
    QString getLastName() const noexcept override;
    Gender getGender() const noexcept override;

    void setFirstName(const QString &firstName) noexcept override;
    void setLastName(const QString &lastName) noexcept override;
    void setGender(Gender gender) noexcept override;
};

#endif // PERSONALDATAMOCK_H
