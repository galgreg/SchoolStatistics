#ifndef CONFIRMACTION_H
#define CONFIRMACTION_H

#include <QMetaType>

enum ConfirmAction {
    ADD_STUDENT,
    EDIT_STUDENT,
    DELETE_STUDENT
};
Q_DECLARE_METATYPE(ConfirmAction)

#endif // CONFIRMACTION_H
