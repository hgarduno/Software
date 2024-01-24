#ifndef __REPORTEPOREXISTENCIAMINIMA_H__
#define __REPORTEPOREXISTENCIAMINIMA_H__
#include <SiscomDesarrollo2.h>

SiscomOperaciones2 *OpReportePorExistenciaMinima();
SiscomOperaciones2 *OpProductosPorcentajeExMinima();

void EnviaReportePorExistenciaMinima(SArgsSiscom *);
void FechasSemestreActual(SArgsSiscom *pSArgsSiscom);
void FechasSemestreAnterior(SArgsSiscom *pSArgsSiscom);
void ObtenFechaActual(SArgsSiscom *pSArgsSiscom);
void AsignaInformacionUltimaCompra(SArgsSiscom *pSAgsSiscom);
void ArgumentosVentas(SArgsSiscom *pSAgsSiscom);
void AsignaVentasSemAnterior(SArgsSiscom *pSAgsSiscom);
void AsignaVentasActuales(SArgsSiscom *pSAgsSiscom);

void AsignaVentas(const char *pchrPtrColumna,
		  const char *pchrPtrArgumento,
		  SArgsSiscom *pSAgsSiscom);
#endif
