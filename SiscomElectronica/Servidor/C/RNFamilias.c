#include <RNFamilias.h>
#include <RNPersonas.h>
#include <RNCotizaDispositivos.h>
#include <ServidorGeneral.h>
#include <string.h>

extern StcSiscomConfiguracion gSSiscomConfiguracionSvr;
StcConsultas gStcCnsFamilias[]={ {EsConsultaFamilias,FormaConsultaFamilias}
			       };
int gintCnsFamilias=2;

int EsConsultaFamilias(char **pchrPtrEntrada)
{
	return !strcmp(pchrPtrEntrada[0],"Familias");
}
void FormaConsultaFamilias(char **pchrPtrEntrada,
			   SiscomOperacionesServidor *pSOpServidor)
{

 SiscomInformacionOperaciones("ConsultaSQL","Consultas",pSOpServidor);
 SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2EPrim,
		         &pSOpServidor->LCSiscomPro2EAct,
			&pSOpServidor->intNRegistros,
			"ConsultaSQL",
			"select * from familias");


}
void AnalizaConsultaFamilias(char **pchrPtrEntrada,
			      SiscomOperacionesServidor *pSOpServidor)
{
int lintContador;
	for(lintContador=0;
	    lintContador<gintCnsFamilias;
	    lintContador++)
	   if(gStcCnsFamilias[lintContador].Consulta(pchrPtrEntrada))
	   {
	      gStcCnsFamilias[lintContador].FormaConsulta(pchrPtrEntrada,
	     						  pSOpServidor);
	      break;
	   }

	

}
void ConsultaFamilias(int pintSocket,
		       int pintNRegistros)
{
SiscomOperacionesServidor lSOpServidor;
char **lchrPtrEntrada=0;

	lSOpServidor.EjecutaProcesoAntes=0;
	SiscomIniciaComunicacionesSrv(gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
				      gSSiscomConfiguracionSvr.intPtoAccesoDatos,
				      &lSOpServidor);
	SiscomLeeInformacionProtocolo(pintSocket,
				      pintNRegistros,
				      &lSOpServidor.LCSiscomPro2Dat);
	SiscomCopiaDatosProtocoloCharChar(lSOpServidor.LCSiscomPro2Dat,
					  pintNRegistros,
					  "Parametro",
					  &lchrPtrEntrada);
	AnalizaConsultaFamilias(lchrPtrEntrada,&lSOpServidor);
	SiscomOperacionesServidores(&lSOpServidor);
	SiscomEnviaAlServidor(pintSocket,
			      lSOpServidor.intNRegistrosRes,
			      "ClientesRegistrados",
			      lSOpServidor.LCSiscomPro2);
	close(pintSocket);
}
int FormaCadenaOperacionSqlFamilias(int lintContador,
			     LCamposSiscomPro2 *pLCSiscomPro2,
			     char *pchrPtrCadena)
{
int lintRegreso=0;
	if(!strcmp(SiscomObtenDato(pLCSiscomPro2,"EdoRegistro"),"Insertar"))
	{
	 sprintf(pchrPtrCadena,
	 	 "insert into Familias values(%ld,'%s','%s');",
		 SiscomObtenNumeroUnico()+lintContador,
		 SiscomObtenDato(pLCSiscomPro2,"NmbFamilia"),
		 SiscomObtenDato(pLCSiscomPro2,"DscFamilia"));
	  lintRegreso=1;
	}
	if(!strcmp(SiscomObtenDato(pLCSiscomPro2,"EdoRegistro"),"Actualiza"))
	{
	 sprintf(pchrPtrCadena,
	 	 "update familias set NmbFamilia='%s',         	\
		 		      DscFamilia='%s'		\
		  where IdFamilia=%s",
		  SiscomObtenDato(pLCSiscomPro2,"NmbFamilia"),
		  SiscomObtenDato(pLCSiscomPro2,"DscFamilia"),
		  SiscomObtenDato(pLCSiscomPro2,"IdFamilia"));
	 lintRegreso=1;
	}
		  
	return lintRegreso;


}
void RegistraFamilias(int pintSocket,
			int pintNRegistros)
{
LCamposSiscomPro2 *lLCSiscomPro2=0;
LCamposSiscomPro2 *lLCSiscomPro2Ins=0,
                  *lLCSiscomPro2InsAct=0;
char lchrArrActualiza[1204];
char *lchrPtrEdoConexion=0;
int     lintSocketAD,
        lintNRegistros=0,
	lintContador;
SiscomLeeInformacionProtocolo(pintSocket,
                                      pintNRegistros,
                                      &lLCSiscomPro2);
SiscomMensajesLog(gPtrFleArchivoLog,
		  "RegistraFamilias");
SiscomImprimeContenidoProtocolo("",gPtrFleArchivoLog,lLCSiscomPro2);
  for(lintContador=0;
  	lLCSiscomPro2;
	lLCSiscomPro2=lLCSiscomPro2->SCP2PtrSig,
	lintContador++)
  {
  	 if(FormaCadenaOperacionSqlFamilias(lintContador,lLCSiscomPro2,lchrArrActualiza))
	 SiscomAnexaRegistroPro2(&lLCSiscomPro2Ins,
	 			 &lLCSiscomPro2InsAct,
				 &lintNRegistros,
				 "ComandoSQL",
				 lchrArrActualiza);
  }
  	SiscomImprimeContenidoProtocolo("",gPtrFleArchivoLog,lLCSiscomPro2Ins);
	SiscomInformacionServidor(gSSiscomConfiguracionSvr.intPtoAccesoDatos,
	                          gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
				  "Inserciones",
				  lintNRegistros,
				  lLCSiscomPro2Ins,
				  &lchrPtrEdoConexion,
				  &lintSocketAD);
	if(lchrPtrEdoConexion)
	SiscomMensajesLog(gPtrFleArchivoLog,
			  "Error Al Enviar:%s",
	                  lchrPtrEdoConexion);
}

