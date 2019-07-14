#include "confirmdialogmock.h"

ConfirmDialogMock::ConfirmDialogMock(
        const QString &defaultAction,
        const QString &defaultStudentName) :
            mActionString(defaultAction),
            mStudentName(defaultStudentName) {

}

void ConfirmDialogMock::showDialog() {

}

void ConfirmDialogMock::hideDialog() {

}

void ConfirmDialogMock::customizeDialogMessage(
        DialogAction /* actionToDo */,
        const QString &actionString,
        const QString &studentName) {
    mActionString = actionString;
    mStudentName = studentName;
}

QString ConfirmDialogMock::getCurrentActionString() {
    return mActionString;
}

QString ConfirmDialogMock::getCurrentStudentName() {
    return mStudentName;
}
