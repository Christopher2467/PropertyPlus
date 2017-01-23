#-------------------------------------------------
#
# Project created by QtCreator 2016-10-14T09:50:17
#
#-------------------------------------------------

QT       += core gui
QT       += xml
QT += qml quick
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PropertyPlus
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    creator.cpp \
    infor.cpp \
    databsecontroller.cpp

HEADERS  += mainwindow.h \
    creator.h \
    infor.h \
    databsecontroller.h

FORMS    += mainwindow.ui \
    creator.ui \
    infor.ui

DISTFILES +=
