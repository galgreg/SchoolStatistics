#ifndef GENDER_H
#define GENDER_H

#include <QMetaType>

enum Gender {
    MALE,
    FEMALE,
    UNKNOWN
};
Q_DECLARE_METATYPE(Gender)

#endif // GENDER_H
