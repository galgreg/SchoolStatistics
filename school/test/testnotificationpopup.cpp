#include "testnotificationpopup.h"
#include <QLabel>

TestNotificationPopup::TestNotificationPopup(
        unsigned &passed,
        unsigned &failed) : TestExecutionCounter (passed, failed) {

}

void TestNotificationPopup::init() {
    mNotificationPopup.reset(new NotificationPopup);
}

void TestNotificationPopup::cleanup() {
    if (QTest::currentTestFailed()) {
        incrementFailCounter();
    } else {
        incrementPassCounter();
    }
}

void TestNotificationPopup::testShowAndHidePopup() {
    mNotificationPopup->showPopup();
    bool isPopupVisible = mNotificationPopup->isVisible();
    QVERIFY(isPopupVisible == true);

    mNotificationPopup->hidePopup();
    isPopupVisible = mNotificationPopup->isVisible();
    QVERIFY(isPopupVisible == false);
}

void TestNotificationPopup::testSetContent() {
    QString expectedPopupContent =
            "Invalid input, it must begin from upper case "
            "and have minimum 3 chars!";
    mNotificationPopup->setContent(expectedPopupContent);

    QString actualPopupContent_1 = mNotificationPopup->getContent();
    QCOMPARE(actualPopupContent_1, expectedPopupContent);

    QString actualPopupContent_2 = mNotificationPopup->mPopupContent->text();
    QCOMPARE(actualPopupContent_2, expectedPopupContent);
}

void TestNotificationPopup::testSetPosition() {
    QPoint expectedPopupPosition(300, 114);
    mNotificationPopup->setPopupPosition(expectedPopupPosition);

    QPoint actualPopupPosition_1 = mNotificationPopup->getPopupPosition();
    QCOMPARE(actualPopupPosition_1, expectedPopupPosition);

    QPoint actualPopupPosition_2 = mNotificationPopup->pos();
    QCOMPARE(actualPopupPosition_2, expectedPopupPosition);
}
