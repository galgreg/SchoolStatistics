#include "testgrades.h"

TestGrades::TestGrades(unsigned &passed, unsigned &failed) noexcept :
        TestExecutionCounter(passed, failed) {

}

void TestGrades::init() {
    grades.reset(new Grades);
}

void TestGrades::testDefaultState() noexcept {
    const size_t expectedInitialCount = 0;
    const size_t actualInitialCount = grades->count();
    QCOMPARE(actualInitialCount, expectedInitialCount);
}

void TestGrades::cleanup() noexcept {
    if (QTest::currentTestFailed()) {
        incrementFailCounter();
    } else {
        incrementPassCounter();
    }
}

void TestGrades::testAddGrade_OK() noexcept {
    const double expectedGrade = 5.0;
    grades->add(expectedGrade);

    const size_t expectedCount = 1;
    const size_t actualCount = grades->count();
    QCOMPARE(actualCount, expectedCount);

    const size_t whichGrade = 0;
    const double actualGrade = grades->getGrade(whichGrade);
    QCOMPARE(actualGrade, expectedGrade);
}

void TestGrades::testAddGrade_GradesOverflow() noexcept {
    const size_t maxCount = grades->maxAllowedCount();
    for (unsigned i = 0; i != maxCount; ++i) {
        grades->add(5.0);
    }
    QVERIFY_EXCEPTION_THROWN(grades->add(5.0), std::out_of_range);
}

void TestGrades::testRemoveGrade_OK() noexcept {
    grades->add(5.0);
    const size_t whichGrade = 0;
    grades->remove(whichGrade);

    const size_t expectedCount = 0;
    const size_t actualCount = grades->count();
    QCOMPARE(actualCount, expectedCount);
}

void TestGrades::testRemoveGrade_Error_NoSuchGrade() noexcept {
    const size_t whichGrade = 0;
    QVERIFY_EXCEPTION_THROWN(grades->remove(whichGrade), std::out_of_range);
}

void TestGrades::testEditGrade_OK() noexcept {
    const double expectedGradeBeforeEdit = 5.0;
    grades->add(expectedGradeBeforeEdit);
    const size_t whichGrade = 0;
    const double actualGradeBeforeEdit = grades->getGrade(whichGrade);
    QCOMPARE(actualGradeBeforeEdit, expectedGradeBeforeEdit);

    const double expectedGradeAfterEdit = 3.0;
    grades->edit(whichGrade, expectedGradeAfterEdit);
    const double actualGradeAfterEdit = grades->getGrade(whichGrade);
    QCOMPARE(actualGradeAfterEdit, expectedGradeAfterEdit);
}

void TestGrades::testEditGrade_Error_NoSuchGrade() noexcept {
    const size_t whichGrade = 2;
    const double newValue = 4.0;
    QVERIFY_EXCEPTION_THROWN(
            grades->edit(whichGrade, newValue),
            std::out_of_range);
}

