#ifndef TESTNOTIFICATIONPOPUP_H
#define TESTNOTIFICATIONPOPUP_H

#include "testexecutioncounter.h"
#include <QtTest>
#include "notificationpopup.h"

class TestNotificationPopup : public QObject, public TestExecutionCounter
{
    Q_OBJECT
public:
    TestNotificationPopup(unsigned &passed, unsigned &failed);
private slots:
    void init();
    void cleanup();
    void testShowAndHidePopup();
    void testSetContent();
    void testSetPosition();
private:
    std::unique_ptr<NotificationPopup> mNotificationPopup;
};

#endif // TESTNOTIFICATIONPOPUP_H
