INCLUDEPATH=H ../../H ../../../SiscomDesarrollo4++/H
SOURCES=CPP/Probando.cpp 
OBJECTS_DIR=O
unix:LIBS+=-L../../..//SiscomDesarrollo4++  -lSiscomDesarrollo4++ \
	   -L../../ -lSiscomComunicaciones++



TARGET=ProbandoProtocolo
