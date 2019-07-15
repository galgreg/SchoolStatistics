#ifndef STUDENTDATAFORM_H
#define STUDENTDATAFORM_H

#include "istudentdataform.h"
#include <QWidget>
#include <memory>

class TestStudentDataForm;

namespace Ui {
    class StudentDataForm;
    }

class StudentDataForm : public QWidget, public IStudentDataForm
{
    Q_OBJECT

public:
    friend TestStudentDataForm;

    explicit StudentDataForm(QWidget *parent = nullptr);
    ~StudentDataForm() override;

    void showForm() override;
    void hideForm() override;

    void setHeader(const QString &newHeader) override;
    void setFirstName(const QString &newFirstName) override;
    void setLastName(const QString &newLastName) override;
    void setGender(Gender newGender) override;

    void addGrade(double newGrade) override;
    void editGrade(size_t whichGrade, double newGrade) override;
    void deleteGrade(size_t whichGrade) override;
    void deleteAllGrades() override;

    QString getHeader() override;
    QString getFirstName() override;
    QString getLastName() override;
    Gender getGender() override;
    QList<double> getGrades() override;

private:
    std::unique_ptr<Ui::StudentDataForm> ui;
    Gender mGender;
};

#endif // STUDENTDATAFORM_H
