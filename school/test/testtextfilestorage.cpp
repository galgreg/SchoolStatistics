#include "testtextfilestorage.h"
#include "textfilestorage.h"
#include "studentclass.h"
#include "student.h"
#include "personaldata.h"
#include "grades.h"
#include "studentfactory.h"

TestTextFileStorage::TestTextFileStorage(
        unsigned &passed,
        unsigned &failed) : TestExecutionCounter(passed, failed) {

}

void TestTextFileStorage::init() {
    const QString filePath = QString::fromStdString(testFilePath);
    QFile file(filePath);

    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream outputStream(&file);
        outputStream << "1 Jan Kowalski M 5.0 4.5 4.0" << " \n";
        outputStream << "2 Maria Nowak F 4.0 3.5 3.0" << " \n";
        file.close();
    }
}

void TestTextFileStorage::cleanup() {
    if (QTest::currentTestFailed()) {
        incrementFailCounter();
    } else {
        incrementPassCounter();
    }
    remove(testFilePath.c_str());
}

void TestTextFileStorage::testDefaultState() {
    const std::string expectedFilePath = "file.txt";
    TextFileStorage fileStorage(expectedFilePath);
    const std::string actualFilePath = fileStorage.getPath();
    QCOMPARE(actualFilePath, expectedFilePath);
}

void TestTextFileStorage::testRead_Error_NoSuchFile() {
    const std::string nonExistentFilePath = "nonExistent.txt";
    TextFileStorage fileStorage(nonExistentFilePath);
    bool expectedDoesFileExist = false;
    bool actualDoesFileExist = fileStorage.exist();
    QCOMPARE(actualDoesFileExist, expectedDoesFileExist);
    const size_t maxStudentCount = 1, maxGradesCount = 1;
    QVERIFY_EXCEPTION_THROWN(
            fileStorage.read(
                maxStudentCount, maxGradesCount), std::ios_base::failure);
}

void TestTextFileStorage::testRead_OK() {
    IStudent *expectedStudent_1 = StudentFactory::create(
            1, "Jan", "Kowalski", MALE, {5.0, 4.5, 4.0});

    IStudent *expectedStudent_2 = StudentFactory::create(
            2, "Maria", "Nowak", FEMALE, {4.0, 3.5, 3.0});

    const size_t maximumStudentsCount = 3;
    const size_t maximumGradesCount = 3;
    std::unique_ptr<IStudentClass> expectedStudentClass(
            new StudentClass(maximumStudentsCount));

    expectedStudentClass->addStudent(expectedStudent_1);
    expectedStudentClass->addStudent(expectedStudent_2);

    TextFileStorage fileStorage(testFilePath);
    std::unique_ptr<IStudentClass> actualStudentClass(
            fileStorage.read(
                maximumStudentsCount,
                maximumGradesCount));

    QVERIFY(actualStudentClass != nullptr);
    compareClasses(*actualStudentClass, *expectedStudentClass);
}

void TestTextFileStorage::compareClasses(
        const IStudentClass &actualClass,
        const IStudentClass &expectedClass) {
    const size_t actualClassCount = actualClass.count();
    const size_t expectedClassCount = expectedClass.count();

    QCOMPARE(actualClassCount, expectedClassCount);

    for (size_t i = 0; i != actualClassCount; ++i) {
        QCOMPARE(actualClass.getStudent(i), expectedClass.getStudent(i));
    }
}
