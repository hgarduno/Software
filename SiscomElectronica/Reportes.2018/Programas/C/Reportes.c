#include <Reportes.h>
#include <Soporte.h>
#include <SiscomDesarrolloMacros.h>
#include <string.h>
/*
const char *gchrPtrMeses[]={"Enero",
			    "Febrero",
			    "Marzo",
			    "Abril",
			    "Mayo",
			    "Junio",
			    "Julio",
			    "Agosto",
			    "Septiembre",
			    "Octubre",
			    "Noviembre",
			    "Diciembre",
			    0};
*/

const char *gchrPtrMeses[]={"1",
			    "2",
			    "3",
			    "4",
			    "5",
			    "6",
			    "7",
			    "8",
			    "9",
			    "10",
			    "11",
			    "12",
			    0};
void EjecutandoComparacionPeriodo(StcSiscomOpciones *pStcPtrSisOpciones)
{
char lchrArrFechaInicio[28],
     lchrArrFechaFin[28],
     lchrArrBuffer[128],
     lchrArrFechaInicioAnterior[28],
     lchrArrFechaFinAnterior[28];
const char *lchrPtrPrefijo;
SiscomRegistroProL *lSisRegProLPtrBases=0,
		   *lSisRegProLPtrReporte=0,
		   *lSisRegProLPtrPeriodoAnterior=0;
   ObtenFechas(pStcPtrSisOpciones,lchrArrFechaInicio,lchrArrFechaFin);
   ObtenBasesExpendios(lchrArrBuffer,pStcPtrSisOpciones,&lSisRegProLPtrBases);
   FechaPeriodoAnterior(pStcPtrSisOpciones,lchrArrFechaInicioAnterior,lchrArrFechaFinAnterior);
   lchrPtrPrefijo=PrefijoParaNombre(lSisRegProLPtrBases,pStcPtrSisOpciones);
   EjecutandoReporteVentas(lchrArrFechaInicio,
   			   lchrArrFechaFin,
			   0,
			   lSisRegProLPtrBases,
			   &lSisRegProLPtrReporte);
   EjecutandoReporteVentas(lchrArrFechaInicioAnterior,
   			   lchrArrFechaFinAnterior,
			   0,
			   lSisRegProLPtrBases,
			   &lSisRegProLPtrPeriodoAnterior);
  GenerandoReporteComparacionPeriodos(lchrArrFechaInicio,
  				      lchrArrFechaFin,
  				      lchrPtrPrefijo,
				      lSisRegProLPtrReporte,
				      lSisRegProLPtrPeriodoAnterior);
}

void EjecutandoReporteVentas(const char *pchrPtrFechaInicio,
			     const char *pchrPtrFechaFin,
			     const char *pchrPtrPrefijo,
			     SiscomRegistroProL *pSisRegProLPtrBases,
			     SiscomRegistroProL **pSisRegProLPtrReporte)
{
SiscomRegistroProL *lSisRegProLPtrExisMatriz=0,
		   *lSisRegProLPtrDatos=0,
		   *lSisRegProLPtrAgrupados=0;
   ConsultaExistenciaMatriz(&lSisRegProLPtrExisMatriz);
   ConsultaBases(pchrPtrFechaInicio,pchrPtrFechaFin,pSisRegProLPtrBases,&lSisRegProLPtrDatos);
   AgrupaInformacion(lSisRegProLPtrDatos,pSisRegProLPtrReporte);
   SumaVentasSiscom(lSisRegProLPtrExisMatriz,*pSisRegProLPtrReporte);
   if(pchrPtrPrefijo)
   GeneraReporte(pchrPtrFechaInicio,pchrPtrFechaFin,pchrPtrPrefijo,*pSisRegProLPtrReporte);
}

void EjecutandoReporte(StcSiscomOpciones *pStcPtrSisOpciones)
{
int lintCualReporteEjecuta;
     lintCualReporteEjecuta=CualReporteEjecuta(pStcPtrSisOpciones);
     if(!lintCualReporteEjecuta)
     ReporteVentas(pStcPtrSisOpciones);
     else
     if(lintCualReporteEjecuta==1)
     ComparacionPeriodo(pStcPtrSisOpciones);
}

int CualReporteEjecuta(StcSiscomOpciones *pStcPtrSisOpciones)
{
  if(SiscomEstaLaOpcion("Ventas",pStcPtrSisOpciones))
  return 0;
  else
  if(SiscomEstaLaOpcion("ComparacionPeriodo",pStcPtrSisOpciones))
  return 1;
 return 0;
}

void ReporteVentas(StcSiscomOpciones *pStcPtrSisOpciones)
{
char lchrArrBuffer[256];
char lchrArrFechaInicio[28],
	lchrArrFechaFin[28];
SiscomRegistroProL *lSisRegProLPtrBases=0,
		   *lSisRegProLPtrDatos=0,
		   *lSisRegProLPtrAgrupados=0,
		   *lSisRegProLPtrExisMatriz=0;
   ObtenBasesExpendios(lchrArrBuffer,pStcPtrSisOpciones,&lSisRegProLPtrBases);
   ObtenFechas(pStcPtrSisOpciones,lchrArrFechaInicio,lchrArrFechaFin);
   ConsultaExistenciaMatriz(&lSisRegProLPtrExisMatriz);
   ConsultaBases(lchrArrFechaInicio,lchrArrFechaFin,lSisRegProLPtrBases,&lSisRegProLPtrDatos);
   AgrupaInformacion(lSisRegProLPtrDatos,&lSisRegProLPtrAgrupados);
   SumaVentasSiscom(lSisRegProLPtrExisMatriz,lSisRegProLPtrAgrupados);
   GeneraReporte(SiscomOpcionAChar("FechaInicio",pStcPtrSisOpciones),
		 SiscomOpcionAChar("FechaFin",pStcPtrSisOpciones),
		 PrefijoParaNombre(lSisRegProLPtrBases,pStcPtrSisOpciones),
   		 lSisRegProLPtrAgrupados);
}
void FormaCampoMesAnteriorActual(SiscomRegistroProL **pSisRegProLPtrPrim,	
				 SiscomRegistroProL **pSisRegProLPtrAct)
{
char lchrArrBuffer[128];
SiscomAnexaRegistroPro(pSisRegProLPtrPrim,
		      pSisRegProLPtrAct,
		      lchrArrBuffer,
		      "Anterior,Actual,",
		      0,
		      0,
		      0);
}
void AgregaMesesAnteriorActual(SiscomRegistroProL *pSisRegProLPtrReportePrim)
			      
{
const char **lchrPtrMesesPaso;
SiscomRegistroProL *lSisRegProLPtrPrimPeriodo=0,
		   *lSisRegProLPtrActPeriodo=0;
MesesReporte(&lchrPtrMesesPaso);
for(;*lchrPtrMesesPaso;lchrPtrMesesPaso++)
{
   FormaCampoMesAnteriorActual(&lSisRegProLPtrPrimPeriodo,&lSisRegProLPtrActPeriodo);
   SiscomRegistrosAlCampo(*lchrPtrMesesPaso,
   			  lSisRegProLPtrPrimPeriodo,
			  lSisRegProLPtrActPeriodo,
			  pSisRegProLPtrReportePrim);
   lSisRegProLPtrPrimPeriodo=lSisRegProLPtrActPeriodo=0;
}
}
void FormaMesesReporteComparacionPeriodo(const char **pchrPtrMeses,
				   	 SiscomCampoProL **pSisCamProLPtrPrim,
					 SiscomCampoProL **pSisCamProLPtrAct)
{
    while(*pchrPtrMeses)
    {
	SiscomAgregaCampo(*pchrPtrMeses,0,pSisCamProLPtrPrim,pSisCamProLPtrAct);
	pchrPtrMeses++;
    }
}
void AgregaVentasAnteriorActual(SiscomRegistroProL *pSisRegProLPtrReporteAct)
{
SiscomRegistroProL *lSisRegProLPtrPrim=0,
		   *lSisRegProLPtrAct=0;

FormaCampoMesAnteriorActual(&lSisRegProLPtrPrim,&lSisRegProLPtrAct);
SiscomRegistrosAlCampo("VeTotales",lSisRegProLPtrPrim,lSisRegProLPtrAct,pSisRegProLPtrReporteAct);
}
void AgregaRegistroReporteComparacionPeriodo(SiscomRegistroProL *pSisRegProLPtrRegistro,
					     SiscomRegistroProL **pSisRegProLPtrReporteRegPrim,
					     SiscomRegistroProL **pSisRegProLPtrReporteRegAct)
{
SiscomCampoProL *lSisCamProLPtrPrim=0,
  		*lSisCamProLPtrAct=0;
const char *lchrPtrCveProducto,**lchrPtrMeses;
MesesReporte(&lchrPtrMeses);
lchrPtrCveProducto=SiscomObtenCampoRegistroProLChar("cveproducto",pSisRegProLPtrRegistro);
SiscomAgregaCampo("CveProducto",lchrPtrCveProducto,&lSisCamProLPtrPrim,&lSisCamProLPtrAct);
SiscomAgregaCampo("ExMatriz",0,&lSisCamProLPtrPrim,&lSisCamProLPtrAct);
SiscomAgregaCampo("ExExpendio",0,&lSisCamProLPtrPrim,&lSisCamProLPtrAct);
SiscomAgregaCampo("VeTotales",0,&lSisCamProLPtrPrim,&lSisCamProLPtrAct);
FormaMesesReporteComparacionPeriodo(lchrPtrMeses,&lSisCamProLPtrPrim,&lSisCamProLPtrAct); 
SiscomNodoRegistroPro(lSisCamProLPtrPrim,pSisRegProLPtrReporteRegPrim,pSisRegProLPtrReporteRegAct);
AgregaMesesAnteriorActual(*pSisRegProLPtrReporteRegAct);
AgregaVentasAnteriorActual(*pSisRegProLPtrReporteRegAct);
}
void ObtenPeriodoConMasProductos(SiscomRegistroProL *pSisRegProLPtrPeriodoActual,
				 SiscomRegistroProL *pSisRegProLPtrPeriodoAnterior,
				 SiscomRegistroProL **pSisRegProLPtrMayor,
				 SiscomRegistroProL **pSisRegProLPtrMenor)
{
     if(pSisRegProLPtrPeriodoActual->intNRegistros>=pSisRegProLPtrPeriodoAnterior->intNRegistros)
     {
        *pSisRegProLPtrMayor=pSisRegProLPtrPeriodoActual;
	*pSisRegProLPtrMenor=pSisRegProLPtrPeriodoAnterior;
     }
     else
     {
        *pSisRegProLPtrMayor=pSisRegProLPtrPeriodoAnterior;
	*pSisRegProLPtrMenor=pSisRegProLPtrPeriodoActual;
     }
}
void RegistroParaElReporte(SiscomRegistroProL *pSisRegProLPtrMayor,
			    SiscomRegistroProL *pSisRegProLPtrMenor,
			    SiscomRegistroProL **pSisRegProLPtrReportePrim,
			    SiscomRegistroProL **pSisRegProLPtrReporteAct)
{
  for(;pSisRegProLPtrMenor;pSisRegProLPtrMenor=pSisRegProLPtrMenor->SiscomRegProLPtrSig)
  {
    if(!SiscomComparaCampoRegistrosProL("cveproducto",pSisRegProLPtrMayor,pSisRegProLPtrMenor))
    {
	AgregaRegistroReporteComparacionPeriodo(pSisRegProLPtrMayor,
						pSisRegProLPtrReportePrim,
						pSisRegProLPtrReporteAct);
	return;
    }
  }
	AgregaRegistroReporteComparacionPeriodo(pSisRegProLPtrMayor,
						pSisRegProLPtrReportePrim,
						pSisRegProLPtrReporteAct);
}
void RegistrosParaElReporte(SiscomRegistroProL *pSisRegProLPtrMayor,
			    SiscomRegistroProL *pSisRegProLPtrMenor,
			    SiscomRegistroProL **pSisRegProLPtrReportePrim,
			    SiscomRegistroProL **pSisRegProLPtrReporteAct)
{
*pSisRegProLPtrReportePrim=*pSisRegProLPtrReporteAct=0;
for(;pSisRegProLPtrMayor;pSisRegProLPtrMayor=pSisRegProLPtrMayor->SiscomRegProLPtrSig)
RegistroParaElReporte(pSisRegProLPtrMayor,
		      pSisRegProLPtrMenor,
		      pSisRegProLPtrReportePrim,
		      pSisRegProLPtrReporteAct);
}
SiscomRegistroProL *ObtenProductoActualizar(SiscomRegistroProL *pSisRegProLPtrReporte,
					    SiscomRegistroProL *pSisRegProLPtrPeriodoActual)
{
    for(;pSisRegProLPtrPeriodoActual;
    	 pSisRegProLPtrPeriodoActual=pSisRegProLPtrPeriodoActual->SiscomRegProLPtrSig)
    {
	if(!SiscomComparaCampoRegistrosProL2("CveProducto",
					     "cveproducto",
					     pSisRegProLPtrReporte,
					     pSisRegProLPtrPeriodoActual))
	 return pSisRegProLPtrPeriodoActual;
    }
return 0;
}
void ActualizaVentasMesActual(const char *pchrPtrPeriodo,
			      const char *pchrPtrMes,
			      SiscomRegistroProL *pSisRegProLPtrPeriodoActual,
			      SiscomRegistroProL *pSisRegProLPtrReporte)
{
char lchrArrBuffer[128];
const char *lchrPtrVentasMes;
SiscomRegistroProL *lSisRegProLPtrPeriodos;
if((lSisRegProLPtrPeriodos=SiscomObtenRegistrosCampoProL(pchrPtrMes,pSisRegProLPtrReporte)))
{
   lchrPtrVentasMes=SiscomObtenCampoRegistroProLChar(pchrPtrMes,pSisRegProLPtrPeriodoActual);
   SiscomActualizaCampoRegistro(pchrPtrPeriodo,(char *)lchrPtrVentasMes,lSisRegProLPtrPeriodos);
}
else
LogSiscom("NO Se encontro el campo Periodos");
}
void ActualizaVentasMesesActual(const char *pchrPtrPeriodo,
				SiscomRegistroProL *pSisRegProLPtrPeriodoActual,
			        SiscomRegistroProL *pSisRegProLPtrReporte)
{
const char **lchrPtrMesesPaso;
MesesReporte(&lchrPtrMesesPaso);
for(;*lchrPtrMesesPaso;lchrPtrMesesPaso++)
ActualizaVentasMesActual(pchrPtrPeriodo,
			*lchrPtrMesesPaso,
			pSisRegProLPtrPeriodoActual,
			pSisRegProLPtrReporte);
}
void ObtenAnteriorActualCampo(SiscomCampoProL *pSisCamProLPtrDato,
			      const char **pchrPtrActual,
			      const char **pchrPtrAnterior)
{
 *pchrPtrActual=SiscomObtenCampoRegistroProLChar("Actual",
 						 (SiscomRegistroProL *)pSisCamProLPtrDato->vidPtrSubPrim);
 *pchrPtrAnterior=SiscomObtenCampoRegistroProLChar("Anterior",
 						 (SiscomRegistroProL *)pSisCamProLPtrDato->vidPtrSubPrim);
}
void ActualizaDatosPeriodoActual(const char *pchrPtrPeriodo,
				 SiscomRegistroProL *pSisRegProLPtrPeriodoActual,
				 SiscomRegistroProL *pSisRegProLPtrReporte)
{
SiscomRegistroProL *lSisRegProLPtrPeriodoActual;
const char *lchrPtrExMatriz,
	   *lchrPtrExExpendio,
	   *lchrPtrVentaTotal;
  if((lSisRegProLPtrPeriodoActual=ObtenProductoActualizar(pSisRegProLPtrReporte,
  							  pSisRegProLPtrPeriodoActual)))
  { 
     lchrPtrExMatriz=SiscomObtenCampoRegistroProLChar("ExistenciaMatriz",lSisRegProLPtrPeriodoActual);
     lchrPtrExExpendio=SiscomObtenCampoRegistroProLChar("ExistenciaExpendio",lSisRegProLPtrPeriodoActual);
     lchrPtrVentaTotal=SiscomObtenCampoRegistroProLChar("VentaTotal",lSisRegProLPtrPeriodoActual);
     SiscomActualizaCampoRegistro("ExMatriz",(char *)lchrPtrExMatriz,pSisRegProLPtrReporte);
     SiscomActualizaCampoRegistro("ExExpendio",(char *)lchrPtrExExpendio,pSisRegProLPtrReporte);
     SiscomActualizaCampoAsociado(pchrPtrPeriodo,
     				  "VeTotales",
				  (char *)lchrPtrVentaTotal,
				  pSisRegProLPtrReporte);
     ActualizaVentasMesesActual(pchrPtrPeriodo,lSisRegProLPtrPeriodoActual,pSisRegProLPtrReporte);
  }
  else
  {
  LogSiscom("Producto %s NO Se encuentra",
  	    SiscomObtenCampoRegistroProLChar("CveProducto",pSisRegProLPtrReporte));
  }
}
void ActualizaDatosReporteComparacionPeriodos(SiscomRegistroProL *pSisRegProLPtrPeriodoActual,
					      SiscomRegistroProL *pSisRegProLPtrPeriodoAnterior,
					      SiscomRegistroProL *pSisRegProLPtrReporte)
{
for(;pSisRegProLPtrReporte;pSisRegProLPtrReporte=pSisRegProLPtrReporte->SiscomRegProLPtrSig)
{
   ActualizaDatosPeriodoActual("Actual",pSisRegProLPtrPeriodoActual,pSisRegProLPtrReporte);
   ActualizaDatosPeriodoActual("Anterior",pSisRegProLPtrPeriodoAnterior,pSisRegProLPtrReporte);
}
}
void AgregandoCadenaEncabezado(SiscomCampoProL *pSisCamProLPtrDato,char *pchrPtrEncabezado)
{
char lchrArrPaso[28];
     sprintf(lchrArrPaso,"%s|",pSisCamProLPtrDato->chrPtrNmbCampo);
   if(*pchrPtrEncabezado)
   strcat(pchrPtrEncabezado,lchrArrPaso);
   else
     strcpy(pchrPtrEncabezado,lchrArrPaso);
}
void AgregandoMesCadenaEncabezado(const char *pchrPtrMes,char *pchrPtrEncabezado)
{
char lchrArrPaso[28];
sprintf(lchrArrPaso,"%s|",pchrPtrMes);
strcat(pchrPtrEncabezado,lchrArrPaso);
}
void GeneraEncabezadoComparacionPeriodos(FILE *pFlePtrArchivo,
					 SiscomRegistroProL *pSisRegProLPtrReporte)
{
const char **lchrPtrMesesPaso;
char lchrArrEncabezado[1024];
SiscomCampoProL *lSisCamProLPtrDato;
lchrArrEncabezado[0]=0;
MesesReporte(&lchrPtrMesesPaso);
for(lSisCamProLPtrDato=pSisRegProLPtrReporte->SiscomCamProLPtrDato;
    lSisCamProLPtrDato;
    lSisCamProLPtrDato=lSisCamProLPtrDato->SiscomCamProLPtrSig)
{
  if(!strcmp(*lchrPtrMesesPaso,lSisCamProLPtrDato->chrPtrNmbCampo))
  {
  	AgregandoMesCadenaEncabezado(*lchrPtrMesesPaso,lchrArrEncabezado);
	lchrPtrMesesPaso++;
  }
  else
  AgregandoCadenaEncabezado(lSisCamProLPtrDato,lchrArrEncabezado);
}
fprintf(pFlePtrArchivo,"%s\n",lchrArrEncabezado);
}
const char *SiEsNuloACero(const char *pchrPtrValor)
{
  return pchrPtrValor ? pchrPtrValor : "0.00";
}
void GeneraProductosComparacionPeriodos(FILE *pFlePtrArchivo,
					SiscomRegistroProL *pSisRegProLPtrReporte)
{
const char **lchrPtrMesesPaso,*lchrPtrActual,**lchrPtrMeses,*lchrPtrAnterior;
SiscomCampoProL *lSisCamProLPtrDato;
MesesReporte(&lchrPtrMesesPaso);
lchrPtrMeses=lchrPtrMesesPaso;
for(;pSisRegProLPtrReporte;pSisRegProLPtrReporte=pSisRegProLPtrReporte->SiscomRegProLPtrSig)
{
lchrPtrMesesPaso=lchrPtrMeses;
for(lSisCamProLPtrDato=pSisRegProLPtrReporte->SiscomCamProLPtrDato;
    lSisCamProLPtrDato;
    lSisCamProLPtrDato=lSisCamProLPtrDato->SiscomCamProLPtrSig)
{
      if(!strcmp(*lchrPtrMesesPaso,lSisCamProLPtrDato->chrPtrNmbCampo))
      {	 
         ObtenAnteriorActualCampo(lSisCamProLPtrDato,&lchrPtrActual,&lchrPtrAnterior);
         fprintf(pFlePtrArchivo," %s / %s |",SiEsNuloACero(lchrPtrActual),SiEsNuloACero(lchrPtrAnterior));
	 lchrPtrMesesPaso++;
      }
      else
      if(!strcmp(lSisCamProLPtrDato->chrPtrNmbCampo,"VeTotales"))
      {
         ObtenAnteriorActualCampo(lSisCamProLPtrDato,&lchrPtrActual,&lchrPtrAnterior);
         fprintf(pFlePtrArchivo," %s / %s |",SiEsNuloACero(lchrPtrActual),SiEsNuloACero(lchrPtrAnterior));
      }
      else
	fprintf(pFlePtrArchivo,"%s|",lSisCamProLPtrDato->chrPtrDato);
}
fprintf(pFlePtrArchivo,"\n");
}
}
void EscribeReporteComparacionPeriodos(const char *pchrPtrFechaInicio,
				       const char *pchrPtrFechaFin,
				       const char *pchrPtrPrefijo,
				       SiscomRegistroProL *pSisRegProLPtrReporte)
{
FILE *lFlePtrArchivo;
char lchrArrNombreArchivo[1024];
GeneraNombreArchivoReporte(pchrPtrFechaInicio,pchrPtrFechaFin,pchrPtrPrefijo,lchrArrNombreArchivo);
if((lFlePtrArchivo=fopen(lchrArrNombreArchivo,"w")))
{
GeneraEncabezadoComparacionPeriodos(lFlePtrArchivo,pSisRegProLPtrReporte);
GeneraProductosComparacionPeriodos(lFlePtrArchivo,pSisRegProLPtrReporte);
}
}
void GenerandoReporteComparacionPeriodos(const char *pchrPtrFechaInicio,
					 const char *pchrPtrFechaFin,
					 const char *pchrPtrPrefijo,
					 SiscomRegistroProL *pSisRegProLPtrPeriodoActual,
				         SiscomRegistroProL *pSisRegProLPtrPeriodoAnterior)
{
SiscomRegistroProL *lSisRegProLPtrMayor,
		   *lSisRegProLPtrMenor,
		   *lSisRegProLPtrReportePrim,
		   *lSisRegProLPtrReporteAct;
ObtenPeriodoConMasProductos(pSisRegProLPtrPeriodoActual,
			    pSisRegProLPtrPeriodoAnterior,
			    &lSisRegProLPtrMayor,
			    &lSisRegProLPtrMenor);
RegistrosParaElReporte(lSisRegProLPtrMayor,
		       lSisRegProLPtrMenor,
		       &lSisRegProLPtrReportePrim,
		       &lSisRegProLPtrReporteAct);
/* Tepotzotlan 9 Mayo 2020 COVID 19 
 * Se agregan los registros que no estuvieron en el otro periodo
 */
RegistrosParaElReporte(lSisRegProLPtrMenor,
		       lSisRegProLPtrMayor,
		       &lSisRegProLPtrReportePrim,
		       &lSisRegProLPtrReporteAct);
ActualizaDatosReporteComparacionPeriodos(pSisRegProLPtrPeriodoActual,
					 pSisRegProLPtrPeriodoAnterior,
					 lSisRegProLPtrReportePrim);
EscribeReporteComparacionPeriodos(pchrPtrFechaInicio,
				  pchrPtrFechaFin,
				  pchrPtrPrefijo,
				  lSisRegProLPtrReportePrim);
}

void MesesReporte(const char ***pchrPtrMeses)
{
  *pchrPtrMeses=gchrPtrMeses;
}
const char *PrefijoParaNombre(SiscomRegistroProL *pSisRegProLPtrBases,
			      StcSiscomOpciones *pStcPtrSisOpciones)
{
   if(pSisRegProLPtrBases->intNRegistros==1)
   return SiscomOpcionAChar("Base",pStcPtrSisOpciones);
   else
   if(SiscomEstaLaOpcion("Prefijo",pStcPtrSisOpciones))
   return SiscomOpcionAChar("Prefijo",pStcPtrSisOpciones);
   else
   return "ArchivoTemporalReporte";
}
