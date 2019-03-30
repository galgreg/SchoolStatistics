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

CONFIG += c++11

SOURCES += \
        main.cpp \
    student.cpp \
    idgenerator.cpp \
    statistics_generator.cpp \
    studentinfo.cpp \
    studentlist.cpp \
    studentdatamanager.cpp \
    mainwindow.cpp \
    studentdatawindow.cpp \
    confirmdialog.cpp

HEADERS += \
    student.h \
    gender.h \
    idgenerator.h \
    statistics_generator.h \
    studentinfo.h \
    studentlist.h \
    studentdatamanager.h \
    mainwindow.h \
    studentdatawindow.h \
    confirmdialog.h

FORMS += \
    mainwindow.ui \
    studentdatawindow.ui \
    confirmdialog.ui

test {
    message(Test build)
    QT += testlib
    TARGET = UnitTests

    SOURCES -= main.cpp

    HEADERS += test/testidgenerator.h \
    test/teststudent.h \
    test/teststudentinfo.h

    SOURCES += test/test_main.cpp \
    test/testidgenerator.cpp \
    test/teststudent.cpp \
    test/teststudentinfo.cpp

} else {
    message(Normal build)
}

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
