#ifndef __RASTREAPRODUCTO_H__
#define __RASTREAPRODUCTO_H__
#include <SiscomDesarrollo2.h>

SiscomOperaciones2 *OpRastreaProducto();
void RastreaProducto(SArgsSiscom *pSAgsSiscom);
void ArgumentosRastreaProducto(SArgsSiscom *pSAgsSiscom);

void FormaRegistroTotales(SArgsSiscom *pSAgsSiscom);
LCamposSiscomPro2 *TExpendioExpendio(SArgsSiscom *);

LCamposSiscomPro2 *ValidaConsultaVacia(const char *pchrPtrArgumento,
				       SArgsSiscom *pSAgsSiscom);

void AgregaRegistrosVacios(SArgsSiscom *pSAgsSiscom);
void ValidaExistenciaParaRastreo(SArgsSiscom *pSAgsSiscom);
void ValidaExistenciaBodegas(SArgsSiscom *pSAgsSiscom);
void ValidaVentas(SArgsSiscom *pSAgsSiscom);
void ValidaCompras(SArgsSiscom *pSAgsSiscom);
void ValidaTotalVentas(SArgsSiscom *pSAgsSiscom);
void ValidaTotalCompras(SArgsSiscom *pSAgsSiscom);
void ValidaTransferenciaBodegaExpendio(SArgsSiscom *pSAgsSiscom);
void ValidaTransferenciaExpendioExpendio(SArgsSiscom *pSAgsSiscom);
void ValidaTotalTransferenciaBodegaExpendio(SArgsSiscom *pSAgsSiscom);
void ValidaTotalTransferenciaExpendioExpendio(SArgsSiscom *pSAgsSiscom);
void ValidaTransferenciaBodegaBodega(SArgsSiscom *pSAgsSiscom);

void ValidaActualizoInventario(SArgsSiscom *pSAgsSiscom);
#endif
