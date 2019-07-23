#ifndef IDATAREPOSITORY_H
#define IDATAREPOSITORY_H

#include "istudentclass.h"
#include <memory>
#include <QString>

class IDataRepository
{
public:
    explicit IDataRepository(const QString &repositoryPath);
    virtual ~IDataRepository() = default;

    virtual std::unique_ptr<IStudentClass> read(
            size_t maxStudentCount,
            size_t maxGradesCount) = 0;
    virtual void write(const IStudentClass& studentClass) = 0;
    virtual bool exist() = 0;

    QString getPath();
private:
    const QString mRepositoryPath;
};

#endif // IDATAREPOSITORY_H
