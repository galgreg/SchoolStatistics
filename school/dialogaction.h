#ifndef CONFIRMACTION_H
#define CONFIRMACTION_H

#include <QMetaType>

enum DialogAction {
    ADD_STUDENT,
    EDIT_STUDENT,
    DELETE_STUDENT
};
Q_DECLARE_METATYPE(DialogAction)

#endif // CONFIRMACTION_H
