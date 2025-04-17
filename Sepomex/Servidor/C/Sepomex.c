#include<Sepomex.h>
#include <SqlSepomex.h>
#include <string.h>
StcConsultaSvrSiscom2 gStcCnsSepomex[]={
			   {EsConsultaEstados,FormaConsultaEstados},
			   {EsConsultaTAsentamientos,FormaConsultaTAsentamientos},
			   {EsConsultaAsentamientos,FormaConsultaAsentamientos},
			   {EsConsultaMunicipios,FormaConsultaMunicipios}
			   };
int gintCnsSepomex=4;
int EsConsultaTAsentamientos(char **pchrPtrEntrada)
{
	return !strcmp(pchrPtrEntrada[0],"ConsultaTAsentamientos");
}
void FormaConsultaTAsentamientos(char **pchrPtrEntrada,
		     SiscomOperacionesServidor *pSOpServidor)
{
char lchrArrConsulta[1024];
sprintf(lchrArrConsulta, "select * from tipoasentamientos");
SiscomInformacionOperaciones("ConsultaSQL","Consultas",pSOpServidor);
SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2EPrim,
			&pSOpServidor->LCSiscomPro2EAct,
			&pSOpServidor->intNRegistros,
			"ConsultaSQL",	
			lchrArrConsulta);
pSOpServidor->EjecutaProcesoDespues=0;
}
int EsConsultaAsentamientos(char **pchrPtrEntrada)
{
	return !strcmp(pchrPtrEntrada[0],"ConsultaAsentamientos");
}
void FormaConsultaAsentamientos(char **pchrPtrEntrada,
		     SiscomOperacionesServidor *pSOpServidor)
{
char lchrArrConsulta[1024];
SiscomMensajesLog2("FormaConsultaAsentamientos");
sprintf(lchrArrConsulta,
	"select * 				\
	 from asentamientos			\
	 where numestado=%s and 		\
	       nummunicipio=%s 			\
	 order by asentamiento",
	 pchrPtrEntrada[1],
	 pchrPtrEntrada[2]);
SiscomInformacionOperaciones("ConsultaSQL","Consultas",pSOpServidor);
SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2EPrim,
			&pSOpServidor->LCSiscomPro2EAct,
			&pSOpServidor->intNRegistros,
			"ConsultaSQL",	
			lchrArrConsulta);
pSOpServidor->EjecutaProcesoDespues=0;
}

int EsConsultaEstados(char **pchrPtrEntrada)
{
	return !strcmp(pchrPtrEntrada[0],"ConsultaEstados");
}
void FormaConsultaEstados(char **pchrPtrEntrada,
		     SiscomOperacionesServidor *pSOpServidor)
{
char lchrArrConsulta[1024];
sprintf(lchrArrConsulta, "select * from estados");
SiscomInformacionOperaciones("ConsultaSQL","Consultas",pSOpServidor);
SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2EPrim,
			&pSOpServidor->LCSiscomPro2EAct,
			&pSOpServidor->intNRegistros,
			"ConsultaSQL",	
			lchrArrConsulta);
pSOpServidor->EjecutaProcesoDespues=0;
}


int EsConsultaMunicipios(char **pchrPtrEntrada)
{
	return !strcmp(pchrPtrEntrada[0],"ConsultaMunicipios");
}
void FormaConsultaMunicipios(char **pchrPtrEntrada,
		     SiscomOperacionesServidor *pSOpServidor)
{
char lchrArrConsulta[1024];
sprintf(lchrArrConsulta,
	 "select * 			\
	  from municipios 		\
	  where numestado=%s		\
	  order by municipio",
	  pchrPtrEntrada[1]);
SiscomInformacionOperaciones("ConsultaSQL","Consultas",pSOpServidor);
SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2EPrim,
			&pSOpServidor->LCSiscomPro2EAct,
			&pSOpServidor->intNRegistros,
			"ConsultaSQL",	
			lchrArrConsulta);
pSOpServidor->EjecutaProcesoDespues=0;
}
void AnalizaConsultaSepomex(char **pchrPtrEntrada, 
			SiscomOperacionesServidor *pSOpServidor)
{ 
int lintContador;
for(lintContador=0;
    lintContador<gintCnsSepomex;
    lintContador++)
{
if(gStcCnsSepomex[lintContador].Consulta(pchrPtrEntrada))
gStcCnsSepomex[lintContador].FormaConsulta(pchrPtrEntrada,pSOpServidor);
}
}
void ConsultaSepomex(int pintSocket,int pintNRegistros)
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
SiscomCopiaDatosProtocoloCharChar(lSOpServidor.LCSiscomPro2Dat,
				  pintNRegistros,
				  "Parametro",
				  &lchrPtrEntrada);
AnalizaConsultaSepomex(lchrPtrEntrada,&lSOpServidor); 
SiscomOperacionesServidores(&lSOpServidor);
SiscomEnviaAlServidor(pintSocket,
		      lSOpServidor.intNRegistrosRes,
		      "Respuesta",
		      lSOpServidor.LCSiscomPro2);
close(pintSocket);
}
int CreaCadenaComandoSepomexSql(LCamposSiscomPro2 *pLCSiscomPro2, 
			 char *pchrPtrCadena)
{
	if(!strcmp(SiscomObtenDato(pLCSiscomPro2,"EdoRegistro"),"Insertar"))
	{
	 return 1;
	}
  return 0;
}
void RegistraSepomex(int pintSocket,int pintNRegistros)
{
LCamposSiscomPro2 *lLCSiscomPro2=0;
LCamposSiscomPro2 *lLCSiscomPro2Ins=0,
		  *lLCSiscomPro2InsAct=0;
char lchrArrInsercion[1024];
int lintNRegistros=0;
int lintSocketAD;
char *lchrPtrEdoConexion=0;
SiscomLeeInformacionProtocolo(pintSocket,pintNRegistros,&lLCSiscomPro2);
for(;		
	lLCSiscomPro2;
    lLCSiscomPro2=lLCSiscomPro2->SCP2PtrSig)
if(CreaCadenaComandoSepomexSql(lLCSiscomPro2,lchrArrInsercion))
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
SiscomMensajesLog(gPtrFleArchivoLog,"Error al Envia:Sepomex",lchrPtrEdoConexion);
}



SiscomOperaciones2 *SepomexEstados()
{
SiscomOperaciones2 *lSOpOperaciones2;
SiscomMemoriaOperaciones2(120,&lSOpOperaciones2);
if(ComunicacionAccesoDatosSepomex)
SiscomAnexaOperacionAlArreglo2(ComunicacionAccesoDatosSepomex,lSOpOperaciones2);
else
SiscomLog("Se debe iniciar la variable ComunicacionAccesoDatosSepomex");
SiscomAnexaOperacionAlArreglo2(SqlSepomexEstados,lSOpOperaciones2);
return lSOpOperaciones2;
}
SiscomOperaciones2 *SepomexMunicipios()
{
SiscomOperaciones2 *lSOpOperaciones2;
SiscomMemoriaOperaciones2(120,&lSOpOperaciones2);
if(ComunicacionAccesoDatosSepomex)
SiscomAnexaOperacionAlArreglo2(ComunicacionAccesoDatosSepomex,lSOpOperaciones2);
else
SiscomLog("Se debe iniciar la variable ComunicacionAccesoDatosSepomex");
SiscomAnexaOperacionAlArreglo2(SqlSepomexMunicipios,lSOpOperaciones2);
return lSOpOperaciones2;
}


SiscomOperaciones2 *SepomexAsentamientos()
{
SiscomOperaciones2 *lSOpOperaciones2;
SiscomMemoriaOperaciones2(120,&lSOpOperaciones2);
if(ComunicacionAccesoDatosSepomex)
SiscomAnexaOperacionAlArreglo2(ComunicacionAccesoDatosSepomex,lSOpOperaciones2);
else
SiscomLog("Se debe iniciar la variable ComunicacionAccesoDatosSepomex");
SiscomAnexaOperacionAlArreglo2(SqlSepomexAsentamientos,lSOpOperaciones2);
return lSOpOperaciones2;

}
