#ifndef __ZREPORTESSERVISNTE_H__
#define __ZREPORTESSERVISNTE_H__
#include <zSiscomOperaciones.h>
class zSiscomConexion;
class zSiscomRegistro;
class zSiscomRegistros;
class zListaPrecios;
class zStockTienda;
class zExistenciaProveedor;
class zDatosCompra;
class zProveedores;
class zReportesServiSNTE:public zSiscomOperaciones
{
public:
	zReportesServiSNTE(zSiscomConexion *pzSisConexion,
			   const char *pchrPtrFuncion,
			   const char *pchrPtrModulo="libSiscomServiSNTE.so");
	zSiscomRegistros *StockDepartamentoProveedor(zSiscomRegistro *pzSisRegTienda,
				   zSiscomRegistro *pzSisRegDepartamento,
				   zSiscomRegistro *pzSisRegProveedor);
	zExistenciaProveedor *ExistenciaProveedor(zSiscomRegistro *pzSisRegProveedor,
						  zSiscomRegistro *pzSisRegProducto=0);
	zListaPrecios *ListaPrecios(zSiscomRegistro *pzSisRegTienda,
					zSiscomRegistro *pzSisRegProveedor,
					char **pchrPtrMensajeError);
	zListaPrecios *ListaPreciosComprador(zSiscomRegistro *pzSisRegProveedor,
					char **pchrPtrMensajeError);
	zStockTienda *StockTienda(zSiscomRegistro *pzSisRegTienda,zSiscomRegistro *pzSisRegProveedor);
	zDatosCompra *DatosCompra(zSiscomRegistro *pzSisRegProveedor,zSiscomRegistro *pzSisRegDepartamento);
	zProveedores *Proveedores(zSiscomRegistro *pzSisRegProveedor);

};

#endif
