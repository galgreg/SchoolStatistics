#ifndef TESTSTUDENTDATAFORM_H
#define TESTSTUDENTDATAFORM_H

#include "testexecutioncounter.h"
#include "studentdataform.h"
#include <QtTest>

class TestStudentDataForm : public QObject, public TestExecutionCounter {
    Q_OBJECT

public:
    TestStudentDataForm(unsigned &passed, unsigned &failed);

private slots:
    void init();
    void cleanup();
    void testShowAndHideForm();
    void testSetHeader();
    void testSetFirstName();
    void testSetLastName();
    void testSetGender_data();
    void testSetGender();
    void testAddGrade();
    void testEditGrade();
    void testDeleteGrade();
    void testDeleteAllGrades();

    void testStudentNameValidation_data();
    void testStudentNameValidation();
private:
    QList<double> getGradesFromUiGradesList();

    std::unique_ptr<StudentDataForm> mStudentDataForm;
};

#endif // TESTSTUDENTDATAFORM_H
