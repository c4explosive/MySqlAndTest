#-------------------------------------------------
#
# Project created by QtCreator 2016-08-27T20:44:46
#
#-------------------------------------------------

QT       += core gui sql svg androidextras

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MySqlAndTest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    snd.cpp \
    entitiesfxs.cpp \
    ufilter.cpp \
    utask.cpp \
    multiplesfxs.cpp \
    agregartarea.cpp \
    modificartarea.cpp \
    eliminartarea.cpp \
    buscartarea.cpp \
    androidfiledialog.cpp \
    view_horary.cpp \
    weekview.cpp

HEADERS  += mainwindow.h \
    snd.h \
    entitiesfxs.h \
    ufilter.h \
    utask.h \
    multiplesfxs.h \
    agregartarea.h \
    modificartarea.h \
    eliminartarea.h \
    buscartarea.h \
    androidfiledialog.h \
    view_horary.h \
    weekview.h

FORMS    += mainwindow.ui \
    snd.ui \
    agregartarea.ui \
    modificartarea.ui \
    eliminartarea.ui \
    buscartarea.ui \
    view_horary.ui \
    weekview.ui

CONFIG += mobility
MOBILITY = 



INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

contains(ANDROID_TARGET_ARCH,armeabi-v7a) {
    ANDROID_EXTRA_LIBS = \
        $$PWD/libmariadb.so
}
#else:unix: LIBS += -L$$PWD/./ -lmysql

RESOURCES += \
    rsour.qrc

DISTFILES += \
    libmariadb.so \
    add_obj.svg \
    cancell.svg \
    comoda.svg \
    delete_obj.svg \
    desktop_ref.svg \
    Folder_add.svg \
    ing_accept.svg \
    mov_object.svg \
    search_find.svg \
    server_database.svg \
    update.svg \
    user_homeRoom.svg \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat \
    IMG-20150311-WA0001.jpg

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
