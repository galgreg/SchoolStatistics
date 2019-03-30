#include "teststudentdatamanager.h"

TestStudentDataManager::TestStudentDataManager(
        unsigned &passed,
        unsigned &failed) : TestExecutionCounter(passed, failed) {

}
void TestStudentDataManager::cleanup() {
    if(QTest::currentTestFailed()) {
        incrementFailCounter();
    } else {
        incrementPassCounter();
    }
}
