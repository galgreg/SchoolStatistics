#ifndef ISTUDENTDATAFORM_H
#define ISTUDENTDATAFORM_H

#include "gender.h"
#include <QList>
#include <QString>

class IStudentDataForm {
public:
    virtual ~IStudentDataForm() = default;
    virtual void showForm() = 0;
    virtual void hideForm() = 0;

    virtual void setHeader(const QString &newHeader) = 0;
    virtual void setFirstName(const QString &newFirstName) = 0;
    virtual void setLastName(const QString &newLastName) = 0;
    virtual void setGender(Gender newGender) = 0;

    virtual void addGrade(double newGrade) = 0;
    virtual void editGrade(size_t whichGrade, double newGrade) = 0;
    virtual void deleteGrade(size_t whichGrade) = 0;

    virtual QString getHeader() = 0;
    virtual QString getFirstName() = 0;
    virtual QString getLastName() = 0;
    virtual Gender getGender() = 0;
    virtual QList<double> getGrades() = 0;
};

#endif // ISTUDENTDATAFORM_H
