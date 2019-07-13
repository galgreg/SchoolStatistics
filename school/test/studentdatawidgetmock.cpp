#include "studentdatawidgetmock.h"

void StudentDataWidgetMock::showWidget() {

}

void StudentDataWidgetMock::hideWidget() {

}

QString StudentDataWidgetMock::getID() {
    return mStudentID;
}

QString StudentDataWidgetMock::getFirstName() {
    return mFirstName;
}

QString StudentDataWidgetMock::getLastName() {
    return mLastName;
}

QString StudentDataWidgetMock::getGender() {
    return mGender;
}

QString StudentDataWidgetMock::getGrades() {
    return mGrades;
}

QString StudentDataWidgetMock::getGradesAverage() {
    return mGradesAverage;
}

void StudentDataWidgetMock::setID(const QString &newID) {
    mStudentID = newID;
}

void StudentDataWidgetMock::setFirstName(const QString &newFirstName) {
    mFirstName = newFirstName;
}

void StudentDataWidgetMock::setLastName(const QString &newLastName) {
    mLastName = newLastName;
}

void StudentDataWidgetMock::setGender(const QString &newGender) {
    mGender = newGender;
}

void StudentDataWidgetMock::setGrades(const QString &newGrades) {
    mGrades = newGrades;
}

void StudentDataWidgetMock::setGradesAverage(const QString &newGradesAverage) {
    mGradesAverage = newGradesAverage;
}

