#include "personaldata.h"

PersonalData::PersonalData(
        const std::string &firstName,
        const std::string &lastName,
        Gender gender) :
            mFirstName(firstName), mLastName(lastName), mGender(gender) {

}

PersonalData::PersonalData(const IPersonalData& originalData) {
    mFirstName = originalData.getFirstName();
    mLastName = originalData.getLastName();
    mGender = originalData.getGender();
}

std::string PersonalData::getFirstName() const {
    return mFirstName;
}

std::string PersonalData::getLastName() const {
    return mLastName;
}

Gender PersonalData::getGender() const {
    return mGender;
}

void PersonalData::setFirstName(const std::string &firstName) {
    mFirstName = firstName;
}

void PersonalData::setLastName(const std::string &lastName) {
    mLastName = lastName;
}

void PersonalData::setGender(Gender gender) {
    mGender = gender;
}
