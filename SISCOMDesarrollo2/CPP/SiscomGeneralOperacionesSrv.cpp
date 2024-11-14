#include <SiscomGeneralOperacionesSrv.h>
#include <SiscomComunicaSrv.h>

SiscomGeneralOperacionesSrv::SiscomGeneralOperacionesSrv(
			SiscomDatCom *pSDatCom,
			QPtrList<SiscomInformacion> *pPtrInformacion):
		SDatCom(pSDatCom),
		PtrInformacion(pPtrInformacion),
		chrPtrEdoConexion(0)
{


}
void SiscomGeneralOperacionesSrv::SiscomImprimeInformacion()
{
SiscomInformacion *lSInformacion;
	SiscomRegistrosPro2 lSRegistrosPro2;
int lintRegistros=0;
for(lSInformacion=PtrInformacion->first();
    lSInformacion;
    lSInformacion=PtrInformacion->next())
{
lSRegistrosPro2=(SiscomRegistrosPro2 &)(*lSInformacion);
printf("SiscomGeneralOperacionesSrv::SiscomImprimeInformacion\n");
SiscomImprimeContenidoProtocolo2("",lSRegistrosPro2.SiscomObtenRegistros());

}

}
void SiscomGeneralOperacionesSrv::SiscomEjecutaEnvio2(const char *pchrPtrOperacion)
{
SiscomInformacion *lSInformacion;
SiscomRegistrosPro2 lSRegistrosPro2;
SiscomRegistrosPro2 lSRegistroPro2Int;
const char *lchrPtrEdoConexion;
		lSInformacion=PtrInformacion->first();
	     for(;
		 lSInformacion;
		 lSInformacion=PtrInformacion->next())
	     {
	     	 lSRegistroPro2Int=(SiscomRegistrosPro2 &)(*lSInformacion);
		 lSRegistroPro2Int.SiscomColocaPrimerRegistro();
		 for(;
		      !lSRegistroPro2Int.SiscomEsElUltimoRegistro();
		      ++lSRegistroPro2Int)
		  lSRegistrosPro2 << (const SCampoSiscomPro2 *)lSRegistroPro2Int;
	     }
	    SComunicaSrv=new SiscomComunicaSrv(SDatCom);  
	    if(!(lchrPtrEdoConexion=SComunicaSrv->SiscomObtenEdoConexion()))
	    {
		SComunicaSrv->SiscomEnvia(&lSRegistrosPro2,pchrPtrOperacion);
		SComunicaSrv->SiscomObtenRespuesta();
	    }
}
void SiscomGeneralOperacionesSrv::SiscomEjecutaEnvioSubRegistros(const char *pchrPtrOperacion)
{
SiscomInformacion *lSInformacion;
SiscomRegistrosPro2 lSRegistrosPro2;
SiscomRegistrosPro2 lSRegistrosPro2Envio;
const char *lchrPtrEdoConexion;
	     for(lSInformacion=PtrInformacion->first();
		 lSInformacion;
		 lSInformacion=PtrInformacion->next())
	     {
		lSRegistrosPro2=(SiscomRegistrosPro2 &)(*lSInformacion);
		lSRegistrosPro2.SiscomColocaPrimerRegistro();
		for(;
		     !lSRegistrosPro2.SiscomEsElUltimoRegistro();
		     ++lSRegistrosPro2)
		   lSRegistrosPro2Envio << (const SCampoSiscomPro2 *)lSRegistrosPro2;
	     }
	    SComunicaSrv=new SiscomComunicaSrv(SDatCom);  
	    if(!(lchrPtrEdoConexion=SComunicaSrv->SiscomObtenEdoConexion()))
	    {
		SComunicaSrv->SiscomEnvia(&lSRegistrosPro2Envio,pchrPtrOperacion);
		SComunicaSrv->SiscomObtenRespuesta();
	    }
}
void SiscomGeneralOperacionesSrv::SiscomEjecutaEnvio(const char *pchrPtrOperacion)
{
SiscomInformacion *lSInformacion;
SiscomRegistrosPro2 lSRegistrosPro2;
SiscomRegistroPro2 lSRegistroPro2;
		lSInformacion=PtrInformacion->first();
		lSRegistroPro2=(const SiscomRegistroPro2 &)(*lSInformacion);
		
	     for(;
		 lSInformacion;
		 lSInformacion=PtrInformacion->next())
		 lSRegistrosPro2 << (const SCampoSiscomPro2 *)(*lSInformacion);

	    SComunicaSrv=new SiscomComunicaSrv(SDatCom);  
	    if(!(chrPtrEdoConexion=SComunicaSrv->SiscomObtenEdoConexion()))
	    {
		SComunicaSrv->SiscomEnvia(&lSRegistrosPro2,pchrPtrOperacion);
		SComunicaSrv->SiscomObtenRespuesta();
	    }
}
const char *SiscomGeneralOperacionesSrv::EstadoConexion()
{
	return chrPtrEdoConexion;
}
