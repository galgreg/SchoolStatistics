#include "studentdatawidgetmock.h"

void StudentDataWidgetMock::showWidget() noexcept {

}

void StudentDataWidgetMock::hideWidget() noexcept {

}

QString StudentDataWidgetMock::getID() noexcept {
    return mStudentID;
}

QString StudentDataWidgetMock::getFirstName() noexcept {
    return mFirstName;
}

QString StudentDataWidgetMock::getLastName() noexcept {
    return mLastName;
}

QString StudentDataWidgetMock::getGender() noexcept {
    return mGender;
}

QString StudentDataWidgetMock::getGrades() noexcept {
    return mGrades;
}

QString StudentDataWidgetMock::getGradesAverage() noexcept {
    return mGradesAverage;
}

void StudentDataWidgetMock::setID(const QString &newID) noexcept {
    mStudentID = newID;
}

void StudentDataWidgetMock::setFirstName(const QString &newFirstName) noexcept {
    mFirstName = newFirstName;
}

void StudentDataWidgetMock::setLastName(const QString &newLastName) noexcept {
    mLastName = newLastName;
}

void StudentDataWidgetMock::setGender(const QString &newGender) noexcept {
    mGender = newGender;
}

void StudentDataWidgetMock::setGrades(const QString &newGrades) noexcept {
    mGrades = newGrades;
}

void StudentDataWidgetMock::setGradesAverage(const QString &newGradesAverage) noexcept {
    mGradesAverage = newGradesAverage;
}

