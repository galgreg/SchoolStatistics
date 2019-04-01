#include "personaldatamock.h"

std::string PersonalDataMock::getFirstName() const {
    return "";
}

std::string PersonalDataMock::getLastName() const {
    return "";
}

Gender PersonalDataMock::getGender() const {
    return MALE;
}

void PersonalDataMock::setFirstName(const std::string &) {
}

void PersonalDataMock::setLastName(const std::string &) {
}

void PersonalDataMock::setGender(Gender) {
}
