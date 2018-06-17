#-------------------------------------------------
#
# Project created by QtCreator 2018-02-18T17:21:09
#
#-------------------------------------------------

QT       += core gui network xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DollarVPN
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
macx: {
    QMAKE_INFO_PLIST = ./Info.plist
    QMAKE_LFLAGS += -F /System/Library/Frameworks/
    QMAKE_RPATHDIR += @executable_path/../Frameworks
    LIBS += -framework Security
    target.path = /Applications
    resources.path = /Applications/DollarVPN.app/Contents/Resources
    resources.files = ./resources/*
    INSTALLS = target resources
}
win32:{
RC_FILE=DollarVPN.rc
LIBS += -lws2_32 -lIphlpapi
DESTDIR = ../../buildwindowsdollar/
MOC_DIR = ../obj_dollar/
}

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    server.cpp \
    connectpage.cpp \
    portforpage.cpp \
    wndmanager.cpp \
    subsettings.cpp \
    connectionsettings.cpp \
    authmanager.cpp     \
    openvpnmanager.cpp  \
    osspecific.cpp      \
    pathhelper.cpp      \
    pingwaiter.cpp      \
    portforwarder.cpp   \
    trayiconmanager.cpp \
    log.cpp \
    settingpage.cpp     \
    setting.cpp \
    errordialog.cpp     \
    common.cpp \
    location.cpp \
    notification.cpp \
    loading.cpp \
    listwidgetthread.cpp \
    locationitemview.cpp


HEADERS += \
        mainwindow.h \
    server.h \
    connectpage.h \
    portforpage.h \
    wndmanager.h \
    subsettings.h \
    connectionsettings.h \
    authmanager.h   \
    openvpnmanager.h    \
    osspecific.h      \
    pathhelper.h      \
    pingwaiter.h      \
    portforwarder.h   \
    trayiconmanager.h \
    log.h \
    settingpage.h     \
    setting.h \
    errordialog.h     \
    common.h \
    location.h \
    notification.h \
    loading.h \
    listwidgetthread.h \
    locationitemview.h

FORMS += \
        mainwindow.ui \
        server.ui \
    connectpage.ui \
    portforpage.ui \
    subsettings.ui \
    connectionsettings.ui \
    settingpage.ui \
    errordialog.ui \
    location.ui \
    locationitemview.ui



RESOURCES += \
    resource.qrc
