#include "testconfirmdialog.h"
#include "ui_confirmdialog.h"

TestConfirmDialog::TestConfirmDialog(unsigned &passed, unsigned &failed) :
        TestExecutionCounter(passed, failed),
        mConfirmDialog(nullptr) {

}

void TestConfirmDialog::init() {
    mConfirmDialog.reset(new ConfirmDialog);
}

void TestConfirmDialog::cleanup() {
    if (QTest::currentTestFailed()) {
        incrementFailCounter();
    } else {
        incrementPassCounter();
    }
}

void TestConfirmDialog::testInitialState() {
    QString expectedInitialActionString = "";
    QString actualInitialActionString = mConfirmDialog->getCurrentActionString();
    QCOMPARE(actualInitialActionString, expectedInitialActionString);

    QString expectedInitialStudentName = "";
    QString actualInitialStudentName = mConfirmDialog->getCurrentStudentName();
    QCOMPARE(actualInitialStudentName, expectedInitialStudentName);
}

void TestConfirmDialog::testCustomizeDialogMessage() {
    QString actionString = "add";
    QString studentName = "Jan Kowalski";
    mConfirmDialog->customizeDialogMessage(actionString, studentName);

    QString expectedActionString = actionString;
    QString actualActionString = mConfirmDialog->getCurrentActionString();
    QCOMPARE(actualActionString, expectedActionString);

    QString expectedStudentName = studentName;
    QString actualStudentName = mConfirmDialog->getCurrentStudentName();
    QCOMPARE(actualStudentName, expectedStudentName);

    QString expectedDialogMessage =
            "<html><head/><body>"
            "<p align=\"center\"> You asked to add data about Jan Kowalski. </p>"
            "<p align=\"center\">Are you sure?</p>"
            "</body></html>";
    QString actualDialogMessage = mConfirmDialog->ui->dialogMessage->text();
    QCOMPARE(actualDialogMessage, expectedDialogMessage);
}

void TestConfirmDialog::testShowDialog() {
    mConfirmDialog->showDialog();
    bool isDialogVisible = mConfirmDialog->isVisible();
    QVERIFY(isDialogVisible == true);
}

void TestConfirmDialog::testHideDialog() {
    mConfirmDialog->hideDialog();
    bool isDialogVisible = mConfirmDialog->isVisible();
    QVERIFY(isDialogVisible == false);
}
