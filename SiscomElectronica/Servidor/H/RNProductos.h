#ifndef __RNPRODUCTOS_H__
#define __RNPRODUCTOS_H__
#include <SiscomDesarrollo2.h>
#include <ServidorGeneral.h>

void RegistraProductos(int,int);

void ConsultaProductosDescripcion(int,int);
void ConsultaProductos(int,int);
void ActualizaProducto(int,int);
void ActualizaPrecio(int,int);
void ActualizaExistenciaMinima(int,int);

int EsConsultaCodigoCapacitores(char **);
void FormaConsultaCodigoCapacitores(char **,SiscomOperacionesServidor *);
int EsConsultaProductos(char **);
void FormaConsultaProductos(char **,SiscomOperacionesServidor *);

int EsConsultaPrecioProducto(char **);
void FormaConsultaPrecioProducto(char **,SiscomOperacionesServidor *);

int EsConsultaUltimaCompra(char **);
void FormaConsultaUltimaCompra(char **,SiscomOperacionesServidor *);

int EsConsultaProductosSimilares(char **);
void FormaConsultaProductosSimilares(char **,SiscomOperacionesServidor *);
int EsConsultaDatosProductos(char **);
void FormaConsultaDatosProductos(char **,SiscomOperacionesServidor *);

int EsConsultaPorcentajeExistenciaMinima(char **);
void FormaConsultaPorcentajeExistenciaMinima(char **,SiscomOperacionesServidor *);

void ConexionNoDisponibleALosExpendiosProductos(LCamposSiscomPro2 *pLCSiscomPro2Prod,
					       LCamposSiscomPro2 *pLCSiscomPro2EdoExpendioPrim);

void RegistrandoProductos(LCamposSiscomPro2 *pLCSiscomPro2,
			  LCamposSiscomPro2 *pLCSiscomPro2Expendios,
			  int pintRegistraEnMatriz,
			  int pintSocket);


void RegistraProductoBodegas(const char *pchrPtrCveProducto,
		     LCamposSiscomPro2 **pLCSiscomPro2Prim,
		     LCamposSiscomPro2 **pLCSiscomPro2Act,
		     int *pintPtrNRegistros);
void RespondiendoExpendioSinConexion(int pintSocket,
				     LCamposSiscomPro2 *pLCSisPro2EdoExpendioPrim);

#endif
