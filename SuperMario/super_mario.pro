#-------------------------------------------------
#
# Project created by QtCreator 2014-06-05T10:46:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = super_mario
TEMPLATE = app


SOURCES += main.cpp\
        board.cpp \
    mygraphicscene.cpp \
    mario.cpp \
    baseobj.cpp \
    barrier.cpp \
    mainwindow.cpp \
    question.cpp \
    reward.cpp \
    mashroom.cpp \
    flower.cpp \
    enemy.cpp \
    coin.cpp \
    movablebarrier.cpp \
    cloud.cpp \
    buttongraphicsobject.cpp \
    form.cpp \
    scene.cpp \
    gameover.cpp \
    flag.cpp \
    wingame.cpp \
    score.cpp

HEADERS  += board.h \
    mygraphicscene.h \
    info.h \
    mario.h \
    baseobj.h \
    barrier.h \
    mainwindow.h \
    question.h \
    reward.h \
    mashroom.h \
    flower.h \
    enemy.h \
    coin.h \
    movablebarrier.h \
    cloud.h \
    buttongraphicsobject.h \
    form.h \
    scene.h \
    gameover.h \
    flag.h \
    wingame.h \
    score.h

FORMS    += board.ui \
    mainwindow.ui \
    form.ui

RESOURCES += \
    res.qrc
