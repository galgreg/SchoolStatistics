#ifndef ICONFIRMDIALOG_H
#define ICONFIRMDIALOG_H

#include "dialogaction.h"
class QString;

class IConfirmDialog {
public:
    virtual ~IConfirmDialog() = default;
    virtual void showDialog() = 0;
    virtual void hideDialog() = 0;

    virtual void customizeDialogMessage(
            DialogAction actionToDo,
            const QString &actionString,
            const QString &studentName) = 0;

    virtual QString getCurrentActionString() = 0;
    virtual QString getCurrentStudentName() = 0;
};

#endif // ICONFIRMDIALOG_H
