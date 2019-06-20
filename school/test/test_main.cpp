#include <QtTest/QtTest>
#include "testgrades.h"
#include "testpersonaldata.h"
#include "teststudent.h"
#include "teststudentclass.h"
#include "testclassstatistics.h"
#include "testtextfilestorage.h"
#include "teststudentfactory.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    unsigned passedCounter = 0, failedCounter = 0;
    int result = 0;

    TestGrades testGrades(passedCounter, failedCounter);
    result |= QTest::qExec(&testGrades, argc, argv);
    TestPersonalData testPersonalData(passedCounter, failedCounter);
    result |= QTest::qExec(&testPersonalData, argc, argv);
    TestStudent testStudent(passedCounter, failedCounter);
    result |= QTest::qExec(&testStudent, argc, argv);
    TestStudentClass testStudentClass(passedCounter, failedCounter);
    result |= QTest::qExec(&testStudentClass, argc, argv);
    TestClassStatistics testClassStatistics(passedCounter, failedCounter);
    result |= QTest::qExec(&testClassStatistics, argc, argv);
    TestTextFileStorage testTextFileStorage(passedCounter, failedCounter);
    result |= QTest::qExec(&testTextFileStorage, argc, argv);
    TestStudentFactory testStudentFactory(passedCounter, failedCounter);
    result |= QTest::qExec(&testStudentFactory, argc, argv);
    qDebug() << QString("Totals: %1 passed, %2 failed.")
                .arg(passedCounter)
                .arg(failedCounter);
    return result;
}
