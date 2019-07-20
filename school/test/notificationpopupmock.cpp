#include "notificationpopupmock.h"

void NotificationPopupMock::showPopup() {

}

void NotificationPopupMock::hidePopup() {

}

void NotificationPopupMock::setPopupPosition(const QPoint &newPosition) {
    mPosition = newPosition;
}

QPoint NotificationPopupMock::getPopupPosition() {
    return mPosition;
}

void NotificationPopupMock::setContent(const QString &newContent) {
    mContent = newContent;
}

QString NotificationPopupMock::getContent() {
    return mContent;
}
