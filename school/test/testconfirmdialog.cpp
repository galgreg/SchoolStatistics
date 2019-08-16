#include "testconfirmdialog.h"
#include "ui_confirmdialog.h"
#include <QSignalSpy>

TestConfirmDialog::TestConfirmDialog(unsigned &passed, unsigned &failed) noexcept :
        TestExecutionCounter(passed, failed),
        mConfirmDialog(nullptr) {

}

void TestConfirmDialog::init() {
    mConfirmDialog.reset(
            new ConfirmDialog(std::make_shared<SignalTransmitter>()));
}

void TestConfirmDialog::cleanup() noexcept {
    if (QTest::currentTestFailed()) {
        incrementFailCounter();
    } else {
        incrementPassCounter();
    }
}

void TestConfirmDialog::testInitialState() noexcept {
    QString expectedInitialActionString = "";
    QString actualInitialActionString = mConfirmDialog->getCurrentActionString();
    QCOMPARE(actualInitialActionString, expectedInitialActionString);

    QString expectedInitialStudentName = "";
    QString actualInitialStudentName = mConfirmDialog->getCurrentStudentName();
    QCOMPARE(actualInitialStudentName, expectedInitialStudentName);
}

void TestConfirmDialog::testCustomizeDialogMessage() noexcept {
    StudentDataAction actionToDo = ADD_STUDENT;
    QString studentName = "Jan Kowalski";
    mConfirmDialog->customizeDialogMessage(actionToDo, studentName);

    QString expectedActionString = "add";
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

void TestConfirmDialog::testShowDialog() noexcept {
    mConfirmDialog->showDialog();
    bool isDialogVisible = mConfirmDialog->isVisible();
    QVERIFY(isDialogVisible == true);
}

void TestConfirmDialog::testHideDialog() noexcept {
    mConfirmDialog->hideDialog();
    bool isDialogVisible = mConfirmDialog->isVisible();
    QVERIFY(isDialogVisible == false);
}

void TestConfirmDialog::testConfirmButtonClicked_data() noexcept {
    QTest::addColumn<StudentDataAction>("actionToCommit");

    QTest::newRow("commit_add_student") << ADD_STUDENT;
    QTest::newRow("commit_edit_student") << EDIT_STUDENT;
    QTest::newRow("commit_delete_student") << DELETE_STUDENT;
}

void TestConfirmDialog::testConfirmButtonClicked() noexcept {
    QFETCH(StudentDataAction, actionToCommit);
    QSignalSpy signalSpy(mConfirmDialog.get(), &ConfirmDialog::commit);

    mConfirmDialog->mActionToDo = actionToCommit;
    mConfirmDialog->confirmButtonClicked();

    QCOMPARE(signalSpy.count(), 1);

    auto signalArguments = signalSpy.takeFirst();
    StudentDataAction expectedActionToCommit = actionToCommit;
    StudentDataAction actualActionToCommit =
            signalArguments.at(0).value<StudentDataAction>();
    QCOMPARE(actualActionToCommit, expectedActionToCommit);

    bool isDialogVisible = mConfirmDialog->isVisible();
    QVERIFY(isDialogVisible == false);
}

void TestConfirmDialog::testConvertActionToString_data() noexcept {
    QTest::addColumn<StudentDataAction>("actionToConvert");
    QTest::addColumn<QString>("expectedActionString");

    QTest::newRow("Convert ADD_STUDENT") << ADD_STUDENT << "add";
    QTest::newRow("Convert EDIT_STUDENT") << EDIT_STUDENT << "edit";
    QTest::newRow("Convert DELETE_STUDENT") << DELETE_STUDENT << "delete";
}

void TestConfirmDialog::testConvertActionToString() noexcept {
    QFETCH(StudentDataAction, actionToConvert);
    QFETCH(QString, expectedActionString);
    QString actualActionString =
            mConfirmDialog->convertActionToString(actionToConvert);
    QCOMPARE(actualActionString, expectedActionString);
}
