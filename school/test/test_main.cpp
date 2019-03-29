#include <QtTest/QtTest>
#include "testidgenerator.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    TestIdGenerator testGenerator;
    return QTest::qExec(&testGenerator, argc, argv);
}
