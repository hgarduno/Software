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
LIBS+=-lSiscomDesarrollo4Qt++
LIBS+=-lSiscomComunicaciones++
LIBS+=-lSiscomDesarrollo4++
LIBS+=-lqui


SOURCES+=Cpp/QtCorteCaja.cpp
SOURCES+=Cpp/QtCorteCajaImp.cpp
SOURCES+=Cpp/QtImpCaja.cpp
SOURCES+=Cpp/QCtrlPluginSiscomSoporte.cpp
SOURCES+=Cpp/zControlesCorteCaja.cpp
SOURCES+=Cpp/zCeldaCorte.cpp
SOURCES+=Cpp/zCaja.cpp
SOURCES+=Cpp/zDenominacion.cpp
SOURCES+=Cpp/zGasto.cpp
SOURCES+=Cpp/zZonaGasto.cpp
SOURCES+=Cpp/zDenominaciones.cpp
SOURCES+=Cpp/zCajas.cpp
SOURCES+=Cpp/zCeldasCorte.cpp
SOURCES+=Cpp/zEncabezadoCaja.cpp
SOURCES+=Cpp/zEncabezadosCaja.cpp
SOURCES+=Cpp/zGastos.cpp
SOURCES+=Cpp/zCeldaPagoTarjeta.cpp
SOURCES+=Cpp/zCeldaImporteGastos.cpp
SOURCES+=Cpp/zCeldaImporteTransferencias.cpp
SOURCES+=Cpp/zCeldaImporteEfectivoCaja.cpp

HEADERS=H/QtCorteCaja.h
HEADERS+=H/QtCorteCajaImp.h
HEADERS+=H/QtImpCaja.h




TEMPLATE=lib
DESTDIR = $(QTDIR)/plugins/designer
