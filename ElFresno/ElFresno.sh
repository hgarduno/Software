#!/bin/sh 

#LD_LIBRARY_PATH=$QTDIR/lib:$SISCOM_LIB_DIR:Cliente/SO/:$DIRLIBSISCOM2:$QTDIR/plugins/designer:
LD_LIBRARY_PATH=$SISCOM_LIB_DIR:$QTDIR/lib:$DIRLIBSISCOM2:Cliente/SO:$DIRDesarrolloHGE/SISCOMControles:$DIRLIBSISCOM2:/QT/plugins/designer/


### Se anexo la ruta, de la biblioteca /usr/local/hgarduno/ProyectosSiscom/LibSiscom1.5/libInterfazSISCOMTiendasFirmaUsuario2.so

########  

#######



########### Por la integracion con el sistema actual de Firmas

ArchivoServidores=$HOME/.ComunicacionesElFresno

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$HOME/ProyectosSiscom/LibSiscom1.5
PATH=Cliente/
DirectorioConfiguracion=Configuracion
ArchivoConfiguracionModulos=ElFresno.xml
PtoComSvr2=2645
MAXIMIZADA=Si
Aplicacion=ElFresno
export	LD_LIBRARY_PATH 		\
	PATH				\
	DirectorioConfiguracion 	\
	ArchivoConfiguracionModulos 	\
	MAXIMIZADA 			\
	DISPLAY 			\
	Aplicacion 			\
	PtoComSvr2			\
	ArchivoServidores



ElFresno $* &
