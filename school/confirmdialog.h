#ifndef CONFIRMDIALOG_H
#define CONFIRMDIALOG_H

#include <QWidget>
#include "iconfirmdialog.h"
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
        std::shared_ptr<SignalTransmitter> signalTransmitter,
        QWidget *parent = nullptr);
    ~ConfirmDialog() override;
    void showDialog() override;
    void hideDialog() override;

    void customizeDialogMessage(
            DialogAction actionToDo,
            const QString &actionString,
            const QString &studentName) override;

    QString getCurrentActionString() override;
    QString getCurrentStudentName() override;

signals:
    void commit(DialogAction);

private slots:
    void confirmButtonClicked();

private:
    std::unique_ptr<Ui::ConfirmDialog> ui;
    std::shared_ptr<SignalTransmitter> mSignalTransmitter;
    DialogAction mActionToDo;
    QString mCurrentActionString;
    QString mCurrentStudentName;
};

#endif // CONFIRMDIALOG_H
