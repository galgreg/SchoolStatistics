#include "testidgenerator.h"
#include "teststudent.h"
#include "teststudentinfo.h"
#include <QtTest/QtTest>

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    TestIdGenerator testGenerator;
    TestStudent testStudent;
    TestStudentInfo testStudentInfo;
    return QTest::qExec(&testGenerator, argc, argv) |
            QTest::qExec(&testStudent, argc, argv) |
            QTest::qExec(&testStudentInfo, argc, argv);
}
