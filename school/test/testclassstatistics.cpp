#include "testclassstatistics.h"
#include "istudentclass.h"
#include "studentclassmock.h"
#include "classstatistics.h"

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

void TestClassStatistics::testGetStudentAverage() {
    const double expectedStudentAverage = 4.0;
    ClassStatistics statistics;
    std::unique_ptr<IStudentClass> studentClass(new StudentClassMock);

    const size_t whichStudent = 3;
    const double actualStudentAverage =
            statistics.getStudentAverage(*studentClass, whichStudent);
    QCOMPARE(actualStudentAverage, expectedStudentAverage);
}

void TestClassStatistics::testGetClassAverage() {
    const double expectedClassAverage = 4.0;
    ClassStatistics statistics;
    std::unique_ptr<IStudentClass> studentClass(new StudentClassMock);
    const double actualClassAverage = statistics.getClassAverage(*studentClass);
    QCOMPARE(actualClassAverage, expectedClassAverage);
}
