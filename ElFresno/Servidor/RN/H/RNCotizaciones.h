#ifndef __RNCOTIZACIONES_H__
#define __RNCOTIZACIONES_H__
#include <FuncionesComunes.h>

#define RNCotizaciones_Cliente		1
#define RNCotizaciones_Producto		2
#define RNCotizaciones_Cantidad		3
#define RNCotizaciones_NmbTipoPrecio	4
#define RNCotizaciones_IdExpendio       5


const char *ObtenCliente(char **);
const char *ObtenProductoCotizacion(char **);
const char *ObtenCantidad(char **);
const char *ObtenNmbTipoPrecioCotizacion(char **);
const char *ObtenIdExpendio(char **);
const char *RNCotizacionesObtenPrecioVenta(StcLtaRegComSISCOM *);

const char *ObtenPrecioAlQueSeVende(StcLtaRegComSISCOM *,StcLtaRegComSISCOM *);

StcLtaRegComSISCOM *EjecutaCotizacion(int , const char *, StcLtaRegComSISCOM *, int *);

#endif
