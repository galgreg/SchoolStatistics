#include "personaldatamock.h"

PersonalDataMock::PersonalDataMock(const IPersonalData &) {

}

QString PersonalDataMock::getFirstName() const {
    return "";
}

QString PersonalDataMock::getLastName() const {
    return "";
}

Gender PersonalDataMock::getGender() const {
    return UNKNOWN;
}

void PersonalDataMock::setFirstName(const QString &) {
}

void PersonalDataMock::setLastName(const QString &) {
}

void PersonalDataMock::setGender(Gender) {
}
