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

    void customizeDialogMessage(
            StudentDataAction actionToDo,
            const QString &studentName) override;

    QString getCurrentActionString() override;
    QString getCurrentStudentName() override;

private:
    QString mActionString;
    QString mStudentName;
};

#endif // CONFIRMDIALOGMOCK_H
