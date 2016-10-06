TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    interfejs.cpp \
    struktury.cpp \
    funkcje.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    interfejs.h \
    struktury.h \
    funkcje.h

