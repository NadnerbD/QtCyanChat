# -------------------------------------------------
# Project created by QtCreator 2009-03-11T17:05:10
# -------------------------------------------------
TARGET = CyanChat
TEMPLATE = app
SOURCES += main.cpp \
    cyanchat.cpp \
    cyanchat_user.cpp \
    pmwidget.cpp \
    options.cpp \
    useriptable.cpp
HEADERS += cyanchat.h \
    pmwidget.h \
    options.h \
    useriptable.h
FORMS += cyanchat.ui \
    options.ui \
    pmwidget.ui
QT += network
RC_FILE += cyanchat.rc
RESOURCES += resources.qrc
OTHER_FILES += cyanchat.rc
CONFIG += x86 ppc
