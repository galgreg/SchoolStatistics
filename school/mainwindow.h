#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "studentdataaction.h"
#include "iconfirmdialog.h"
#include "idatarepository.h"
#include "istudentclass.h"
#include "istudentdataform.h"
#include "istudentdatawidget.h"
#include "signaltransmitter.h"
#include <memory>

class TestMainWindow;

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    friend TestMainWindow;

    MainWindow(
        std::unique_ptr<IDataRepository> dataRepository,
        std::unique_ptr<IStudentDataWidget> studentDataWidget,
        std::unique_ptr<IConfirmDialog> confirmDialog,
        std::unique_ptr<IStudentDataForm> studentDataForm,
        std::shared_ptr<SignalTransmitter> signalTransmitter,
        size_t maxStudentCount = 20,
        size_t maxGradesCount = 3);
    ~MainWindow();

private slots:
    void showStudentDataWidget();
    void beginDeleteTransaction();
    void showAddNewStudentForm();
    void doAction(StudentDataAction actionToDo);
    void beginAddTransaction();

private:
    void doDeleteAction();
    void doAddAction();

    void readDataFromRepository();
    void deleteStudent(size_t studentIndex);

    void prepareStudentDataWidgetToDisplay(size_t studentIndex);
    void prepareConfirmDialogToDisplay(
            StudentDataAction actionToConfirm,
            QString studentName);
    void prepareStudentDataFormToDisplay(StudentDataAction actionToPerform);

    std::unique_ptr<Ui::MainWindow> ui;
    std::unique_ptr<IDataRepository> mDataRepository;
    std::unique_ptr<IStudentClass> mStudentClass;
    std::unique_ptr<IStudentDataWidget> mStudentDataWidget;
    std::unique_ptr<IConfirmDialog> mConfirmDialog;
    std::unique_ptr<IStudentDataForm> mStudentDataForm;
    std::shared_ptr<SignalTransmitter> mSignalTransmitter;
    size_t mMaxStudentCount, mMaxGradesCount;
    unsigned mNextStudentID;
};

#endif // MAINWINDOW_H
