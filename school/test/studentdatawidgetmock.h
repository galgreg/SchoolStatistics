#ifndef STUDENTDATAWIDGETMOCK_H
#define STUDENTDATAWIDGETMOCK_H

#include "istudentdatawidget.h"
#include <QString>

class StudentDataWidgetMock : public IStudentDataWidget
{
public:
    void showWidget() override;
    void hideWidget() override;

    QString getID() override;
    QString getFirstName() override;
    QString getLastName() override;
    QString getGender() override;
    QString getGrades() override;
    QString getGradesAverage() override;

    void setID(const QString&) override;
    void setFirstName(const QString&) override;
    void setLastName(const QString&) override;
    void setGender(const QString&) override;
    void setGrades(const QString&) override;
    void setGradesAverage(const QString&) override;
private:
    QString mStudentID;
    QString mFirstName;
    QString mLastName;
    QString mGender;
    QString mGrades;
    QString mGradesAverage;
};

#endif // STUDENTDATAWIDGETMOCK_H
