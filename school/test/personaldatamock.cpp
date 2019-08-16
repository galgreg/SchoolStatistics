#include "personaldatamock.h"

PersonalDataMock::PersonalDataMock(const IPersonalData &) noexcept {

}

QString PersonalDataMock::getFirstName() const noexcept {
    return "";
}

QString PersonalDataMock::getLastName() const noexcept {
    return "";
}

Gender PersonalDataMock::getGender() const noexcept {
    return UNKNOWN;
}

void PersonalDataMock::setFirstName(const QString &) noexcept {
}

void PersonalDataMock::setLastName(const QString &) noexcept {
}

void PersonalDataMock::setGender(Gender) noexcept {
}
