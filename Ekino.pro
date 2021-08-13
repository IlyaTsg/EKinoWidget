QT += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Sources/addnewfilm.cpp \
    Sources/main.cpp \
    Sources/mainwindow.cpp \
    Sources/wchange.cpp \
    Sources/wdelete.cpp \
    Sources/wedit.cpp \
    Sources/wfind.cpp \
    Sources/wsort.cpp \
    Sources/wcollection.cpp

HEADERS += \
    Headers/addnewfilm.h \
    Headers/mainwindow.h \
    Headers/wchange.h \
    Headers/wdelete.h \
    Headers/wedit.h \
    Headers/wfind.h \
    Headers/wsort.h \
    Headers/wcollection.h

FORMS += \
    Forms/addnewfilm.ui \
    Forms/mainwindow.ui \
    Forms/wchange.ui \
    Forms/wdelete.ui \
    Forms/wedit.ui \
    Forms/wfind.ui \
    Forms/wsort.ui \
    Forms/wcollection.ui

TRANSLATIONS += \
    Ekino_ru_RU.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
