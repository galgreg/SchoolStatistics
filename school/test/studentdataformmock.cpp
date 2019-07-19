#include "studentdataformmock.h"

StudentDataFormMock::StudentDataFormMock() :
        mHeader(""), mFirstName(""), mLastName(""), mGender(UNKNOWN) {

}

void StudentDataFormMock::showForm() {

}

void StudentDataFormMock::hideForm() {

}

void StudentDataFormMock::setHeader(const QString &newHeader) {
    mHeader = newHeader;
}

void StudentDataFormMock::setFirstName(const QString &newFirstName) {
    mFirstName = newFirstName;
}

void StudentDataFormMock::setLastName(const QString &newLastName) {
    mLastName = newLastName;
}

void StudentDataFormMock::setGender(Gender newGender) {
    mGender = newGender;
}

void StudentDataFormMock::setMaxGradesCount(size_t newMaxGradesCount) {
    mMaxGradesCount = newMaxGradesCount;
}

size_t StudentDataFormMock::getMaxGradesCount() {
    return mMaxGradesCount;
}

void StudentDataFormMock::addGrade(double newGrade) {
    mGrades.append(newGrade);
}

void StudentDataFormMock::editGrade(size_t whichGrade, double newGrade) {
    mGrades[static_cast<int>(whichGrade)] = newGrade;
}

void StudentDataFormMock::deleteGrade(size_t whichGrade) {
    mGrades.removeAt(static_cast<int>(whichGrade));
}

void StudentDataFormMock::deleteAllGrades() {
    mGrades.clear();
}

QString StudentDataFormMock::getHeader() {
    return mHeader;
}

QString StudentDataFormMock::getFirstName() {
    return mFirstName;
}

QString StudentDataFormMock::getLastName() {
    return mLastName;
}

Gender StudentDataFormMock::getGender() {
    return mGender;
}

QList<double> StudentDataFormMock::getGrades() {
    return mGrades;
}
