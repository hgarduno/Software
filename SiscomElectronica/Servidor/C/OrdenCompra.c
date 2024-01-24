#include<OrdenCompra.h>
#include <string.h>
StcConsultaSvrSiscom2 gStcCnsOrdenCompra[]={
			   {EsConsultaOrdenCompra,FormaConsultaOrdenCompra}
			   };
int gintCnsOrdenCompra=1;
int EsConsultaOrdenCompra(char **pchrPtrEntrada)
{
	return !strcmp(pchrPtrEntrada[0],"OrdenCompra");
}
void FormaConsultaOrdenCompra(char **pchrPtrEntrada,
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
void AnalizaConsultaOrdenCompra(char **pchrPtrEntrada, 
			SiscomOperacionesServidor *pSOpServidor)
{ 
int lintContador;
for(lintContador=0;
    lintContador<gintCnsOrdenCompra;
    lintContador++)
{
if(gStcCnsOrdenCompra[lintContador].Consulta(pchrPtrEntrada))
gStcCnsOrdenCompra[lintContador].FormaConsulta(pchrPtrEntrada,pSOpServidor);
}
}
void ConsultaOrdenCompra(int pintSocket,int pintNRegistros)
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
AnalizaConsultaOrdenCompra(lchrPtrEntrada,&lSOpServidor); 
SiscomOperacionesServidores(&lSOpServidor);
SiscomEnviaAlServidor(pintSocket,
		      lSOpServidor.intNRegistrosRes,
		      "Respuesta",
		      lSOpServidor.LCSiscomPro2);
close(pintSocket);
}
int CreaCadenaComandoOrdenCompraSql(LCamposSiscomPro2 *pLCSiscomPro2, 
			 char *pchrPtrCadena)
{
	if(!strcmp(SiscomObtenDato(pLCSiscomPro2,"EdoRegistro"),"Insertar"))
	{
	 return 1;
	}
  return 0;
}
void RegistraOrdenCompra(int pintSocket,int pintNRegistros)
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
if(CreaCadenaComandoOrdenCompraSql(lLCSiscomPro2,lchrArrInsercion))
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
SiscomMensajesLog(gPtrFleArchivoLog,"Error al Envia:OrdenCompra",lchrPtrEdoConexion);
}

