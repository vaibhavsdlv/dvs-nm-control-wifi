QT       += dbus
QT       -= gui

CONFIG += plugin

TEMPLATE = lib

TARGET = dvs-nm-control-wifi

INCLUDEPATH += .

DEFINES += QT_DEPRECATED_WARNINGS

HEADERS += wifidevice.h
SOURCES += wifidevice.cpp

unix {
    target.path = /usr/lib
    INSTALLS += target
}

DISTFILES +=
