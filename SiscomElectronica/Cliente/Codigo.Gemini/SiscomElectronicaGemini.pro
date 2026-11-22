TEMPLATE = lib
CONFIG += qt warn_on release

INCLUDEPATH += ../H
INCLUDEPATH += ./H
INCLUDEPATH += $(DIRDesarrolloHGE)/SiscomDesarrollo4++/H
INCLUDEPATH += $(DIRDesarrolloHGE)/SiscomComunicaciones++/H

HEADERS += H/QtGeminiModuloVentas.h
HEADERS += H/zOperacionesGemini.h

SOURCES += Cpp/QtGeminiModuloVentas.cpp
SOURCES += Cpp/zOperacionesGemini.cpp

MOC_DIR = MocCpp
OBJECTS_DIR = O
