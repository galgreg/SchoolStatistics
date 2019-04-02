#include "testtextfilestorage.h"
#include "textfilestorage.h"
#include "studentclass.h"
#include "student.h"
#include "personaldata.h"
#include "grades.h"

TestTextFileStorage::TestTextFileStorage(
        unsigned &passed,
        unsigned &failed) : TestExecutionCounter(passed, failed) {

}

void TestTextFileStorage::init() {
    const QString filePath = QString::fromStdString(testFilePath);
    QFile file(filePath);

    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream outputStream(&file);
        outputStream << "1 Jan Kowalski MALE 5.0 4.5 4.0" << "\n";
        outputStream << "2 Maria Nowak FEMALE 4.0 3.5 3.0" << "\n";
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
    IStudent *expectedStudent_1 =
            makeStudent(1, "Jan", "Kowalski", MALE, {5.0, 4.5, 4.0});
    IStudent *expectedStudent_2 =
            makeStudent(2, "Maria", "Nowak", FEMALE, {4.0, 3.5, 3.0});

    const size_t maximumStudentsCount = 3;
    const size_t maximumGradesCount = 3;
    IStudentClass *expectedStudentClass =
            new StudentClass(maximumStudentsCount);

    expectedStudentClass->addStudent(expectedStudent_1);
    expectedStudentClass->addStudent(expectedStudent_2);

    TextFileStorage fileStorage(testFilePath);
    IStudentClass *actualStudentClass =
            fileStorage.read(maximumStudentsCount, maximumGradesCount);

    QVERIFY(actualStudentClass != nullptr);
    compareClasses(actualStudentClass, expectedStudentClass);
}

IStudent* TestTextFileStorage::makeStudent(
        unsigned ID,
        const std::string &firstName,
        const std::string &lastName,
        Gender gender,
        const std::vector<double> &grades) {
    IStudent *student = new Student(ID);
    IPersonalData *personalData =
            new PersonalData(firstName, lastName, gender);
    IGrades *studentGrades = new Grades(grades.size());

    for(auto grade : grades) {
        studentGrades->add(grade);
    }

    student->setPersonalData(personalData);
    student->setGrades(studentGrades);
    return student;
}

void TestTextFileStorage::compareClasses(
        IStudentClass *actualClass,
        IStudentClass *expectedClass) {
    QVERIFY(actualClass != nullptr);
    QVERIFY(expectedClass != nullptr);

    const size_t actualClassCount = actualClass->count();
    const size_t expectedClassCount = expectedClass->count();

    QCOMPARE(actualClassCount, expectedClassCount);

    for (size_t i = 0; i != actualClassCount; ++i) {
        compareStudents(
                actualClass->getStudent(i),
                expectedClass->getStudent(i));
    }
}

void TestTextFileStorage::compareStudents(
        IStudent *actualStudent,
        IStudent *expectedStudent) {
    QVERIFY(actualStudent != nullptr);
    QVERIFY(expectedStudent != nullptr);
    QCOMPARE(actualStudent->getID(), expectedStudent->getID());

    IPersonalData *actualPersonalData = actualStudent->getPersonalData();
    IPersonalData *expectedPersonalData = expectedStudent->getPersonalData();
    comparePersonalData(actualPersonalData, expectedPersonalData);

    IGrades *actualGrades = actualStudent->getGrades();
    IGrades *expectedGrades = expectedStudent->getGrades();
    compareGrades(actualGrades, expectedGrades);
}

void TestTextFileStorage::comparePersonalData(
        IPersonalData *actualPersonalData,
        IPersonalData *expectedPersonalData) {
    QVERIFY(actualPersonalData != nullptr);
    QVERIFY(expectedPersonalData != nullptr);

    QCOMPARE(
            actualPersonalData->getFirstName(),
            expectedPersonalData->getFirstName());
    QCOMPARE(
            actualPersonalData->getLastName(),
            expectedPersonalData->getLastName());
    QCOMPARE(
            actualPersonalData->getGender(),
                expectedPersonalData->getGender());
}

void TestTextFileStorage::compareGrades(
        IGrades *actualGrades,
        IGrades *expectedGrades) {
    QVERIFY(actualGrades != nullptr);
    QVERIFY(expectedGrades != nullptr);
    QCOMPARE(actualGrades->count(), expectedGrades->count());

    const size_t gradesCount = actualGrades->count();

    for (unsigned i = 0; i != gradesCount; ++i) {
        QCOMPARE(actualGrades->getGrade(i), expectedGrades->getGrade(i));
    }
}
