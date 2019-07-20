#ifndef NOTIFICATIONPOPUPMOCK_H
#define NOTIFICATIONPOPUPMOCK_H

#include "inotificationpopup.h"
#include <QPoint>
#include <QString>

class NotificationPopupMock : public INotificationPopup
{
public:
    void showPopup() override;
    void hidePopup() override;

    void setPopupPosition(const QPoint &newPosition) override;
    QPoint getPopupPosition() override;

    void setContent(const QString &newContent) override;
    QString getContent() override;
private:
    QPoint mPosition;
    QString mContent;
};

#endif // NOTIFICATIONPOPUPMOCK_H
