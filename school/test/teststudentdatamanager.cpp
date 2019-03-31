#include "teststudentdatamanager.h"

TestStudentDataManager::TestStudentDataManager(
        unsigned &passed,
        unsigned &failed) :
            TestExecutionCounter(passed, failed),
            fileName("test_students.txt"),
            dataManager(nullptr) {

}

void TestStudentDataManager::init() {
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream outputStream(&file);
        outputStream << "Jan Kowalski M 5.0 4.5 3.0 4.0 5.0" << "\n";
        outputStream << "Maria Nowak F 4.0 3.5 5.0 3.0 4.0" << "\n";
        file.close();
    }
    dataManager = new StudentDataManager(fileName);
}

void TestStudentDataManager::cleanup() {
    if(QTest::currentTestFailed()) {
        incrementFailCounter();
    } else {
        incrementPassCounter();
    }

    delete dataManager;
    dataManager = nullptr;
    remove(qPrintable(fileName));
}

void TestStudentDataManager::testRead() {
    auto students = dataManager->read();
    const int expectedStudentsCount = 2;
    const int actualStudentsCount = students.size();
    QCOMPARE(actualStudentsCount, expectedStudentsCount);
    // auto firstStudent = students.at(0);
    // auto secondStudent = students.at(1);
}
