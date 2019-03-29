#ifndef CONFIRMDIALOG_H
#define CONFIRMDIALOG_H

#include <QWidget>

namespace Ui {
class ConfirmDialog;
}

class ConfirmDialog : public QWidget
{
    Q_OBJECT

public:
    explicit ConfirmDialog(QWidget *parent = nullptr);
    ~ConfirmDialog();

private:
    Ui::ConfirmDialog *ui;
};

#endif // CONFIRMDIALOG_H
