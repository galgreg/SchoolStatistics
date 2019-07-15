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
        IDataRepository *dataRepository,
        IStudentDataWidget *studentDataWidget,
        IConfirmDialog *confirmDialog,
        IStudentDataForm *studentDataForm,
        std::shared_ptr<SignalTransmitter> signalTransmitter,
        QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showStudentDataWidget();
    void beginDeleteTransaction();
    void doAction(StudentDataAction actionToDo);

private:
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
};

#endif // MAINWINDOW_H
