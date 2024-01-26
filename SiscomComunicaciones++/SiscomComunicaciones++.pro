
QMAKE=$(QTDIR)/bin/qmake
CONFIG+=debug thread
INCLUDEPATH=H $(DIRDesarrolloHGE)/SiscomDesarrollo4++/H

SOURCES=CPP/zSisListas.cpp 		\
	CPP/zSisNodo.cpp 		\
	CPP/zSisOperacionesListas.cpp	\
	CPP/zSisCampoProtocolo.cpp	\
	CPP/zSisCampoProtocoloLst.cpp	\
	CPP/zSiscomCampo.cpp		\
	CPP/zSiscomRegistro.cpp		\
	CPP/zSiscomRegistros.cpp	\
	CPP/zSiscomConexion.cpp		\
	CPP/zSiscomEnvio.cpp		\
	CPP/zSiscomOperaciones.cpp	\
	CPP/zSiscomRecibe.cpp		\
	CPP/zSiscomArchivo.cpp		\
	CPP/zSiscomEnviaArchivo.cpp	\
	CPP/zSiscomRecibeArchivo.cpp	\
	CPP/zSiscomLineaComandos.cpp	\
	CPP/zSiscomEnvioACadena.cpp	\
	CPP/zSiscomRecibeDeCadena.cpp

TARGET=SiscomComunicaciones++
TEMPLATE=lib
OBJECTS_DIR=O
