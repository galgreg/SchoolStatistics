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
private:
    std::unique_ptr<StudentDataForm> mStudentDataForm;
};

#endif // TESTSTUDENTDATAFORM_H
