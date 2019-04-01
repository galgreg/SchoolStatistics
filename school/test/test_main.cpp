#include <QtTest/QtTest>
#include "testgrades.h"
#include "testpersonaldata.h"
#include "teststudent.h"

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
    qDebug() << QString("Totals: %1 passed, %2 failed.")
                .arg(passedCounter)
                .arg(failedCounter);
    return result;
}
