#include <RNEmpleadosExpendio.h>
#include <RNPersonas.h>
#include <ServidorGeneral.h>

#include <ComunElectronica.h>
#include <ComunElectronica2.h>
#include <string.h>

extern StcSiscomConfiguracion gSSiscomConfiguracionSvr;
StcConsultas gStcCnsEmpleadosExp[]={ {EsConsultaEmpleadosExp,FormaConsultaEmpleadosExp}
			       };
int gintCnsEmpleadosExp=1;

int EsConsultaEmpleadosExp(char **pchrPtrEntrada)
{
	return 1;
}
void FormaConsultaEmpleadosExp(char **pchrPtrEntrada,
			   SiscomOperacionesServidor *pSOpServidor)
{
char lchrArrConsulta[128];

	sprintf(lchrArrConsulta,
		"select *		\
		from empresas 		\
		where idEmpresa<0");
 SiscomInformacionOperaciones("ConsultaSQL","Consultas",pSOpServidor);
 SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2EPrim,
		         &pSOpServidor->LCSiscomPro2EAct,
			&pSOpServidor->intNRegistros,
			"ConsultaSQL",
			lchrArrConsulta);


pSOpServidor->EjecutaProcesoDespues=0;
}
void AnalizaConsultaEmpleadosExp(char **pchrPtrEntrada,
			      SiscomOperacionesServidor *pSOpServidor)
{
int lintContador;
	for(lintContador=0;
	    lintContador<gintCnsEmpleadosExp;
	    lintContador++)
	   if(gStcCnsEmpleadosExp[lintContador].Consulta(pchrPtrEntrada))
	      gStcCnsEmpleadosExp[lintContador].FormaConsulta(pchrPtrEntrada,
	     						  pSOpServidor);

	

}
void ConsultaEmpleadosExp(int pintSocket,
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
	AnalizaConsultaEmpleadosExp(lchrPtrEntrada,&lSOpServidor);
	SiscomOperacionesServidores(&lSOpServidor);
	SiscomEnviaAlServidor(pintSocket,
			      lSOpServidor.intNRegistrosRes,
			      "ClientesRegistrados",
			      lSOpServidor.LCSiscomPro2);

	close(pintSocket);
}

void AsignaEmpleadosExp(int pintSocket,
			int pintNRegistros)
{
LCamposSiscomPro2 *lLCSiscomPro2=0;
LCamposSiscomPro2 *lLCSiscomPro2Ins=0,
                  *lLCSiscomPro2InsAct=0;
char lchrArrActualiza[1204];
char *lchrPtrEdoConexion=0;
int lintNRegistros=0,
    lintSocketAD;
char **lchrPtrEntrada;
SiscomLeeInformacionProtocolo(pintSocket,
                                      pintNRegistros,
                                      &lLCSiscomPro2);
	SiscomCopiaDatosProtocoloCharChar(lLCSiscomPro2,
					  pintNRegistros,
					  "Parametro",
					  &lchrPtrEntrada);
	
  for(;
  	lLCSiscomPro2;
	lLCSiscomPro2=lLCSiscomPro2->SCP2PtrSig)
  {
  	
	 sprintf(lchrArrActualiza,
	 	"update firmas 			\
		        set idExpendio=%s 	\
		 where idPersona=%s;",
		  lchrPtrEntrada[1],
		  lchrPtrEntrada[0]);
	 SiscomAnexaRegistroPro2(&lLCSiscomPro2Ins,
	 			 &lLCSiscomPro2InsAct,
				 &lintNRegistros,
				 "ComandoSQL",
				 lchrArrActualiza);

  }
    SiscomMensajesLog(gPtrFleArchivoLog,
    		      "%s");
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
