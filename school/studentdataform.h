#ifndef STUDENTDATAFORM_H
#define STUDENTDATAFORM_H

#include "istudentdataform.h"
#include "signaltransmitter.h"
#include <QWidget>
#include <memory>

class QLineEdit;
class QRegExpValidator;
class TestStudentDataForm;

namespace Ui {
    class StudentDataForm;
    }

class StudentDataForm : public QWidget, public IStudentDataForm
{
    Q_OBJECT

public:
    friend TestStudentDataForm;

    explicit StudentDataForm(
            std::shared_ptr<SignalTransmitter> signalTransmitter);
    ~StudentDataForm() override;

    void showForm() override;
    void hideForm() override;
    void setFormAction(StudentDataAction newFormAction) override;
    StudentDataAction getFormAction() override;

    void setHeader(const QString &newHeader) override;
    void setFirstName(const QString &newFirstName) override;
    void setLastName(const QString &newLastName) override;
    void setGender(Gender newGender) override;

    void setMaxGradesCount(size_t newMaxGradesCount) override;
    size_t getMaxGradesCount() override;
    void addGrade(double newGrade) override;
    void editGrade(size_t whichGrade, double newGrade) override;
    void deleteGrade(size_t whichGrade) override;
    void deleteAllGrades() override;

    QString getHeader() override;
    QString getFirstName() override;
    QString getLastName() override;
    Gender getGender() override;
    QList<double> getGrades() override;

signals:
    void requestAction(StudentDataAction);

private slots:
    void addGradeToList();
    void editGradeOnGradesList();
    void deleteGradeFromGradesList();

    void tryToSubmitForm();
    void clearNotificationLabel();
private:
    std::unique_ptr<Ui::StudentDataForm> ui;
    std::unique_ptr<QRegExpValidator> mStudentNameValidator;
    std::shared_ptr<SignalTransmitter> mSignalTransmitter;
    QString mHeader;
    StudentDataAction mFormAction;
    size_t mMaxGradesCount = 0;
};

#endif // STUDENTDATAFORM_H
