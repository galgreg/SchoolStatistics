#ifndef TEXTFILESTORAGE_H
#define TEXTFILESTORAGE_H

#include "idatarepository.h"

class TextFileStorage : public IDataRepository
{
public:
    TextFileStorage(const std::string &filePath);

    IStudentClass *read(size_t maxStudentCount, size_t maxGradesCount) override;
    void write(IStudentClass *studentClass) override;
    bool exist() override;
};

#endif // TEXTFILESTORAGE_H
