QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = school
TEMPLATE = app
DEFINES += QT_DEPRECATED_WARNINGS
QMAKE_CXXFLAGS += -std=c++14

SOURCES += classstatistics.cpp \
    confirmdialog.cpp \
    grades.cpp \
    idatarepository.cpp \
    igrades.cpp \
    ipersonaldata.cpp \
    istudent.cpp \
    istudentclass.cpp \
    main.cpp \
    mainwindow.cpp \
    personaldata.cpp \
    signaltransmitter.cpp \
    student.cpp \
    studentclass.cpp \
    studentdataform.cpp \
    studentdatawindow.cpp \
    studentfactory.cpp \
    textfilestorage.cpp

HEADERS += classstatistics.h \
    confirmdialog.h \
    gender.h \
    grades.h \
    iconfirmdialog.h \
    idatarepository.h \
    igrades.h \
    ipersonaldata.h \
    istudent.h \
    istudentclass.h \
    istudentdataform.h \
    istudentdatawidget.h \
    mainwindow.h \
    personaldata.h \
    signaltransmitter.h \
    student.h \
    studentclass.h \
    studentdataaction.h \
    studentdataform.h \
    studentdatawindow.h \
    studentfactory.h \
    textfilestorage.h

FORMS += confirmdialog.ui \
    mainwindow.ui \
    studentdataform.ui \
    studentdatawindow.ui

test {
    message(Test build)
    QT += testlib
    TARGET = UnitTests

    SOURCES -= main.cpp

    HEADERS += test/confirmdialogmock.h \
        test/datarepositorymock.h \
        test/gradesmock.h \
        test/personaldatamock.h \
        test/studentclassmock.h \
        test/studentdataformmock.h \
        test/studentdatawidgetmock.h \
        test/studentmock.h \
        test/testclassstatistics.h \
        test/testconfirmdialog.h \
        test/testexecutioncounter.h \
        test/testgrades.h \
        test/testmainwindow.h \
        test/testpersonaldata.h \
        test/testsignaltransmitter.h \
        test/teststudent.h \
        test/teststudentclass.h \
        test/teststudentdataform.h \
        test/teststudentdatawindow.h \
        test/teststudentfactory.h \
        test/testtextfilestorage.h \

    SOURCES += test/test_main.cpp \
        test/confirmdialogmock.cpp \
        test/datarepositorymock.cpp \
        test/gradesmock.cpp \
        test/personaldatamock.cpp \
        test/studentclassmock.cpp \
        test/studentdataformmock.cpp \
        test/studentdatawidgetmock.cpp \
        test/studentmock.cpp \
        test/testclassstatistics.cpp \
        test/testconfirmdialog.cpp \
        test/testexecutioncounter.cpp \
        test/testgrades.cpp \
        test/testmainwindow.cpp \
        test/testpersonaldata.cpp \
        test/testsignaltransmitter.cpp \
        test/teststudent.cpp \
        test/teststudentclass.cpp \
        test/teststudentdataform.cpp \
        test/teststudentdatawindow.cpp \
        test/teststudentfactory.cpp \
        test/testtextfilestorage.cpp \

} else {
    message(Normal build)
}

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
