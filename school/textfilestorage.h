#ifndef TEXTFILESTORAGE_H
#define TEXTFILESTORAGE_H

#include "idatarepository.h"

class TextFileStorage : public IDataRepository
{
public:
    TextFileStorage(const std::string &filePath);

    IStudentClass *read() override;
    void write(IStudentClass *studentClass) override;
    bool exist() override;
};

#endif // TEXTFILESTORAGE_H
