
QMAKE=$(QTDIR)/bin/qmake

INCLUDEPATH=../H $(HOME)/SiscomDesarrollo4++/H
CONFIG=debug

unix:LIBS=-L$(HOME)/SiscomComunicaciones++ 	\
	  -L$(HOME)/SiscomDesarrollo4++		\
	  -lSiscomComunicaciones++		\
	  -lSiscomDesarrollo4++

SOURCES=../CPP/ClienteEnvioProtocolo.cpp



TARGET=ClienteEnvioProtocolo
TEMPLATE=app
OBJECTS_DIR=O
