#ifndef TESTCONFIRMDIALOG_H
#define TESTCONFIRMDIALOG_H

#include "testexecutioncounter.h"
#include "confirmdialog.h"
#include <QtTest>

class TestConfirmDialog : public QObject, public TestExecutionCounter {
    Q_OBJECT

public:
    TestConfirmDialog(unsigned &passed, unsigned &failed) noexcept;

private slots:
    void init();
    void cleanup() noexcept;
    void testInitialState() noexcept;
    void testCustomizeDialogMessage() noexcept;
    void testShowDialog() noexcept;
    void testHideDialog() noexcept;
    void testConfirmButtonClicked_data() noexcept;
    void testConfirmButtonClicked() noexcept;

    void testConvertActionToString_data() noexcept;
    void testConvertActionToString() noexcept;

private:
    std::unique_ptr<ConfirmDialog> mConfirmDialog;
};

#endif // TESTCONFIRMDIALOG_H
