#ifndef TESTIDGENERATOR_H
#define TESTIDGENERATOR_H

#include <QtTest>

class TestIdGenerator : public QObject
{
    Q_OBJECT

private slots:
    void testInstanceReturnsNotNull();
    void testInstanceIsAlwaysSame();
    void testGeneratedValuesAreUnique();
};

#endif // TESTIDGENERATOR_H
