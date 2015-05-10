#-------------------------------------------------
#
# Project created by QtCreator 2015-05-06T21:27:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bludiste2015
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gamesetup.cpp \
    labyrint.cpp \
    myrect.cpp \
    ../src/deska.cpp

HEADERS  += mainwindow.h \
    gamesetup.h \
    labyrint.h \
    myrect.h \
    ../src/deska.h

FORMS    += mainwindow.ui \
    gamesetup.ui \
    labyrint.ui

RESOURCES += \
    images.qrc


