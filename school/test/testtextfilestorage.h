#ifndef TESTTEXTFILESTORAGE_H
#define TESTTEXTFILESTORAGE_H

#include "testexecutioncounter.h"
#include <QtTest>
#include "istudentclass.h"

class TestTextFileStorage : public QObject, public TestExecutionCounter
{
    Q_OBJECT

public:
    TestTextFileStorage(unsigned &passed, unsigned &failed);
private slots:
    void init();
    void cleanup();
    void testDefaultState();
    void testRead_Error_NoSuchFile();
    void testRead_OK();
private:
    IStudent* makeStudent(
        unsigned ID,
        const std::string &firstName,
        const std::string &lastName,
        Gender gender,
        const std::vector<double> &grades);
    void compareClasses(
        IStudentClass *actualClass,
        IStudentClass *expectedClass);
    void compareStudents(IStudent *actualStudent, IStudent *expectedStudent);
    void comparePersonalData(
        IPersonalData *actualPersonalData,
        IPersonalData *expectedPersonalData);
    void compareGrades(IGrades *actualGrades, IGrades *expectedGrades);

    const std::string testFilePath = "testFile.txt";
};

#endif // TESTTEXTFILESTORAGE_H
