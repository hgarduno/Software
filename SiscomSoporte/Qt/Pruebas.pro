QMAKE=$(QTDIR)/bin/qmake

CONFIG+=debug thread
OBJECTS_DIR=O
SRC_MOC=MocCpp

INCLUDEPATH=H
INCLUDEPATH+=$(DIRDesarrolloHGE)/SiscomDesarrollo4Qt++/H
INCLUDEPATH+=$(DIRDesarrolloHGE)/SiscomDesarrollo4++/H
INCLUDEPATH+=$(DIRDesarrolloHGE)/SiscomComunicaciones++/H
INCLUDEPATH+=$(QTDIR)/include

LIBS+=-L$(DIRDesarrolloHGE)/SiscomDesarrollo4Qt++
LIBS+=-L$(DIRDesarrolloHGE)/SiscomComunicaciones++
LIBS+=-L$(DIRDesarrolloHGE)/SiscomDesarrollo4++
LIBS+=-L$(QTDIR)/lib
LIBS+=-L$(QTDIR)/plugins/designer
LIBS+=-lSiscomDesarrollo4Qt++
LIBS+=-lSiscomComunicaciones++
LIBS+=-lSiscomDesarrollo4++
LIBS+=-lqui
LIBS+=-lSiscomSoporte

SOURCES=Cpp/PruebaTablas.cpp


MAKEFILE=PruebasMakefile


