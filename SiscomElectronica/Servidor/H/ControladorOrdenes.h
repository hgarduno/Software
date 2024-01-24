#ifndef __CONTROLADORORDENES_H__
#define __CONTROLADORORDENES_H__
#include <SiscomDesarrollo2.h>
#include <ServidorGeneral.h>
typedef struct ProductoOrden
{
	char chrArrIdVenta[20];
	float fltCantidad;
	char chrArrCveProducto[50];
	float fltPrecioU;
	float fltPrecioTotal;
}SProductoOrden;
void CreaNodoProductoOrden(SProductoOrden *,
			   StcListaGeneral **);

void ConsultaControladorOrdenes(int,int);
int EsConsultaControladorOrdenes(char **);
void FormaConsultaControladorOrdenes(char **,SiscomOperacionesServidor *);

int EsConsultaGeneraIdOrden(char **);
void FormaConsultaGeneraIdOrden(char **,SiscomOperacionesServidor *);
void GeneraIdOrden(SiscomOperacionesServidor *);

int EsConsultaProductosCotizacion(char **);
void FormaConsultaProductosCotizacion(char **,SiscomOperacionesServidor *);

int EsConsultaProductosOrdenVendida(char **);
void FormaConsultaProductosOrdenVendida(char **,SiscomOperacionesServidor *);
/* Martes 15 de enero del 2013
 * Se agrega la consulta de los productos almacenados
 * en la caja central, para  continuar con el esquema de cotizacion
 * de la ventana de Siscom Electronica
 */

int EsConsultaProductosOrdenCajaCentral(char **);
void FormaConsultaProductosOrdenCajaCentral(char **,SiscomOperacionesServidor *);

int EsConsultaOrdenesPorFechas(char **);
void FormaConsultaOrdenesPorFechas(char **,SiscomOperacionesServidor *);
void RealizaCalculosOrdenesFecha(SiscomOperacionesServidor *);

int EsConsultaProductosOrdenes(char **);
void FormaConsultaProductosOrdenes(char **,SiscomOperacionesServidor *);
void RealizaCalculosProductosOrdenes(SiscomOperacionesServidor *);


void RegistraControladorOrdenes(int,int);
#endif
