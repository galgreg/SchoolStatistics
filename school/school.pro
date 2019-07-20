#-------------------------------------------------
#
# Project created by QtCreator 2019-03-26T13:06:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = school
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QMAKE_CXXFLAGS += -std=c++17

SOURCES += main.cpp \
    mainwindow.cpp \
    studentdatawindow.cpp \
    confirmdialog.cpp \
    grades.cpp \
    personaldata.cpp \
    student.cpp \
    studentclass.cpp \
    classstatistics.cpp \
    textfilestorage.cpp \
    idatarepository.cpp \
    studentfactory.cpp \
    istudentclass.cpp \
    istudent.cpp \
    studentdataform.cpp \
    signaltransmitter.cpp \
    igrades.cpp \
    ipersonaldata.cpp \
    notificationpopup.cpp

HEADERS += mainwindow.h \
    studentdatawindow.h \
    confirmdialog.h \
    grades.h \
    gender.h \
    personaldata.h \
    ipersonaldata.h \
    igrades.h \
    student.h \
    studentclass.h \
    istudent.h \
    istudentclass.h \
    classstatistics.h \
    idatarepository.h \
    textfilestorage.h \
    studentfactory.h \
    istudentdatawidget.h \
    studentdataform.h \
    iconfirmdialog.h \
    signaltransmitter.h \
    istudentdataform.h \
    studentdataaction.h \
    inotificationpopup.h \
    notificationpopup.h

FORMS += mainwindow.ui \
    studentdatawindow.ui \
    confirmdialog.ui \
    studentdataform.ui

test {
    message(Test build)
    QT += testlib
    TARGET = UnitTests

    SOURCES -= main.cpp

    HEADERS += test/testexecutioncounter.h \
    test/testgrades.h \
    test/testpersonaldata.h \
    test/teststudent.h \
    test/personaldatamock.h \
    test/gradesmock.h \
    test/teststudentclass.h \
    test/studentmock.h \
    test/testclassstatistics.h \
    test/studentclassmock.h \
    test/testtextfilestorage.h \
    test/teststudentfactory.h \
    test/testmainwindow.h \
    test/studentdatawidgetmock.h \
    test/confirmdialogmock.h \
    test/testconfirmdialog.h \
    test/teststudentdatawindow.h \
    test/testsignaltransmitter.h \
    test/studentdataformmock.h \
    test/teststudentdataform.h \
    test/datarepositorymock.h \
    test/notificationpopupmock.h \
    test/testnotificationpopup.h


    SOURCES += test/test_main.cpp \
    test/testexecutioncounter.cpp \
    test/testgrades.cpp \
    test/testpersonaldata.cpp \
    test/teststudent.cpp \
    test/personaldatamock.cpp \
    test/gradesmock.cpp \
    test/teststudentclass.cpp \
    test/studentmock.cpp \
    test/testclassstatistics.cpp \
    test/studentclassmock.cpp \
    test/testtextfilestorage.cpp \
    test/teststudentfactory.cpp \
    test/testmainwindow.cpp \
    test/studentdatawidgetmock.cpp \
    test/confirmdialogmock.cpp \
    test/testconfirmdialog.cpp \
    test/teststudentdatawindow.cpp \
    test/testsignaltransmitter.cpp \
    test/studentdataformmock.cpp \
    test/teststudentdataform.cpp \
    test/datarepositorymock.cpp \
    test/notificationpopupmock.cpp \
    test/testnotificationpopup.cpp

} else {
    message(Normal build)
}

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
