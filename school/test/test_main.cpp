#include <QtTest/QtTest>
#include "testgrades.h"
#include "testpersonaldata.h"
#include "teststudent.h"
#include "teststudentclass.h"
#include "testclassstatistics.h"
#include "testtextfilestorage.h"
#include "teststudentfactory.h"
#include "testmainwindow.h"
#include "testconfirmdialog.h"
#include "teststudentdatawindow.h"
#include "testsignaltransmitter.h"
#include "teststudentdataform.h"

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
    TestMainWindow testMainWindow(passedCounter, failedCounter);
    result |= QTest::qExec(&testMainWindow, argc, argv);
    TestConfirmDialog testConfirmDialog(passedCounter, failedCounter);
    result |= QTest::qExec(&testConfirmDialog, argc, argv);
    TestStudentDataWindow testStudentDataWindow(passedCounter, failedCounter);
    result |= QTest::qExec(&testStudentDataWindow, argc, argv);
    TestSignalTransmitter testSignalTransmitter(passedCounter, failedCounter);
    result |= QTest::qExec(&testSignalTransmitter, argc, argv);
    TestStudentDataForm testStudentDataForm(passedCounter, failedCounter);
    result |= QTest::qExec(&testStudentDataForm, argc, argv);

    qDebug() << QString("Totals: %1 passed, %2 failed.")
                .arg(passedCounter)
                .arg(failedCounter);
    return result;
}
