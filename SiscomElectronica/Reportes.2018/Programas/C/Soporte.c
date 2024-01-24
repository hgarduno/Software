#include <Soporte.h>
#include <unistd.h> 
#include <stdlib.h>
#include <string.h>

#include <SiscomDesarrolloMacros.h>
void SqlReporteVentas(const char *pchrPtrFechaInicio,
		      const char *pchrPtrFechaFin,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"select extract(mon from fechahora::date) as Mes,	\n\
                cveproducto,					\n\
                sum(cantidad) as ventas,			\n\
		existencia					\n\
	from ventas as a inner join  				\n\
		existencias as b using(cveproducto)		\n\
	where fechahora>='%s' and 				\n\
              fechahora<='%s' 					\n\
	group by mes,						\n\
        	cveproducto,					\n\
		b.existencia					\n\
	order by mes,						\n\
        	ventas desc,					\n\
        	cveproducto",
	pchrPtrFechaInicio,
	pchrPtrFechaFin);
}

int ConectateBaseDatos(PostgresSql *pPosSqlPtrConexion,
		       const char *pchrPtrBase)
{
char *lchrPtrRegreso;

if((lchrPtrRegreso=SiscomConectateBD(pPosSqlPtrConexion,
				    (const char *)0,
				    pchrPtrBase)))
{
   LogSiscom("No se pudo conectar a la bas %s (%s)",
   		pchrPtrBase,
		lchrPtrRegreso);
  exit(0);

}
else
return 1;
}
int EsBase(StcSiscomOpciones *pStcPtrSisOpciones)
{
   return pStcPtrSisOpciones->chrPtrNmbComando && 
          !strcmp(pStcPtrSisOpciones->chrPtrNmbComando,"Base");
}
void ObtenBasesExpendios(char *pchrPtrBuffer,
			 StcSiscomOpciones *pStcSisOpciones,
			 SiscomRegistroProL **pSisRegProLPtrReg)
{
SiscomRegistroProL *lSisRegProLPtrAct=0;
int lintContador,
    lintNOpciones=pStcSisOpciones->intNOpciones;
for(lintContador=0;
    lintContador<lintNOpciones;
    lintContador++)
 {
   if(EsBase(pStcSisOpciones)) 
    SiscomAnexaRegistroPro(pSisRegProLPtrReg,
    			   &lSisRegProLPtrAct,
			   pchrPtrBuffer,
			   "Base,",
			   pStcSisOpciones->chrPtrComando);
   pStcSisOpciones++;
 }

}
SiscomCampoProL *FormaRegistroExpendios(SiscomRegistroProL *pSisRegProLPtrBases)
{
SiscomCampoProL *lSisCamProLExpPrim=0,
		*lSisCamProLExpAct=0;
for(;pSisRegProLPtrBases;
     pSisRegProLPtrBases=pSisRegProLPtrBases->SiscomRegProLPtrSig)
     SiscomNodoCampoPro2(SiscomObtenCampoRegistroProLChar("Base",pSisRegProLPtrBases),
     			 0,
			 &lSisCamProLExpPrim,
			 &lSisCamProLExpAct);
return lSisCamProLExpPrim;
}
void RealizaConsultaBase(PostgresSql *pPostgresSql,
			 const char *pchrPtrNombreConsulta,
			 const char *pchrPtrSql,
			 SiscomRegistroProL **pSisRegProLPtrRegreso)
{
	PostgresEjecutaConsulta(pPostgresSql->PGConPtrConexion,
			        0,
				pchrPtrNombreConsulta,
				pchrPtrSql,
				&pPostgresSql->intNumCampos,
				&pPostgresSql->intNumRegistros,
				&pPostgresSql->PGresPtrEdoComando);
	PostgresFormaRespuestaConsulta(pPostgresSql,pchrPtrNombreConsulta,*pSisRegProLPtrRegreso);
}
void ConsultaBases(const char *pchrPtrFechaInicio,
		   const char *pchrPtrFechaFin,
		   SiscomRegistroProL *pSisRegProLPtrBases,
		   SiscomRegistroProL **pSisRegProLPtrRegreso)
{
char lchrArrBuffer[1024];
char lchrArrSql[1024];
const char *lchrPtrBase;
PostgresSql lPosSqlRegreso;
SiscomRegistroProL *lSisRegProLPtrRegresoAct=0;

*pSisRegProLPtrRegreso=0;
SqlReporteVentas(pchrPtrFechaInicio,pchrPtrFechaFin,lchrArrSql);
SiscomNodoRegistroPro(FormaRegistroExpendios(pSisRegProLPtrBases),
		      pSisRegProLPtrRegreso,
		      &lSisRegProLPtrRegresoAct);
for(;pSisRegProLPtrBases;
    pSisRegProLPtrBases=pSisRegProLPtrBases->SiscomRegProLPtrSig)
{
lchrPtrBase=SiscomObtenCampoRegistroProLChar("Base",pSisRegProLPtrBases);
 LogSiscom("Conectandose %s",lchrPtrBase);
 if(ConectateBaseDatos(&lPosSqlRegreso,lchrPtrBase))
 {
 	RealizaConsultaBase(&lPosSqlRegreso,
			    lchrPtrBase,
			    lchrArrSql,
			    pSisRegProLPtrRegreso);
	PQfinish(lPosSqlRegreso.PGConPtrConexion);
 }
 else
 {
   LogSiscom("error ......");
 }

}
}
void JuntaRegistros(SiscomRegistroProL *pSisRegProLPtrVentas,
		    SiscomRegistroProL **pSisRegProLPtrRegreso)
{
SiscomRegistroProL *lSisRegProLPtrUltimaVenta;
    if(!(*pSisRegProLPtrRegreso))
     *pSisRegProLPtrRegreso=pSisRegProLPtrVentas;
    else
    {
       lSisRegProLPtrUltimaVenta=SiscomUltimoNodoLista(*pSisRegProLPtrRegreso);
       lSisRegProLPtrUltimaVenta->SiscomRegProLPtrSig=pSisRegProLPtrVentas;
       (*pSisRegProLPtrRegreso)->intNRegistros+=pSisRegProLPtrVentas->intNRegistros; 
    }

}
void OrdenaProductos(SiscomRegistroProL *pSisRegProLPtrVentas,
		     SiscomRegistroProL **pSisRegProLPtrProdsOrdenados)
{
SiscomRegistroProL *lSisRegProLPtrProdsOrdenadosAct=0;
SiscomOrdenaRegistroProL("cveproducto",
			pSisRegProLPtrVentas,
			pSisRegProLPtrProdsOrdenados,
			&lSisRegProLPtrProdsOrdenadosAct);
}
void AgrupaPorProducto(SiscomRegistroProL *pSisRegProLPtrDatos,
		       SiscomRegistroProL **pSisRegProLPtrAgrupados)
{
char lchrArrBuffer[128];
char *lchrPtrCamposProducto[]={"cveproducto",
				"ExistenciaMatriz",
				"ExistenciaExpendio",
				"VentaTotal",
				"1",
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
char *lchrPtrCampos[]={"mes","ventas",0};
SiscomRegistroProL *lSisRegProLPtrPrimProdAgru=0,
		   *lSisRegProLPtrActProdAgru=0;

SiscomAgrupaPorCampo("cveproducto",
		     "Producto",
		     lchrPtrCamposProducto,
		     lchrPtrCampos,
		     pSisRegProLPtrDatos,
		     pSisRegProLPtrAgrupados,
		     &lSisRegProLPtrActProdAgru);
}
SiscomRegistroProL *ObtenProductoParaExistencia(SiscomRegistroProL *pSisRegProLPtrDatos,
						SiscomRegistroProL *pSisRegProLPtrAgrupado)
{
    while(pSisRegProLPtrDatos) 
    {
        if(!SiscomComparaCampoRegistrosProL("cveproducto",
					    pSisRegProLPtrDatos,
					    pSisRegProLPtrAgrupado))
	    return pSisRegProLPtrDatos; 
	pSisRegProLPtrDatos=pSisRegProLPtrDatos->SiscomRegProLPtrSig;
    }

return 0;
}
void AsignaExistenciaExpendio(SiscomRegistroProL *pSisRegProLPtrDatos,
			      SiscomRegistroProL *pSisRegProLPtrAgrupados)
{
SiscomRegistroProL *lSisRegProLPtrProducto;
char *lchrPtrExistencia;
      for( ; 
      	    pSisRegProLPtrAgrupados;
      	    pSisRegProLPtrAgrupados=pSisRegProLPtrAgrupados->SiscomRegProLPtrSig)
      {

         if((lSisRegProLPtrProducto=ObtenProductoParaExistencia(pSisRegProLPtrDatos,
	      							pSisRegProLPtrAgrupados)))
	 {
		    lchrPtrExistencia=(char *)SiscomObtenCampoRegistroProLChar("existencia",
		    								lSisRegProLPtrProducto);
		   SiscomActualizaCampo2("ExistenciaExpendio",
		   		         lchrPtrExistencia,
					 pSisRegProLPtrAgrupados);
	  }
      }
}
void AgrupaInformacion(SiscomRegistroProL *pSisRegProLPtrDatos,
		       SiscomRegistroProL **pSisRegProLPtrAgrupados)
{
char lchrArrBuffer[256];
SiscomCampoProL *lSisCamProLPtrBases;
SiscomRegistroProL *lSisRegProLPtrVentaExpendio,
		   *lSisRegProLPtrRegreso=0,
		   *lSisRegProLPtrProdsOrdenados=0;
for(lSisCamProLPtrBases=pSisRegProLPtrDatos->SiscomCamProLPtrDato;
    lSisCamProLPtrBases;
    lSisCamProLPtrBases=lSisCamProLPtrBases->SiscomCamProLPtrSig)
{
 lSisRegProLPtrVentaExpendio=SiscomObtenRegistrosCampoProL(lSisCamProLPtrBases->chrPtrNmbCampo,
 							   pSisRegProLPtrDatos);
 JuntaRegistros(lSisRegProLPtrVentaExpendio,&lSisRegProLPtrRegreso); 
}
 OrdenaProductos(lSisRegProLPtrRegreso,&lSisRegProLPtrProdsOrdenados); 
 AgrupaPorProducto(lSisRegProLPtrProdsOrdenados,pSisRegProLPtrAgrupados);
 AsignaExistenciaExpendio(lSisRegProLPtrProdsOrdenados,*pSisRegProLPtrAgrupados);
}
const char *ExistenciaMatrizProducto(SiscomRegistroProL *pSisRegProLPtrProducto,
				     SiscomRegistroProL *pSisRegProLPtrExisMatriz)
{
char lchrArrBuffer[128];
    for(;pSisRegProLPtrExisMatriz;
         pSisRegProLPtrExisMatriz=pSisRegProLPtrExisMatriz->SiscomRegProLPtrSig)
    {
     if(!SiscomComparaCampoRegistrosProL("cveproducto",
     					 pSisRegProLPtrProducto,
					 pSisRegProLPtrExisMatriz))
      return SiscomObtenCampoRegistroProLChar("existencia",pSisRegProLPtrExisMatriz);
    }
  return 0;
}
			
void AsignaExistenciaMatriz(SiscomRegistroProL *pSisRegProLPtrExisMatriz,
			    SiscomRegistroProL *pSisRegProLPtrProductos)
{
char lchrArrBuffer[128];
const char *lchrPtrCveProducto,
	   *lchrPtrExistencia;
for(;pSisRegProLPtrProductos;
     pSisRegProLPtrProductos=pSisRegProLPtrProductos->SiscomRegProLPtrSig)
{
  lchrPtrCveProducto=SiscomObtenCampoRegistroProLChar("cveproducto",pSisRegProLPtrProductos); 
  if((lchrPtrExistencia=ExistenciaMatrizProducto(pSisRegProLPtrProductos,pSisRegProLPtrExisMatriz)))
  SiscomActualizaCampo2("ExistenciaMatriz",(char *)lchrPtrExistencia,pSisRegProLPtrProductos);
}
}
void SumaVentasSiscom(SiscomRegistroProL *pSisRegProLPtrExisMatriz,
			SiscomRegistroProL *pSisRegProLPtrAgrupados)
{
char lchrArrBuffer[128];
VentasTotalesSiscom(pSisRegProLPtrAgrupados);
AsignaExistenciaMatriz(pSisRegProLPtrExisMatriz,pSisRegProLPtrAgrupados);
}
void SumaVentas(SiscomRegistroProL *pSisRegProLPtrProducto,
		SiscomRegistroProL *pSisRegProLPtrVentas)
{
float lfltVentasTotales;
lfltVentasTotales=SiscomObtenSumatoriaRegistros("ventas",pSisRegProLPtrVentas);
SiscomActualizaCampoFloatRegistroActual("VentaTotal",
					"%.2f",
					lfltVentasTotales,
					pSisRegProLPtrProducto);


}
void SumaVentasDelMes(const char *pchrPtrMes,
		      SiscomRegistroProL *pSisRegProLPtrProducto,
		      SiscomRegistroProL *pSisRegProLPtrVentas)
{
float lfltSumatoria=0;
   while(pSisRegProLPtrVentas)
   {
      if(!SiscomComparaCadenaCampoRegistroProL(pchrPtrMes,"mes",pSisRegProLPtrVentas))
	 lfltSumatoria+=SiscomObtenCampoRegistroProLFloat("ventas",pSisRegProLPtrVentas);
       pSisRegProLPtrVentas=pSisRegProLPtrVentas->SiscomRegProLPtrSig;
   }
SiscomActualizaCampoFloatRegistroActual(pchrPtrMes,"%.2f",lfltSumatoria,pSisRegProLPtrProducto);
}

void SumaVentasPorMes(SiscomRegistroProL *pSisRegProLPtrProducto,
		      SiscomRegistroProL *pSisRegProLPtrVentas)
{
const char *lchrPtrMesesPaso[]={"1","2","3","4","5","6","7","8","9","10","11","12",0};
const char **lchrPtrMeses=lchrPtrMesesPaso;
  while(*lchrPtrMeses)
  {
 	SumaVentasDelMes(*lchrPtrMeses,pSisRegProLPtrProducto,pSisRegProLPtrVentas);	
	lchrPtrMeses++;
  }


}
void VentasTotalesSiscom(SiscomRegistroProL *pSisRegProLPtrProductos)
{
SiscomRegistroProL *lSisRegProLPtrVentas;
for(;pSisRegProLPtrProductos;
    pSisRegProLPtrProductos=pSisRegProLPtrProductos->SiscomRegProLPtrSig)
{
    if((lSisRegProLPtrVentas=SiscomObtenRegistrosCampoProL("Producto",pSisRegProLPtrProductos)))
    {
	SumaVentas(pSisRegProLPtrProductos,lSisRegProLPtrVentas);
	SumaVentasPorMes(pSisRegProLPtrProductos,lSisRegProLPtrVentas);
    }
}

}
void ConsultaExistenciaMatriz(SiscomRegistroProL **pSisRegProLPtrExisMatriz)
{
SiscomRegistroProL *lSisRegProLPtrAct=0,
		   *lSisRegProLPtrPrim=0;
char lchrArrBuffer[128];
const char *lchrPtrSql="select cveproducto,					\n\
		              existencia+exbodegas as existencia 		\n\
			from existenciaexpendiobodegas 			\n\
			where idexpendio=-1165857915 order by cveproducto;";
PostgresSql lPosSqlRegreso;
SiscomAnexaRegistroPro(&lSisRegProLPtrPrim,
		       &lSisRegProLPtrAct,
		       lchrArrBuffer,
		       "ExistenciaMatriz,",
		       "ExistenciaMatriz");

  if(ConectateBaseDatos(&lPosSqlRegreso,"SiscomElectronica"))
  {
     RealizaConsultaBase(&lPosSqlRegreso,"ExistenciaMatriz",lchrPtrSql,&lSisRegProLPtrPrim);
     PQfinish(lPosSqlRegreso.PGConPtrConexion);
     *pSisRegProLPtrExisMatriz=SiscomObtenRegistrosCampoProL("ExistenciaMatriz",lSisRegProLPtrPrim); 

  }
}
void GeneraProductos(FILE *pFlePtrArchivo,
		     SiscomRegistroProL *pSisRegProLPtrProducto)
{
SiscomCampoProL *lSisCamProLPtrDato;
for(;pSisRegProLPtrProducto;pSisRegProLPtrProducto=pSisRegProLPtrProducto->SiscomRegProLPtrSig)
{
for(lSisCamProLPtrDato=pSisRegProLPtrProducto->SiscomCamProLPtrDato;
    lSisCamProLPtrDato;
    lSisCamProLPtrDato=lSisCamProLPtrDato->SiscomCamProLPtrSig)
    if(lSisCamProLPtrDato->SiscomCamProLPtrSig)
   fprintf(pFlePtrArchivo,"%s|", lSisCamProLPtrDato->chrPtrDato);
 fprintf(pFlePtrArchivo,"\n");
}
  
}
void GeneraEncabezado(FILE *pFlePtrArchivo,
		      SiscomRegistroProL *pSisRegProLPtrProducto)
{
SiscomCampoProL *lSisCamProLPtrDato;
for(lSisCamProLPtrDato=pSisRegProLPtrProducto->SiscomCamProLPtrDato;
    lSisCamProLPtrDato;
    lSisCamProLPtrDato=lSisCamProLPtrDato->SiscomCamProLPtrSig)
fprintf(pFlePtrArchivo,"%s|",lSisCamProLPtrDato->chrPtrNmbCampo);
fprintf(pFlePtrArchivo,"\n");
}
void CambiaCaracteresFecha(const char *pchrPtrFecha,
			   char *pchrPtrFechaSalida)
{
char lchrArrPaso[128];
strcpy(lchrArrPaso,pchrPtrFecha);
SiscomCambiaCaracter('/','_',lchrArrPaso);
strcpy(pchrPtrFechaSalida,lchrArrPaso);
}
void PrefijoNombreArchivoFecha(const char *pchrPtrFechaInicio,
			       const char *pchrPtrFechaFin,
			       const char *pchrPtrBase,
			       char *pchrPtrArchivo)
{
char lchrArrFechaInicio[28],
	lchrArrFechaFin[28];
	CambiaCaracteresFecha(pchrPtrFechaInicio,lchrArrFechaInicio);
	CambiaCaracteresFecha(pchrPtrFechaFin,lchrArrFechaFin);
sprintf(pchrPtrArchivo,
	"%s_Inicio_%s_Fin_%s",
	pchrPtrBase,
	lchrArrFechaInicio,
	lchrArrFechaFin);
}
const char *ObtenDirectorioTrabajo()
{
const char *lchrPtrDirectorioTrabajo;
lchrPtrDirectorioTrabajo=getenv("DirectorioTrabajo");
return lchrPtrDirectorioTrabajo;
}
void GeneraNombreArchivoReporte(const char *pchrPtrFechaInicio,
			        const char *pchrPtrFechaFin,
				const char *pchrPtrPrefijo,
			        char *pchrPtrNombreReporte)
{
char lchrArrNombre[256];
const char *lchrPtrDirectorioTrabajo;
PrefijoNombreArchivoFecha(pchrPtrFechaInicio,pchrPtrFechaFin,pchrPtrPrefijo,lchrArrNombre);
if((lchrPtrDirectorioTrabajo=ObtenDirectorioTrabajo()))
sprintf(pchrPtrNombreReporte,"%s/%s.txt",lchrPtrDirectorioTrabajo,lchrArrNombre);
else
sprintf(pchrPtrNombreReporte,"%s.txt",lchrArrNombre);

}
void GeneraReporte(const char *pchrPtrFechaInicio,
		   const char *pchrPtrFechaFin,
		   const char *pchrPtrPrefijo,
		   SiscomRegistroProL *pSisRegProLPtrProducto)
{
FILE *lFlePtrArchivo;
char lchrArrNombreArchivo[1024];
GeneraNombreArchivoReporte(pchrPtrFechaInicio,pchrPtrFechaFin,pchrPtrPrefijo,lchrArrNombreArchivo);
if((lFlePtrArchivo=fopen(lchrArrNombreArchivo,"w")))
{
GeneraEncabezado(lFlePtrArchivo,pSisRegProLPtrProducto);
GeneraProductos(lFlePtrArchivo,pSisRegProLPtrProducto);
}
fclose(lFlePtrArchivo);
}

void ObtenFechas(StcSiscomOpciones *pStcPtrSisOpciones,
		 char *pchrPtrFechaInicio,
		 char *pchrPtrFechaFin)
{
  strcpy(pchrPtrFechaInicio,SiscomOpcionAChar("FechaInicio",pStcPtrSisOpciones));
  strcpy(pchrPtrFechaFin,SiscomOpcionAChar("FechaFin",pStcPtrSisOpciones));
}

int ObtenParteCadenaAInt(const char *pchrPtrCadena,
			 int pintPosicion,
			 int pintCaracteres)
{
 char lchrArrCadena[28];

 	strncpy(lchrArrCadena,pchrPtrCadena+pintPosicion,pintCaracteres);
	lchrArrCadena[pintCaracteres]=0;
	return atoi(lchrArrCadena);
}
void GeneraFechaPeriodoAnterior(int pintPeriodo,
			        const char *pchrPtrFecha,
				char *pchrPtrFechaPeriodo)
{
int lintDia,lintMes,lintAnio;
 lintAnio=ObtenParteCadenaAInt(pchrPtrFecha,0,4)-pintPeriodo;
 lintMes=ObtenParteCadenaAInt(pchrPtrFecha,5,2);
 lintDia=ObtenParteCadenaAInt(pchrPtrFecha,8,2);
 sprintf(pchrPtrFechaPeriodo,"%04d/%02d/%02d",lintAnio,lintMes,lintDia);
}
				
void FechaPeriodoAnterior(StcSiscomOpciones *pStcPtrSisOpciones,
			  char *pchrPtrFechaInicio,
			  char *pchrPtrFechaFin)
{
 GeneraFechaPeriodoAnterior(SiscomOpcionAInt("Periodo",pStcPtrSisOpciones),
 			    SiscomOpcionAChar("FechaInicio",pStcPtrSisOpciones),
			    pchrPtrFechaInicio);
 GeneraFechaPeriodoAnterior(SiscomOpcionAInt("Periodo",pStcPtrSisOpciones),
 			    SiscomOpcionAChar("FechaFin",pStcPtrSisOpciones),
			    pchrPtrFechaFin);
}
