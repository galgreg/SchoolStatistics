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

void TestStudentClass::testAddStudent() {
    const size_t expectedMaxCount = 20;
    const size_t expectedCount = 1;
    StudentClass actualClass(expectedMaxCount);
    actualClass.addStudent(new StudentMock);
    QCOMPARE(actualClass.count(), expectedCount);
}

