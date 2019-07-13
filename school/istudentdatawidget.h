#ifndef ISTUDENTDATAWIDGET_H
#define ISTUDENTDATAWIDGET_H

class QString;

class IStudentDataWidget {
public:
    virtual ~IStudentDataWidget() = default;
    virtual void showWidget() = 0;
    virtual void hideWidget() = 0;

    virtual QString getID() = 0;
    virtual QString getFirstName() = 0;
    virtual QString getLastName() = 0;
    virtual QString getGender() = 0;
    virtual QString getGrades() = 0;
    virtual QString getGradesAverage() = 0;

    virtual void setID(const QString&) = 0;
    virtual void setFirstName(const QString&) = 0;
    virtual void setLastName(const QString&) = 0;
    virtual void setGender(const QString&) = 0;
    virtual void setGrades(const QString&) = 0;
    virtual void setGradesAverage(const QString&) = 0;
};

#endif // ISTUDENTDATAWIDGET_H
