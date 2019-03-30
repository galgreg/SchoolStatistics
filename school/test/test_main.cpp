#include "testidgenerator.h"
#include "teststudent.h"
#include "teststudentinfo.h"
#include <QtTest/QtTest>

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    unsigned passedCounter = 0, failedCounter = 0;

    TestIdGenerator testGenerator(passedCounter, failedCounter);
    int result = QTest::qExec(&testGenerator, argc, argv);
    TestStudent testStudent(passedCounter, failedCounter);
    result |= QTest::qExec(&testStudent, argc, argv);
    TestStudentInfo testStudentInfo(passedCounter, failedCounter);
    result |= QTest::qExec(&testStudentInfo, argc, argv);

    qDebug() << QString("Totals: %1 passed, %2 failed.")
                .arg(passedCounter)
                .arg(failedCounter);
    return result;
}
