#ifndef STUDENTDATAFORM_H
#define STUDENTDATAFORM_H

#include <QWidget>
#include <memory>

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
    std::unique_ptr<Ui::StudentDataForm> ui;
};

#endif // STUDENTDATAFORM_H
