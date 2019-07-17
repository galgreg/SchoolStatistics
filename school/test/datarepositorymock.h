#ifndef DATAREPOSITORYMOCK_H
#define DATAREPOSITORYMOCK_H

#include "idatarepository.h"
#include "studentclass.h"
#include <memory>

class DataRepositoryMock : public IDataRepository
{
public:
    explicit DataRepositoryMock(
        const std::string &repositoryPath = "STUDENT_DATA_REPO_MOCK_PATH");
    std::unique_ptr<IStudentClass> read(
        size_t maxStudentCount,
        size_t maxGradesCount) override;
    void write(const IStudentClass& studentClass) override;
    bool exist() override;
private:
    StudentClass mStudentClass;
};

#endif // DATAREPOSITORYMOCK_H
