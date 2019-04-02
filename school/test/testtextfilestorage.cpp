#include "testtextfilestorage.h"
#include "textfilestorage.h"

TestTextFileStorage::TestTextFileStorage(
        unsigned &passed,
        unsigned &failed) : TestExecutionCounter(passed, failed) {

}

void TestTextFileStorage::cleanup() {
    if (QTest::currentTestFailed()) {
        incrementFailCounter();
    } else {
        incrementPassCounter();
    }
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
    QVERIFY_EXCEPTION_THROWN(fileStorage.read(), std::ios_base::failure);
}
