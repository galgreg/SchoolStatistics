#include "confirmdialogmock.h"

ConfirmDialogMock::ConfirmDialogMock(
        const QString &defaultAction,
        const QString &defaultStudentName) :
            mAction(defaultAction),
            mStudentName(defaultStudentName) {

}

void ConfirmDialogMock::showDialog() {

}

void ConfirmDialogMock::hideDialog() {

}

void ConfirmDialogMock::setAction(const QString &newAction) {
    mAction = newAction;
}

void ConfirmDialogMock::setStudentName(const QString &newStudentName) {
    mStudentName = newStudentName;
}

QString ConfirmDialogMock::getAction() {
    return mAction;
}

QString ConfirmDialogMock::getStudentName() {
    return mStudentName;
}
