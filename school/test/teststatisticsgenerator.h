#ifndef TESTSTATISTICSGENERATOR_H
#define TESTSTATISTICSGENERATOR_H

#include <QtTest>
#include "testexecutioncounter.h"
#include "statistics_generator.h"

class TestStatisticsGenerator : public QObject, public TestExecutionCounter
{
    Q_OBJECT

public:
    TestStatisticsGenerator(unsigned &passed, unsigned &failed);

private slots:
    void init();
    void cleanup();
    void testGetAverageForStudent();
    void testGetAverageOfWholeClass();
    void testGetInfoAboutStudent();
private:
    QList<StudentInterface*> students;
    StatisticsGenerator *generator;
};

#endif // TESTSTATISTICSGENERATOR_H
