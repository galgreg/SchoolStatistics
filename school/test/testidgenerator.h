#ifndef TESTIDGENERATOR_H
#define TESTIDGENERATOR_H

#include <QtTest/QtTest>

class TestIdGenerator : public QObject
{
    Q_OBJECT

private slots:
    void testStubPass();
    void testStubFail();
};

#endif // TESTIDGENERATOR_H
