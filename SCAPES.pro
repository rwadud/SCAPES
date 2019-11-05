#-------------------------------------------------
#
# Project created by QtCreator 2019-10-22T10:14:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SCAPES
TEMPLATE = app

INCLUDEPATH += $$PWD/Application
INCLUDEPATH += $$PWD/Interface
INCLUDEPATH += $$PWD/Logic
INCLUDEPATH += $$PWD/Storage

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
    Application/dcistmt.cpp \
    Application/statementfactory.cpp \
        main.cpp \
        $$files(Storage/*.cpp) \
        $$files(Logic/*.cpp) \
        $$files(Interface/*.cpp) \
        $$files(Application/*.cpp) \

HEADERS += \
        $$files(Storage/*.h) \
        $$files(Logic/*.h) \
        $$files(Interface/*.h) \
        $$files(Application/*.h) \ \
    Application/dcistmt.h \
    Application/statementfactory.h

FORMS += \
        $$files(Interface/*.ui)

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
