#-------------------------------------------------
#
# Project created by QtCreator 2017-03-23T00:25:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DisassemblyPDB
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    disassebly.cpp

HEADERS  += mainwindow.h \
    disassembly.h

FORMS    += mainwindow.ui

CONFIG += console
