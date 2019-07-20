#ifndef INOTIFICATIONPOPUP_H
#define INOTIFICATIONPOPUP_H

class QString;
class QPoint;

class INotificationPopup {
public:
    virtual ~INotificationPopup() = default;

    virtual void showPopup() = 0;
    virtual void hidePopup() = 0;

    virtual void setPopupPosition(const QPoint &newPosition) = 0;
    virtual QPoint getPopupPosition() = 0;

    virtual void setContent(const QString &newContent) = 0;
    virtual QString getContent() = 0;
};

#endif // INOTIFICATIONPOPUP_H
