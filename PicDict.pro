#-------------------------------------------------
#
# Project created by QtCreator 2016-09-22T09:24:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

DESTDIR = $$PWD/bin

TARGET = PicDict
TEMPLATE = app

INCLUDEPATH += \
    ui \
    data \
    service

SOURCES += main.cpp\
        ui/PicDictMainWindow.cpp \
    ui/MemoryForm.cpp \
    ui/WordDefsForm.cpp \
    ui/MemoryControlForm.cpp \
    data/PicDictDataSource.cpp \
    data/Word.cpp \
    data/WordBook.cpp \
    service/MemoryService.cpp \
    data/WordDef.cpp

HEADERS  += \
    ui/PicDictMainWindow.h \
    ui/MemoryForm.h \
    ui/WordDefsForm.h \
    ui/MemoryControlForm.h \
    data/PicDictDataSource.h \
    data/Word.h \
    data/WordBook.h \
    service/MemoryService.h \
    data/WordDef.h

FORMS    += \
    ui/PicDictMainWindow.ui \
    ui/MemoryForm.ui \
    ui/WordDefsForm.ui \
    ui/MemoryControlForm.ui
