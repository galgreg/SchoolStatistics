#ifndef CONFIRMDIALOG_H
#define CONFIRMDIALOG_H

#include "iconfirmdialog.h"
#include <QWidget>
#include "signaltransmitter.h"
#include <memory>

class TestConfirmDialog;

namespace Ui {
    class ConfirmDialog;
}

class ConfirmDialog : public QWidget, public IConfirmDialog
{
    Q_OBJECT

public:
    friend TestConfirmDialog;

    explicit ConfirmDialog(
        std::shared_ptr<SignalTransmitter> signalTransmitter);
    ~ConfirmDialog() override;
    void showDialog() override;
    void hideDialog() override;

    void customizeDialogMessage(
        StudentDataAction actionToDo,
        const QString &studentName) override;

    QString getCurrentActionString() override;
    QString getCurrentStudentName() override;

signals:
    void commit(StudentDataAction);

private slots:
    void confirmButtonClicked();

private:
    QString convertActionToString(StudentDataAction actionToConvert);

    std::unique_ptr<Ui::ConfirmDialog> ui;
    std::shared_ptr<SignalTransmitter> mSignalTransmitter;
    StudentDataAction mActionToDo;
    QString mCurrentActionString;
    QString mCurrentStudentName;
};

#endif // CONFIRMDIALOG_H
