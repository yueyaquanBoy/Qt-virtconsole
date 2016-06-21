#-------------------------------------------------
#
# Project created by QtCreator 2016-06-20T19:08:22
#
#-------------------------------------------------

QT       += core
QT       += gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = console
TEMPLATE = app

LIBS += -lvirt

SOURCES += main.cpp\
        eccloud.cpp \
    server.cpp

HEADERS  += eccloud.h \
    addvm.h \
    server.h

FORMS    += eccloud.ui
