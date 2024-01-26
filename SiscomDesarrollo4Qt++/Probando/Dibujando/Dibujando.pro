INCLUDEPATH=H 
INCLUDEPATH+=$(DIRDesarrolloHGE)/SiscomComunicaciones++/H
INCLUDEPATH+=$(DIRDesarrolloHGE)/SiscomDesarrollo4Qt++/H
INCLUDEPATH+=$(DIRDesarrolloHGE)/SiscomDesarrollo4++/H


unix:LIBS=-L$(DIRDesarrolloHGE)/SiscomComunicaciones++
unix:LIBS+=-L$(DIRDesarrolloHGE)/SiscomDesarrollo4++
unix:LIBS+=-L$(DIRDesarrolloHGE)/SiscomDesarrollo4Qt++
unix:LIBS+=-lSiscomComunicaciones++
unix:LIBS+=-lSiscomDesarrollo4++
unix:LIBS+=-lSiscomDesarrollo4Qt++
unix:LIBS+=-lqui


OBJECTS_DIR=O

HEADERS=H/zDibujando.h
SOURCES=CPP/zDibujando.cpp
SOURCES+=CPP/PrincipalDibujando.cpp
TEMPLATE=app
TARGET=Dibujando

