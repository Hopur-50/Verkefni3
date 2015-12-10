#-------------------------------------------------
#
# Project created by QtCreator 2015-12-10T14:50:03
#
#-------------------------------------------------

QT       += core sql
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Verkefni3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    models/computer.cpp \
    models/scientist.cpp \
    repositories/computerrepository.cpp \
    repositories/scientistrepository.cpp \
    services/computerservice.cpp \
    services/scientistservice.cpp \
    utilities/utils.cpp

HEADERS  += mainwindow.h \
    models/computer.h \
    models/scientist.h \
    repositories/computerrepository.h \
    repositories/scientistrepository.h \
    services/computerservice.h \
    services/scientistservice.h \
    utilities/constants.h \
    utilities/utils.h

FORMS    += mainwindow.ui
