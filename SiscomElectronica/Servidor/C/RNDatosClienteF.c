#include <RNDatosClienteF.h>
#include <RNPersonas.h>
#include <ServidorGeneral.h>
#include <ComunElectronica.h>
#include <ComunElectronica2.h>
#include <string.h>

extern StcSiscomConfiguracion gSSiscomConfiguracionSvr;
StcConsultas gStcCnsDatosClienteF[]={ {EsConsultaDatosClienteF,FormaConsultaDatosClienteF}
			       };
int gintCnsDatosClienteF=1;

int EsConsultaDatosClienteF(char **pchrPtrEntrada)
{
	return !strcmp(pchrPtrEntrada[0],"ConsultaDatosClienteF");
}
void FormaConsultaDatosClienteF(char **pchrPtrEntrada,
			   SiscomOperacionesServidor *pSOpServidor)
{
char lchrArrConsulta[128];

	sprintf(lchrArrConsulta,
		"SELECT * from clientefrecuente where idexpendio=%s;",
		pchrPtrEntrada[1]);
 SiscomInformacionOperaciones("ConsultaSQL","Consultas",pSOpServidor);
 SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2EPrim,
		         &pSOpServidor->LCSiscomPro2EAct,
			&pSOpServidor->intNRegistros,
			"ConsultaSQL",
			lchrArrConsulta);

pSOpServidor->EjecutaProcesoDespues=0;

}
void AnalizaConsultaDatosClienteF(char **pchrPtrEntrada,
			      SiscomOperacionesServidor *pSOpServidor)
{
int lintContador;
	for(lintContador=0;
	    lintContador<gintCnsDatosClienteF;
	    lintContador++)
	   if(gStcCnsDatosClienteF[lintContador].Consulta(pchrPtrEntrada))
	      gStcCnsDatosClienteF[lintContador].FormaConsulta(pchrPtrEntrada,
	     						  pSOpServidor);

	

}
void ConsultaDatosClienteF(int pintSocket,
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
	
	ElectronicaComunicacionExpendio2(
			lchrPtrEntrada[1],
			&lSOpServidor.intPtoCom,
			lSOpServidor.chrPtrDirIpSvr,
			0);
					 
	AnalizaConsultaDatosClienteF(lchrPtrEntrada,&lSOpServidor);
	SiscomOperacionesServidores(&lSOpServidor);
	SiscomEnviaAlServidor(pintSocket,
			      lSOpServidor.intNRegistrosRes,
			      "ClientesRegistrados",
			      lSOpServidor.LCSiscomPro2);

	close(pintSocket);
}

void RegistraDatosClienteF(int pintSocket,
			int pintNRegistros)
{
LCamposSiscomPro2 *lLCSiscomPro2=0;
LCamposSiscomPro2 *lLCSiscomPro2Ins=0,
                  *lLCSiscomPro2InsAct=0;
char lchrArrActualiza[1204];
char *lchrPtrEdoConexion=0;
const char *lchrPtrEdoRegistro;
int lintNRegistros=0,
    lintSocketAD;
int lintIdDatCliF;
int lintContador;
char *lchrPtrIdExpendio;
int lintPtoCom;
char lchrArrDirIpSvr[35];
SiscomLeeInformacionProtocolo(pintSocket,
                                      pintNRegistros,
                                      &lLCSiscomPro2);
SiscomImprimeContenidoProtocolo("",gPtrFleArchivoLog,lLCSiscomPro2);

	lchrPtrIdExpendio=(char *)SiscomObtenDato(lLCSiscomPro2,"IdExpendio");
  for(lintContador=0;
  	lLCSiscomPro2;
	lLCSiscomPro2=lLCSiscomPro2->SCP2PtrSig,
	lintContador++)
  {
  	 lintIdDatCliF=SiscomObtenNumeroUnico();	
	 lchrPtrEdoRegistro=SiscomObtenDato(lLCSiscomPro2,"EdoRegistro");
	 if(lchrPtrEdoRegistro &&
	    !lchrPtrEdoRegistro[0])
	 {
	 sprintf(lchrArrActualiza,
	 	 "insert into clientefrecuente values(%d,%s,%s,%s,%s,%s,%s);",
		 lintIdDatCliF+lintContador,
		 SiscomObtenDato(lLCSiscomPro2,"NumDias"),
		 SiscomObtenDato(lLCSiscomPro2,"LimiteInferior"),
		 SiscomObtenDato(lLCSiscomPro2,"LimiteSuperior"),
		 SiscomObtenDato(lLCSiscomPro2,"Descuento"),
		 SiscomObtenDato(lLCSiscomPro2,"IdAutorizo"),
		 SiscomObtenDato(lLCSiscomPro2,"IdExpendio"));
	 SiscomAnexaRegistroPro2(&lLCSiscomPro2Ins,
	 			 &lLCSiscomPro2InsAct,
				 &lintNRegistros,
				 "ComandoSQL",
				 lchrArrActualiza);
	 sprintf(lchrArrActualiza,
	 	 "update clientefrecuente set numDias=%s",
		 SiscomObtenDato(lLCSiscomPro2,"NumDias"));
	  SiscomAnexaRegistroPro2(&lLCSiscomPro2Ins,
	 			 &lLCSiscomPro2InsAct,
				 &lintNRegistros,
				 "ComandoSQL",
				 lchrArrActualiza);
	 }
	 else
	 if(!strcmp(SiscomObtenDato(lLCSiscomPro2,"EdoRegistro"),"Actualiza"))
	 {
	   sprintf(lchrArrActualiza,
	   	   "update clientefrecuente 		\
		   	   set NumDias=%s ,		\
			       LimiteInferior=%s,	\
			       LimiteSuperior=%s,	\
			       Descuento=%s		\
	             where idDatoClienteF=%s",
		    SiscomObtenDato(lLCSiscomPro2,"NumDias"),
		    SiscomObtenDato(lLCSiscomPro2,"LimiteInferior"),
		    SiscomObtenDato(lLCSiscomPro2,"LimiteSuperior"),
		    SiscomObtenDato(lLCSiscomPro2,"Descuento"),
		    SiscomObtenDato(lLCSiscomPro2,"IdDatoClienteF"));

	  SiscomAnexaRegistroPro2(&lLCSiscomPro2Ins,
	 			 &lLCSiscomPro2InsAct,
				 &lintNRegistros,
				 "ComandoSQL",
				 lchrArrActualiza);
	sprintf(lchrArrActualiza,
	 	 "update clientefrecuente set numDias=%s",
		 SiscomObtenDato(lLCSiscomPro2,"NumDias"));
	  SiscomAnexaRegistroPro2(&lLCSiscomPro2Ins,
	 			 &lLCSiscomPro2InsAct,
				 &lintNRegistros,
				 "ComandoSQL",
				 lchrArrActualiza);


		   		
	 }
	 else
	 if(!strcmp(SiscomObtenDato(lLCSiscomPro2,"EdoRegistro"),"Elimina"))
	 {
	   sprintf(lchrArrActualiza,
	   	   "delete from clientefrecuente where idDatoClienteF=%s;",
		    SiscomObtenDato(lLCSiscomPro2,"IdDatoClienteF"));

	  SiscomAnexaRegistroPro2(&lLCSiscomPro2Ins,
	 			 &lLCSiscomPro2InsAct,
				 &lintNRegistros,
				 "ComandoSQL",
				 lchrArrActualiza);
	 }
  }
  SiscomImprimeContenidoProtocolo("",
  				  gPtrFleArchivoLog,
				  lLCSiscomPro2Ins);
  				  
  	ElectronicaComunicacionExpendio2(lchrPtrIdExpendio,
					 &lintPtoCom,
					 lchrArrDirIpSvr,
					 0);
					 
	SiscomInformacionServidor(lintPtoCom,
	                          lchrArrDirIpSvr,
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
