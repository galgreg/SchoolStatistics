#include "studentdataformmock.h"

StudentDataFormMock::StudentDataFormMock() noexcept :
        mHeader(""), mFirstName(""), mLastName(""), mGender(UNKNOWN) {

}

void StudentDataFormMock::showForm() noexcept {

}

void StudentDataFormMock::hideForm() noexcept {

}

void StudentDataFormMock::setFormAction(StudentDataAction newFormAction) noexcept {
    mFormAction = newFormAction;
}

StudentDataAction StudentDataFormMock::getFormAction() noexcept {
    return mFormAction;
}

void StudentDataFormMock::setHeader(const QString &newHeader) noexcept {
    mHeader = newHeader;
}

void StudentDataFormMock::setFirstName(const QString &newFirstName) noexcept {
    mFirstName = newFirstName;
}

void StudentDataFormMock::setLastName(const QString &newLastName) noexcept {
    mLastName = newLastName;
}

void StudentDataFormMock::setGender(Gender newGender) noexcept {
    mGender = newGender;
}

void StudentDataFormMock::setMaxGradesCount(size_t newMaxGradesCount) noexcept {
    mMaxGradesCount = newMaxGradesCount;
}

size_t StudentDataFormMock::getMaxGradesCount() noexcept {
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

void StudentDataFormMock::deleteAllGrades() noexcept {
    mGrades.clear();
}

QString StudentDataFormMock::getHeader() noexcept {
    return mHeader;
}

QString StudentDataFormMock::getFirstName() noexcept {
    return mFirstName;
}

QString StudentDataFormMock::getLastName() noexcept {
    return mLastName;
}

Gender StudentDataFormMock::getGender() noexcept {
    return mGender;
}

QList<double> StudentDataFormMock::getGrades() noexcept {
    return mGrades;
}
