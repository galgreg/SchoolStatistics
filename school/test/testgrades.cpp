#include "testgrades.h"

TestGrades::TestGrades(unsigned &passed, unsigned &failed) :
        TestExecutionCounter(passed, failed) {

}

void TestGrades::init() {
    grades.reset(new Grades);
}

void TestGrades::cleanup() {
    if (QTest::currentTestFailed()) {
        incrementFailCounter();
    } else {
        incrementPassCounter();
    }
}

void TestGrades::testAddGrade_OK() {
    const size_t expectedCountBeforeAdd = 0;
    const size_t actualCountBeforeAdd = grades->count();
    QCOMPARE(actualCountBeforeAdd, expectedCountBeforeAdd);

    const double expectedGrade = 5.0;
    grades->add(expectedGrade);

    const size_t expectedCountAfterAdd = 1;
    const size_t actualCountAfterAdd = grades->count();
    QCOMPARE(actualCountAfterAdd, expectedCountAfterAdd);

    const double actualGrade = grades->getGrade(0);
    QCOMPARE(actualGrade, expectedGrade);
}

void TestGrades::testAddGrade_GradesOverflow() {
    const size_t maxCount = grades->maxAllowedCount();
    for (unsigned i = 0; i != maxCount; ++i) {
        grades->add(5.0);
    }
    QVERIFY_EXCEPTION_THROWN(grades->add(5.0), std::out_of_range);
}
