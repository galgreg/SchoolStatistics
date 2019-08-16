#ifndef STUDENTDATAWIDGETMOCK_H
#define STUDENTDATAWIDGETMOCK_H

#include "istudentdatawidget.h"
#include <QString>

class StudentDataWidgetMock : public IStudentDataWidget
{
public:
    void showWidget() noexcept override;
    void hideWidget() noexcept override;

    QString getID() noexcept override;
    QString getFirstName() noexcept override;
    QString getLastName() noexcept override;
    QString getGender() noexcept override;
    QString getGrades() noexcept override;
    QString getGradesAverage() noexcept override;

    void setID(const QString&) noexcept override;
    void setFirstName(const QString&) noexcept override;
    void setLastName(const QString&) noexcept override;
    void setGender(const QString&) noexcept override;
    void setGrades(const QString&) noexcept override;
    void setGradesAverage(const QString&) noexcept override;
private:
    QString mStudentID;
    QString mFirstName;
    QString mLastName;
    QString mGender;
    QString mGrades;
    QString mGradesAverage;
};

#endif // STUDENTDATAWIDGETMOCK_H
