#ifndef __SOPORTE_H__
#define __SOPORTE_H__
#include <SiscomFuncionesComunes.h>
#include <SiscomLineaComandos.h>
#include <SiscomErrores.h>
#include <PostgresAccesoDatos.h>


void SqlReporteVentas(const char *pchrPtrFechaInicio,
		      const char *pchrPtrFecharFin,
		      char *pchrPtrSql);
void ObtenFechas(StcSiscomOpciones *,char *,char *);
int ConectateBaseDatos(PostgresSql *,const char *pchrPtrBase);


void ObtenBasesExpendios(char *pchrPtrBuffer,StcSiscomOpciones *pStcPtrSisOpciones,SiscomRegistroProL **pSisRegProLPtrReg);
void ConsultaBases(const char *,const char *,SiscomRegistroProL *,SiscomRegistroProL **);
void ConsultaExistenciaMatriz(SiscomRegistroProL **pSisRegProLPtrExisMatriz);
void AgrupaInformacion(SiscomRegistroProL *pSisRegProLPtrDatos,SiscomRegistroProL **);

void SumaVentasSiscom(SiscomRegistroProL *,SiscomRegistroProL *pSisRegProLPtrAgrupados);
void VentasTotalesSiscom(SiscomRegistroProL *pSisRegProLPtrProductos);
void GeneraReporte(const char *pchrPtrFechaInicio,
		   const char *pchrPtrFechaFin,
		   const char *pchrPtrPrefijo,
		   SiscomRegistroProL *pSisRegProLPtrProducto); 
void GeneraNombreArchivoReporte(const char *pchrPtrFechaInicio,
			        const char *pchrPtrFechaFin,
				const char *pchrPtrPrefijo,
			        char *pchrPtrNombreReporte);

void FechaPeriodoAnterior(StcSiscomOpciones *pStcPtrSisOpciones,
			  char *pchrPtrFechaInicio,
			  char *pchrPtrFechaFin);
#endif
