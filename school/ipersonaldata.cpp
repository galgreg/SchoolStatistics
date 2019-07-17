#include "ipersonaldata.h"

bool IPersonalData::operator==(const IPersonalData &dataToCompare) const {
    return this->getFirstName() == dataToCompare.getFirstName() &&
    this->getLastName() == dataToCompare.getLastName() &&
    this->getGender() == dataToCompare.getGender();
}
