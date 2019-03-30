#ifndef STUDENTDATAMANAGERINTERFACE_H
#define STUDENTDATAMANAGERINTERFACE_H

#include <QList>
#include "studentinterface.h"

class StudentDataManagerInterface
{
public:
    virtual ~StudentDataManagerInterface() = default;
    virtual QList<StudentInterface*> read() const = 0;
    virtual void write(const QList<StudentInterface*> &students) = 0;
};

#endif // STUDENTDATAMANAGERINTERFACE_H
