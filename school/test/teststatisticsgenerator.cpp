#include "teststatisticsgenerator.h"
#include "studentmock.h"

TestStatisticsGenerator::TestStatisticsGenerator(
        unsigned &passed,
        unsigned &failed) : TestExecutionCounter(passed, failed) {

}

void TestStatisticsGenerator::init() {
    for (unsigned i = 0; i != 3; ++i) {
        students.push_back(new StudentMock);
    }
    generator = new StatisticsGenerator(students);
}

void TestStatisticsGenerator::cleanup() {
    if(QTest::currentTestFailed()) {
        incrementFailCounter();
    } else {
        incrementPassCounter();
    }
    delete generator;
    generator = nullptr;

    for (auto student : students) {
        delete student;
    }
    students.clear();
}

void TestStatisticsGenerator::testGetAverageForStudent() {
    const double expectedAverage = 5.0;
    const double actualAverage = generator->getAverageForStudent(1);
    QCOMPARE(actualAverage, expectedAverage);
}

void TestStatisticsGenerator::testGetAverageOfWholeClass() {
    const double expectedAverage = 5.0;
    const double actualAverage = generator->getAverageOfWholeClass();
    QCOMPARE(actualAverage, expectedAverage);
}

void TestStatisticsGenerator::testGetInfoAboutStudent() {
    StudentInfo expectedInfo(1, "Jan Kowalski", MALE);
    auto actualInfo = generator->getInfoAboutStudent(2);
    QCOMPARE(actualInfo->hisID, expectedInfo.hisID);
    QCOMPARE(actualInfo->hisFullName, expectedInfo.hisFullName);
    QCOMPARE(actualInfo->hisGender, expectedInfo.hisGender);
}
