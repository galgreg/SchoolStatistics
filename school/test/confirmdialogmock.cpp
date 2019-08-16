#include "confirmdialogmock.h"

ConfirmDialogMock::ConfirmDialogMock(
        const QString &defaultAction,
        const QString &defaultStudentName) noexcept :
            mActionString(defaultAction),
            mStudentName(defaultStudentName) {

}

void ConfirmDialogMock::showDialog() noexcept {

}

void ConfirmDialogMock::hideDialog() noexcept {

}

void ConfirmDialogMock::customizeDialogMessage(
        StudentDataAction actionToDo,
        const QString &studentName) noexcept {
    if (actionToDo == ADD_STUDENT) {
        mActionString = "add";
    } else if (actionToDo == EDIT_STUDENT) {
        mActionString = "edit";
    } else if (actionToDo == DELETE_STUDENT) {
        mActionString = "delete";
    } else {
        mActionString = "";
    }
    mStudentName = studentName;
}

QString ConfirmDialogMock::getCurrentActionString() noexcept {
    return mActionString;
}

QString ConfirmDialogMock::getCurrentStudentName() noexcept {
    return mStudentName;
}
