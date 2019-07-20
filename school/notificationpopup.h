#ifndef NOTIFICATIONPOPUP_H
#define NOTIFICATIONPOPUP_H

#include "inotificationpopup.h"
#include <QWidget>
#include <memory>
#include <QLabel>

class TestNotificationPopup;

class NotificationPopup :  public QWidget, public INotificationPopup {
    Q_OBJECT

public:
    friend TestNotificationPopup;
    NotificationPopup();

    void showPopup() override;
    void hidePopup() override;

    void setPopupPosition(const QPoint &newPosition) override;
    QPoint getPopupPosition() override;

    void setContent(const QString &newContent) override;
    QString getContent() override;

private:
    std::unique_ptr<QLabel> mPopupContent;
};

#endif // NOTIFICATIONPOPUP_H
