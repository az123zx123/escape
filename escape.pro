#-------------------------------------------------
#
# Project created by QtCreator 2018-11-19T16:44:24
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = escape
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
    square.cpp \
    character.cpp \
    gameinstance.cpp \
    piece.cpp \
    a_star.cpp \
    edge.cpp \
    graph.cpp \
    point.cpp \
    mainwindow.cpp \
    terrain.cpp \
    hero.cpp \
    monster.cpp \
    treasure.cpp \
    start.cpp \
    end_point.cpp \
    moor.cpp \
    forest.cpp \
    grass.cpp \
    mountain.cpp \
    gamewindow.cpp

HEADERS += \
    square.h \
    character.h \
    gameinstance.h \
    piece.h \
    a_star.h \
    edge.h \
    graph.h \
    point.h \
    mainwindow.h \
    terrain.h \
    hero.h \
    monster.h \
    treasure.h \
    start.h \
    end_point.h \
    moor.h \
    forest.h \
    grass.h \
    mountain.h \
    gamewindow.h

FORMS += \
    mainwindow.ui \
    gamewindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    resource.qrc \
