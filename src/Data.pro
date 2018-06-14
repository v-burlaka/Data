#-------------------------------------------------
#
# Project created by QtCreator 2018-04-22T17:03:41
#
#-------------------------------------------------

QT       += core gui
CONFIG   += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Data
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

HEADERS += \
    fileProcessingCore/api/CCUBDeserializator.hpp \
    fileProcessingCore/api/CCUBSerializator.hpp \
    fileProcessingCore/api/IDeserializator.hpp \
    fileProcessingCore/api/ISerializator.hpp \
    fileProcessingCore/api/Structs.hpp \
    gui/BrozeFileDialog.hpp \
    gui/DataEditDialog.hpp \
    gui/MainWindow.hpp \
    gui/Form.hpp \
    gui/CSetCoordDialog.hpp \
    gui/CTrancalancyBlockDialog.hpp \
    gui/CSetBoxSettingDialog.hpp

SOURCES += \
    fileProcessingCore/src/CCUBDeserializator.cpp \
    fileProcessingCore/src/CCUBSerializator.cpp \
    fileProcessingCore/src/ISerializator.cpp \
    main.cpp \
    gui/BrozeFileDialog.cpp \
    gui/DataEditDialog.cpp \
    gui/MainWindow.cpp \
    gui/Form.cpp \
    gui/CSetCoordDialog.cpp \
    gui/CTrancalancyBlockDialog.cpp \
    gui/CSetBoxSettingDialog.cpp

FORMS += \
    gui/BrozeFileDialog.ui \
    gui/DataEditDialog.ui \
    gui/MainWindow.ui \
    gui/Form.ui
