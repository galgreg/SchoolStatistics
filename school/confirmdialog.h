#ifndef CONFIRMDIALOG_H
#define CONFIRMDIALOG_H

#include <QWidget>
#include "iconfirmdialog.h"
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

    explicit ConfirmDialog(QWidget *parent = nullptr);
    ~ConfirmDialog() override;
    void showDialog() override;
    void hideDialog() override;

    void customizeDialogMessage(
            const QString &actionString,
            const QString &studentName) override;

    QString getCurrentActionString() override;
    QString getCurrentStudentName() override;

private:
    std::unique_ptr<Ui::ConfirmDialog> ui;
    QString mCurrentActionString;
    QString mCurrentStudentName;
};

#endif // CONFIRMDIALOG_H
