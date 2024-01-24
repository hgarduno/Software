#!/bin/sh 

LD_LIBRARY_PATH=$QTDIR/lib:$HOME/Trampolin/Cliente/SO:$QTDIR/plugins/designer:$DIRLIBSISCOM2:$QTDIR/plugins/designer:$KDEDIR/lib

PATH=$HOME/Trampolin/Cliente/
DirectorioConfiguracion=$HOME/Trampolin/Configuracion
ArchivoConfiguracionModulos=SiscomTrampolin.xml
Aplicacion=SISCOMEscuelas
PtoComSvr2=2645
RutaIconos=/Cliente/Iconos
ArchivoServidores=$HOME/.SiscomEscuelas.txt

#IdExpendio=-1165435786
IdExpendio=-1165434773
DirIpSvr=127.0.0.1
PtoComSvr=5645

#export	LD_LIBRARY_PATH \
#	PATH	\
#	DirectorioConfiguracion \
#	ArchivoConfiguracionModulos \
#	Aplicacion	\
#	PtoComSvr2	\
#	RutaIconos	\
#	ArchivoServidores \
#	Aplicacion
#
export LD_LIBRARY_PATH
export PATH
export DirectorioConfiguracion
export ArchivoConfiguracionModulos
export Aplicacion
export PtoComSvr2 
export RutaIconos
export ArchivoServidores 

export IdExpendio
export DirIpSvr
export PtoComSvr

ulimit -c 0

PruebaForma 1 1 #Maximizada
