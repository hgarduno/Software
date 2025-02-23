#ifndef __REPORTES_H__
#define __REPORTES_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomArchivosIni.h>

void RegistraReporteVentas(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct);

int EnviaReporteVentas(SiscomOperaciones *pSiscomOpePtrDat);
int EnviaReporteCompras(SiscomOperaciones *pSiscomOpePtrDato);

int ObtenRangoFecha(SiscomOperaciones *pSiscomOpePtrDat);
int EnviaExistenciasTienda(SiscomOperaciones *pSiscomOpePtrDat);
int EnviaExistenciasAlmacen(SiscomOperaciones *pSiscomOpePtrDat);
int EnviaDetalleCompra(SiscomOperaciones *pSiscomOpePtrDat);
int EnviaReporteDetalleCompra(SiscomOperaciones *pSiscomOpePtrDat);
int EnviaVentasCliente(SiscomOperaciones *pSiscomOpePtrDat);
int EnviaConsultaReporte(const char *pchrPtrAsociado,
			SiscomOperaciones *pSiscomOpePtrDat);
void FormaCondicionConsultaListaProductos(SiscomOperaciones *pSiscomOpePtrDatos,
					 char **pchrPtrCondicion);
int CambiaRFCAMayusculas(SiscomOperaciones *pSiscomOpePtrDato);
int EnviaFoliosCancelados(SiscomOperaciones *pSiscomOpePtrDat);

int EnviaStockDepartamentoProveedor(SiscomOperaciones *pSiscomOpePtrDat);
int EnviaPreciosProductos(SiscomOperaciones *pSiscomOpePtrDat);
int EnviaPreciosProductosComprador(SiscomOperaciones *pSiscomOpePtrDat);
int EnviaExistenciasProveedor(SiscomOperaciones *pSiscomOpePtrDat);
int EnviaStockTienda(SiscomOperaciones *pSiscomOpePtrDat);
int EnviaDatosCompra(SiscomOperaciones *pSiscomOpePtrDat);
int EnviaRepProveedores(SiscomOperaciones *pSiscomOpePtrDat);



void FormaCondicionConsultaListaProductosTienda(SiscomOperaciones *pSiscomOpePtrDatos,
					 char **pchrPtrCondicion);
#endif
