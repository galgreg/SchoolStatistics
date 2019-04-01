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

