#include <SiscomDatCom.h>
/*! \file SiscomDatCom.cpp
 *  \brief SISCOM Electronica
 *  Archivo que contiene el manejo de la informacion
 *  para los datos de conexion entre el cliente y 
 *  el servidor
 */ 
SiscomDatCom::SiscomDatCom(int pintPtoCom,
			   const char *pchrPtrDirIpSvr):
			intPtoCom(pintPtoCom),
			chrPtrDirIpSvr(pchrPtrDirIpSvr)
{

}


SiscomDatCom::SiscomDatCom(int pintPtoCom,
			   const char *pchrPtrDirIpSvr,
			   const char *pchrPtrDescServidor):
			intPtoCom(pintPtoCom),
			chrPtrDirIpSvr(pchrPtrDirIpSvr),
			chrPtrDescServidor(pchrPtrDescServidor)
{

}
int SiscomDatCom::SiscomObtenPuertoCom()
{
	return intPtoCom;
}
const char *SiscomDatCom::SiscomObtenDireccionIp()
{
	return chrPtrDirIpSvr;
}
void SiscomDatCom::SiscomDescripcionServidor(const char *pchrPtrDescServidor)
{
chrPtrDescServidor=pchrPtrDescServidor;
}
const char *SiscomDatCom::SiscomDescripcionServidor()
{
return chrPtrDescServidor;
}
