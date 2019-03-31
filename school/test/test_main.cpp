#include <QtTest/QtTest>

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    unsigned passedCounter = 0, failedCounter = 0;
    int result = 0;

    qDebug() << QString("Totals: %1 passed, %2 failed.")
                .arg(passedCounter)
                .arg(failedCounter);
    return result;
}
