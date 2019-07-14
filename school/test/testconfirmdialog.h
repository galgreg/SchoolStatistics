#ifndef TESTCONFIRMDIALOG_H
#define TESTCONFIRMDIALOG_H

#include "testexecutioncounter.h"
#include "confirmdialog.h"
#include <QtTest>

class TestConfirmDialog : public QObject, public TestExecutionCounter
{
    Q_OBJECT

public:
    TestConfirmDialog(unsigned &passed, unsigned &failed);

private slots:
    void init();
    void cleanup();
    void testInitialState();
    void testCustomizeDialogMessage();
    void testShowDialog();
    void testHideDialog();
    void testConfirmButtonClicked_data();
    void testConfirmButtonClicked();

private:
    std::unique_ptr<ConfirmDialog> mConfirmDialog;
};

#endif // TESTCONFIRMDIALOG_H
