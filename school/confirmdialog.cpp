#include "confirmdialog.h"
#include "ui_confirmdialog.h"

ConfirmDialog::ConfirmDialog(
        std::shared_ptr<SignalTransmitter> signalTransmitter) :
            QWidget(nullptr),
            ui(new Ui::ConfirmDialog),
            mSignalTransmitter(signalTransmitter),
            mCurrentActionString(""),
            mCurrentStudentName("") {
    ui->setupUi(this);

    connect(ui->confirmButton, &QPushButton::clicked,
            this, &ConfirmDialog::confirmButtonClicked);
    connect(this, &ConfirmDialog::commit,
            mSignalTransmitter.get(), &SignalTransmitter::transmitSignal);
}

ConfirmDialog::~ConfirmDialog() {

}

void ConfirmDialog::showDialog() {
    this->show();
}

void ConfirmDialog::hideDialog() {
    this->hide();
}

void ConfirmDialog::customizeDialogMessage(
         StudentDataAction actionToDo,
        const QString &studentName) {
    mActionToDo = actionToDo;
    mCurrentActionString = convertActionToString(actionToDo);
    mCurrentStudentName = studentName;
    QString dialogMessage = QString(
            "<html><head/><body>"
            "<p align=\"center\"> You asked to %1 data about %2. </p>"
            "<p align=\"center\">Are you sure?</p>"
            "</body></html>").arg(mCurrentActionString).arg(studentName);
    ui->dialogMessage->setText(dialogMessage);
}

QString ConfirmDialog::getCurrentActionString() {
    return mCurrentActionString;
}

QString ConfirmDialog::getCurrentStudentName() {
    return mCurrentStudentName;
}

void ConfirmDialog::confirmButtonClicked() {
    emit commit(mActionToDo);
    this->hide();
}

QString ConfirmDialog::convertActionToString(StudentDataAction actionToConvert) {
    if (actionToConvert == ADD_STUDENT) {
        return "add";
    } else if (actionToConvert == EDIT_STUDENT) {
        return "edit";
    } else if (actionToConvert == DELETE_STUDENT) {
        return "delete";
    } else {
        return "";
    }
}



