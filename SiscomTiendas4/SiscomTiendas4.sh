#!/bin/sh 

DirSistema=$HOME/SiscomTiendas4

LD_LIBRARY_PATH=$QTDIR/lib:$DIRDesarrolloHGE/SiscomTiendas4/Cliente/SO:$QTDIR/plugins/designer:$DIRLIBSISCOM2:$QTDIR/plugins/designer:$KDEDIR/lib:$SISCOM_LIB_DIR:$DIRDesarrolloHGE//GeneraValidacionCpuInfo/XPS/SO

PATH=$PATH:$DIRDesarrolloHGE/SiscomTiendas4/Cliente/
DirectorioConfiguracion=$DIRDesarrolloHGE/SiscomTiendas4/Configuracion
ArchivoConfiguracionModulos=Configuracion/SiscomTiendas4.hgarduno
Aplicacion=SiscomTiendas4
#Aplicacion=Seid
#PtoComSvr2=2645
RutaIconos=/Cliente/Iconos
ArchivoServidores=$HOME/.SiscomTiendas4Comunicaciones.txt

#UtilizacionVentas=libSiscomVentasNivelDosLapTopDell.so
#FuncionUtilizacionVentas=UtilizacionNivelDos
#FuncionUtilizacionPrincipal=NivelDosPrincipal

UtilizacionVentas=libSiscomVentasUtilizacionLinuxHGE.so
CpuInfo=CpuInfo
ArchivoTicket=/usr/local/hgarduno/SiscomTiendas4/TicketMolinoZuniga.txt
export UtilizacionVentas
export CpuInfo
export FuncionUtilizacionVentas
export FuncionUtilizacionPrincipal

#DirIpSvr=127.0.0.1
#PtoComSvr=5650

export LD_LIBRARY_PATH
export PATH
export DirectorioConfiguracion
export ArchivoConfiguracionModulos
export Aplicacion
export RutaIconos
export ArchivoServidores 
export IdExpendio
export ArchivoTicket
export DirSistema

echo $Aplicacion
if [ "$1" == "Debug" ]
then
gdb SiscomTiendas4
else
SiscomTiendas4  $*
fi
