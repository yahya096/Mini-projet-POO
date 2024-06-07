#-------------------------------------------------
#
# Project created by QtCreator 2023-01-26T09:20:15
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Seance1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    userdialog.cpp \
    admindialog.cpp \
    utilisateur.cpp \
    dbconnection.cpp \
    lampadaires_dialog.cpp \
    lampadaires.cpp \
    avenue.cpp \
    avenuedialog.cpp \
    consommation_dialog.cpp \
    consommation.cpp

HEADERS  += mainwindow.h \
    userdialog.h \
    admindialog.h \
    utilisateur.h \
    dbconnection.h \
    lampadaires_dialog.h \
    lampadaires.h \
    avenue.h \
    avenuedialog.h \
    consommation_dialog.h \
    consommation.h

FORMS    += mainwindow.ui \
    userdialog.ui \
    admindialog.ui \
    lampadaires_dialog.ui \
    avenuedialog.ui \
    consommation_dialog.ui
