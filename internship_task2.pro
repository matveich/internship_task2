#-------------------------------------------------
#
# Project created by QtCreator 2018-07-14T21:04:21
#
#-------------------------------------------------

QT       += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = internship_task2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    pulltxsthread.cpp

HEADERS  += mainwindow.h \
    pulltxsthread.h

FORMS    += mainwindow.ui

CONFIG += console
