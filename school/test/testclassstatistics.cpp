#include "testclassstatistics.h"
#include "istudentclass.h"
#include "studentclassmock.h"

TestClassStatistics::TestClassStatistics(
        unsigned &passed,
        unsigned &failed) : TestExecutionCounter(passed, failed) {
}

void TestClassStatistics::cleanup() {
    if (QTest::currentTestFailed()) {
        incrementFailCounter();
    } else {
        incrementPassCounter();
    }
}

void TestClassStatistics::testGetClassAverage() {
    const double expectedClassAverage = 4.0;
    ClassStatistics statistics;
    IStudentClass *studentClass = new StudentClassMock;
    const double actualClassAverage = statistics.getClassAverage(studentClass);
    QCOMPARE(actualClassAverage, expectedClassAverage);
}
