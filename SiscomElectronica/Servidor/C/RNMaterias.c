#include <RNMaterias.h>
#include <RNPersonas.h>
#include <ServidorGeneral.h>
#include <string.h>
extern StcSiscomConfiguracion gSSiscomConfiguracionSvr;
StcConsultas gStcCnsMaterias[]={ {EsConsultaMaterias,FormaConsultaMaterias}
			       };
int gintCnsMaterias=1;

int EsConsultaMaterias(char **pchrPtrEntrada)
{
	if(pchrPtrEntrada[0][0])
	return 1;
	else
	return 0;
}
void FormaConsultaMaterias(char **pchrPtrEntrada,
			   SiscomOperacionesServidor *pSOpServidor)
{
char lchrArrConsulta[128];

	sprintf(lchrArrConsulta,
		"select *		\
		from materias 		\
		where idEscuela=%s",
		pchrPtrEntrada[0]);
 SiscomInformacionOperaciones("ConsultaSQL","Consultas",pSOpServidor);
 SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2EPrim,
		         &pSOpServidor->LCSiscomPro2EAct,
			&pSOpServidor->intNRegistros,
			"ConsultaSQL",
			lchrArrConsulta);


}
void AnalizaConsultaMaterias(char **pchrPtrEntrada,
			      SiscomOperacionesServidor *pSOpServidor)
{
int lintContador;
	for(lintContador=0;
	    lintContador<gintCnsMaterias;
	    lintContador++)
	   if(gStcCnsMaterias[lintContador].Consulta(pchrPtrEntrada))
	      gStcCnsMaterias[lintContador].FormaConsulta(pchrPtrEntrada,
	     						  pSOpServidor);

	

}
void ConsultaMaterias(int pintSocket,
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
	AnalizaConsultaMaterias(lchrPtrEntrada,&lSOpServidor);
	SiscomOperacionesServidores(&lSOpServidor);
	SiscomEnviaAlServidor(pintSocket,
			      lSOpServidor.intNRegistrosRes,
			      "ClientesRegistrados",
			      lSOpServidor.LCSiscomPro2);

	close(pintSocket);
}

void FormaCadenaOperacionSqlMaterias(int lintContador,
			     LCamposSiscomPro2 *pLCSiscomPro2,
			     char *pchrPtrCadena)
{

	if(!strcmp(SiscomObtenDato(pLCSiscomPro2,"EdoRegistro"),"Insertar"))
	{
	 sprintf(pchrPtrCadena,
	 	 "insert into Materias values(%s,%ld,'%s');",
		 SiscomObtenDato(pLCSiscomPro2,"IdEscuela"),
		 SiscomObtenNumeroUnico()+lintContador,
		 SiscomObtenDato(pLCSiscomPro2,"Nombre"));
	}

		   


}
void RegistraMaterias(int pintSocket,
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
  for(lintContador=0;
  	lLCSiscomPro2;
	lLCSiscomPro2=lLCSiscomPro2->SCP2PtrSig,
	lintContador++)
  {
  	 FormaCadenaOperacionSqlMaterias(lintContador,lLCSiscomPro2,lchrArrActualiza); 
	 SiscomAnexaRegistroPro2(&lLCSiscomPro2Ins,
	 			 &lLCSiscomPro2InsAct,
				 &lintNRegistros,
				 "ComandoSQL",
				 lchrArrActualiza);
  }
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
