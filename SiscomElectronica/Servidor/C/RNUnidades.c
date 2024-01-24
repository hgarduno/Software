#include <RNUnidades.h>
#include <RNPersonas.h>
#include <RNCotizaDispositivos.h>
#include <ServidorGeneral.h>
#include <string.h>

extern StcSiscomConfiguracion gSSiscomConfiguracionSvr;
StcConsultas gStcCnsUnidades[]={ {EsConsultaUnidades,FormaConsultaUnidades}
			       };
int gintCnsUnidades=1;

int EsConsultaUnidades(char **pchrPtrEntrada)
{
	return !strcmp(pchrPtrEntrada[0],"Unidades");
}
void FormaConsultaUnidades(char **pchrPtrEntrada,
			   SiscomOperacionesServidor *pSOpServidor)
{

 SiscomInformacionOperaciones("ConsultaSQL","Consultas",pSOpServidor);
 SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2EPrim,
		         &pSOpServidor->LCSiscomPro2EAct,
			&pSOpServidor->intNRegistros,
			"ConsultaSQL",
			"select * from unidades");


}
void AnalizaConsultaUnidades(char **pchrPtrEntrada,
			      SiscomOperacionesServidor *pSOpServidor)
{
int lintContador;
	for(lintContador=0;
	    lintContador<gintCnsUnidades;
	    lintContador++)
	   if(gStcCnsUnidades[lintContador].Consulta(pchrPtrEntrada))
	   {
	      gStcCnsUnidades[lintContador].FormaConsulta(pchrPtrEntrada,
	     						  pSOpServidor);
	      break;
	   }

	

}
void ConsultaUnidades(int pintSocket,
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
	AnalizaConsultaUnidades(lchrPtrEntrada,&lSOpServidor);
	SiscomOperacionesServidores(&lSOpServidor);
	SiscomEnviaAlServidor(pintSocket,
			      lSOpServidor.intNRegistrosRes,
			      "ClientesRegistrados",
			      lSOpServidor.LCSiscomPro2);
	close(pintSocket);
}
void FormaCadenaOperacionSqlUnidades(int lintContador,
			     LCamposSiscomPro2 *pLCSiscomPro2,
			     char *pchrPtrCadena)
{
	if(!strcmp(SiscomObtenDato(pLCSiscomPro2,"EdoRegistro"),"Insertar"))
	{
	 sprintf(pchrPtrCadena,
	 	 "insert into Unidades values(%ld,%s,'%s');",
		 SiscomObtenNumeroUnico()+lintContador,
		 SiscomObtenDato(pLCSiscomPro2,"IdMateria"),
		 SiscomObtenDato(pLCSiscomPro2,"Nombre"));
	}

	

}
void RegistraUnidades(int pintSocket,
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
		  "RegistraUnidades");
SiscomImprimeContenidoProtocolo("",gPtrFleArchivoLog,lLCSiscomPro2);
  for(lintContador=0;
  	lLCSiscomPro2;
	lLCSiscomPro2=lLCSiscomPro2->SCP2PtrSig,
	lintContador++)
  {
  	 FormaCadenaOperacionSqlUnidades(lintContador,lLCSiscomPro2,lchrArrActualiza); 
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
