#include<VentasPorHora.h>

#include <ComunElectronica.h>
#include <stdlib.h>
#include <string.h>
int gintHoraInicio=7;
int gintHoraFin=21;
StcDatosSemana gStcDatSemana[54];

StcConsultaSvrSiscom2 gStcCnsVentasPorHora[]={
			   {EsConsultaVentasPorHora,FormaConsultaVentasPorHora}
			   };
int gintCnsVentasPorHora=1;
int EsConsultaVentasPorHora(char **pchrPtrEntrada)
{
	return !strcmp(pchrPtrEntrada[0],"VentasPorHora");
}
void ObtenImportePorHoraDia(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    StcHora *pStcHrsDat)
{
int lintContador;
char lchrArrHora[8];
LCamposSiscomPro2 *lLCSiscomPro2=pLCSiscomPro2Dat;
float lfltImportePorHora=0.0;
for(lintContador=gintHoraInicio;lintContador<gintHoraFin;lintContador++)
{
	sprintf(lchrArrHora,"%02d:",lintContador);
lfltImportePorHora=0.0;
	SiscomLog("\t\t %s ",lchrArrHora);
for(lLCSiscomPro2=pLCSiscomPro2Dat;
  	lLCSiscomPro2;
	lLCSiscomPro2=lLCSiscomPro2->SCP2PtrSig)
{
	if(!strncmp(SiscomObtenDato(lLCSiscomPro2,"hora"),lchrArrHora,3))
	 lfltImportePorHora+=atof(SiscomObtenDato(lLCSiscomPro2,"importe"));
}
	strcpy((pStcHrsDat+lintContador)->chrCadenaHora,lchrArrHora);
	(pStcHrsDat+lintContador)->fltImporte=lfltImportePorHora;
}
}
void FormaRespuesta(SiscomOperacionesServidor *pSOpServidor)
{
int lintContador,
	lintContadorJ,
	lintContadorK;
LCamposSiscomPro2 *lLCSiscomPro2ActRes=0;
char lchrArrNoSemana[5],
     lchrArrImporte[20],
     lchrArrOrdenes[20],
     lchrArrHora[10],
     lchrArrHoraInicio[10],
     lchrArrHoraFin[10],
     lchrArrImporteDia[10],
     lchrArrImporteSemana[10];
     pSOpServidor->intNRegistrosRes=0;
     pSOpServidor->LCSiscomPro2=0;
float lfltImporteDia=0.0;
float lfltImporteSemana;
sprintf(lchrArrHoraInicio,"%d",gintHoraInicio);
sprintf(lchrArrHoraFin,"%d",gintHoraFin);
SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2,
				&lLCSiscomPro2ActRes,
				&pSOpServidor->intNRegistrosRes,
				"FechaVenta,	\
				 InicioSemana,	\
				 FinSemana,	\
				 NoSemana,	\
				 Dia,		\
				 Hora,		\
				 Importe,	\
				 Ordenes,	\
				 HoraInicio,	\
				 HoraFin,	\
				 ImporteDia,	\
				 ImporteSemana",
				 "",
				 "",
				 "",
				 "",
				 "",
				 "",
				 "",
				 "",
				 lchrArrHoraInicio,
				 lchrArrHoraFin,
				 "",
				 "");
 for(lintContador=0;lintContador<52;lintContador++)
  {
     if(gStcDatSemana[lintContador].intConInformacion)
     {
	sprintf(lchrArrNoSemana,"%d",lintContador);
	SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2,
				&lLCSiscomPro2ActRes,
				&pSOpServidor->intNRegistrosRes,
				"FechaVenta,	\
				 InicioSemana,	\
				 FinSemana,	\
				 NoSemana,	\
				 Dia,		\
				 Hora,		\
				 Importe,	\
				 Ordenes,	\
				 HoraInicio,	\
				 HoraFin,	\
				 ImporteDia,	\
				 ImporteSemana",
				 "",
				 gStcDatSemana[lintContador].chrArrFechaIniSemana,
				 gStcDatSemana[lintContador].chrArrFechaFinSemana,
				 lchrArrNoSemana,
				 "",
				 "",
				 "",
				 "",
				 "",
				 "",
				 "",
				 "");
	lfltImporteSemana=0.0;
	for(lintContadorJ=0;lintContadorJ<8;lintContadorJ++)
	{
	if(gStcDatSemana[lintContador].StcDatSemana[lintContadorJ].LCSiscomPro2Prim)
	{
	SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2,
				&lLCSiscomPro2ActRes,
				&pSOpServidor->intNRegistrosRes,
				"FechaVenta,	\
				 InicioSemana,	\
				 FinSemana,	\
				 NoSemana,	\
				 Dia,		\
				 Hora,		\
				 Importe,	\
				 Ordenes,	\
				 HoraInicio,	\
				 HoraFin,	\
				 ImporteDia,	\
				 ImporteSemana",
				 gStcDatSemana[lintContador].StcDatSemana[lintContadorJ].chrArrFecha,
				 "",
				 "",
				 "", 
				 gStcDatSemana[lintContador].StcDatSemana[lintContadorJ].chrArrDia,
				 "",
				 "",
				 "",
				 "",
				 "",
				 "",
				 "");
	lfltImporteDia=0.0;
	 for(lintContadorK=gintHoraInicio;lintContadorK<gintHoraFin;lintContadorK++)
	 {
	 lfltImporteDia+=gStcDatSemana[lintContador].StcDatSemana[lintContadorJ].StcHrs[lintContadorK].fltImporte;
	sprintf(lchrArrImporte,
	"%.2f",
gStcDatSemana[lintContador].StcDatSemana[lintContadorJ].StcHrs[lintContadorK].fltImporte);
	sprintf(lchrArrHora,
		"%s00",
		gStcDatSemana[lintContador].StcDatSemana[lintContadorJ].StcHrs[lintContadorK].chrCadenaHora);
	SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2,
				&lLCSiscomPro2ActRes,
				&pSOpServidor->intNRegistrosRes,
				"FechaVenta,	\
				 InicioSemana,	\
				 FinSemana,	\
				 NoSemana,	\
				 Dia,		\
				 Hora,		\
				 Importe,	\
				 Ordenes,	\
				 HoraInicio,	\
				 HoraFin,	\
				 ImporteDia,	\
				 ImporteSemana",	
				 "",
				 "",
				 "",
				 "", 
				 "",
				 lchrArrHora,
				 lchrArrImporte,
				 "",
				 "",
				 "",
				 "",
				 "");

	 }
	sprintf(lchrArrImporteDia,"%.2f",lfltImporteDia);
	lfltImporteSemana+=lfltImporteDia;
	SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2,
				&lLCSiscomPro2ActRes,
				&pSOpServidor->intNRegistrosRes,
				"FechaVenta,	\
				 InicioSemana,	\
				 FinSemana,	\
				 NoSemana,	\
				 Dia,		\
				 Hora,		\
				 Importe,	\
				 Ordenes,	\
				 HoraInicio,	\
				 HoraFin,	\
				 ImporteDia,	\
				 ImporteSemana",	
				 "",
				 "",
				 "",
				 "", 
				 "",
				 "Total",
				 "",
				 "",
				 "",
				 "",
				 lchrArrImporteDia,
				 "");

	}
	 				
	}
	SiscomLog("Importe Por Semana:%f", lfltImporteSemana);
	sprintf(lchrArrImporteSemana,"%.2f",lfltImporteSemana);
	SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2,
				&lLCSiscomPro2ActRes,
				&pSOpServidor->intNRegistrosRes,
				"FechaVenta,	\
				 InicioSemana,	\
				 FinSemana,	\
				 NoSemana,	\
				 Dia,		\
				 Hora,		\
				 Importe,	\
				 Ordenes,	\
				 HoraInicio,	\
				 HoraFin,	\
				 ImporteDia,	\
				 ImporteSemana",	
				 "",
				 "",
				 "",
				 "", 
				 "",
				 "T. Semana",
				 "",
				 "",
				 "",
				 "",
				 lchrArrImporteDia,
				 lchrArrImporteSemana);

     }

  }
SiscomContenidoProtocolo(pSOpServidor->LCSiscomPro2);
}
void AnalizaVentasDiaHora(SiscomOperacionesServidor *pSOpServidor)
{
 LCamposSiscomPro2 *lLCSiscomPro2=pSOpServidor->LCSiscomPro2;
 int lintNumSemana,
     lintNumDiaSemana,
     lintContador,
     lintContadorJ;
 const char *lchrPtrDia;
 const char *lchrPtrFecha;
 memset(gStcDatSemana,0,sizeof(StcDatosSemana)*8);
 SiscomLog("AnalizaVentasDiaHora");
 for(lLCSiscomPro2=pSOpServidor->LCSiscomPro2;
  	lLCSiscomPro2;
	lLCSiscomPro2=lLCSiscomPro2->SCP2PtrSig)
 {
    lchrPtrFecha=SiscomObtenDato(lLCSiscomPro2,"fecha");
    lintNumSemana=SiscomObtenNumeroSemana(lchrPtrFecha); 
    lchrPtrDia=SiscomZellerFecha(lchrPtrFecha);
    lintNumDiaSemana=SiscomZeller2(lchrPtrFecha);
   SiscomLog("%s Numero Dia Semana (%d) Semana #(%d) ",
   	     lchrPtrFecha,
	     lintNumDiaSemana,
	     lintNumSemana);
        if(!gStcDatSemana[lintNumSemana].StcDatSemana[lintNumDiaSemana].chrArrDia[0])
    {
	strcpy(gStcDatSemana[lintNumSemana].StcDatSemana[lintNumDiaSemana].chrArrDia,
	       lchrPtrDia);
	gStcDatSemana[lintNumSemana].StcDatSemana[lintNumDiaSemana].intDia=lintNumDiaSemana;
	strcpy(gStcDatSemana[lintNumSemana].StcDatSemana[lintNumDiaSemana].chrArrFecha,
	       lchrPtrFecha);
	SiscomObtenDatosSemana(lchrPtrFecha,
			       gStcDatSemana[lintNumSemana].chrArrFechaIniSemana,
			       gStcDatSemana[lintNumSemana].chrArrFechaFinSemana);
	SiscomLog("Semana (%s,%s)",
		  gStcDatSemana[lintNumSemana].chrArrFechaIniSemana,
		  gStcDatSemana[lintNumSemana].chrArrFechaFinSemana);
    }
    gStcDatSemana[lintNumSemana].intConInformacion=1;
    SiscomCreaListaCamposPro2(
    	lLCSiscomPro2->SCSiscomPro2,
	&gStcDatSemana[lintNumSemana].StcDatSemana[lintNumDiaSemana].LCSiscomPro2Prim,
	&gStcDatSemana[lintNumSemana].StcDatSemana[lintNumDiaSemana].LCSiscomPro2Actual
	);
 }
  for(lintContador=0;lintContador<52;lintContador++)
  {
     if(gStcDatSemana[lintContador].intConInformacion)
     {
       SiscomLog("Semana %d",lintContador);
	for(lintContadorJ=0;lintContadorJ<8;lintContadorJ++)
	{
	 SiscomLog("Dia(%d)",lintContadorJ);
	if(gStcDatSemana[lintContador].StcDatSemana[lintContadorJ].LCSiscomPro2Prim)
	{
	 SiscomLog("\tCalculando venta del dia (%s)",
	 	 gStcDatSemana[lintContador].StcDatSemana[lintContadorJ].chrArrDia);
	ObtenImportePorHoraDia(
	        gStcDatSemana[lintContador].StcDatSemana[lintContadorJ].LCSiscomPro2Prim,
		gStcDatSemana[lintContador].StcDatSemana[lintContadorJ].StcHrs);
	}
	}
    }
  }
	 				
			  

 /*
  * Se debe contemplar, el calculo del numero de ordenes por hora.
  *
  */

 FormaRespuesta(pSOpServidor);
}
/*void FormaConsultaVentasPor
 */
void FormaConsultaVentasPorHora(char **pchrPtrEntrada,
		     SiscomOperacionesServidor *pSOpServidor)
{
char lchrArrConsulta[1024];
sprintf(lchrArrConsulta,
	"select cast(fechahora as time) as hora,		\
		cast(fechahora as date) as fecha,		\
		importe,					\
		idventa						\
	 from ventas 						\
	 where cast(fechahora as date)>='%s' and		\
	       cast(fechahora as date)<='%s' and		\
	       idexpendio=%s		     and		\
	       edoventa=0",
	 pchrPtrEntrada[2],
	 pchrPtrEntrada[3],
	 pchrPtrEntrada[1]);
/*
 *  Como podemos observar se va poder hacer un seguimiento, por producto
 *  en el tiempo, asi como el importe que aporto por hora en las 
 *  ventas
sprintf(lchrArrConsulta,
        "select cast(fechahora as time) as hora,		\
	        cast(fechahora as date) as fecha,		\
		importe,					\
		idventa						\
	 from ventas						\
	 where cast(fechahora as date)>='%s' and		\
	       cast(fechahora as date)<='%s' and		\
	       cveproducto='PROTO' 	     and		\
	       idexpendio=%s",
	  pchrPtrEntrada[2],
	  pchrPtrEntrada[3],
	  pchrPtrEntrada[1]);
*/	     
SiscomInformacionOperaciones("ConsultaSQL","Consultas",pSOpServidor);
SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2EPrim,
			&pSOpServidor->LCSiscomPro2EAct,
			&pSOpServidor->intNRegistros,
			"ConsultaSQL",
			lchrArrConsulta);
SiscomLog("%s",lchrArrConsulta);

pSOpServidor->EjecutaProcesoDespues=AnalizaVentasDiaHora; 
}
void AnalizaConsultaVentasPorHora(char **pchrPtrEntrada, 
			SiscomOperacionesServidor *pSOpServidor)
{ 
int lintContador;
for(lintContador=0;
    lintContador<gintCnsVentasPorHora;
    lintContador++)
if(gStcCnsVentasPorHora[lintContador].Consulta(pchrPtrEntrada))
{
gStcCnsVentasPorHora[lintContador].FormaConsulta(pchrPtrEntrada,pSOpServidor);
break;
}
}
void ConsultaVentasPorHora(int pintSocket,int pintNRegistros)
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
SiscomContenidoProtocolo(lSOpServidor.LCSiscomPro2Dat);
SiscomCopiaDatosProtocoloCharChar(lSOpServidor.LCSiscomPro2Dat,
				  pintNRegistros,
				  "Parametro",
				  &lchrPtrEntrada);
AnalizaConsultaVentasPorHora(lchrPtrEntrada,&lSOpServidor); 
ElectronicaComunicacionExpendio2(lchrPtrEntrada[1],
				 &lSOpServidor.intPtoCom,
				 lSOpServidor.chrPtrDirIpSvr,
				 0);
SiscomLog("Antes:SiscomEnviaAlServidor:%d",
                  lSOpServidor.intNRegistrosRes);
SiscomOperacionesServidores(&lSOpServidor);
SiscomEnviaAlServidor(pintSocket,
		      lSOpServidor.intNRegistrosRes,
		      "Respuesta",
		      lSOpServidor.LCSiscomPro2);
close(pintSocket);
}
int CreaCadenaComandoVentasPorHoraSql(LCamposSiscomPro2 *pLCSiscomPro2, 
			 char *pchrPtrCadena)
{
	if(!strcmp(SiscomObtenDato(pLCSiscomPro2,"EdoRegistro"),"Insertar"))
	{
	 return 1;
	}
  return 0;
}
void RegistraVentasPorHora(int pintSocket,int pintNRegistros)
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
if(CreaCadenaComandoVentasPorHoraSql(lLCSiscomPro2,lchrArrInsercion))
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
SiscomLog("Error al Envia:VentasPorHora",lchrPtrEdoConexion);
}

