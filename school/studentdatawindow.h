#ifndef STUDENTDATAWINDOW_H
#define STUDENTDATAWINDOW_H

#include <QWidget>
#include "istudentdatawidget.h"
#include "signaltransmitter.h"
#include <memory>

class TestStudentDataWindow;

namespace Ui {
class StudentDataWindow;
}

class StudentDataWindow : public QWidget, public IStudentDataWidget
{
    Q_OBJECT

public:
    friend TestStudentDataWindow;

    StudentDataWindow(std::shared_ptr<SignalTransmitter> signalTransmitter);
    ~StudentDataWindow() override;
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
    std::unique_ptr<Ui::StudentDataWindow> ui;
    std::shared_ptr<SignalTransmitter> mSignalTransmitter;
};

#endif // STUDENTDATAWINDOW_H
