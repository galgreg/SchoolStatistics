#ifndef GENDER_H
#define GENDER_H
#include <QMetaType>

enum Gender {
    UNKNOWN,
    FEMALE,
    MALE
};

Q_DECLARE_METATYPE(Gender)

#endif // GENDER_H
