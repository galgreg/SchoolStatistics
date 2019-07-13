#include "confirmdialog.h"
#include "ui_confirmdialog.h"

ConfirmDialog::ConfirmDialog(QWidget *parent) :
            QWidget(parent),
            ui(new Ui::ConfirmDialog),
            mCurrentActionString(""),
            mCurrentStudentName("") {
    ui->setupUi(this);
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
        const QString &actionString,
        const QString &studentName) {
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



