#include "testmainwindow.h"
#include "confirmdialogmock.h"
#include "datarepositorymock.h"
#include "studentclass.h"
#include "studentdataformmock.h"
#include "studentdatawidgetmock.h"
#include "studentfactory.h"
#include "ui_mainwindow.h"

TestMainWindow::TestMainWindow(
        unsigned &passed,
        unsigned &failed) :
                TestExecutionCounter(passed, failed),
                mMainWindow(nullptr),
                mStudentClassData(nullptr) {

}

TestMainWindow::~TestMainWindow() {
    QFile testFile(mPathToTestRepository);
    if (testFile.exists()) {
        testFile.remove();
    }
}

void TestMainWindow::init() {
    mStudentClassData.reset(new StudentClass);
    mStudentClassData->addStudent(StudentFactory::create(
            1, "Jan", "Kowalski", MALE, {5.0, 3.0, 4.0}));
    mStudentClassData->addStudent(StudentFactory::create(
            2, "Maria", "Nowak", FEMALE, {3.0, 3.0, 3.0}));
    mStudentClassData->addStudent(StudentFactory::create(
            3, "Gal", "Anonim", UNKNOWN, {2.0, 2.0, 2.0}));

    std::unique_ptr<IDataRepository> dataRepository(new DataRepositoryMock);
    dataRepository->write(*mStudentClassData);

    mMainWindow.reset(
            new MainWindow(
                    std::move(dataRepository),
                    std::make_unique<StudentDataWidgetMock>(),
                    std::make_unique<ConfirmDialogMock>(),
                    std::make_unique<StudentDataFormMock>(),
                    std::make_shared<SignalTransmitter>()));
}

void TestMainWindow::cleanup() {
    if (QTest::currentTestFailed()) {
        incrementFailCounter();
    } else {
        incrementPassCounter();
    }
}

void TestMainWindow::testInitialState_WhenRepositoryIsEmpty() {
    std::unique_ptr<MainWindow> tempWindow(
            new MainWindow(
                std::make_unique<DataRepositoryMock>(),
                std::make_unique<StudentDataWidgetMock>(),
                std::make_unique<ConfirmDialogMock>(),
                std::make_unique<StudentDataFormMock>(),
                std::make_shared<SignalTransmitter>()));

    unsigned expectedInitialNextStudentID = 1;
    unsigned actualInitialNextStudentID = tempWindow->mNextStudentID;
    QCOMPARE(actualInitialNextStudentID, expectedInitialNextStudentID);
}

void TestMainWindow::testMaxCounts_Default() {
    std::unique_ptr<MainWindow> tempWindow(
            new MainWindow(
                std::make_unique<DataRepositoryMock>(),
                std::make_unique<StudentDataWidgetMock>(),
                std::make_unique<ConfirmDialogMock>(),
                std::make_unique<StudentDataFormMock>(),
                std::make_shared<SignalTransmitter>()));

    size_t expectedStudentMaxCount = 20;
    size_t actualStudentMaxCount = tempWindow->mMaxStudentCount;
    QCOMPARE(actualStudentMaxCount, expectedStudentMaxCount);

    size_t expectedGradesMaxCount = 3;
    size_t actualGradesMaxCount_1 = tempWindow->mMaxGradesCount;
    QCOMPARE(actualGradesMaxCount_1, expectedGradesMaxCount);

    size_t actualGradesMaxCount_2 =
            tempWindow->mStudentDataForm->getMaxGradesCount();
    QCOMPARE(actualGradesMaxCount_2, expectedGradesMaxCount);
}

void TestMainWindow::testMaxCounts_SetValues() {
    size_t windowStudentMaxCount = 13;
    size_t windowGradesMaxCount = 5;

    std::unique_ptr<MainWindow> tempWindow(
            new MainWindow(
                std::make_unique<DataRepositoryMock>(),
                std::make_unique<StudentDataWidgetMock>(),
                std::make_unique<ConfirmDialogMock>(),
                std::make_unique<StudentDataFormMock>(),
                std::make_shared<SignalTransmitter>(),
                windowStudentMaxCount,
                windowGradesMaxCount));

    size_t expectedStudentMaxCount = windowStudentMaxCount;
    size_t actualStudentMaxCount = tempWindow->mMaxStudentCount;
    QCOMPARE(actualStudentMaxCount, expectedStudentMaxCount);

    size_t expectedGradesMaxCount = windowGradesMaxCount;
    size_t actualGradesMaxCount_1 = tempWindow->mMaxGradesCount;
    QCOMPARE(actualGradesMaxCount_1, expectedGradesMaxCount);

    size_t actualGradesMaxCount_2 =
            tempWindow->mStudentDataForm->getMaxGradesCount();
    QCOMPARE(actualGradesMaxCount_2, expectedGradesMaxCount);
}

void TestMainWindow::testReadDataFromRepository() {
    mMainWindow->readDataFromRepository();
    const IStudentClass& expectedStudentClass = *mStudentClassData;
    const IStudentClass& actualStudentClass = *mMainWindow->mStudentClass;

    QCOMPARE(actualStudentClass, expectedStudentClass);

    QString expectedStudentNumberValueText = "3";
    QString actualStudentNumberValueText =
            mMainWindow->ui->studentsNumberValue->text();
    QCOMPARE(actualStudentNumberValueText, expectedStudentNumberValueText);

    QString expectedClassAverageValue = "3.0";
    QString actualClassAverageValue =
            mMainWindow->ui->classAverageValue->text();
    QCOMPARE(actualClassAverageValue, expectedClassAverageValue);

    QList<QString> expectedStudentListContent =
            {"Jan Kowalski", "Maria Nowak", "Gal Anonim"};
    QList<QString> actualStudentListContent;
    const auto& studentList = *(mMainWindow->ui->studentList);

    for (int i = 0; i < studentList.count(); ++i) {
        const auto& item = studentList.item(i);
        actualStudentListContent.append(item->text());
    }
    QCOMPARE(actualStudentListContent, expectedStudentListContent);

    unsigned expectedNextStudentID =
            mStudentClassData->getStudent(2).getID() + 1;
    unsigned actualNextStudentID = mMainWindow->mNextStudentID;
    QCOMPARE(actualNextStudentID, expectedNextStudentID);
}

void TestMainWindow::testDeleteStudent() {
    size_t studentIndex = 1;
    const auto& expectedStudentClassBeforeDelete = *mStudentClassData;
    const auto& actualStudentClassBeforeDelete = *mMainWindow->mStudentClass;
    QCOMPARE(actualStudentClassBeforeDelete, expectedStudentClassBeforeDelete);

    mStudentClassData->removeStudent(studentIndex);
    mMainWindow->deleteStudent(studentIndex);

    const auto& expectedStudentClassAfterDelete = *mStudentClassData;
    const auto& actualStudentClassAfterDelete = *mMainWindow->mStudentClass;
    QCOMPARE(actualStudentClassAfterDelete, expectedStudentClassAfterDelete);
}

void TestMainWindow::testPrepareStudentDataWidgetToDisplay() {
    size_t studentIndex = 1;
    mMainWindow->prepareStudentDataWidgetToDisplay(studentIndex);
    QString expectedStudentID = "2";
    QString actualStudentID = mMainWindow->mStudentDataWidget->getID();
    QCOMPARE(actualStudentID, expectedStudentID);

    QString expectedFirstName = "Maria";
    QString actualFirstName = mMainWindow->mStudentDataWidget->getFirstName();
    QCOMPARE(actualFirstName, expectedFirstName);

    QString expectedLastName = "Nowak";
    QString actualLastName = mMainWindow->mStudentDataWidget->getLastName();
    QCOMPARE(actualLastName, expectedLastName);

    QString expectedGender = "Female";
    QString actualGender = mMainWindow->mStudentDataWidget->getGender();
    QCOMPARE(actualGender, expectedGender);

    QString expectedGrades = "3.0, 3.0, 3.0";
    QString actualGrades = mMainWindow->mStudentDataWidget->getGrades();
    QCOMPARE(actualGrades, expectedGrades);

    QString expectedGradesAverage = "3.0";
    QString actualGradesAverage =
            mMainWindow->mStudentDataWidget->getGradesAverage();
    QCOMPARE(actualGradesAverage, expectedGradesAverage);
}

void TestMainWindow::testDoAction_DeleteStudent() {
    size_t studentIndex = 1;
    mMainWindow->ui->studentList->setCurrentRow(static_cast<int>(studentIndex));

    const auto& expectedStudentClassBeforeDelete = *mStudentClassData;
    const auto& actualStudentClassBeforeDelete = *mMainWindow->mStudentClass;
    QCOMPARE(actualStudentClassBeforeDelete, expectedStudentClassBeforeDelete);

    mStudentClassData->removeStudent(studentIndex);
    mMainWindow->doAction(DELETE_STUDENT);

    const auto& expectedStudentClassAfterDelete = *mStudentClassData;
    const auto& actualStudentClassAfterDelete = *mMainWindow->mStudentClass;
    QCOMPARE(actualStudentClassAfterDelete, expectedStudentClassAfterDelete);
}

void TestMainWindow::testDoAction_AddStudent() {
    unsigned expectedStudentIdBeforeAdd = 4;
    QString firstName = "Jack";
    mMainWindow->mStudentDataForm->setFirstName(firstName);
    QString lastName = "Stone";
    mMainWindow->mStudentDataForm->setLastName(lastName);
    Gender studentGender = MALE;
    mMainWindow->mStudentDataForm->setGender(studentGender);
    std::vector<double> studentGrades = {4.0, 5.0, 3.0};
    for (auto grade : studentGrades) {
        mMainWindow->mStudentDataForm->addGrade(grade);
    }

    mMainWindow->doAction(ADD_STUDENT);

    size_t expectedStudentClassCount = 4;
    size_t actualStudentClassCount_1 = mMainWindow->mStudentClass->count();
    QCOMPARE(expectedStudentClassCount, actualStudentClassCount_1);

    size_t actualStudentClassCount_2 =
            static_cast<size_t>(mMainWindow->ui->studentList->count());
    QCOMPARE(expectedStudentClassCount, actualStudentClassCount_2);

    size_t actualStudentClassCount_3 =
            mMainWindow->ui->studentsNumberValue->text().toUInt();
    QCOMPARE(expectedStudentClassCount, actualStudentClassCount_3);

    std::unique_ptr<IStudent> expectedNewStudent(
                StudentFactory::create(
                        expectedStudentIdBeforeAdd,
                        firstName.toStdString(),
                        lastName.toStdString(),
                        studentGender,
                        studentGrades));
    const IStudent& actualNewStudent = mMainWindow->mStudentClass->getStudent(3);
    QCOMPARE(actualNewStudent, *expectedNewStudent);

    unsigned expectedNextStudentIdAfterAdd = expectedStudentIdBeforeAdd + 1;
    unsigned actualNextStudentIdAfterAdd = mMainWindow->mNextStudentID;
    QCOMPARE(actualNextStudentIdAfterAdd, expectedNextStudentIdAfterAdd);
}

void TestMainWindow::testDoAction_EditStudent() {
    size_t indexOfStudentToEdit = 1;

    const auto& expectedStudentBeforeEdit =
            mStudentClassData->getStudent(indexOfStudentToEdit);
    const auto& actualStudentBeforeEdit =
            mMainWindow->mStudentClass->getStudent(indexOfStudentToEdit);
    QCOMPARE(actualStudentBeforeEdit, expectedStudentBeforeEdit);

    mMainWindow->ui->studentList->setCurrentRow(
            static_cast<int>(indexOfStudentToEdit));

    const auto& studentToEdit =
            mMainWindow->mStudentClass->getStudent(indexOfStudentToEdit);

    QString newFirstName = "Konstancja";
    mMainWindow->mStudentDataForm->setFirstName(newFirstName);
    QString newLastName = "Nowakowska";
    mMainWindow->mStudentDataForm->setLastName(newLastName);
    Gender studentGender = studentToEdit.getPersonalData().getGender();
    mMainWindow->mStudentDataForm->setGender(studentGender);

    mMainWindow->mStudentDataForm->deleteAllGrades();
    const auto& studentGrades = studentToEdit.getGrades();
    for (unsigned i = 0; i < studentGrades.count(); ++i) {
        mMainWindow->mStudentDataForm->addGrade(studentGrades.getGrade(i));
    }

    mMainWindow->doAction(EDIT_STUDENT);

    std::unique_ptr<IStudent> expectedStudentAfterEdit(
            StudentFactory::copy(
                    mStudentClassData->getStudent(indexOfStudentToEdit)));

    std::unique_ptr<IPersonalData> newPersonalData(
            new PersonalData(
                    newFirstName.toStdString(),
                    newLastName.toStdString(),
                    studentGender));
    expectedStudentAfterEdit->setPersonalData(*newPersonalData);

    const auto& actualStudentAfterEdit =
            mMainWindow->mStudentClass->getStudent(indexOfStudentToEdit);
    QCOMPARE(actualStudentAfterEdit, *expectedStudentAfterEdit);
}

void TestMainWindow::testDoDeleteAction() {
    size_t studentIndex = 1;
    mMainWindow->ui->studentList->setCurrentRow(static_cast<int>(studentIndex));

    const auto& expectedStudentClassBeforeDelete = *mStudentClassData;
    const auto& actualStudentClassBeforeDelete = *mMainWindow->mStudentClass;
    QCOMPARE(actualStudentClassBeforeDelete, expectedStudentClassBeforeDelete);

    mStudentClassData->removeStudent(studentIndex);
    mMainWindow->doDeleteAction();

    const auto& expectedStudentClassAfterDelete = *mStudentClassData;
    const auto& actualStudentClassAfterDelete = *mMainWindow->mStudentClass;
    QCOMPARE(actualStudentClassAfterDelete, expectedStudentClassAfterDelete);
}

void TestMainWindow::testDoAddAction() {
    unsigned expectedStudentIdBeforeAdd = 4;
    QString firstName = "Jack";
    mMainWindow->mStudentDataForm->setFirstName(firstName);
    QString lastName = "Stone";
    mMainWindow->mStudentDataForm->setLastName(lastName);
    Gender studentGender = MALE;
    mMainWindow->mStudentDataForm->setGender(studentGender);
    std::vector<double> studentGrades = {4.0, 5.0, 3.0};
    for (auto grade : studentGrades) {
        mMainWindow->mStudentDataForm->addGrade(grade);
    }

    mMainWindow->doAddAction();

    size_t expectedStudentClassCount = 4;
    size_t actualStudentClassCount_1 = mMainWindow->mStudentClass->count();
    QCOMPARE(expectedStudentClassCount, actualStudentClassCount_1);

    size_t actualStudentClassCount_2 =
            static_cast<size_t>(mMainWindow->ui->studentList->count());
    QCOMPARE(expectedStudentClassCount, actualStudentClassCount_2);

    size_t actualStudentClassCount_3 =
            mMainWindow->ui->studentsNumberValue->text().toUInt();
    QCOMPARE(expectedStudentClassCount, actualStudentClassCount_3);

    std::unique_ptr<IStudent> expectedNewStudent(
                StudentFactory::create(
                        expectedStudentIdBeforeAdd,
                        firstName.toStdString(),
                        lastName.toStdString(),
                        studentGender,
                        studentGrades));
    const IStudent& actualNewStudent = mMainWindow->mStudentClass->getStudent(3);
    QCOMPARE(actualNewStudent, *expectedNewStudent);

    unsigned expectedNextStudentIdAfterAdd = expectedStudentIdBeforeAdd + 1;
    unsigned actualNextStudentIdAfterAdd = mMainWindow->mNextStudentID;
    QCOMPARE(actualNextStudentIdAfterAdd, expectedNextStudentIdAfterAdd);
}

void TestMainWindow::testDoEditAction() {
    size_t indexOfStudentToEdit = 1;

    const auto& expectedStudentBeforeEdit =
            mStudentClassData->getStudent(indexOfStudentToEdit);
    const auto& actualStudentBeforeEdit =
            mMainWindow->mStudentClass->getStudent(indexOfStudentToEdit);
    QCOMPARE(actualStudentBeforeEdit, expectedStudentBeforeEdit);

    mMainWindow->ui->studentList->setCurrentRow(
            static_cast<int>(indexOfStudentToEdit));

    const auto& studentToEdit =
            mMainWindow->mStudentClass->getStudent(indexOfStudentToEdit);

    QString newFirstName = "Konstancja";
    mMainWindow->mStudentDataForm->setFirstName(newFirstName);
    QString newLastName = "Nowakowska";
    mMainWindow->mStudentDataForm->setLastName(newLastName);
    Gender studentGender = studentToEdit.getPersonalData().getGender();
    mMainWindow->mStudentDataForm->setGender(studentGender);

    mMainWindow->mStudentDataForm->deleteAllGrades();
    const auto& studentGrades = studentToEdit.getGrades();
    for (unsigned i = 0; i < studentGrades.count(); ++i) {
        mMainWindow->mStudentDataForm->addGrade(studentGrades.getGrade(i));
    }

    mMainWindow->doEditAction();

    std::unique_ptr<IStudent> expectedStudentAfterEdit(
            StudentFactory::copy(
                    mStudentClassData->getStudent(indexOfStudentToEdit)));

    std::unique_ptr<IPersonalData> newPersonalData(
            new PersonalData(
                    newFirstName.toStdString(),
                    newLastName.toStdString(),
                    studentGender));
    expectedStudentAfterEdit->setPersonalData(*newPersonalData);

    const auto& actualStudentAfterEdit =
            mMainWindow->mStudentClass->getStudent(indexOfStudentToEdit);
    QCOMPARE(actualStudentAfterEdit, *expectedStudentAfterEdit);
}

void TestMainWindow::testBeginFormTransaction_AddStudent() {
    QString firstName = "Jan";
    mMainWindow->mStudentDataForm->setFirstName(firstName);
    QString lastName = "Kowalski";
    mMainWindow->mStudentDataForm->setLastName(lastName);

    mMainWindow->beginFormTransaction(ADD_STUDENT);

    QString expectedActionString = "add";
    QString actualActionString =
            mMainWindow->mConfirmDialog->getCurrentActionString();
    QCOMPARE(actualActionString, expectedActionString);

    QString expectedStudentName = QString("%1 %2").arg(firstName).arg(lastName);
    QString actualStudentName =
            mMainWindow->mConfirmDialog->getCurrentStudentName();
    QCOMPARE(actualStudentName, expectedStudentName);
}

void TestMainWindow::testPrepareStudentDataFormToDisplay_AddStudent() {
    StudentDataAction actionToPerform = ADD_STUDENT;
    mMainWindow->prepareStudentDataFormToDisplay(actionToPerform);

    StudentDataAction expectedFormAction = actionToPerform;
    StudentDataAction actualFormAction =
            mMainWindow->mStudentDataForm->getFormAction();
    QCOMPARE(actualFormAction, expectedFormAction);

    QString expectedHeader = "Add Student";
    QString actualHeader = mMainWindow->mStudentDataForm->getHeader();
    QCOMPARE(actualHeader, expectedHeader);

    QString expectedFirstName = "";
    QString actualFirstName = mMainWindow->mStudentDataForm->getFirstName();
    QCOMPARE(actualFirstName, expectedFirstName);

    QString expectedLastName = "";
    QString actualLastName = mMainWindow->mStudentDataForm->getLastName();
    QCOMPARE(actualLastName, expectedLastName);

    Gender expectedGender = UNKNOWN;
    Gender actualGender = mMainWindow->mStudentDataForm->getGender();
    QCOMPARE(actualGender, expectedGender);

    QList<double> expectedGrades = {};
    QList<double> actualGrades = mMainWindow->mStudentDataForm->getGrades();
    QCOMPARE(actualGrades, expectedGrades);
}

void TestMainWindow::testPrepareStudentDataFormToDisplay_EditStudent() {
    mMainWindow->ui->studentList->setCurrentRow(1);
    StudentDataAction actionToPerform = EDIT_STUDENT;
    mMainWindow->prepareStudentDataFormToDisplay(actionToPerform);

    StudentDataAction expectedFormAction = actionToPerform;
    StudentDataAction actualFormAction =
            mMainWindow->mStudentDataForm->getFormAction();
    QCOMPARE(actualFormAction, expectedFormAction);

    QString expectedFormHeader =
            "<html><head/><body><p align=\"center\">"
            "<span style=\" font-size:16pt; font-weight:600; color:#ef2929;\">"
            "Edit Student</span></p></body></html>";
    QString actualFormHeader = mMainWindow->mStudentDataForm->getHeader();

    const auto& studentToEdit = mStudentClassData->getStudent(1);

    std::string expectedFirstName =
            studentToEdit.getPersonalData().getFirstName();
    std::string actualFirstName =
            mMainWindow->mStudentDataForm->getFirstName().toStdString();
    QCOMPARE(actualFirstName, expectedFirstName);

    std::string expectedLastName =
            studentToEdit.getPersonalData().getLastName();
    std::string actualLastName =
            mMainWindow->mStudentDataForm->getLastName().toStdString();
    QCOMPARE(actualLastName, expectedLastName);

    Gender expectedGender = studentToEdit.getPersonalData().getGender();
    Gender actualGender = mMainWindow->mStudentDataForm->getGender();
    QCOMPARE(actualGender, expectedGender);

    QList<double> expectedGrades;
    const auto& studentGrades = studentToEdit.getGrades();
    for(unsigned i = 0; i < studentGrades.count(); ++i) {
        expectedGrades.append(studentGrades.getGrade(i));
    }
    QList<double> actualGrades = mMainWindow->mStudentDataForm->getGrades();
    QCOMPARE(actualGrades, expectedGrades);
}

void TestMainWindow::testShowEditStudentForm() {
    mMainWindow->ui->studentList->setCurrentRow(1);
    mMainWindow->showEditStudentForm();

    QString expectedFormHeader =
            "<html><head/><body><p align=\"center\">"
            "<span style=\" font-size:16pt; font-weight:600; color:#ef2929;\">"
            "Edit Student</span></p></body></html>";
    QString actualFormHeader = mMainWindow->mStudentDataForm->getHeader();

    const auto& studentToEdit = mStudentClassData->getStudent(1);

    std::string expectedFirstName =
            studentToEdit.getPersonalData().getFirstName();
    std::string actualFirstName =
            mMainWindow->mStudentDataForm->getFirstName().toStdString();
    QCOMPARE(actualFirstName, expectedFirstName);

    std::string expectedLastName =
            studentToEdit.getPersonalData().getLastName();
    std::string actualLastName =
            mMainWindow->mStudentDataForm->getLastName().toStdString();
    QCOMPARE(actualLastName, expectedLastName);

    Gender expectedGender = studentToEdit.getPersonalData().getGender();
    Gender actualGender = mMainWindow->mStudentDataForm->getGender();
    QCOMPARE(actualGender, expectedGender);

    QList<double> expectedGrades;
    const auto& studentGrades = studentToEdit.getGrades();
    for(unsigned i = 0; i < studentGrades.count(); ++i) {
        expectedGrades.append(studentGrades.getGrade(i));
    }

    QList<double> actualGrades = mMainWindow->mStudentDataForm->getGrades();
    QCOMPARE(actualGrades, expectedGrades);
}
