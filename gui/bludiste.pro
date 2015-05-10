#-------------------------------------------------
#
# Project created by QtCreator 2015-05-06T21:27:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bludiste
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gamesetup.cpp \
    labyrint.cpp \
    deska.cpp \
    myrect.cpp

HEADERS  += mainwindow.h \
    gamesetup.h \
    labyrint.h \
    deska.h \
    myrect.h

FORMS    += mainwindow.ui \
    gamesetup.ui \
    labyrint.ui

RESOURCES += \
    images.qrc

DISTFILES += \
    block.png \
    cloud.png \
    cog.png \
    compass.png \
    dribbble.png \
    drop.png \
    globe.png \
    hashtag.png \
    heart.png \
    location.png
