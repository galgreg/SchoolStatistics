#include "notificationpopup.h"

NotificationPopup::NotificationPopup() :
        QWidget(nullptr),
        mPopupContent(new QLabel) {

}

void NotificationPopup::showPopup() {
    this->show();
}

void NotificationPopup::hidePopup() {
    this->hide();
}

void NotificationPopup::setPopupPosition(const QPoint &newPosition) {
    this->move(newPosition);
}

QPoint NotificationPopup::getPopupPosition() {
    return this->pos();
}

void NotificationPopup::setContent(const QString &newContent) {
    mPopupContent->setText(newContent);
}

QString NotificationPopup::getContent() {
    return  mPopupContent->text();
}
