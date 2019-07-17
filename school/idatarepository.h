#ifndef IDATAREPOSITORY_H
#define IDATAREPOSITORY_H

#include "istudentclass.h"
#include <memory>

class IDataRepository
{
public:
    explicit IDataRepository(const std::string &repositoryPath);
    virtual ~IDataRepository();

    virtual std::unique_ptr<IStudentClass> read(
            size_t maxStudentCount, size_t maxGradesCount) = 0;
    virtual void write(const IStudentClass& studentClass) = 0;
    virtual bool exist() = 0;

    std::string getPath();
private:
    const std::string mRepositoryPath;
};

#endif // IDATAREPOSITORY_H
