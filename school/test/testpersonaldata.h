#ifndef TESTPERSONALDATA_H
#define TESTPERSONALDATA_H

#include "testexecutioncounter.h"
#include <QtTest>
#include "gender.h"
#include "personaldata.h"

class TestPersonalData : public QObject, public TestExecutionCounter
{
    Q_OBJECT
public:
    TestPersonalData(unsigned &passed, unsigned &failed);
private slots:
    void cleanup();
    void testGetters();
    void testSetters();
private:
    void testPersonalDataState(
            const PersonalData &actualPersonalData,
            const std::string &expectedFirstName,
            const std::string &expectedLastName,
            Gender expectedGender);
};

#endif // TESTPERSONALDATA_H
