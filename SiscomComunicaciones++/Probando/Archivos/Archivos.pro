
INCLUDEPATH=H ../../..//SiscomComunicaciones++/H
SOURCES=CPP/CopiaArchivo.cpp 

unix:LIBS+=-L../../ \
	   -L../../..//SiscomDesarrollo4++ \
	   -lSiscomComunicaciones++ \
	   -lSiscomDesarrollo4++

TARGET=CopiaArchivo
TEMPLATE=app

OBJECTS_DIR=O
