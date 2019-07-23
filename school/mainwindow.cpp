#include "mainwindow.h"
#include "classstatistics.h"
#include "ui_mainwindow.h"
#include "studentclass.h"
#include "studentfactory.h"
#include "textfilestorage.h"

MainWindow::MainWindow(
        std::unique_ptr<IDataRepository> dataRepository,
        std::unique_ptr<IStudentDataWidget> studentDataWidget,
        std::unique_ptr<IConfirmDialog> confirmDialog,
        std::unique_ptr<IStudentDataForm> studentDataForm,
        std::shared_ptr<SignalTransmitter> signalTransmitter,
        size_t maxStudentCount,
        size_t maxGradesCount) :
            QWidget(nullptr),
            ui(new Ui::MainWindow),
            mDataRepository(std::move(dataRepository)),
            mStudentClass(nullptr),
            mStudentDataWidget(std::move(studentDataWidget)),
            mConfirmDialog(std::move(confirmDialog)),
            mStudentDataForm(std::move(studentDataForm)),
            mSignalTransmitter(signalTransmitter),
            mMaxStudentCount(maxStudentCount),
            mMaxGradesCount(maxGradesCount),
            mNextStudentID(1) {
    ui->setupUi(this);

    connect(ui->showStudentButton, &QPushButton::clicked,
            this, &MainWindow::showStudentDataWidget);
    connect(ui->addStudentButton, &QPushButton::clicked,
            this, &MainWindow::showAddNewStudentForm);
    connect(ui->deleteStudentButton, &QPushButton::clicked,
            this, &MainWindow::beginDeleteTransaction);
    connect(mSignalTransmitter.get(), &SignalTransmitter::transactionCommitted,
            this, &MainWindow::doAction);
    connect(mSignalTransmitter.get(), &SignalTransmitter::requestFormAction,
            this, &MainWindow::beginFormTransaction);
    connect(mSignalTransmitter.get(), &SignalTransmitter::showEditForm,
            this, &MainWindow::showEditStudentForm);
    mStudentDataForm->setMaxGradesCount(mMaxGradesCount);
    readDataFromRepository();
}

MainWindow::~MainWindow() {
}

void MainWindow::showStudentDataWidget() {
    int studentIndex = ui->studentList->currentRow();

    if (studentIndex > -1) {
        prepareStudentDataWidgetToDisplay(static_cast<size_t>(studentIndex));
        mStudentDataWidget->showWidget();
    }
}

void MainWindow::beginDeleteTransaction() {
    StudentDataAction actionToConfirm = DELETE_STUDENT;

    if (ui->studentList->currentRow() > -1) {
        QString studentName = ui->studentList->currentItem()->text();
        mConfirmDialog->customizeDialogMessage(actionToConfirm, studentName);
        mConfirmDialog->showDialog();
    }
}

void MainWindow::showAddNewStudentForm() {
    prepareStudentDataFormToDisplay(ADD_STUDENT);
    mStudentDataForm->showForm();
}

void MainWindow::showEditStudentForm() {
    prepareStudentDataFormToDisplay(EDIT_STUDENT);
    mStudentDataForm->showForm();
}

void MainWindow::doAction(StudentDataAction actionToDo) {
    if (actionToDo == DELETE_STUDENT) {
        doDeleteAction();
    } else if (actionToDo == ADD_STUDENT) {
        doAddAction();
    } else if (actionToDo == EDIT_STUDENT) {
        doEditAction();
    }
}

void MainWindow::beginFormTransaction(StudentDataAction formAction) {
    if (formAction == ADD_STUDENT || formAction == EDIT_STUDENT) {
        QString studentName =
        QString("%1 %2")
        .arg(mStudentDataForm->getFirstName())
        .arg(mStudentDataForm->getLastName());
        mConfirmDialog->customizeDialogMessage(formAction, studentName);
        mConfirmDialog->showDialog();
    }
}

void MainWindow::doDeleteAction() {
    int indexOfStudentToDelete = ui->studentList->currentRow();
    if (indexOfStudentToDelete > -1) {
        deleteStudent(static_cast<size_t>(indexOfStudentToDelete));
    }
}

void MainWindow::doAddAction() {
    unsigned studentID = mNextStudentID++;
    std::string studentFirstName =
            mStudentDataForm->getFirstName().toStdString();
    std::string studentLastName =
            mStudentDataForm->getLastName().toStdString();
    Gender studentGender = mStudentDataForm->getGender();

    auto tempGrades = mStudentDataForm->getGrades();
    std::vector<double> studentGrades;
    for(int i = 0; i < tempGrades.size(); ++i) {
        studentGrades.push_back(tempGrades.at(i));
    }
    std::unique_ptr<IStudent> newStudent(
            StudentFactory::create(
                    studentID,
                    studentFirstName,
                    studentLastName,
                    studentGender,
                    studentGrades));

    mStudentClass->addStudent(std::move(newStudent));
    mDataRepository->write(*mStudentClass);
    readDataFromRepository();
    mStudentDataForm->hideForm();
}

void MainWindow::doEditAction() {
    int indexOfStudentToEdit = ui->studentList->currentRow();

    if (indexOfStudentToEdit > -1) {
        const auto& studentToEdit =
                mStudentClass->getStudent(
                    static_cast<size_t>(indexOfStudentToEdit));

        unsigned studentID = studentToEdit.getID();
        std::string studentFirstName =
                mStudentDataForm->getFirstName().toStdString();
        std::string studentLastName =
                mStudentDataForm->getLastName().toStdString();
        Gender studentGender = mStudentDataForm->getGender();
        std::vector<double> studentGrades =
                mStudentDataForm->getGrades().toVector().toStdVector();
        std::unique_ptr<IStudent> newStudent(
                StudentFactory::create(
                        studentID,
                        studentFirstName,
                        studentLastName,
                        studentGender,
                        studentGrades));
        mStudentClass->editStudent(
                static_cast<size_t>(indexOfStudentToEdit),
                std::move(newStudent));
        mDataRepository->write(*mStudentClass);
        readDataFromRepository();
        mStudentDataForm->hideForm();
        mStudentDataWidget->hideWidget();
    }
}

void MainWindow::readDataFromRepository() {
    try {
        mStudentClass = mDataRepository->read(mMaxStudentCount, mMaxGradesCount);
        ui->errorLabel->setText("");
    } catch (...) {
        mStudentClass.reset(new StudentClass(mMaxStudentCount));
        ui->studentsNumberValue->setText("0");
        ui->classAverageValue->setText("0.0");
        ui->studentList->clear();
        ui->errorLabel->setText(
                "<html><head/><body>"
                "<p><span style=\" font-weight:600; color:#cc0000;\">"
                "Cannot open data storage!</span></p>"
                "</body></html>");
        return;
    }
    size_t studentClassCount = mStudentClass->count();
    ui->studentsNumberValue->setText(QString::number(studentClassCount));
    double studentClassAverage =
            ClassStatistics::getClassAverage(*mStudentClass);
    ui->classAverageValue->setText(QString::number(studentClassAverage, 'f', 1));

    auto& studentList = ui->studentList;
    studentList->clear();
    for (size_t i = 0; i < mStudentClass->count(); ++i) {
        const auto& student = mStudentClass->getStudent(i);
        const auto& personalData = student.getPersonalData();
        std::string studentFullName =
                personalData.getFirstName() + " " + personalData.getLastName();
        studentList->addItem(QString::fromStdString(studentFullName));

        if (mNextStudentID <= student.getID()) {
           mNextStudentID = student.getID() + 1;
        }
    }
}

void MainWindow::deleteStudent(size_t studentIndex) {
    mStudentClass->removeStudent(studentIndex);
    mDataRepository->write(*mStudentClass);
    readDataFromRepository();
}

void MainWindow::prepareStudentDataWidgetToDisplay(size_t studentIndex) {
    const auto& student = mStudentClass->getStudent(studentIndex);
    QString studentID = QString::number(student.getID());
    mStudentDataWidget->setID(studentID);
    const auto& studentPersonalData = student.getPersonalData();
    QString studentFirstName =
            QString::fromStdString(studentPersonalData.getFirstName());
    mStudentDataWidget->setFirstName(studentFirstName);
    QString studentLastName =
            QString::fromStdString(studentPersonalData.getLastName());
    mStudentDataWidget->setLastName(studentLastName);

    Gender studentGenderEnum = studentPersonalData.getGender();
    QString studentGender;

    if (studentGenderEnum == MALE) {
        studentGender = "Male";
    } else if (studentGenderEnum == FEMALE) {
        studentGender = "Female";
    } else {
        studentGender = "Unknown";
    }
    mStudentDataWidget->setGender(studentGender);

    const auto& studentGrades = student.getGrades();
    QString gradesString = "";

    for (unsigned i = 0; i < studentGrades.count(); ++i) {
        QString tempString = QString::number(studentGrades.getGrade(i), 'f', 1);
        gradesString += tempString;
        if (i < (studentGrades.count() - 1)) {
            gradesString += ", ";
        }
    }
    mStudentDataWidget->setGrades(gradesString);

    QString gradesAverage = QString::number(
            ClassStatistics::getStudentAverage(*mStudentClass, studentIndex),
            'f',
            1);
    mStudentDataWidget->setGradesAverage(gradesAverage);
}

void MainWindow::prepareStudentDataFormToDisplay(
        StudentDataAction actionToPerform) {
    mStudentDataForm->setFormAction(actionToPerform);
    if (actionToPerform == ADD_STUDENT) {
        mStudentDataForm->setHeader("Add Student");
        mStudentDataForm->setFirstName("");
        mStudentDataForm->setLastName("");
        mStudentDataForm->setGender(UNKNOWN);
        mStudentDataForm->deleteAllGrades();
    } else if(actionToPerform == EDIT_STUDENT) {
        size_t currentIndex =
                static_cast<size_t>(ui->studentList->currentRow());
        const auto& studentToEdit = mStudentClass->getStudent(currentIndex);
        const auto& studentPersonalData = studentToEdit.getPersonalData();
        const auto& studentGrades = studentToEdit.getGrades();

        mStudentDataForm->setHeader("Edit Student");
        mStudentDataForm->setFirstName(
                QString::fromStdString(studentPersonalData.getFirstName()));
        mStudentDataForm->setLastName(
                QString::fromStdString(studentPersonalData.getLastName()));
        mStudentDataForm->setGender(studentPersonalData.getGender());
        mStudentDataForm->deleteAllGrades();
        for (unsigned i = 0; i < studentGrades.count(); ++i) {
            mStudentDataForm->addGrade(studentGrades.getGrade(i));
        }
    }
}

