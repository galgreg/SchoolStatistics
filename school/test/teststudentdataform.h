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
    void testSetMaxGradesCount();
    void testAddGrade();
    void testAddGrade_CannotAddBecauseListIsFull();
    void testEditGrade();
    void testDeleteGrade();
    void testDeleteAllGrades();

    void testStudentNameValidation_data();
    void testStudentNameValidation();

    void testAddGradeToList_data();
    void testAddGradeToList();
    void testEditGradeOnGradesList_data();
    void testEditGradeOnGradesList();
    void testDeleteGradeFromGradesList();

private:
    QList<double> getGradesFromUiGradesList();

    std::unique_ptr<StudentDataForm> mStudentDataForm;
};

#endif // TESTSTUDENTDATAFORM_H
