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
};

#endif // TESTTEXTFILESTORAGE_H
