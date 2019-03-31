#ifndef STUDENTINTERFACE_H
#define STUDENTINTERFACE_H

#include <QString>
#include <QList>
#include "gender.h"

class StudentInterface
{
public:
    using GradesRange = std::pair<
            QList<double>::const_iterator,
            QList<double>::const_iterator>;

    virtual ~StudentInterface() = default;

    virtual unsigned getID() const = 0;
    virtual QString getFullName() const = 0;
    virtual Gender getGender() const = 0;
    virtual GradesRange getGrades() const = 0;
    virtual double getGradesAverage() const = 0;

    virtual void addGrade(double grade) = 0;
    virtual void editGrade(int whichGrade, double newGrade) = 0;
    virtual void removeGrade(int whichGrade) = 0;
};

#endif // STUDENTINTERFACE_H
