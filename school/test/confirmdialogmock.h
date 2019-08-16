#ifndef CONFIRMDIALOGMOCK_H
#define CONFIRMDIALOGMOCK_H

#include "iconfirmdialog.h"
#include <QString>

class ConfirmDialogMock : public IConfirmDialog
{
public:
    ConfirmDialogMock(
            const QString &defaultAction = "",
            const QString &defaultStudentName = "") noexcept;

    void showDialog() noexcept override;
    void hideDialog() noexcept override;

    void customizeDialogMessage(
            StudentDataAction actionToDo,
            const QString &studentName) noexcept override;

    QString getCurrentActionString() noexcept override;
    QString getCurrentStudentName() noexcept override;

private:
    QString mActionString;
    QString mStudentName;
};

#endif // CONFIRMDIALOGMOCK_H
