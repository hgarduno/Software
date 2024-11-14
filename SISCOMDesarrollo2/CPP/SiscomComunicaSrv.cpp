#include <SiscomComunicaSrv.h>
#include <SiscomRegistrosPro2.h>
#include <SiscomDatCom.h>

SiscomComunicaSrv::SiscomComunicaSrv(SiscomDatCom *pSDatCom):
		SDatCom(pSDatCom),
		chrPtrEdoComunicacion(0),
		LCSiscomPro2PrimRes(0)
{
	/* CDMX , a Sabado 18 de diciembre del 2021
	 * Seguimos con lo del COVID, y no podemos salir
	 *
	 * Se cambia a la version no bloqueante de la funcion de conexion
	 * debido a que en la conexion para los expendios, si no esta 
	 * arriba el servidor se queda ahi pegado
	 *
	intSocket=SiscomConectateServidor(SDatCom->SiscomObtenPuertoCom(),
					  SDatCom->SiscomObtenDireccionIp(),
					  &chrPtrEdoComunicacion);

	*/
	intSocket=SiscomConectateClienteNoBloqueante(
					  SDatCom->SiscomObtenDireccionIp(),
					  SDatCom->SiscomObtenPuertoCom(),
					  2,
					  &chrPtrEdoComunicacion);
 

}
SiscomComunicaSrv::~SiscomComunicaSrv()
{
	close(intSocket);
}
void SiscomComunicaSrv::SiscomEnvia(SiscomRegistrosPro2 *pSRegistrosPro2,
				    const char *pchrPtrOperacion)
{
	if(!chrPtrEdoComunicacion)	
	{
	 SiscomEnviaVersionProtocolo(intSocket);   
	 SiscomEnviaAlServidor(intSocket,
			       pSRegistrosPro2->SiscomObtenNumRegistros(),
			       pchrPtrOperacion,
			       pSRegistrosPro2->SiscomObtenRegistros());
	}
}
int SiscomComunicaSrv::SiscomObtenRespuesta()
{
	LCSiscomPro2PrimRes=0;
	intNRegistrosRes=0;
	SiscomLeeNumeroRegistros(intSocket,
				 &intNRegistrosRes);
	if(intNRegistrosRes)
	{
	SiscomLeeOperacion(intSocket,
			   &chrPtrOperacion);
	SiscomLeeInformacionProtocolo(intSocket,
				      intNRegistrosRes,
				      &LCSiscomPro2PrimRes);

	}
	
	return intNRegistrosRes;			     
}
const char *SiscomComunicaSrv::SiscomObtenEdoConexion()
{
	return chrPtrEdoComunicacion;
}
int SiscomComunicaSrv::SiscomObtenSocket()
{
	return intSocket;
}
LCamposSiscomPro2 *SiscomComunicaSrv::SiscomRegistrosRespuesta()
{
	return LCSiscomPro2PrimRes;
}
int SiscomComunicaSrv::SiscomObtenNumRegistrosRes()
{
	return intNRegistrosRes;
}
const char *SiscomComunicaSrv::SiscomObtenOperacion()
{
	return chrPtrOperacion;
}
