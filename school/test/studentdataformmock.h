#ifndef STUDENTDATAFORMMOCK_H
#define STUDENTDATAFORMMOCK_H

#include "istudentdataform.h"

class StudentDataFormMock : public IStudentDataForm {
public:
    StudentDataFormMock() noexcept;
    void showForm() noexcept override;
    void hideForm() noexcept override;
    void setFormAction(StudentDataAction newFormAction) noexcept override;
    StudentDataAction getFormAction() noexcept override;

    void setHeader(const QString &newHeader) noexcept override;
    void setFirstName(const QString &newFirstName) noexcept override;
    void setLastName(const QString &newLastName) noexcept override;
    void setGender(Gender newGender) noexcept override;

    void setMaxGradesCount(size_t newMaxGradesCount) noexcept override;
    size_t getMaxGradesCount() noexcept override;
    void addGrade(double newGrade) override;
    void editGrade(size_t whichGrade, double newGrade) override;
    void deleteGrade(size_t whichGrade) override;
    void deleteAllGrades() noexcept override;

    QString getHeader() noexcept override;
    QString getFirstName() noexcept override;
    QString getLastName() noexcept override;
    Gender getGender() noexcept override;
    QList<double> getGrades() noexcept override;

private:
    QString mHeader, mFirstName, mLastName;
    Gender mGender;
    QList<double> mGrades;
    size_t mMaxGradesCount = 0;
    StudentDataAction mFormAction;
};

#endif // STUDENTDATAFORMMOCK_H
