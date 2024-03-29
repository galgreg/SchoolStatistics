#ifndef TESTSTUDENTCLASS_H
#define TESTSTUDENTCLASS_H

#include "testexecutioncounter.h"
#include <QtTest>

class TestStudentClass : public QObject, TestExecutionCounter
{
    Q_OBJECT

public:
    TestStudentClass(unsigned &passed, unsigned &failed);
private slots:
    void cleanup();
    void testStateAfterInitialization();
    void testAddStudent_OK();
    void testAddStudent_Error_ClassOverflow();
    void testAddStudent_Error_NullPtrStudent();
    void testRemoveStudent_OK();
    void testRemoveStudent_Error_NoSuchElement();
    void testGetStudent_OK();
    void testGetStudent_Error_NoSuchElement();
    void testEditStudent_OK();
    void testEditStudent_Error_NoSuchElement();
    void testEditStudent_Error_NullPtrStudent();
    void testRemoveAll();
};

#endif // TESTSTUDENTCLASS_H
