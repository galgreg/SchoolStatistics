#include "testclassstatistics.h"
#include "istudentclass.h"
#include "studentclassmock.h"
#include "classstatistics.h"

TestClassStatistics::TestClassStatistics(
        unsigned &passed,
        unsigned &failed) noexcept : TestExecutionCounter(passed, failed) {
}

void TestClassStatistics::cleanup() noexcept {
    if (QTest::currentTestFailed()) {
        incrementFailCounter();
    } else {
        incrementPassCounter();
    }
}

void TestClassStatistics::testGetStudentAverage() noexcept {
    const double expectedStudentAverage = 4.0;
    std::unique_ptr<IStudentClass> studentClass(
            new StudentClassMock({3.5, 4.0, 4.5}));

    const size_t whichStudent = 3;
    const double actualStudentAverage =
            ClassStatistics::getStudentAverage(*studentClass, whichStudent);
    QCOMPARE(actualStudentAverage, expectedStudentAverage);
}

void TestClassStatistics::testGetStudentAverage_NoGrades() noexcept {
    const double expectedStudentAverage = 0.0;
    auto studentClass = std::make_unique<StudentClassMock>();

    const size_t whichStudent = 3;
    const double actualStudentAverage =
            ClassStatistics::getStudentAverage(*studentClass, whichStudent);
    QCOMPARE(actualStudentAverage, expectedStudentAverage);
}

void TestClassStatistics::testGetClassAverage() noexcept {
    const double expectedClassAverage = 4.0;
    std::unique_ptr<IStudentClass> studentClass(
            new StudentClassMock({3.5, 4.0, 4.5}));
    const double actualClassAverage =
            ClassStatistics::getClassAverage(*studentClass);
    QCOMPARE(actualClassAverage, expectedClassAverage);
}

void TestClassStatistics::testGetClassAverage_EmptyClass() noexcept {
    const double expectedClassAverage = 0.0;
     auto studentClass = std::make_unique<StudentClassMock>();
     studentClass->removeAll();
     const double actualClassAverage =
             ClassStatistics::getClassAverage(*studentClass);
     QCOMPARE(actualClassAverage, expectedClassAverage);
}
