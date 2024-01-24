#include <SQLVentas.h>
#include <ComunSiscomTiendas4.h>
#include <stdlib.h>






/*
 *
 * EdoVenta 0
 *
 * Se registra una venta normal
 * 
 * --- Venta para persona Fisica 
 * SQLVenta
 * SQLDetalleVenta
 * SQLVentaFisica
 * SQLActualizaInventarioVentas
 *
 * -- Venta para persona moral
 * SQLVenta
 * SQLDetalleVenta
 * SQLVentaMoral
 * SQLActualizaInventarioVentas
 *
 * EdoVenta 1
 * --- Venta para persona Fisica 
 * SQLVenta
 * SQLDetalleVenta
 * SQLVentaFisica
 *
 * -- Venta para persona moral
 * SQLVenta
 * SQLDetalleVenta
 * SQLVentaMoral
 *
 * EdoVenta 2
 * Implica una actualizacion de los datos de la orden
 *
 * SQLActualizaVenta
 * SQLEliminaDetalleVenta
 * SQLDetalleVenta
 *
 * EdoVenta 3
 *
 * Este es el proceso que cambia EdoVenta de 1 a
 * cero
 *
 * SQLMarcaComoVendida
 * SQLActualizaInventarioVentas
 *
 *
 */

void SQLVenta(SArgsSiscom *pSAgsSiscom)
{
GeneraInsercionActualizacion(pSAgsSiscom,
			     "SQLVenta",
			     SQLGeneraVenta);
}
void SQLActualizaVenta(SArgsSiscom *pSAgsSiscom)
{
GeneraInsercionActualizacion(pSAgsSiscom,
			     "SQLVenta",
			     SQLGeneraActualizaVenta);
}
void SQLMarcaComoVendida(SArgsSiscom *pSAgsSiscom)
{
GeneraInsercionActualizacion(pSAgsSiscom,
			     "SQLVenta",
			     SQLGeneraMarcaComoVendida);
}
void SQLEliminaDetalleVenta(SArgsSiscom *pSAgsSiscom)
{
GeneraInsercionActualizacion(pSAgsSiscom,
			     "SQLVenta",
			     SQLGeneraEliminaDetalleVenta);
}
void SQLDetalleVenta(SArgsSiscom *pSAgsSiscom)
{
GeneraInsercionActualizacion(pSAgsSiscom,
			     "SQLVenta",
			     SQLGeneraDetalleVenta);

}
void SQLVentaFisica(SArgsSiscom *pSAgsSiscom)
{
GeneraInsercionActualizacion(pSAgsSiscom,
			     "SQLVenta",
			     SQLGeneraVentaFisica);

}
void SQLVentaMoral(SArgsSiscom *pSAgsSiscom)
{
GeneraInsercionActualizacion(pSAgsSiscom,
			     "SQLVenta",
			     SQLGeneraVentaMoral);
}
void SQLActualizaInventarioVentas(SArgsSiscom *pSAgsSiscom)
{
	GeneraInsercionActualizacion(pSAgsSiscom,
				     "SQLVenta",
				     SQLGeneraActualizaInventarioVentas);
}
void SQLActualizaProductosCotizandoVenta(SArgsSiscom *pSAgsSiscom)
{
	GeneraInsercionActualizacion(pSAgsSiscom,
				     "SQLVenta",
				     SQLGeneraActualizaProductosCotizandoVenta);
}
void SQLRemisionFactura(SArgsSiscom *pSAgsSiscom)
{
	GeneraInsercionActualizacion(
		pSAgsSiscom,
		"SQLVenta",
		SQLGeneraInsertaRemisionFactura);
}
float CalculaTotal(LCamposSiscomPro2 *pLCSiscomPro2)
{
float lfltTotal=0.0;
for(;
	pLCSiscomPro2;
	pLCSiscomPro2=pLCSiscomPro2->SCP2PtrSig)
 lfltTotal+=atof(SiscomObtenDato(pLCSiscomPro2,"Total"));
 return lfltTotal;
}
void SQLGeneraVenta(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			 LCamposSiscomPro2 **pLCSiscomPro2Prim,
			 LCamposSiscomPro2 **pLCSiscomPro2Act,
			 int *pintPtrNRegistros)
{
char lchrArrSQL[1024];
char lchrArrFechaHoraHoy[25];
SiscomObtenFechaHoraActualAAAADDMM(lchrArrFechaHoraHoy);
SiscomContenidoProtocolo(pLCSiscomPro2Dat);
sprintf(lchrArrSQL,
	"insert into ventas values(%s,%s,%s,'%s','%s',%.2f,%s,%s);",
	SiscomObtenDato(pLCSiscomPro2Dat,"IdCotizacion"),
	SiscomObtenDato(pLCSiscomPro2Dat,"IdExpendio"),
	SiscomObtenDato(pLCSiscomPro2Dat,"IdFormaPago"),
	SiscomObtenDato(pLCSiscomPro2Dat,"TipoCliente"),
	lchrArrFechaHoraHoy,
	CalculaTotal(pLCSiscomPro2Dat),
	SiscomObtenDato(pLCSiscomPro2Dat,"EdoVenta"),
	SiscomObtenDato(pLCSiscomPro2Dat,"IdCliente"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}
void SQLGeneraActualizaVenta(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			 LCamposSiscomPro2 **pLCSiscomPro2Prim,
			 LCamposSiscomPro2 **pLCSiscomPro2Act,
			 int *pintPtrNRegistros)
{
char lchrArrSQL[1024];
char lchrArrFechaHoraHoy[25];
SiscomObtenFechaHoraActualAAAADDMM(lchrArrFechaHoraHoy);
sprintf(lchrArrSQL,
	"update ventas set fecha='%s',tipoCliente='%s',importe=%.2f,idformapago=%s where idventa=%s and idexpendio=%s",
	lchrArrFechaHoraHoy,
	 SiscomObtenDato(pLCSiscomPro2Dat,"TipoCliente"),
	 CalculaTotal(pLCSiscomPro2Dat),
	 SiscomObtenDato(pLCSiscomPro2Dat,"IdFormaPago"),
	 SiscomObtenDato(pLCSiscomPro2Dat,"IdCotizacion"),
	 SiscomObtenDato(pLCSiscomPro2Dat,"IdExpendio"));
			
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}
void SQLGeneraMarcaComoVendida(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			 LCamposSiscomPro2 **pLCSiscomPro2Prim,
			 LCamposSiscomPro2 **pLCSiscomPro2Act,
			 int *pintPtrNRegistros)
{
char lchrArrSQL[1024];
sprintf(lchrArrSQL,
	"update ventas set EdoVenta=0 where idventa=%s and idexpendio=%s",
	 SiscomObtenDato(pLCSiscomPro2Dat,"IdCotizacion"),
	 SiscomObtenDato(pLCSiscomPro2Dat,"IdExpendio"));
			
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}
void SQLGeneraEliminaDetalleVenta(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			 LCamposSiscomPro2 **pLCSiscomPro2Prim,
			 LCamposSiscomPro2 **pLCSiscomPro2Act,
			 int *pintPtrNRegistros)
{
char lchrArrSQL[1024];
char lchrArrFechaHoraHoy[25];
SiscomObtenFechaHoraActualAAAADDMM(lchrArrFechaHoraHoy);
sprintf(lchrArrSQL,
	"delete from detalleventa where idventa=%s",
	SiscomObtenDato(pLCSiscomPro2Dat,"IdCotizacion"));
			
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}
void SQLGeneraDetalleVenta(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			 LCamposSiscomPro2 **pLCSiscomPro2Prim,
			 LCamposSiscomPro2 **pLCSiscomPro2Act,
			 int *pintPtrNRegistros)
{
char lchrArrSQL[1024];
const char *lchrPtrIdCotizacion=SiscomObtenDato(pLCSiscomPro2Dat,"IdCotizacion");
for(;
	pLCSiscomPro2Dat;
    pLCSiscomPro2Dat=pLCSiscomPro2Dat->SCP2PtrSig)
{
sprintf(lchrArrSQL,
	"insert into detalleventa values(%s,%s,%s,%s,%s);",
	lchrPtrIdCotizacion,
	SiscomObtenDato(pLCSiscomPro2Dat,"IdProducto"),
	SiscomObtenDato(pLCSiscomPro2Dat,"Cantidad"),
	SiscomObtenDato(pLCSiscomPro2Dat,"IdPrecio"),
	SiscomObtenDato(pLCSiscomPro2Dat,"Total"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}
}
void SQLGeneraVentaFisica(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			 LCamposSiscomPro2 **pLCSiscomPro2Prim,
			 LCamposSiscomPro2 **pLCSiscomPro2Act,
			 int *pintPtrNRegistros)
{
char lchrArrSQL[1024];
sprintf(lchrArrSQL,
	"insert into ventasfisicas values(%s,%s);",
	SiscomObtenDato(pLCSiscomPro2Dat,"IdCotizacion"),
	SiscomObtenDato(pLCSiscomPro2Dat,"IdCliente"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}
void SQLGeneraVentaMoral(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			 LCamposSiscomPro2 **pLCSiscomPro2Prim,
			 LCamposSiscomPro2 **pLCSiscomPro2Act,
			 int *pintPtrNRegistros)
{
char lchrArrSQL[1024];
sprintf(lchrArrSQL,
	"insert into ventasmorales values(%s,%s);",
	SiscomObtenDato(pLCSiscomPro2Dat,"IdCotizacion"),
	SiscomObtenDato(pLCSiscomPro2Dat,"IdCliente"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}
void SQLGeneraActualizaInventarioVentas(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			 LCamposSiscomPro2 **pLCSiscomPro2Prim,
			 LCamposSiscomPro2 **pLCSiscomPro2Act,
			 int *pintPtrNRegistros)
{
char lchrArrSQL[1024];
for(;
	pLCSiscomPro2Dat;
    pLCSiscomPro2Dat=pLCSiscomPro2Dat->SCP2PtrSig)
{
sprintf(lchrArrSQL,
	"update inventario set existencia=existencia-%s where idexpendio=%s and	idproducto=%s",
	SiscomObtenDato(pLCSiscomPro2Dat,"Cantidad"),
	 SiscomObtenDato(pLCSiscomPro2Dat,"IdExpendio"),
	 SiscomObtenDato(pLCSiscomPro2Dat,"IdProducto"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}
}
void SQLGeneraActualizaProductosCotizandoVenta(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			 LCamposSiscomPro2 **pLCSiscomPro2Prim,
			 LCamposSiscomPro2 **pLCSiscomPro2Act,
			 int *pintPtrNRegistros)
{
char lchrArrSQL[1024];
for(;
	pLCSiscomPro2Dat;
    pLCSiscomPro2Dat=pLCSiscomPro2Dat->SCP2PtrSig)
{
sprintf(lchrArrSQL,
	"update inventario set existencia=existencia-%s where idexpendio=%s and	idproducto=%s",
	SiscomObtenDato(pLCSiscomPro2Dat,"Cantidad"),
	 SiscomObtenDato(pLCSiscomPro2Dat,"IdExpendio"),
	 SiscomObtenDato(pLCSiscomPro2Dat,"IdProducto"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}
}

void SQLGeneraInsertaRemisionFactura(LCamposSiscomPro2 *pLCSiscomPro2Dat,
				     LCamposSiscomPro2 **pLCSiscomPro2Prim,
				     LCamposSiscomPro2 **pLCSiscomPro2Act,
				     int *pintPtrNRegistros)
{
char lchrArrSQL[256];
sprintf(lchrArrSQL,
	"insert into RemisionFactura values(%s,'%s','%s');",
	SiscomObtenDato(pLCSiscomPro2Dat,"IdCotizacion"),
	SiscomObtenDato(pLCSiscomPro2Dat,"TipoOrden"),
	SiscomObtenDato(pLCSiscomPro2Dat,"NoRemFactura"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}
void SqlObtenDetalleVenta(SArgsSiscom *pSAgsSiscom)
{

char lchrArrSql[1024];
LCamposSiscomPro2 *lLCSiscomPro2PedidoPrim,*lLCSiscomPro2PedidoAct;
LCamposSiscomPro2 *lLCSiscomPro2Arg;
int lintNRegistrosRes;
int lintNRegistrosPedido;
SiscomObtenInformacionArgumento("SQLCliente",
				pSAgsSiscom,
				&lLCSiscomPro2PedidoPrim,
				&lLCSiscomPro2PedidoAct,
				&lintNRegistrosPedido);
if(lLCSiscomPro2PedidoPrim)
{
sprintf(lchrArrSql,
	"select d.idfamilia,						\
	        d.familia,						\
		a.idproducto,						\
		b.clave,						\
		b.dsc as dscproducto,					\
		a.cantidad,						\
		e.precio,						\
		a.total as importe					\
	 from  detalleventa as a inner join				\
	       producto as b using(idproducto) inner join		\
	       famproducto as c using(idproducto) inner join		\
	       familia	as d using(idfamilia) inner join 		\
	       preciosproducto  as e on a.idproducto=e.idproducto and	\
	                                a.idprecio=e.idprecio		\
	 where a.idventa=%s",
	 SiscomObtenDato(lLCSiscomPro2PedidoPrim,"idventa"));
SiscomConsultaBaseDatosSinDatosConexion(
	lchrArrSql,
	pSAgsSiscom->chrArrDirIpAD,
	pSAgsSiscom->intPtoComAD,
	&lLCSiscomPro2Arg,
	&lintNRegistrosRes);
SiscomAsignaInformacionArgumento(
		"SqlDetallePedido",
		pSAgsSiscom,
		lLCSiscomPro2Arg,
		0,
		lintNRegistrosRes);
}
else
/*
 * Despues de realizar la consulta, enla que se obtiene el 
 * numero telefonico, el pedido, la venta etc 
 * (SqlClientePorNumeroTelefonico), y no se obtuvo informacion
 * en esta consulta, no se podra ralizar la consulta del 
 * ultimo pedido
 *
 */
SiscomLog("No se tiene registrada Informacion Para el Numero Telefonico");
}
