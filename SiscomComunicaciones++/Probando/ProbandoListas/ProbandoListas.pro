
CONFIG+=debug -D__ALGO__
INCLUDEPATH=H ../../H
SOURCES=CPP/Probando.cpp CPP/zDatosPersonales.cpp
OBJECTS_DIR=O
unix:LIBS+=-L../../ -L../../../SiscomDesarrollo4++ -lSiscomComunicaciones++ -lSiscomDesarrollo4++



TARGET=Probando
