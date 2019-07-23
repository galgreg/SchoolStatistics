#ifndef PERSONALDATA_H
#define PERSONALDATA_H

#include "ipersonaldata.h"

class PersonalData : public IPersonalData
{
public:
    PersonalData(
        const QString &firstName,
        const QString &lastName,
        Gender gender);
    PersonalData(const IPersonalData &);
    QString getFirstName() const override;
    QString getLastName() const override;
    Gender getGender() const override;

    void setFirstName(const QString &firstName) override;
    void setLastName(const QString &lastName) override;
    void setGender(Gender gender) override;

private:
    QString mFirstName, mLastName;
    Gender mGender;
};

#endif // PERSONALDATA_H
