#-------------------------------------------------
#
# Project created by QtCreator 2016-04-29T10:45:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BreadthFirstSearch
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    mazeview.cpp \
    mazemodel.cpp \
    queue.cpp

HEADERS  += dialog.h \
    mazeview.h \
    mazemodel.h \
    queue.h \
    location.h

FORMS    += dialog.ui
