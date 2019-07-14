#include "confirmdialog.h"
#include "ui_confirmdialog.h"

ConfirmDialog::ConfirmDialog(QWidget *parent) :
            QWidget(parent),
            ui(new Ui::ConfirmDialog),
            mSignalTransmitter(new SignalTransmitter),
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
         DialogAction actionToDo,
        const QString &actionString,
        const QString &studentName) {
    mActionToDo = actionToDo;
    mCurrentActionString = actionString;
    mCurrentStudentName = studentName;
    QString dialogMessage = QString(
            "<html><head/><body>"
            "<p align=\"center\"> You asked to %1 data about %2. </p>"
            "<p align=\"center\">Are you sure?</p>"
            "</body></html>").arg(actionString).arg(studentName);
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



