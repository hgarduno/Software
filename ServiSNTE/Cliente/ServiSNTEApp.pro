CONFIG+=debug thread
OBJECTS_DIR=O
unix:LIBS+=-L$(DIRDesarrolloHGE)/SiscomComunicaciones++ 	\
	   -L$(DIRDesarrolloHGE)/SiscomDesarrollo4Qt++ 	\
	   -L$(DIRDesarrolloHGE)/SiscomDesarrollo4++	\
	   -lSiscomComunicaciones++			\
	   -lSiscomDesarrollo4++			\
	   -lSiscomDesarrollo4Qt++			\
	   -lqui					\



UI_HEADERS_DIR=Qt/Uic
UI_SOURCES_DIR=Qt/Uic
SRCMOC=Qt/Moc
MOC_DIR=Qt/Moc
INCLUDEPATH=Qt/H					\
	    H						\
  	    $(DIRDesarrolloHGE)/SiscomComunicaciones++/H	\
	    $(DIRDesarrolloHGE)/SiscomDesarrollo4Qt++/H 	\
	    $(DIRDesarrolloHGE)/SiscomDesarrollo4++/H

FORMS=Qt/Ui/AccesoServiSNTE.ui 			\
      Qt/Ui/ActualizandoSistema.ui
HEADERS=Qt/H/QtSiscomServiSNTE.h		\
	Qt/H/QtImpAccesoServiSNTE.h		\
	Qt/H/QtImpActualizandoSistema.h	
SOURCES=Qt/Cpp/QtSiscomServiSNTE.cpp	\
	Qt/Cpp/QtPrincipalServiSNTE.cpp	\
	Qt/Cpp/QtImpAccesoServiSNTE.cpp	\
	Qt/Cpp/QtImpActualizandoSistema.cpp	\
	Cpp/zVerificaActualizacion.cpp



TEMPLATE=app
Target=ServiSNTEApp
