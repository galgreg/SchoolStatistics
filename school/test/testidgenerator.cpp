#include "testidgenerator.h"
#include "idgenerator.h"

TestIdGenerator::TestIdGenerator(
        unsigned &passed,
        unsigned &failed) : TestExecutionCounter(passed, failed) {

}

void TestIdGenerator::testInstanceReturnsNotNull() {
    IDGenerator *generator = IDGenerator::instance();
    QVERIFY(generator != nullptr);
}

void TestIdGenerator::testInstanceIsAlwaysSame() {
    IDGenerator *generator1 = IDGenerator::instance();
    IDGenerator *generator2 = IDGenerator::instance();
    QCOMPARE(generator1, generator2);
}

void TestIdGenerator::testGeneratedValuesAreUnique() {
    IDGenerator *generator = IDGenerator::instance();
    unsigned value1 = generator->next();
    unsigned value2 = generator->next();
    QVERIFY(value1 != value2);
    QVERIFY(value1 < value2);
}

void TestIdGenerator::cleanup() {
    if(QTest::currentTestFailed()) {
        incrementFailCounter();
    } else {
        incrementPassCounter();
    }
}
