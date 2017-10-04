#-------------------------------------------------
#
# Project created by QtCreator 2013-03-07T09:05:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RobotRace
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    robotrace.cpp \
    robot.cpp \
    robotraceview.cpp

HEADERS  += dialog.h \
    robotrace.h \
    robot.h \
    robotraceview.h

FORMS    += dialog.ui

RESOURCES += \
    image.qrc
