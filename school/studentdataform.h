#ifndef STUDENTDATAFORM_H
#define STUDENTDATAFORM_H

#include <QWidget>

namespace Ui {
    class StudentDataForm;
    }

class StudentDataForm : public QWidget
{
    Q_OBJECT

public:
    explicit StudentDataForm(QWidget *parent = nullptr);
    ~StudentDataForm();

private:
    Ui::StudentDataForm *ui;
};

#endif // STUDENTDATAFORM_H
