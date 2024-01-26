#include <QtPluginSiscomServiSNTE.h>
#include <QtImpProveedores.h>
#include <QtImpCapturaProductos.h>
#include <QtImpCargaNominaEmpleados.h>
#include <QtImpCargaBaseDeDatosMaestros.h>
#include <QtImpCapturaCamiones.h>
#include <QtImpCapturaChoferes.h>
#include <QtImpCapturaVendedores.h>
#include <QtImpCapturaConceptosExistencias.h>
#include <QtImpCapturaTienda.h>
#include <QtImpCapturaDepartamentos.h>
#include <QtImpPuntoDeVenta.h>
#include <QtImpRegistroCompras.h>
#include <QtImpImpresionCodigoBarras.h>
#include <QtImpCapturaInventario.h>
#include <QtImpCapturaInventarioAlmacen.h>
#include <QtImpTransferenciaAlmacen.h>
#include <QtImpReporteVentas.h>
#include <QtImpVisorTransferencias.h>
#include <QtImpAbonosApartado.h>
#include <QtImpBeneficiosIntegrales.h>
#include <QtImpRecibirTransferencias.h>
#include <QtImpControlReplicas.h>
#include <QtImpFijaFechaCompra.h>
#include <QtImpExistenciasTienda.h>
#include <QtImpExistenciasAlmacen.h>
#include <QtImpReporteCompras.h>
#include <QtImpTransferenciasEnviadas.h>
#include <QtImpActualizaStock.h>
#include <QtImpConsultaVentas.h>
#include <QtImpFolioApartado.h>
#include <QtImpFoliosCancelados.h>
#include <QtImpRepStockDepartamentoProveedor.h>
#include <QtImpRepExistenciaProveedor.h>
#include <QtImpRepPreciosProducto.h>
#include <QtImpRepStockTienda.h>
#include <QtImpRepStockProveedorCosto.h>
#include <QtImpActivaServidor.h>
#include <QtImpRepCompras.h>
#include <QtImpRegistroUsuarios.h>
#include <QtImpSoporteVentas.h>
#include <QtImpSoporteCompras.h>
#include <QtImpSoporteTransferencias.h>
#include <QtImpRepExistenciaTiendaProveedor.h>
#include <QtImpRegistroInventario.h>
#include <QtImpPagosDocumentosPagar.h>
#include <QtImpDiferenciasInventario.h>
#include <QtImpRegistroLibro.h>
#include <QtImpProveedores.h>
#include <QtImpRepListaPreciosComprador.h>
#include <QtImpMultiApoyos.h>
#include <QtImpMantenimientoProductos.h>
#include <QtImpSaldosMovimientos.h>
#include <QtImpDesajusteInventario.h>
#include <QtImpRepProveedores.h>
#include <QCtrlConceptosExistencias.h>
#include <QCtrlTiendasEntrega.h>
#include <QCtrlVendedores.h>
#include <QCtrlTipoDocumentos.h>
#include <QCtrlEstados.h>
#include <QCtrlFormasEntrega.h>
#include <QCtrlTipoVentas.h>
#include <QCtrlFinanciadoras.h>
#include <QCtrlProveedoresSS.h>
#include <QCtrlProductosSS.h>
#include <QCtrlPlazos.h>
#include <QCtrlCamiones.h>
#include <QCtrlDepartamentosSS.h>
#include <QCtrlCodigoBarras.h>
#include <QCtrlTipoViviendaSS.h>
#include <QCtrlFrecuenciaPagosSS.h>
#include <QCtrlFrecuenciaTransaccionalSS.h>
#include <QCtrlTiposFolio.h>
#include <QCtrlPerfilesSS.h>
#include <QCtrlStock.h>
#include <QCtrlSoporteVentas.h>
#include <QCtrlInventarioProgramado.h>
#include <QCtrlEstadoInventario.h>
#include <QCtrlExistenciaProveedor.h>
#include <QCtrlSaldosMovimientosMes.h>
#include <QCtrlConceptosSaldosMovimientos.h>
#include <zSiscomDesarrollo4.h>

#include <stdio.h>


FILE *gPtrFleArchivoLog;
void *gzSiscomConexion;


static const char *filechooser_pixmap[] = {
    "22 22 8 1",
    "  c Gray100",
    ". c Gray97",
    "X c #4f504f",
    "o c #00007f",
    "O c Gray0",
    "+ c none",
    "@ c Gray0",
    "# c Gray0",
    "++++++++++++++++++++++",
    "++++++++++++++++++++++",
    "++++++++++++++++++++++",
    "++++++++++++++++++++++",
    "+OOOOOOOOOOOOOOOOOOOO+",
    "OOXXXXXXXXXXXXXXXXXXOO",
    "OXX.          OO OO  O",
    "OX.      oo     O    O",
    "OX.      oo     O   .O",
    "OX  ooo  oooo   O    O",
    "OX    oo oo oo  O    O",
    "OX  oooo oo oo  O    O",
    "OX oo oo oo oo  O    O",
    "OX oo oo oo oo  O    O",
    "OX  oooo oooo   O    O",
    "OX            OO OO  O",
    "OO..................OO",
    "+OOOOOOOOOOOOOOOOOOOO+",
    "++++++++++++++++++++++",
    "++++++++++++++++++++++",
    "++++++++++++++++++++++",
    "++++++++++++++++++++++"
};


QtPluginSiscomServiSNTE::QtPluginSiscomServiSNTE()
{
}


QStringList QtPluginSiscomServiSNTE::keys() const
{

    QStringList list;
    list 				<< 
    "QtImpProveedores"			<<	
    "QtImpCapturaProductos"		<<
    "QtImpCargaNominaEmpleados"		<<
    "QtImpCargaBaseDeDatosMaestros"	<<
    "QtImpCapturaCamiones"		<<
    "QtImpCapturaChoferes"		<<
    "QtImpCapturaVendedores"		<<
    "QtImpCapturaConceptosExistencias"	<<
    "QtImpCapturaTienda"		<<
    "QtImpCapturaDepartamentos"		<<
    "QtImpCapturaTienda"		<<
    "QtImpPuntoDeVenta"			<<
    "QtImpRegistroCompras"		<<
    "QtImpRegistroTransferencias"	<<
    "QtImpImpresionCodigoBarras"	<<
    "QtImpCapturaInventario"		<<
    "QtImpCapturaInventarioAlmacen"	<<
    "QtImpTransferenciaAlmacen"		<<
    "QtImpReporteVentas"		<<
    "QtImpVisorTransferencias"		<<
    "QtImpAbonosApartado"		<<
    "QtImpBeneficiosIntegrales"		<<
    "QtImpRecibirTransferencias"	<<
    "QtImpControlReplicas"     		<<
    "QtImpFijaFechaCompra"		<<
    "QtImpExistenciasTienda"      	<<
    "QtImpExistenciasAlmacen"      	<<
    "QtImpReporteCompras"      		<<
    "QtImpTransferenciasEnviadas"	<<
    "QtImpConsultaVentas"		<<
    "QtImpConsultaCompras"		<<
    "QtImpFolioApartado"		<<
    "QtImpFoliosCancelados"		<<
    "QtImpRepStockDepartamentoProveedor"<<
    "QtImpRepExistenciaProveedor"	<<
    "QtImpRepPreciosProducto"		<<
    "QtImpRepStockTienda"		<<
    "QtImpRepStockProveedorCosto"	<<
    "QtImpActivaServidor"		<<
    "QtImpRepCompras"			<<
    "QtImpRegistroUsuarios"		<<
    "QtImpSoporteVentas"		<<
    "QtImpSoporteCompras"		<<
    "QtImpSoporteTransferencias"	<<
    "QtImpRepExistenciaTiendaProveedor"	<<
    "QtImpRegistroInventario"		<<
    "QtImpPagosDocumentosPagar"		<<
    "QtImpDiferenciasInventario"	<<
    "QtImpRegistroLibro"		<<
    "QtImpProveedores"			<<
    "QtImpRepListaPreciosComprador"	<<
    "QtImpMultiApoyos"			<<
    "QtImpMantenimientoProductos"	<<
    "QtImpSaldosMovimientos"		<<
    "QtImpDesajusteInventario"		<<
    "QtImpRepProveedores"		<<
    "QtImpActualizaStock"		<<
    "QCtrlTiendasEntrega" 		<<
    "QCtrlVendedores" 			<<
    "QCtrlTipoDocumentos" 		<<
    "QCtrlEstados" 			<<
    "QCtrlFormasEntrega" 		<<
    "QCtrlTipoVentas" 			<<
    "QCtrlFinanciadoras" 		<<
    "QCtrlProveedoresSS" 		<<
    "QCtrlProductosSS" 			<<
    "QCtrlPlazos" 			<<
    "QCtrlCamiones" 			<<
    "QCtrlDepartamentosSS" 		<<
    "QCtrlConceptosExistencias" 	<<
    "QCtrlCodigoBarras" 		<<
    "QCtrlTipoViviendaSS"		<<
    "QCtrlFrecuenciaPagosSS"		<<
    "QCtrlFrecuenciaTransaccionalSS"	<<
    "QCtrlTiposFolio"			<<
    "QCtrlPerfilesSS"			<<
    "QCtrlStock"			<<
    "QCtrlSoporteVentas"		<<
    "QCtrlInventarioProgramado"		<<
    "QCtrlEstadoInventario"		<<
    "QCtrlExistenciaProveedor"		<<
    "QCtrlSaldosMovimientosMes"		<<
    "QCtrlConceptosSaldosMovimientos";
    return list;
}

QWidget* QtPluginSiscomServiSNTE::create( const QString &key, QWidget* parent, const char* name )
{
    if ( key == "QtImpProveedores" )
	return new QtImpProveedores( parent, name );

    if ( key == "QtImpCapturaProductos" )
	return new QtImpCapturaProductos( parent, name );

    if ( key == "QtImpCargaNominaEmpleados" )
	return new QtImpCargaNominaEmpleados( parent, name );

    if ( key == "QtImpCargaBaseDeDatosMaestros" )
	return new QtImpCargaBaseDeDatosMaestros( parent, name );

    if ( key == "QtImpCapturaTienda" )
	return new QtImpCapturaTienda( parent, name );


    if ( key == "QtImpCapturaCamiones" )
	return new QtImpCapturaCamiones( parent, name );


    if ( key == "QtImpCapturaChoferes" )
	return new QtImpCapturaChoferes( parent, name );

    if ( key == "QtImpCapturaVendedores" )
	return new QtImpCapturaVendedores( parent, name );


    if ( key == "QtImpCapturaConceptosExistencias" )
	return new QtImpCapturaConceptosExistencias( parent, name );

    if ( key == "QtImpCapturaDepartamentos" )
	return new QtImpCapturaDepartamentos( parent, name );

    if ( key == "QtImpPuntoDeVenta" )
	return new QtImpPuntoDeVenta( parent, name );

    if ( key == "QtImpRegistroCompras" )
	return new QtImpRegistroCompras( parent, name );

    if ( key == "QtImpImpresionCodigoBarras" )
	return new QtImpImpresionCodigoBarras( parent, name );

    if ( key == "QtImpCapturaInventario" )
	return new QtImpCapturaInventario( parent, name );

    if ( key == "QtImpCapturaInventarioAlmacen" )
	return new QtImpCapturaInventarioAlmacen( parent, name );
    
    if ( key == "QtImpTransferenciaAlmacen" )
	return new QtImpTransferenciaAlmacen( parent, name );

    if ( key == "QtImpReporteVentas" )
	return new QtImpReporteVentas( parent, name );
    
    if ( key == "QtImpVisorTransferencias" )
	return new QtImpVisorTransferencias( parent, name );

    if ( key == "QtImpAbonosApartado" )
	return new QtImpAbonosApartado( parent, name );
    
    if ( key == "QtImpBeneficiosIntegrales" )
	return new QtImpBeneficiosIntegrales( parent, name );

    if ( key == "QtImpRecibirTransferencias" )
	return new QtImpRecibirTransferencias( parent, name );

    if ( key == "QtImpControlReplicas" )
	return new QtImpControlReplicas( parent, name );
    if ( key == "QtImpFijaFechaCompra" )
	return new QtImpFijaFechaCompra( parent, name );

    if ( key == "QtImpExistenciasTienda" )
	return new QtImpExistenciasTienda( parent, name );

    if ( key == "QtImpExistenciasAlmacen" )
	return new QtImpExistenciasAlmacen( parent, name );

    if ( key == "QtImpReporteCompras" )
	return new QtImpReporteCompras( parent, name );

    if ( key == "QtImpTransferenciasEnviadas" )
	return new QtImpTransferenciasEnviadas( parent, name );
    if ( key == "QtImpConsultaVentas" )
	return new QtImpConsultaVentas( parent, name );

    if ( key == "QtImpFolioApartado" )
	return new QtImpFolioApartado( parent, name );

    if ( key == "QtImpFoliosCancelados" )
	return new QtImpFoliosCancelados( parent, name );

    if ( key == "QtImpRepStockDepartamentoProveedor" )
	return new QtImpRepStockDepartamentoProveedor( parent, name );

    if ( key == "QtImpRepExistenciaProveedor" )
	return new QtImpRepExistenciaProveedor( parent, name );

    if ( key == "QtImpRepPreciosProducto" )
	return new QtImpRepPreciosProducto( parent, name );

    if ( key == "QtImpRepStockTienda" )
	return new QtImpRepStockTienda( parent, name );

    if ( key == "QtImpRepStockProveedorCosto" )
        return new QtImpRepStockProveedorCosto( parent, name );
    
    if ( key == "QtImpActivaServidor" )
        return new QtImpActivaServidor( parent, name );
   
    if ( key == "QtImpRepCompras" )
        return new QtImpRepCompras( parent, name );

    if ( key == "QtImpRegistroUsuarios" )
        return new QtImpRegistroUsuarios( parent, name );

    if ( key == "QtImpSoporteVentas" )
        return new QtImpSoporteVentas( parent, name );

    if ( key == "QtImpSoporteCompras" )
        return new QtImpSoporteCompras( parent, name );

    if ( key == "QtImpSoporteTransferencias" )
        return new QtImpSoporteTransferencias( parent, name );

    if ( key == "QtImpRepExistenciaTiendaProveedor" )
        return new QtImpRepExistenciaTiendaProveedor( parent, name );

    if ( key == "QtImpRegistroInventario" )
        return new QtImpRegistroInventario( parent, name );

    if ( key == "QtImpPagosDocumentosPagar" )
        return new QtImpPagosDocumentosPagar( parent, name );

    if ( key == "QtImpDiferenciasInventario" )
        return new QtImpDiferenciasInventario( parent, name );

    if ( key == "QtImpRegistroLibro" )
        return new QtImpRegistroLibro( parent, name );

    if ( key == "QtImpProveedores" )
        return new QtImpProveedores( parent, name );

    if ( key == "QtImpRepListaPreciosComprador" )
        return new QtImpRepListaPreciosComprador( parent, name );

    if ( key == "QtImpMultiApoyos" )
        return new QtImpMultiApoyos( parent, name );

    if ( key == "QtImpMantenimientoProductos" )
        return new QtImpMantenimientoProductos( parent, name );

    if ( key == "QtImpSaldosMovimientos" )
        return new QtImpSaldosMovimientos( parent, name );

    if ( key == "QtImpDesajusteInventario" )
        return new QtImpDesajusteInventario( parent, name );

    if ( key == "QtImpRepProveedores" )
        return new QtImpRepProveedores( parent, name );

    if ( key == "QtImpActualizaStock" )
        return new QtImpActualizaStock( parent, name );


    if ( key == "QCtrlConceptosExistencias" )
	return new QCtrlConceptosExistencias( parent, name );

    if ( key == "QCtrlTiendasEntrega" )
	return new QCtrlTiendasEntrega( parent, name );

    if ( key == "QCtrlVendedores" )
	return new QCtrlVendedores( parent, name );

    if ( key == "QCtrlTipoDocumentos" )
	return new QCtrlTipoDocumentos( parent, name );

    if ( key == "QCtrlEstados" )
	return new QCtrlEstados( parent, name );

    if ( key == "QCtrlFormasEntrega" )
	return new QCtrlFormasEntrega( parent, name );

   if ( key == "QCtrlTipoVentas" )
	return new QCtrlTipoVentas( parent, name );

   if ( key == "QCtrlFinanciadoras" )
	return new QCtrlFinanciadoras( parent, name );


    if ( key == "QCtrlProveedoresSS" )
	return new QCtrlProveedoresSS( parent, name );

    if ( key == "QCtrlProductosSS" )
	return new QCtrlProductosSS( parent, name );

    if ( key == "QCtrlPlazos" )
	return new QCtrlPlazos( parent, name );

    if ( key == "QCtrlCamiones" )
	return new QCtrlCamiones( parent, name );
    
    if ( key == "QCtrlDepartamentosSS" )
	return new QCtrlDepartamentosSS( parent, name );

    if ( key == "QCtrlCodigoBarras" )
	return new QCtrlCodigoBarras( parent, name );
   
    if ( key == "QCtrlTipoViviendaSS" )
	return new QCtrlTipoViviendaSS( parent, name );

    if ( key == "QCtrlFrecuenciaPagosSS" )
	return new QCtrlFrecuenciaPagosSS( parent, name );
    if ( key == "QCtrlFrecuenciaTransaccionalSS" )
	return new QCtrlFrecuenciaTransaccionalSS( parent, name );

    if ( key == "QCtrlTiposFolio" )
	return new QCtrlTiposFolio( parent, name );

    if ( key == "QCtrlPerfilesSS" )
	return new QCtrlPerfilesSS( parent, name );

    if ( key == "QCtrlStock" )
	return new QCtrlStock( parent, name );

    if ( key == "QCtrlSoporteVentas" )
	return new QCtrlSoporteVentas( parent, name );

    if ( key == "QCtrlInventarioProgramado" )
	return new QCtrlInventarioProgramado( parent, name );

    if ( key == "QCtrlEstadoInventario" )
	return new QCtrlEstadoInventario( parent, name );

    if ( key == "QCtrlExistenciaProveedor" )
	return new QCtrlExistenciaProveedor( parent, name );
    if ( key == "QCtrlSaldosMovimientosMes" )
	return new QCtrlSaldosMovimientosMes( parent, name );

    if ( key == "QCtrlConceptosSaldosMovimientos" )
	return new QCtrlConceptosSaldosMovimientos( parent, name );

    return 0;

}

QString QtPluginSiscomServiSNTE::group( const QString& feature ) const
{
    if ( feature == "QtImpProveedores" )
	return "ServiSNTE (Formas)";

    if ( feature == "QtImpCapturaProductos" )
	return "ServiSNTE (Formas)";

    if ( feature == "QtImpCargaNominaEmpleados" )
	return "ServiSNTE (Formas)";

    if ( feature == "QtImpCargaBaseDeDatosMaestros" )
	return "ServiSNTE (Formas)";

    if ( feature == "QtImpCapturaCamiones" )
	return "ServiSNTE (Formas)";


    if ( feature == "QtImpCapturaChoferes" )
	return "ServiSNTE (Formas)";


    if ( feature == "QtImpCapturaVendedores" )
	return "ServiSNTE (Formas)";


    if ( feature == "QtImpCapturaDepartamentos" )
	return "ServiSNTE (Formas)";


    if ( feature == "QtImpCapturatienda" )
	return "ServiSNTE (Formas)";


    if ( feature == "QtImpCapturaConceptosExistencias" )
	return "ServiSNTE (Formas)";

    if ( feature == "QtImpPuntoDeVenta" )
	return "ServiSNTE (Formas)";

if ( feature == "QtImpRegistroCompras" )
	return "ServiSNTE (Formas)";

if ( feature == "QtImpImpresionCodigoBarras" )
	return "ServiSNTE (Formas)";

if ( feature == "QtImpCapturaInventario" )
	return "ServiSNTE (Formas)";

if ( feature == "QtImpCapturaInventarioAlmacen" )
	return "ServiSNTE (Formas)";
if ( feature == "QtImpTransferenciaAlmacen" )
	return "ServiSNTE (Formas)";
if ( feature == "QtImpReporteVentas" )
	return "ServiSNTE (Formas)";

    if ( feature == "QtImpVisorTransferencias" )
	return "ServiSNTE (Formas)";

    if ( feature == "QtImpAbonosApartado" )
	return "ServiSNTE (Formas)";

    if ( feature == "QtImpBeneficiosIntegrales" )
	return "ServiSNTE (Formas)";
    
    if ( feature == "QtImpRecibirTransferencias" )
	return "ServiSNTE (Formas)";
   
    if ( feature == "QtImpControlReplicas" )
	return "ServiSNTE (Formas)";
    if ( feature == "QtImpFijaFechaCompra" )
	return "ServiSNTE (Formas)";
    if ( feature == "QtImpExistenciasTienda" )
	return "ServiSNTE (Formas)";
    if ( feature == "QtImpExistenciasAlmacen" )
	return "ServiSNTE (Formas)";

    if ( feature == "QtImpReporteCompras" )
	return "ServiSNTE (Formas)";
    if ( feature == "QtImpTransferenciasEnviadas" )
	return "ServiSNTE (Formas)";
    if ( feature == "QtImpConsultaVentas" )
	return "ServiSNTE (Formas)";

    if ( feature == "QtImpFolioApartado" )
	return "ServiSNTE (Formas)";

    if ( feature == "QtImpFoliosCancelados" )
	return "ServiSNTE (Formas)";

    if ( feature == "QtImpRepStockDepartamentoProveedor" )
	return "ServiSNTE (Formas)";

    if ( feature == "QtImpRepExistenciaProveedor" )
	return "ServiSNTE (Formas)";
    if ( feature == "QtImpRepSaldosMovimientosMes" )
	return "ServiSNTE (Formas)";


    if ( feature == "QtImpRepPreciosProducto" )
	return "ServiSNTE (Formas)";

    if ( feature == "QtImpRepStockTienda" )
	return "ServiSNTE (Formas)";

    if ( feature == "QtImpRepCompras" )
	return "ServiSNTE (Formas)";

    if ( feature == "QtImpRegistroUsuarios" )
	return "ServiSNTE (Formas)";

    if ( feature == "QtImpSoporteVentas" )
	return "ServiSNTE (Formas)";

    if ( feature == "QtImpSoporteCompras" )
	return "ServiSNTE (Formas)";

    if ( feature == "QtImpSoporteTransferencias" )
	return "ServiSNTE (Formas)";

    if ( feature == "QtImpRepExistenciaTiendaProveedor" )
	return "ServiSNTE (Formas)";

    if ( feature == "QtImpRegistroInventario" )
	return "ServiSNTE (Formas)";

    if ( feature == "QtImpPagosDocumentosPagar" )
	return "ServiSNTE (Formas)";

    if ( feature == "QtImpDiferenciasInventario" )
	return "ServiSNTE (Formas)";

    if ( feature == "QtImpRegistroLibro" )
	return "ServiSNTE (Formas)";

    if ( feature == "QtImpProveedores" )
	return "ServiSNTE (Formas)";

    if ( feature == "QtImpRepListaPreciosComprador" )
	return "ServiSNTE (Formas)";

    if ( feature == "QtImpMultiApoyos" )
	return "ServiSNTE (Formas)";
    if ( feature == "QtImpMantenimientoProductos" )
	return "ServiSNTE (Formas)";

    if ( feature == "QtImpSaldosMovimientos" )
	return "ServiSNTE (Formas)";

    if ( feature == "QtImpDesajusteInventario" )
	return "ServiSNTE (Formas)";

    if ( feature == "QtImpRepProveedores" )
	return "ServiSNTE (Formas)";

    if ( feature == "QtImpActualizaStock" )
    if ( feature == "QtImpActualizaStock" )
	return "ServiSNTE (Formas)";


    if ( feature == "QCtrlConceptosExistencias" )
	return "Siscom ServiSNTE";

    if ( feature == "QCtrlTiendasEntrega" )
	return "Siscom ServiSNTE";

    if ( feature == "QCtrlVendedores" )
	return "Siscom ServiSNTE";

    if ( feature == "QCtrlTipoDocumentos" )
	return "Siscom ServiSNTE";

    if ( feature == "QCtrlEstados" )
	return "Siscom ServiSNTE";

    if ( feature == "QCtrlFormasEntrega" )
	return "Siscom ServiSNTE";

    if ( feature == "QCtrlTipoVentas" )
	return "Siscom ServiSNTE";

    if ( feature == "QCtrlFinanciadoras" )
	return "Siscom ServiSNTE";


    if ( feature == "QCtrlProveedoresSS" )
	return "Siscom ServiSNTE";

if ( feature == "QCtrlProductosSS" )
	return "Siscom ServiSNTE";

if ( feature == "QCtrlPlazos" )
	return "Siscom ServiSNTE";

if ( feature == "QCtrlCamiones" )
	return "Siscom ServiSNTE";

if ( feature == "QCtrlDepartamentosSS" )
	return "Siscom ServiSNTE";

if ( feature == "QCtrlCodigoBarras" )
	return "Siscom ServiSNTE";
   

if ( feature == "QCtrlTipoViviendaSS" )
	return "Siscom ServiSNTE";
if ( feature == "QCtrlFrecuenciaPagosSS" )
	return "Siscom ServiSNTE";
if ( feature == "QCtrlFrecuenciaTransaccionalSS" )
	return "Siscom ServiSNTE";

if ( feature == "QCtrlTiposFolio" )
	return "Siscom ServiSNTE";

if ( feature == "QCtrlPerfilesSS" )
	return "Siscom ServiSNTE";

if ( feature == "QCtrlStock" )
	return "Siscom ServiSNTE";

if ( feature == "QCtrlSoporteVentas" )
	return "Siscom ServiSNTE";

if ( feature == "QCtrlInventarioProgramado" )
	return "Siscom ServiSNTE";

if ( feature == "QCtrlEstadoInventario" )
	return "Siscom ServiSNTE";


if ( feature == "QCtrlExistenciaProveedor" )
	return "Siscom ServiSNTE";

if ( feature == "QCtrlSaldosMovimientosMes" )
	return "Siscom ServiSNTE";
if ( feature == "QCtrlConceptosSaldosMovimientos" )
	return "Siscom ServiSNTE";
    return QString::null;

}

QIconSet QtPluginSiscomServiSNTE::iconSet( const QString& ) const
{
    return QIconSet( QPixmap( filechooser_pixmap ) );
}

QString QtPluginSiscomServiSNTE::includeFile( const QString& feature ) const
{
    if ( feature == "QtImpProveedores" )
	return "QtImpProveedores.h";

    if ( feature == "QtImpCapturaProductos" )
	return "QtImpCapturaProductos.h";

    if ( feature == "QtImpCapturacliente" )
	return "QtImpCapturacliente.h";

    if ( feature == "QtImpCapturaCamiones" )
	return "QtImpCapturaCamiones.h";

    if ( feature == "QtImpCapturaChoferes" )
	return "QtImpCapturaChoferes.h";

    if ( feature == "QtImpCapturaVendedores" )
	return "QtImpCapturaVendedores.h";

    if ( feature == "QtImpCapturaConceptosExistencias" )
	return "QtImpCapturaConceptosExistencias.h";


    if ( feature == "QtImpCapturaTienda" )
	return "QtImpCapturaTienda.h";

    if ( feature == "QtImpCapturaDepartamentos" )
	return "QtImpCapturaDepartamentos.h";

    if ( feature == "QtImpCargaNominaEmpleados" )
	return "QtImpCargaNominaEmpleados.h";

    if ( feature == "QtImpCargaBaseDeDatosMaestros" )
	return "QtImpCargaBaseDeDatosMaestros.h";
    
    if ( feature == "QtImpPuntoDeVenta" )
	return "QtImpPuntoDeVenta.h";
    
    if ( feature == "QtImpRegistroCompras" )
	return "QtImpRegistroCompras.h";
    
    if ( feature == "QtImpImpresionCodigoBarras" )
	return "QtImpImpresionCodigoBarras.h";

    if ( feature == "QtImpCapturaInventario" )
	return "QtImpCapturaInventario.h";

    if ( feature == "QtImpCapturaInventarioAlmacen" )
	return "QtImpCapturaInventarioAlmacen.h";
    
    if ( feature == "QtImpTransferenciaAlmacen" )
	return "QtImpTransferenciaAlmacen.h";

    if ( feature == "QtImpReporteVentas" )
	return "QtImpReporteVentas.h";

    if ( feature == "QtImpVisorTransferencias" )
	return "QtImpVisorTransferencias.h";

    if ( feature == "QtImpAbonosApartado" )
	return "QtImpAbonosApartado.h";

    if ( feature == "QtImpBeneficiosIntegrales" )
	return "QtImpBeneficiosIntegrales.h";
    
    if ( feature == "QtImpRecibirTransferencias" )
	return "QtImpRecibirTransferencias.h";

    if ( feature == "QtImpControlReplicas" )
	return "QtImpControlReplicas.h";
    if ( feature == "QtImpFijaFechaCompra" )
	return "QtImpFijaFechaCompra.h";

    if ( feature == "QtImpExistenciasAlmacen" )
	return "QtImpExistenciasAlmacen.h";

    if ( feature == "QtImpReporteCompras" )
	return "QtImpReporteCompras.h";


    if ( feature == "QtImpTrasnferenciasEnviadas" )
	return "QtImpTrasnferenciasEnviadas.h";

    if ( feature == "QtImpRepStockDepartamentoProveedor" )
	return "QtImpRepStockDepartamentoProveedor.h";

    if ( feature == "QtImpRepExistenciaProveedor" )
	return "QtImpRepExistenciaProveedor.h";

    if ( feature == "QtImpRepPreciosProducto" )
	return "QtImpRepPreciosProducto.h";

    if ( feature == "QtImpRepStockTienda" )
	return "QtImpRepStockTienda.h";

    if ( feature == "QtImpRepStockProveedorCosto" )
        return "QtImpRepStockProveedorCosto.h";
    
    if ( feature == "QtImpActivaServidor" )
        return "QtImpActivaServidor.h";

    if ( feature == "QtImpRepCompras" )
        return "QtImpRepCompras.h";

    if ( feature == "QtImpRegistroUsuarios" )
        return "QtImpRegistroUsuarios.h";

    if ( feature == "QtImpSoporteVentas" )
        return "QtImpSoporteVentas.h";

    if ( feature == "QtImpSoporteCompras" )
        return "QtImpSoporteCompras.h";

    if ( feature == "QtImpSoporteTransferencias" )
        return "QtImpSoporteTransferencias.h";

    if ( feature == "QtImpRepExistenciaTiendaProveedor" )
        return "QtImpRepExistenciaTiendaProveedor.h";

    if ( feature == "QtImpRegistroInventario" )
        return "QtImpRegistroInventario.h";

    if ( feature == "QtImpPagosDocumentosPagar" )
        return "QtImpPagosDocumentosPagar.h";

    if ( feature == "QtImpDiferenciasInventario" )
        return "QtImpDiferenciasInventario.h";

    if ( feature == "QtImpRegistroLibro" )
        return "QtImpRegistroLibro.h";

    if ( feature == "QtImpProveedores" )
        return "QtImpProveedores.h";

    if ( feature == "QtImpRepListaPreciosComprador" )
        return "QtImpRepListaPreciosComprador.h";

    if ( feature == "QtImpMultiApoyos" )
        return "QtImpMultiApoyos.h";

    if ( feature == "QtImpMantenimientoProductos" )
        return "QtImpMantenimientoProductos.h";

    if ( feature == "QtImpSaldosMovimientos" )
        return "QtImpSaldosMovimientos.h";

    if ( feature == "QtImpDesajusteInventario" )
        return "QtImpDesajusteInventario.h";
    if ( feature == "QtImpRepProveedores" )
        return "QtImpRepProveedores.h";

    if ( feature == "QtImpActualizaStock" )
        return "QtImpActualizaStock.h";


    if ( feature == "QCtrlConceptosExistencias" )
	return "QCtrlConceptosExistencias.h";

    if ( feature == "QCtrlTiendasEntrega" )
	return "QCtrlTiendasEntrega.h";

    if ( feature == "QCtrlVendedores" )
	return "QCtrlVendedores.h";

    if ( feature == "QCtrlTipoDocumentos" )
	return "QCtrlTipoDocumentos.h";

   if ( feature == "QCtrlEstados" )
	return "QCtrlEstados.h";

   if ( feature == "QCtrlFormasEntrega" )
	return "QCtrlFormasEntrega.h";

   if ( feature == "QCtrlTipoVentas" )
	return "QCtrlTipoVentas.h";

   if ( feature == "QCtrlFinanciadoras" )
	return "QCtrlFinanciadoras.h";


    if ( feature == "QCtrlProveedoresSS" )
	return "QCtrlProveedoresSS.h";

    if ( feature == "QCtrlProductosSS" )
	return "QCtrlProductosSS.h";

    if ( feature == "QCtrlPlazos" )
	return "QCtrlPlazos.h";
    
    if ( feature == "QCtrlCamiones" )
	return "QCtrlCamiones.h";
    
    if ( feature == "QCtrlDepartamentosSS" )
	return "QCtrlDepartamentosSS.h";


    if ( feature == "QCtrlCodigoBarras" )
	return "QCtrlCodigoBarras.h";

    if ( feature == "QCtrlTipoViviendaSS" )
	return "QCtrlTipoViviendaSS.h";
    if ( feature == "QCtrlFrecuenciaPagosSS" )
	return "QCtrlFrecuenciaPagosSS.h";
    if ( feature == "QCtrlFrecuenciaTransaccionalSS" )
	return "QCtrlFrecuenciaTransaccionalSS.h";

    if ( feature == "QCtrlTiposFolio" )
	return "QCtrlTiposFolio.h";

    if ( feature == "QCtrlPerfilesSS" )
	return "QCtrlPerfilesSS.h";
    if ( feature == "QCtrlStock" )
	return "QCtrlStock.h";

    if ( feature == "QCtrlSoporteVentas" )
	return "QCtrlSoporteVentas.h";

    if ( feature == "QCtrlInventarioProgramado" )
	return "QCtrlInventarioProgramado.h";

    if ( feature == "QCtrlEstadoInventario" )
	return "QCtrlEstadoInventario.h";

    if ( feature == "QCtrlExistenciaProveedor" )
	return "QCtrlExistenciaProveedor.h";
    if ( feature == "QCtrlSaldosMovimientosMes" )
	return "QCtrlSaldosMovimientosMes.h";
    if ( feature == "QCtrlConceptosSaldosMovimientos" )
	return "QCtrlConceptosSaldosMovimientos.h";

    return QString::null;
}

QString QtPluginSiscomServiSNTE::toolTip( const QString& feature ) const
{
    if ( feature == "QtImpProveedores" )
	return "Selecciona Productos";

    if ( feature == "QtImpCapturaProductos" )
	return "Selecciona Productos";

    if ( feature == "QtImpCargaNominaEmpleados" )
	return "Selecciona Productos";

    if ( feature == "QtImpCargaBaseDeDatosMaestros" )
	return "Selecciona Productos";
    
    if ( feature == "QtImpCapturaCamiones" )
	return "Selecciona Productos";

    if ( feature == "QtImpCapturaChoferes" )
	return "Selecciona Productos";

    if ( feature == "QtImpCapturaVendedores" )
	return "Selecciona Productos";

    if ( feature == "QtImpCapturaConceptosExistencias" )
	return "Selecciona Productos";

    if ( feature == "QtImpCapturaTienda" )
	return "Selecciona Productos";

    if ( feature == "QtImpCapturaDepartamentos" )
	return "Selecciona Productos";

    if ( feature == "QtImpPuntoDeVenta" )
	return "Selecciona Productos";

    if ( feature == "QtImpRegistroCompras" )
	return "Selecciona Productos";

    if ( feature == "QtImpImpresionCodigoBarras" )
	return "Selecciona Productos";
    
    if ( feature == "QtImpCapturaInventario" )
	return "Selecciona Productos";

    if ( feature == "QtImpCapturaInventarioAlmacen" )
	return "Selecciona Productos";
    if ( feature == "QtImpTransferenciaAlmacen" )
	return "Selecciona Productos";

    if ( feature == "QtImpReporteVentas" )
	return "Selecciona Productos";

    if ( feature == "QtImpVisorTransferencias" )
	return "Selecciona Productos";
    
    if ( feature == "QtImpAbonosApartado" )
	return "Selecciona Productos";

    if ( feature == "QtImpBeneficiosIntegrales" )
	return "Selecciona Productos";

    if ( feature == "QtImpRecibirTransferencias" )
	return "Selecciona Productos";

    if ( feature == "QtImpControlReplicas" )
	return "Selecciona Productos";
    if ( feature == "QtImpFijaFechaCompra" )
	return "Selecciona Productos";

    if ( feature == "QtImpExistenciasTienda" )
	return "Selecciona Productos";
    if ( feature == "QtImpExistenciasAlmacen" )
	return "Selecciona Productos";

    if ( feature == "QtImpReporteCompras" )
	return "Selecciona Productos";
    if ( feature == "QtImpTransferenciasEnviadas" )
	return "Selecciona Productos";

    if ( feature == "QtImpConsultaVentas" )
	return "Selecciona Productos";

    if ( feature == "QtImpFolioApartado" )
	return "Selecciona Productos";

    if ( feature == "QtImpFoliosCancelados" )
	return "Selecciona Productos";

    if ( feature == "QtImpRepStockDepartamentoProveedor" )
	return "Selecciona Productos";

    if ( feature == "QtImpRepExistenciaProveedor" )
	return "Selecciona Productos";

    if ( feature == "QtImpRepPreciosProducto" )
	return "Selecciona Productos";

    if ( feature == "QtImpRepStockTienda" )
	return "Selecciona Productos";

    if ( feature == "QtImpRepStockProveedorCosto" )
	return "Selecciona Productos";
    
    if ( feature == "QtImpActivaServidor" )
	return "Selecciona Productos";

    if ( feature == "QtImpRepCompras" )
	return "Selecciona Productos";

    if ( feature == "QtImpRegistroUsuarios" )
	return "Selecciona Productos";

    if ( feature == "QtImpSoporteVentas" )
	return "Selecciona Productos";

    if ( feature == "QtImpSoporteCompras" )
	return "Selecciona Productos";

    if ( feature == "QtImpSoporteTransferencias" )
	return "Selecciona Productos";

    if ( feature == "QtImpRepExistenciaTiendaProveedor" )
	return "Selecciona Productos";

    if ( feature == "QtImpRegistroInventario" )
	return "Selecciona Productos";

    if ( feature == "QtImpPagosDocumentosPagar" )
	return "Selecciona Productos";

    if ( feature == "QtImpDiferenciasInventario" )
	return "Selecciona Productos";

    if ( feature == "QtImpRegistroLibro" )
	return "Selecciona Productos";

    if ( feature == "QtImpProveedores" )
	return "Selecciona Productos";

    if ( feature == "QtImpRepListaPreciosComprador" )
	return "Selecciona Productos";

    if ( feature == "QtImpMultiApoyos" )
	return "Selecciona Productos";

    if ( feature == "QtImpMantenimientoProductos" )
	return "Selecciona Productos";

    if ( feature == "QtImpSaldosMovimientos" )
	return "Selecciona Productos";

    if ( feature == "QtImpDesajusteInventario" )
	return "Selecciona Productos";

    if ( feature == "QtImpRepProveedores" )
	return "Selecciona Productos";
    if ( feature == "QtImpActualizaStock" )
	return "Selecciona Productos";



    if ( feature == "QCtrlConceptosExistencias" )
	return "Selecciona Productos";

    if ( feature == "QCtrlTiendasEntrega" )
	return "Selecciona Productos";

    if ( feature == "QCtrlVendedores" )
	return "Selecciona Productos";

    if ( feature == "QCtrlTipoDocumentos" )
	return "Selecciona Productos";

    if ( feature == "QCtrlEstados" )
	return "Selecciona Productos";

    if ( feature == "QCtrlFormasEntrega" )
	return "Selecciona Productos";

    if ( feature == "QCtrlTipoVentas" )
	return "Selecciona Productos";

    if ( feature == "QCtrlFinanciadoras" )
	return "Selecciona Productos";


    if ( feature == "QCtrlProveedoresSS" )
	return "Selecciona Productos";

    if ( feature == "QCtrlProductosSS" )
	return "Selecciona Productos";

    if ( feature == "QCtrlPlazos" )
	return "Selecciona Productos";

    if ( feature == "QCtrlCamiones" )
	return "Selecciona Camiones";
    
    if ( feature == "QCtrlDepartamentosSS" )
	return "Selecciona Productos";

    if ( feature == "QCtrlCodigoBarras" )
	return "Selecciona Productos";

    if ( feature == "QCtrlTipoViendaSS" )
	return "Selecciona Productos";
    if ( feature == "QCtrlFrecuenciaPagosSS" )
	return "Selecciona Productos";
    if ( feature == "QCtrlFrecuenciaTransaccionalSS" )
	return "Selecciona Productos";

    if ( feature == "QCtrlTiposFolio" )
	return "Selecciona Productos";

    if ( feature == "QCtrlPerfilesSS" )
	return "Selecciona Productos";

    if ( feature == "QCtrlStock" )
	return "Selecciona Productos";

    if ( feature == "QCtrlSoporteVentas" )
	return "Selecciona Productos";

    if ( feature == "QCtrlInventarioProgramado" )
	return "Selecciona Productos";

    if ( feature == "QCtrlEstadoInventario" )
	return "Selecciona Productos";

    if ( feature == "QCtrlExistenciaProveedor" )
	return "Selecciona Productos";

    if ( feature == "QCtrlSaldosMovimientosMes" )
	return "Selecciona Productos";

    if ( feature == "QCtrlConceptosSaldosMovimientos" )
	return "Selecciona Productos";
    return QString::null;
}

QString QtPluginSiscomServiSNTE::whatsThis( const QString& feature ) const
{
    if ( feature == "QtImpProveedores" )
	return "Selecciona un producto";

    if ( feature == "QtImpCapturaProductos" )
	return "Selecciona un producto";

    if ( feature == "QtImpCargaNominaEmpleados" )
	return "Selecciona un producto";

    if ( feature == "QtImpCargaBaseDeDatosMaestros" )
	return "Selecciona un producto";

    if ( feature == "QtImpCapturaCamiones" )
	return "Selecciona un producto";

    if ( feature == "QtImpCapturaChoferes" )
	return "Selecciona un producto";

    if ( feature == "QtImpCapturaVendedores" )
	return "Selecciona un producto";

    if ( feature == "QtImpCapturaConceptosExistencias" )
	return "Selecciona un producto";

    if ( feature == "QtImpCapturaTienda" )
	return "Selecciona un producto";

    if ( feature == "QtImpCapturaDepartamentos" )
	return "Selecciona un producto";

    if ( feature == "QtImpPuntoDeVenta" )
	return "Selecciona un producto";

    if ( feature == "QtImpRegistroCompras" )
	return "Selecciona un producto";

    if ( feature == "QtImpImpresionCodigoBarras" )
	return "Selecciona un producto";

    if ( feature == "QtImpCapturaInventario" )
	return "Selecciona un producto";
    
    if ( feature == "QtImpCapturaInventarioAlmacen" )
	return "Selecciona un producto";

    if ( feature == "QtImpTransferenciaAlmacen" )
	return "Selecciona un producto";
    
    if ( feature == "QtImpReporteVentas" )
	return "Selecciona un producto";

    if ( feature == "QtImpVisorTransferencias" )
	return "Selecciona un producto";

    if ( feature == "QtImpAbonosApartado" )
	return "Selecciona un producto";

    if ( feature == "QtImpBeneficiosIntegrales" )
	return "Selecciona un producto";
    
    if ( feature == "QtImpRecibirTransferencias" )
	return "Selecciona un producto";

    if ( feature == "QtImpControlReplicas" )
	return "Selecciona un producto";
    if ( feature == "QtImpFijaFechaCompra" )
	return "Selecciona un producto";
    if ( feature == "QtImpExistenciasTienda" )
	return "Selecciona un producto";
    if ( feature == "QtImpExistenciasAlmacen" )
	return "Selecciona un producto";

    if ( feature == "QtImpReporteCompras" )
	return "Selecciona un producto";

    if ( feature == "QtImpTransferenciasEnviadas" )
	return "Selecciona un producto";

    if ( feature == "QtImpConsultaVentas" )
	return "Selecciona un producto";

    if ( feature == "QtImpFolioApartado" )
	return "Selecciona un producto";

    if ( feature == "QtImpFoliosCancelados" )
	return "Selecciona un producto";

    if ( feature == "QtImpRepStockDepartamentoProveedor" )
	return "Selecciona un producto";

    if ( feature == "QtImpRepExistenciaProveedor" )
	return "Selecciona un producto";

    if ( feature == "QtImpRepPreciosProducto" )
	return "Selecciona un producto";

    if ( feature == "QtImpRepStockTienda" )
	return "Selecciona un producto";

    if ( feature == "QtImpRepStockProveedorCosto" )
	return "Selecciona un producto";

    if ( feature == "QtImpActivaServidor" )
	return "Selecciona un producto";
   
    if ( feature == "QtImpRepCompras" )
	return "Selecciona un producto";

    if ( feature == "QtImpRegistroUsuarios" )
	return "Selecciona un producto";

    if ( feature == "QtImpSoporteVentas" )
	return "Selecciona un producto";

    if ( feature == "QtImpSoporteCompras" )
	return "Selecciona un producto";

    if ( feature == "QtImpSoporteTransferencias" )
	return "Selecciona un producto";

    if ( feature == "QtImpRepExistenciaTiendaProveedor" )
	return "Selecciona un producto";

    if ( feature == "QtImpRegistroInventario" )
	return "Selecciona un producto";

    if ( feature == "QtImpPagosDocumentosPagar" )
	return "Selecciona un producto";

    if ( feature == "QtImpDiferenciasInventario" )
	return "Selecciona un producto";

    if ( feature == "QtImpRegistroLibro" )
	return "Selecciona un producto";

    if ( feature == "QtImpProveedores" )
	return "Selecciona un producto";

    if ( feature == "QtImpRepListaPreciosComprador" )
	return "Selecciona un producto";

    if ( feature == "QtImpMultiApoyos" )
	return "Selecciona un producto";

    if ( feature == "QtImpMantenimientoProductos" )
	return "Selecciona un producto";

    if ( feature == "QtImpSaldosMovimientos" )
	return "Selecciona un producto";

    if ( feature == "QtImpDesajusteInventario" )
	return "Selecciona un producto";

    if ( feature == "QtImpRepProveedores" )
	return "Selecciona un producto";

    if ( feature == "QtImpActualizaStock" )
	return "Selecciona un producto";


    if ( feature == "QCtrlConceptosExistencias" )
	return "Selecciona un producto";

    if ( feature == "QCtrlTiendasEntrega" )
	return "Selecciona un producto";

    if ( feature == "QCtrlVendedores" )
	return "Selecciona un producto";

    if ( feature == "QCtrlTipoDocumentos" )
	return "Selecciona un producto";

    if ( feature == "QCtrlEstados" )
	return "Selecciona un producto";
    
    if ( feature == "QCtrlFormasEntrega" )
	return "Selecciona un producto";

    if ( feature == "QCtrlTipoVentas" )
	return "Selecciona un producto";

    if ( feature == "QCtrlFinanciadoras" )
	return "Selecciona un producto";

    if ( feature == "QCtrlProveedoresSS" )
	return "Selecciona un producto";

    if ( feature == "QCtrlProductosSS" )
	return "Selecciona un producto";

    if ( feature == "QCtrlPlazos" )
	return "Selecciona un producto";
    
    if ( feature == "QCtrlCamiones" )
	return "Selecciona un producto";
    
    if ( feature == "QCtrlDepartamentosSS" )
	return "Selecciona un producto";

    if ( feature == "QCtrlCodigoBarras" )
	return "Selecciona un producto";

    if ( feature == "QCtrlTipoViviendaSS" )
	return "Selecciona un producto";
    if ( feature == "QCtrlFrecuenciaPagosSS" )
	return "Selecciona un producto";
    if ( feature == "QCtrlFrecuenciaTransaccionalSS" )
	return "Selecciona un producto";
    if ( feature == "QCtrlTiposFolio" )
	return "Selecciona un producto";

    if ( feature == "QCtrlPerfilesSS" )
	return "Selecciona un producto";
    if ( feature == "QCtrlStock" )
	return "Selecciona un producto";

    if ( feature == "QCtrlSoporteVentas" )
	return "Selecciona un producto";

    if ( feature == "QCtrlInventarioProgramado" )
	return "Selecciona un producto";

    if ( feature == "QCtrlEstadoInventario" )
	return "Selecciona un producto";

    if ( feature == "QCtrlExistenciaProveedor" )
	return "Selecciona un producto";
    if ( feature == "QCtrlSaldosMovimientosMes" )
	return "Selecciona un producto";
    if ( feature == "QCtrlConceptosSaldosMovimientos" )
	return "Selecciona un producto";


    return QString::null;
}

bool QtPluginSiscomServiSNTE::isContainer( const QString& ) const
{
    return FALSE;
}


Q_EXPORT_PLUGIN( QtPluginSiscomServiSNTE )

