#ifndef TESTTEXTFILESTORAGE_H
#define TESTTEXTFILESTORAGE_H

#include "testexecutioncounter.h"
#include <QtTest>

class TestTextFileStorage : public QObject, public TestExecutionCounter
{
    Q_OBJECT

public:
    TestTextFileStorage(unsigned &passed, unsigned &failed);
private slots:
    void cleanup();
    void testDefaultState();
    void testRead_Error_NoSuchFile();
};

#endif // TESTTEXTFILESTORAGE_H
