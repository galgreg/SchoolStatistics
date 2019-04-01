#include "personaldatamock.h"

PersonalDataMock::PersonalDataMock(
        const std::string &firstName,
        const std::string &lastName,
        Gender gender) :
            mFirstName(firstName), mLastName(lastName), mGender(gender) {

}

std::string PersonalDataMock::getFirstName() const {
    return mFirstName;
}

std::string PersonalDataMock::getLastName() const {
    return mLastName;
}

Gender PersonalDataMock::getGender() const {
    return mGender;
}

void PersonalDataMock::setFirstName(const std::string &firstName) {
    mFirstName = firstName;
}

void PersonalDataMock::setLastName(const std::string &lastName) {
    mLastName = lastName;
}

void PersonalDataMock::setGender(Gender gender) {
    mGender = gender;
}
