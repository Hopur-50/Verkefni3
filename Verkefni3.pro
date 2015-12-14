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
    utilities/utils.cpp \
    repositories/baserepository.cpp \
    interface/addcomputer.cpp \
    interface/addscientist.cpp \
    interface/editcomputer.cpp \
    interface/editscientist.cpp \
    services/baseservice.cpp \
    interface/addrelation.cpp

HEADERS  += mainwindow.h \
    models/computer.h \
    models/scientist.h \
    repositories/computerrepository.h \
    repositories/scientistrepository.h \
    services/computerservice.h \
    services/scientistservice.h \
    utilities/constants.h \
    utilities/utils.h \
    repositories/baserepository.h \
    interface/addcomputer.h \
    interface/addscientist.h \
    interface/editcomputer.h \
    interface/editscientist.h \
    services/baseservice.h \
    interface/addrelation.h

FORMS    += mainwindow.ui\
    editscientist.ui \
    editcomputer.ui \
    addscientist.ui \
    addcomputer.ui \
    addrelation.ui \

