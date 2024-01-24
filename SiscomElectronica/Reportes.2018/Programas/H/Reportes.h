#ifndef __REPORTES_H__
#define __REPORTES_H__
#include <SiscomFuncionesComunes.h>
#include <SiscomLineaComandos.h>
#include <SiscomErrores.h>
#include <SiscomProtocoloComunicaciones.h>
void EjecutandoComparacionPeriodo(StcSiscomOpciones *pStcPtrSisOpciones);
void EjecutandoReporte(StcSiscomOpciones *pStcPtrSisOpciones);
void ComparacionPeriodo(StcSiscomOpciones *pStcPtrSisOpciones);
void ReporteVentas(StcSiscomOpciones *pStcPtrSisOpciones);
void EjecutandoReporteVentas(const char *pchrPtrFechaInicio,
			     const char *pchrPtrFechaFin,
			     const char *pchrPtrPrefijo,
			     SiscomRegistroProL *pSisRegProLPtrBases,
			     SiscomRegistroProL **pSisRegProLPtrReporte);
int CualReporteEjecuta(StcSiscomOpciones *pStcPtrSisOpciones);
void GenerandoReporteComparacionPeriodos(const char *pchrPtrFechaInicio,
					 const char *pchrPtrFechaFin,
					 const char *pchrPtrPrefijo,
					 SiscomRegistroProL *pSisRegProLPtrPeriodoActual,
				         SiscomRegistroProL *pSisRegProLPtrPeiodoAnterior);
void MesesReporte(const char ***pchrPtrMeses);
const char *PrefijoParaNombre(SiscomRegistroProL *pSisRegProLPtrBases,
			      StcSiscomOpciones *pStcPtrSisOpciones);
#endif
