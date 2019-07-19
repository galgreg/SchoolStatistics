#ifndef STUDENTDATAFORMMOCK_H
#define STUDENTDATAFORMMOCK_H

#include "istudentdataform.h"

class StudentDataFormMock : public IStudentDataForm {
public:
    StudentDataFormMock();
    void showForm() override;
    void hideForm() override;

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

private:
    QString mHeader, mFirstName, mLastName;
    Gender mGender;
    QList<double> mGrades;
    size_t mMaxGradesCount = 0;
};

#endif // STUDENTDATAFORMMOCK_H
