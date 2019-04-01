#include "teststudentclass.h"
#include "studentclass.h"
#include "studentmock.h"

TestStudentClass::TestStudentClass(
        unsigned &passed, unsigned &failed) :
    TestExecutionCounter(passed, failed) {
}

void TestStudentClass::cleanup() {
    if (QTest::currentTestFailed()) {
        incrementFailCounter();
    } else {
        incrementPassCounter();
    }
}

void TestStudentClass::testStateAfterInitialization() {
    const size_t expectedMaxCount = 20;
    const size_t expectedCount = 0;
    StudentClass actualClass(expectedMaxCount);
    QCOMPARE(actualClass.count(), expectedCount);
    QCOMPARE(actualClass.maxAllowedCount(), expectedMaxCount);
}

void TestStudentClass::testAddStudent_OK() {
    const size_t expectedMaxCount = 20;
    const size_t expectedCount = 1;
    StudentClass actualClass(expectedMaxCount);
    actualClass.addStudent(new StudentMock);
    QCOMPARE(actualClass.count(), expectedCount);
}

void TestStudentClass::testAddStudent_Error_ClassOverflow() {
    const size_t expectedCountBeforeOverflow = 2;
    StudentClass actualClass(expectedCountBeforeOverflow);

    for(size_t i = 0; i != expectedCountBeforeOverflow; ++i) {
        actualClass.addStudent(new StudentMock);
    }
    QCOMPARE(actualClass.count(), expectedCountBeforeOverflow);
    QVERIFY_EXCEPTION_THROWN(
            actualClass.addStudent(new StudentMock),
                std::out_of_range);
}

void TestStudentClass::testAddStudent_Error_NullPtrStudent() {
    const size_t expectedMaxCount = 2;
    StudentClass studentClass(expectedMaxCount);

    QVERIFY_EXCEPTION_THROWN(studentClass.addStudent(nullptr), std::bad_alloc);
}

void TestStudentClass::testRemoveStudent_OK() {
    const size_t maxAllowedCount = 20;
    const size_t expectedCountBeforeRemove = 1;
    StudentClass actualClass(maxAllowedCount);
    actualClass.addStudent(new StudentMock);
    QCOMPARE(actualClass.count(), expectedCountBeforeRemove);

    const size_t whichStudent = 0;
    actualClass.removeStudent(whichStudent);
    const size_t expectedCountAfterRemove = 0;
    QCOMPARE(actualClass.count(), expectedCountAfterRemove);
}

void TestStudentClass::testRemoveStudent_Error_NoSuchElement() {
    const size_t maxAllowedCount = 20;
    const size_t expectedCount = 5;
    StudentClass actualClass(maxAllowedCount);

    for (size_t i = 0; i != expectedCount; ++i) {
        actualClass.addStudent(new StudentMock);
    }

    const size_t whichStudentToRemove = 10;
    QVERIFY(actualClass.count() < whichStudentToRemove);
    QVERIFY_EXCEPTION_THROWN(
            actualClass.removeStudent(whichStudentToRemove),
                std::out_of_range);
}

void TestStudentClass::testGetStudent_OK() {
    const size_t maxAllowedCount = 20;
    StudentClass studentClass(maxAllowedCount);
    IStudent *expectedStudent = new StudentMock;
    studentClass.addStudent(expectedStudent);

    const size_t whichStudent = 0;
    IStudent *actualStudent = studentClass.getStudent(whichStudent);
    QCOMPARE(actualStudent, expectedStudent);
}

void TestStudentClass::testGetStudent_Error_NoSuchElement() {
    const size_t maxAllowedCount = 20;
    const size_t expectedCount = 0;
    StudentClass studentClass(maxAllowedCount);
    const size_t actualCount = studentClass.count();

    QCOMPARE(actualCount, expectedCount);
    const size_t whichStudent = 10;

    QVERIFY(actualCount < whichStudent);
    QVERIFY_EXCEPTION_THROWN(
            studentClass.getStudent(whichStudent),
                std::out_of_range);
}

void TestStudentClass::testEditStudent_OK() {
    const size_t maxAllowedCount = 20;
    StudentClass studentClass(maxAllowedCount);

    IStudent *expectedStudent_BeforeEdit = new StudentMock;
    studentClass.addStudent(expectedStudent_BeforeEdit);

    const size_t whichStudent = 0;
    IStudent *actualStudent_BeforeEdit = studentClass.getStudent(whichStudent);
    QCOMPARE(actualStudent_BeforeEdit, expectedStudent_BeforeEdit);

    IStudent *expectedStudent_AfterEdit = new StudentMock;
    studentClass.editStudent(whichStudent, expectedStudent_AfterEdit);
    IStudent *actualStudent_AfterEdit = studentClass.getStudent(whichStudent);
    QCOMPARE(actualStudent_AfterEdit, expectedStudent_AfterEdit);
    QVERIFY(actualStudent_AfterEdit != actualStudent_BeforeEdit);
}

void TestStudentClass::testEditStudent_Error_NoSuchElement() {
    const size_t maxAllowedCount = 20;
    StudentClass studentClass(maxAllowedCount);

    const size_t expectedCount = 0;
    const size_t actualCount = studentClass.count();
    QCOMPARE(actualCount, expectedCount);
    const size_t whichStudent = 10;
    QVERIFY(whichStudent > actualCount);

    IStudent *newStudent = new StudentMock;
    QVERIFY_EXCEPTION_THROWN(
            studentClass.editStudent(whichStudent, newStudent),
            std::out_of_range);
}

void TestStudentClass::testRemoveAll() {
    const size_t maxAllowedCount = 20;
    const size_t expectedCount_BeforeRemoveAll = maxAllowedCount;
    StudentClass studentClass(maxAllowedCount);

    for (size_t i = 0; i !=  expectedCount_BeforeRemoveAll; ++i) {
        studentClass.addStudent(new StudentMock);
    }
    const size_t actualCount_BeforeRemoveAll = studentClass.count();
    QCOMPARE(actualCount_BeforeRemoveAll, expectedCount_BeforeRemoveAll);

    const size_t expectedCount_AfterRemoveAll = 0;
    studentClass.removeAll();
    const size_t actualCount_AfterRemoveAll = studentClass.count();
    QCOMPARE(actualCount_AfterRemoveAll, expectedCount_AfterRemoveAll);
}

