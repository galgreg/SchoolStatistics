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
    const unsigned expectedCountBeforeAdd = 0;
    const unsigned actualCountBeforeAdd = grades->count();
    QCOMPARE(actualCountBeforeAdd, expectedCountBeforeAdd);

    const double expectedGrade = 5.0;
    grades->add(expectedGrade);

    const unsigned expectedCountAfterAdd = 1;
    const unsigned actualCountAfterAdd = grades->count();
    QCOMPARE(actualCountAfterAdd, expectedCountAfterAdd);

    const double actualGrade = grades->getGrade(0);
    QCOMPARE(actualGrade, expectedGrade);
}
