# Lunes 15 de diciembre del 2014 
# se inicia la version 4 del entorno de desarrollo

QMAKE=$(QTDIR)/bin/qmake

CONFIG+=thread

INCLUDEPATH=H $(DIRDesarrolloHGE)/SiscomDesarrollo4++/H $(DIRDesarrolloHGE)/SiscomComunicaciones++/H
HEADERS=H/zSiscomVentanaOpcion.h H/zSiscomVentana.h H/zSiscomQAction.h

SOURCES=CPP/zSiscomVentana.cpp			\
	CPP/zSiscomMenu.cpp			\
	CPP/zSiscomMenus.cpp			\
	CPP/zSiscomMenusVentana.cpp		\
	CPP/zSiscomQAction.cpp			\
	CPP/zSiscomVentanaOpcion.cpp		\
	CPP/zSiscomConfiguracion.cpp		\
	CPP/zSiscomQt3.cpp			\
	CPP/zSiscomBotonPanel.cpp		\
	CPP/zSiscomBotonesPanel.cpp		\
	CPP/zSiscomAdministracionSeguridad.cpp	\
	CPP/zSiscomTableItem.cpp		\
	CPP/zSiscomModuloMenu.cpp		\
	CPP/zSiscomModulosMenus.cpp		\
	CPP/zSiscomDibujando.cpp



TEMPLATE=lib
OBJECTS_DIR=O

