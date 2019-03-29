#include "testidgenerator.h"
#include "teststudent.h"
#include <QtTest/QtTest>

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    TestIdGenerator testGenerator;
    TestStudent testStudent;
    return QTest::qExec(&testGenerator, argc, argv) |
            QTest::qExec(&testStudent, argc, argv);
}
