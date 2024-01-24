#include<ControlInventarios.h>

StcConsultaSvrSiscom2 gStcCnsControlInventarios[]={
			   {EsConsultaControlInventarios,FormaConsultaControlInventarios}
			   };
int gintCnsControlInventarios=1;
int EsConsultaControlInventarios(char **pchrPtrEntrada)
{
	return !strcmp(pchrPtrEntrada[0],"ControlInventarios");
}
void FormaConsultaControlInventarios(char **pchrPtrEntrada,
		     SiscomOperacionesServidor *pSOpServidor)
{
char lchrArrConsulta[1024];
sprintf(lchrArrConsulta,"select * from ??? ");
SiscomInformacionOperaciones("ConsultaSQL","Consultas",pSOpServidor);
SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2EPrim,
			&pSOpServidor->LCSiscomPro2EAct,
			&pSOpServidor->intNRegistros,
			"ConsultaSQL",
			lchrArrConsulta);
pSOpServidor->EjecutaProcesoDespues=0;
}
void AnalizaConsultaControlInventarios(char **pchrPtrEntrada, 
			SiscomOperacionesServidor *pSOpServidor)
{ 
int lintContador;
for(lintContador=0;
    lintContador<gintCnsControlInventarios;
    lintContador++)
{
if(gStcCnsControlInventarios[lintContador].Consulta(pchrPtrEntrada))
gStcCnsControlInventarios[lintContador].FormaConsulta(pchrPtrEntrada,pSOpServidor);
}
}
void ConsultaControlInventarios(int pintSocket,int pintNRegistros)
{
SiscomOperacionesServidor lSOpServidor;
char **lchrPtrEntrada;
lSOpServidor.EjecutaProcesoAntes=0;
SiscomIniciaComunicacionesSrv(gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
			   gSSiscomConfiguracionSvr.intPtoAccesoDatos,
			   &lSOpServidor);
SiscomLeeInformacionProtocolo(pintSocket,
		     pintNRegistros,
		     &lSOpServidor.LCSiscomPro2Dat);
SiscomImprimeContenidoProtocolo("",gPtrFleArchivoLog,lSOpServidor.LCSiscomPro2Dat);
SiscomCopiaDatosProtocoloCharChar(lSOpServidor.LCSiscomPro2Dat,
				  pintNRegistros,
				  "Parametro",
				  &lchrPtrEntrada);
AnalizaConsultaControlInventarios(lchrPtrEntrada,&lSOpServidor); 
SiscomOperacionesServidores(&lSOpServidor);
SiscomEnviaAlServidor(pintSocket,
		      lSOpServidor.intNRegistrosRes,
		      "Respuesta",
		      lSOpServidor.LCSiscomPro2);
close(pintSocket);
}
int CreaCadenaComandoControlInventariosSql(LCamposSiscomPro2 *pLCSiscomPro2, 
			 char *pchrPtrCadena)
{
	if(!strcmp(SiscomObtenDato(pLCSiscomPro2,"EdoRegistro"),"Insertar"))
	{
	 return 1;
	}
  return 0;
}
void RegistraControlInventarios(int pintSocket,int pintNRegistros)
{
LCamposSiscomPro2 *lLCSiscomPro2=0;
LCamposSiscomPro2 *lLCSiscomPro2Ins=0,
		  *lLCSiscomPro2InsAct=0;
char lchrArrInsercion[1024];
int lintNRegistros=0;
int lintSocketAD;
char *lchrPtrEdoConexion=0;
SiscomLeeInformacionProtocolo(pintSocket,pintNRegistros,&lLCSiscomPro2);
SiscomImprimeContenidoProtocolo("??",gPtrFleArchivoLog,lLCSiscomPro2);
for(;		
	lLCSiscomPro2;
    lLCSiscomPro2=lLCSiscomPro2->SCP2PtrSig)
if(CreaCadenaComandoControlInventariosSql(lLCSiscomPro2,lchrArrInsercion))
SiscomAnexaRegistroPro2(&lLCSiscomPro2Ins,
			&lLCSiscomPro2InsAct,
			&lintNRegistros,
			"ComandoSQL",
			lchrArrInsercion);
SiscomInformacionServidor(
	gSSiscomConfiguracionSvr.intPtoAccesoDatos,
	gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
	"Inserciones",
	lintNRegistros,
	lLCSiscomPro2Ins,
	&lchrPtrEdoConexion,
	&lintSocketAD);
if(lchrPtrEdoConexion)
SiscomMensajesLog(gPtrFleArchivoLog,"Error al Envia:ControlInventarios",lchrPtrEdoConexion);
}

