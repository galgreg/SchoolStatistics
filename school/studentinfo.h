#ifndef STUDENTINFO_H
#define STUDENTINFO_H
#include "gender.h"
#include <QString>
class StudentInfo
{
public:
    StudentInfo(unsigned ID, QString fullName, Gender gender);
    const unsigned hisID;
    const QString hisFullName;
    const Gender hisGender;
};

#endif // STUDENTINFO_H
