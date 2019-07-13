#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "confirmaction.h"
#include "iconfirmdialog.h"
#include "idatarepository.h"
#include "istudentclass.h"
#include "istudentdatawidget.h"
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
        QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showStudentDataWidget();

private:
    void readDataFromRepository();
    void deleteStudent(size_t studentIndex);

    void prepareStudentDataWidgetToDisplay(size_t studentIndex);
    void prepareConfirmDialogToDisplay(
            ConfirmAction actionToConfirm,
            QString studentName);

    std::unique_ptr<Ui::MainWindow> ui;
    std::unique_ptr<IDataRepository> mDataRepository;
    std::unique_ptr<IStudentClass> mStudentClass;
    std::unique_ptr<IStudentDataWidget> mStudentDataWidget;
    std::unique_ptr<IConfirmDialog> mConfirmDialog;
};

#endif // MAINWINDOW_H
