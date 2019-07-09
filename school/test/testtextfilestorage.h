#ifndef TESTTEXTFILESTORAGE_H
#define TESTTEXTFILESTORAGE_H

#include "testexecutioncounter.h"
#include <QtTest>
#include "istudentclass.h"

class TestTextFileStorage : public QObject, public TestExecutionCounter
{
    Q_OBJECT

public:
    TestTextFileStorage(unsigned &passed, unsigned &failed);
private slots:
    void init();
    void cleanup();
    void testDefaultState();
    void testRead_Error_NoSuchFile();
    void testRead_OK();
private:
    void compareClasses(
        const IStudentClass &actualClass,
        const IStudentClass &expectedClass);

    const std::string testFilePath = "testFile.txt";
};

#endif // TESTTEXTFILESTORAGE_H
