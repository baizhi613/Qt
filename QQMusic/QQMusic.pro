QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    btform.cpp \
    commonpage.cpp \
    listitembox.cpp \
    main.cpp \
    music.cpp \
    musiclist.cpp \
    musicslider.cpp \
    qqmusic.cpp \
    recbox.cpp \
    recboxitem.cpp \
    volumetool.cpp

HEADERS += \
    btform.h \
    commonpage.h \
    listitembox.h \
    music.h \
    musiclist.h \
    musicslider.h \
    qqmusic.h \
    recbox.h \
    recboxitem.h \
    volumetool.h

FORMS += \
    btform.ui \
    commonpage.ui \
    listitembox.ui \
    musicslider.ui \
    qqmusic.ui \
    recbox.ui \
    recboxitem.ui \
    volumetool.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resourses.qrc