#ifndef __GANANCIAS_H__
#define __GANANCIAS_H__
#include <SiscomDesarrollo2.h>

SiscomOperaciones2 *OpGanancia();
void ArgumentosGanancias(SArgsSiscom *);
void Ganancias(SArgsSiscom *);
/*
 * Seria importante considerar la ganancia del producto 
 * y el porcentaje de ganancia por producto
 *
 */
float GananciaPorProducto(LCamposSiscomPro2 *,
			  char *pchrPtrEdoGanancia,
			  float *);

void GananciaPorPeriodo(SArgsSiscom *);

void GananciasPorProducto(SArgsSiscom *pSAgsSiscom);
void GananciasPorFecha(SArgsSiscom *pSAgsSiscom);
void RegresoGananciaPeriodo(float pfltGanancia,
			    float pfltTotalVentas,
			    SArgsSiscom *);
#endif
