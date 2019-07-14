#include "testconfirmdialog.h"
#include "ui_confirmdialog.h"
#include <QSignalSpy>

TestConfirmDialog::TestConfirmDialog(unsigned &passed, unsigned &failed) :
        TestExecutionCounter(passed, failed),
        mConfirmDialog(nullptr) {

}

void TestConfirmDialog::init() {
    mConfirmDialog.reset(
            new ConfirmDialog(std::make_shared<SignalTransmitter>()));
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
    DialogAction actionToDo = ADD_STUDENT;
    QString actionString = "add";
    QString studentName = "Jan Kowalski";
    mConfirmDialog->customizeDialogMessage(actionToDo,actionString, studentName);

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

void TestConfirmDialog::testConfirmButtonClicked_data() {
    QTest::addColumn<DialogAction>("actionToCommit");

    QTest::newRow("commit_add_student") << ADD_STUDENT;
    QTest::newRow("commit_edit_student") << EDIT_STUDENT;
    QTest::newRow("commit_delete_student") << DELETE_STUDENT;
}

void TestConfirmDialog::testConfirmButtonClicked() {
    QFETCH(DialogAction, actionToCommit);
    QSignalSpy signalSpy(mConfirmDialog.get(), &ConfirmDialog::commit);

    mConfirmDialog->mActionToDo = actionToCommit;
    mConfirmDialog->confirmButtonClicked();

    QCOMPARE(signalSpy.count(), 1);

    auto signalArguments = signalSpy.takeFirst();
    DialogAction expectedActionToCommit = actionToCommit;
    DialogAction actualActionToCommit =
            signalArguments.at(0).value<DialogAction>();
    QCOMPARE(actualActionToCommit, expectedActionToCommit);

    bool isDialogVisible = mConfirmDialog->isVisible();
    QVERIFY(isDialogVisible == false);
}
