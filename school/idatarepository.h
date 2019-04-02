#ifndef IDATAREPOSITORY_H
#define IDATAREPOSITORY_H

#include "istudentclass.h"

class IDataRepository
{
public:
    virtual ~IDataRepository() = default;
    virtual IStudentClass *read() = 0;
    virtual void write(IStudentClass *studentClass) = 0;
};

#endif // IDATAREPOSITORY_H
