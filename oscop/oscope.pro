#-------------------------------------------------
#
# Project created by QtCreator 2016-07-30T12:43:59
#
#-------------------------------------------------

QT       += core gui
QT       += widgets serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = oscope
TEMPLATE = app


SOURCES += main.cpp\
        osil.cpp \
    renderarea.cpp \
    glwidget.cpp \
    settingsdialog.cpp

HEADERS  += osil.h \
    renderarea.h \
    glwidget.h \
    settingsdialog.h \
    oscop_data.h

FORMS += \
    settingsdialog.ui

DISTFILES += \
    readme
