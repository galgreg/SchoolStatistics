#include "personaldata.h"

PersonalData::PersonalData(
        const std::string &firstName,
        const std::string &lastName,
        Gender gender) :
            mFirstName(firstName), mLastName(lastName),mGender(gender) {

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
