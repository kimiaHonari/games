#-------------------------------------------------
#
# Project created by QtCreator 2014-05-09T14:37:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = game4
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    line.cpp \
    gameboard.cpp \
    board.cpp \
    form.cpp \
    about.cpp

HEADERS  += mainwindow.h \
    line.h \
    information.h \
    gameboard.h \
    board.h \
    form.h \
    about.h

FORMS    += mainwindow.ui \
    board.ui \
    form.ui \
    about.ui

RESOURCES += \
    res.qrc
