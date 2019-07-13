#ifndef CONFIRMDIALOGMOCK_H
#define CONFIRMDIALOGMOCK_H

#include "iconfirmdialog.h"
#include <QString>

class ConfirmDialogMock : public IConfirmDialog
{
public:
    ConfirmDialogMock(
            const QString &defaultAction = "",
            const QString &defaultStudentName = "");

    void showDialog() override;
    void hideDialog() override;

    void setAction(const QString &newAction) override;
    void setStudentName(const QString &newStudentName) override;

    QString getAction() override;
    QString getStudentName() override;

private:
    QString mAction;
    QString mStudentName;
};

#endif // CONFIRMDIALOGMOCK_H
