#ifndef STUDENTDATAWINDOW_H
#define STUDENTDATAWINDOW_H

#include <QWidget>

namespace Ui {
class StudentDataWindow;
}

class StudentDataWindow : public QWidget
{
    Q_OBJECT

public:
    explicit StudentDataWindow(QWidget *parent = nullptr);
    ~StudentDataWindow();

private:
    Ui::StudentDataWindow *ui;
};

#endif // STUDENTDATAWINDOW_H
