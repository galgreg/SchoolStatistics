#ifndef IDATAREPOSITORY_H
#define IDATAREPOSITORY_H

#include "istudentclass.h"

class IDataRepository
{
public:
    explicit IDataRepository(const std::string &repositoryPath);
    virtual ~IDataRepository();

    virtual IStudentClass *read() = 0;
    virtual void write(IStudentClass *studentClass) = 0;
    virtual bool exist() = 0;

    std::string getPath();
private:
    const std::string mRepositoryPath;
};

#endif // IDATAREPOSITORY_H
