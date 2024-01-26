
INCLUDEPATH=H 
INCLUDEPATH+=$(DIRDesarrolloHGE)/SiscomComunicaciones++/H 
INCLUDEPATH+=$(DIRDesarrolloHGE)/SiscomDesarrollo4Qt++/H 
INCLUDEPATH+=$(DIRDesarrolloHGE)/SiscomDesarrollo4++/H 
INCLUDEPATH+=../PantallasPruebas/H 
INCLUDEPATH+=../PantallasPruebas/UI_H
INCLUDEPATH+=$(QTDIR)/include

unix:LIBS+=-L$(DIRDesarrolloHGE)/SiscomComunicaciones++ 
unix:LIBS+=-L$(DIRDesarrolloHGE)/SiscomDesarrollo4Qt++ 
unix:LIBS+=-L$(DIRDesarrolloHGE)/SiscomDesarrollo4++ 
unix:LIBS+=-L../PantallasPruebas/  
unix:LIBS+=-L$(QTDIR)/lib
unix:LIBS+=-lSiscomComunicaciones++ 
unix:LIBS+=-lSiscomDesarrollo4++ 
unix:LIBS+=-lSiscomDesarrollo4Qt++ 
unix:LIBS+=-lqui 
OBJECTS_DIR=O

HEADERS=H/ClasesMenus.h
SOURCES=CPP/ClasesMenus.cpp
TEMPLATE=app
TARGET=ClasesMenus

#CONFIG=debug
