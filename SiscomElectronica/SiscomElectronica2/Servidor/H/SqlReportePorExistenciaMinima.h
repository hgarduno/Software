#ifndef __SQLREPORTEPOREXISTENCIAMINIMA_H__
#define __SQLREPORTEPOREXISTENCIAMINIMA_H__
#include <SiscomDesarrollo2.h>

void SqlReportePorExistenciaMinima(SArgsSiscom *);
void SqlProductosPorcentajeExMinima(SArgsSiscom *pSArgsSiscom);

void SqlVentasSemestreAnterior(SArgsSiscom *pSAgsSiscom);
void SqlVentasSemestreActual(SArgsSiscom *pSAgsSiscom);

void SqlVentasPorExistenciaMinima(
			const char *pchrPtrIdExpendio,
			const char *pchrPtrPorExMinimaB,
			const char *pchrPtrPorExMinimaA,
			const char *pchrPtrFechaIni,
			const char *pchrPtrFechaFin,
			const char *pchrPtrArgumento,
			SArgsSiscom *pSAgsSiscom);
#endif
