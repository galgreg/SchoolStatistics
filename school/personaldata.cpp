#include "personaldata.h"

PersonalData::PersonalData(
        const QString &firstName,
        const QString &lastName,
        Gender gender) :
                mFirstName(firstName),
                mLastName(lastName),
                mGender(gender) {

}

PersonalData::PersonalData(const IPersonalData& originalData) {
    mFirstName = originalData.getFirstName();
    mLastName = originalData.getLastName();
    mGender = originalData.getGender();
}

QString PersonalData::getFirstName() const {
    return mFirstName;
}

QString PersonalData::getLastName() const {
    return mLastName;
}

Gender PersonalData::getGender() const {
    return mGender;
}

void PersonalData::setFirstName(const QString &firstName) {
    mFirstName = firstName;
}

void PersonalData::setLastName(const QString &lastName) {
    mLastName = lastName;
}

void PersonalData::setGender(Gender gender) {
    mGender = gender;
}
