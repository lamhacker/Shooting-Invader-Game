#-------------------------------------------------
#
# Project created by QtCreator 2017-03-23T09:59:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

TARGET = DogInvader
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        doginvaders.cpp \
    bullet.cpp \
    bulletfactory.cpp \
    shipfactory.cpp \
    player.cpp \
    ship.cpp \
    plainbullet.cpp \
    configreader.cpp \
    colorbutton.cpp \
    sizebutton.cpp

HEADERS  += doginvaders.h \
    bullet.h \
    bulletfactory.h \
    shipfactory.h \
    player.h \
    ship.h \
    plainbullet.h \
    configreader.h \
    colorbutton.h \
    sizebutton.h

FORMS    += doginvaders.ui

RESOURCES += \
    rsc.qrc

