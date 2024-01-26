#Sabdado 21 Marzo 2015

CONFIG+=plugin thread



UI_HEADERS_DIR=Qt/Uic
UI_SOURCES_DIR=Qt/Uic
SRCMOC=Qt/Moc
MOC_DIR=Qt/Moc
OBJECTS_DIR=O
INCLUDEPATH=H/
FORMS=

HEADERS=H/QBarCode.h \
        H/QtPluginSiscom.h  \
        H/QtPluginSiscomControles.h

SOURCES=Cpp/QBarCode.cpp 	\
	Cpp/QtPluginSiscomControles.cpp

TEMPLATE=lib

TARGET=SiscomControles

