#ifndef CONFIRMACTION_H
#define CONFIRMACTION_H

#include <QMetaType>

enum StudentDataAction {
    ADD_STUDENT,
    EDIT_STUDENT,
    DELETE_STUDENT
};
Q_DECLARE_METATYPE(StudentDataAction)

#endif // CONFIRMACTION_H
