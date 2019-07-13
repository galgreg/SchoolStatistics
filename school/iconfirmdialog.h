#ifndef ICONFIRMDIALOG_H
#define ICONFIRMDIALOG_H

class QString;

class IConfirmDialog {
public:
    virtual ~IConfirmDialog() = default;
    virtual void showDialog() = 0;
    virtual void hideDialog() = 0;

    virtual void setAction(const QString &) = 0;
    virtual void setStudentName(const QString &) = 0;

    virtual QString getAction() = 0;
    virtual QString getStudentName() = 0;
};

#endif // ICONFIRMDIALOG_H
