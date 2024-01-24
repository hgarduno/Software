
#include <QCtrlPluginSiscomElectronica3.h>
#include <QCtrlProdSiscomElectronica.h>
#include <QCtrlEmpleados.h>
#include <QCtrlExpendios.h>
#include <QCtrlBodegas.h>
#include <QCtrlCmbBodegas.h>
#include <QCtrlAlumnos.h>
#include <QCtrlMotivoInventario.h>
#include <QCtrlCursos.h>
#include <QCtrlFechasCursos.h>
#include <QCtrlServiciosSiscom.h>
#include <QCtrlProgramacionCursos.h>
#include <QCtrlEstadisticasSemanalesVentas.h>
#include <QCtrlExplicacionPromocion.h>
#include <QCtrlOrigenCompra.h>
#include <QCtrlProductosSE.h>
#include <QCtrlEscuelasSE.h>
#include <QCtrlEstadosImpresosSE.h>
#include <QCtrlTiposProductoSE.h>
#include <QCtrlGastosSE.h>
#include <QCtrlCuentaDinero.h>
#include <QCtrlExpendiosSE.h>
#include <QCtrlProveedoresSE.h>
#include <QCtrlClientesMayoreo.h>
#include <QCtrlFormaPagoSat.h>
#include <QCtrlUsoCFDISat.h>
#include <QCtrlRFCs.h>
#include <QCtrlMetodoPagoSat.h>
#include <QCtrlMateriasSE.h>
#include <QCtrlCajasUbicacion.h>
#include <QCtrlEstantes.h>
#include <QCtrlOrdenesFavoritas.h>
#include <QCtrlEstadosPedidosClienteSE.h>
#include <QCtrlRegimenFiscal.h>
#include <QCtrlBodegas4.h>
#include <QCtrlCmbBodegas4.h>


#include <SiscomDesarrollo3Qt++.h>
#include <zSiscomDesarrollo4.h>

FILE *gPtrFleArchivoLog3Qt;

void *gzSiscomConexion;
FILE *gPtrFleArchivoLog;

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

QCtrlPluginSiscomElectronica3::QCtrlPluginSiscomElectronica3()
{

}

QStringList QCtrlPluginSiscomElectronica3::keys() const
{
    QStringList list;
    list << 
    "QCtrlProdSiscomElectronica"	<<
    "QCtrlEmpleados"			<<
    "QCtrlExpendios"			<<
    "QCtrlBodegas"			<<
    "QCtrlCmbBodegas"			<<
    "QCtrlAlumnos"			<<
    "QCtrlMotivoInventario"		<<
    "QCtrlCursos"			<<
    "QCtrlFechasCursos"			<<
    "QCtrlServiciosSiscom"		<<
    "QCtrlProgramacionCursos"		<<
    "QCtrlEstadisticasSemanalesVentas"	<<
    "QCtrlExplicacionPromocion"		<<
    "QCtrlOrigenCompra"			<<
    "QCtrlProductosSE"			<<
    "QCtrlEscuelasSE"			<<
    "QCtrlEstadosImpresosSE" 		<<
    "QCtrlTiposProductoSE"  		<<
    "QCtrlGastosSE" 			<<
    "QCtrlCuentaDinero" 		<<
    "QCtrlExpendiosSE"			<<
    "QCtrlProveedoresSE"		<<
    "QCtrlClientesMayoreo"		<<
    "QCtrlFormaPagoSat"			<<
    "QCtrlUsoCFDISat"			<<
    "QCtrlMetodoPagoSat"		<<
    "QCtrlRFCs"				<<
    "QCtrlMateriasSE"			<<
    "QCtrlCajasUbicacion"		<<
    "QCtrlEstantes"			<<
    "QCtrlOrdenesFavoritas"		<<
    "QCtrlEstadosPedidosClienteSE"	<<
    "QCtrlRegimenFiscal"		<<
    "QCtrlBodegas4"			<<
    "QCtrlCmbBodegas4";
    return list;
}

QWidget* QCtrlPluginSiscomElectronica3::create( const QString &key, QWidget* parent, const char* name )
{
    if ( key == "QCtrlProdSiscomElectronica" )
	return new QCtrlProdSiscomElectronica( parent, name );
    if ( key == "QCtrlEmpleados" )
	return new QCtrlEmpleados( parent, name );
    if ( key == "QCtrlExpendios" )
	return new QCtrlExpendios( parent, name );
    if ( key == "QCtrlBodegas" )
	return new QCtrlBodegas( parent, name );
    if ( key == "QCtrlCmbBodegas" )
	return new QCtrlCmbBodegas( parent, name );
    if ( key == "QCtrlAlumnos" )
	return new QCtrlAlumnos( parent, name );
    if ( key == "QCtrlMotivoInventario" )
	return new QCtrlMotivoInventario( parent, name );
    if ( key == "QCtrlCursos" )
	return new QCtrlCursos( parent, name );
    if ( key == "QCtrlFechasCursos" )
	return new QCtrlFechasCursos( parent, name );


    if ( key == "QCtrlServiciosSiscom" )
	return new QCtrlServiciosSiscom( parent, name );

    if ( key == "QCtrlProgramacionCursos" )
	return new QCtrlProgramacionCursos( parent, name );

    if ( key == "QCtrlEstadisticasSemanalesVentas" )
	return new QCtrlEstadisticasSemanalesVentas( parent, name );
    if ( key == "QCtrlExplicacionPromocion" )
	return new QCtrlExplicacionPromocion( parent, name );

    if ( key == "QCtrlOrigenCompra" )
	return new QCtrlOrigenCompra( parent, name );

    if ( key == "QCtrlProductosSE" )
	return new QCtrlProductosSE( parent, name );

    if ( key == "QCtrlEscuelasSE" )
	return new QCtrlEscuelasSE( parent, name );

    if ( key == "QCtrlEstadosImpresosSE" )
	return new QCtrlEstadosImpresosSE( parent, name );


    if ( key == "QCtrlTiposProductoSE" )
	return new QCtrlTiposProductoSE( parent, name );

    if ( key == "QCtrlGastosSE" )
	return new QCtrlGastosSE( parent, name );

    if ( key == "QCtrlCuentaDinero" )
	return new QCtrlCuentaDinero( parent, name );

    if ( key == "QCtrlExpendiosSE" )
	return new QCtrlExpendiosSE( parent, name );

    if ( key == "QCtrlProveedoresSE" )
	return new QCtrlProveedoresSE( parent, name );

    if ( key == "QCtrlClientesMayoreo" )
	return new QCtrlClientesMayoreo( parent, name );
    if ( key == "QCtrlFormaPagoSat" )
	return new QCtrlFormaPagoSat( parent, name );
    if ( key == "QCtrlUsoCFDISat" )
	return new QCtrlUsoCFDISat( parent, name );
    if ( key == "QCtrlMetodoPagoSat" )
	return new QCtrlMetodoPagoSat( parent, name );

    if ( key == "QCtrlRFCs" )
	return new QCtrlRFCs( parent, name );

    if ( key == "QCtrlMateriasSE" )
	return new QCtrlMateriasSE( parent, name );
    if ( key == "QCtrlCajasUbicacion" )
	return new QCtrlCajasUbicacion( parent, name );
    if ( key == "QCtrlEstantes" )
	return new QCtrlEstantes( parent, name );

    if ( key == "QCtrlOrdenesFavoritas" )
	return new QCtrlOrdenesFavoritas( parent, name );

    if ( key == "QCtrlEstadosPedidosClienteSE" )
	return new QCtrlEstadosPedidosClienteSE( parent, name );
    if ( key == "QCtrlRegimenFiscal" )
	return new QCtrlRegimenFiscal( parent, name );

    if ( key == "QCtrlBodegas4" )
	return new QCtrlBodegas4( parent, name );
    if ( key == "QCtrlCmbBodegas4" )
	return new QCtrlCmbBodegas4( parent, name );


    return 0;
}

QString QCtrlPluginSiscomElectronica3::group( const QString& feature ) const
{
    if ( feature == "QCtrlProdSiscomElectronica" )
	return "Siscom Electronica3";
    if ( feature == "QCtrlEmpleados" )
	return "Siscom Electronica3";
    if ( feature == "QCtrlExpendios" )
	return "Siscom Electronica3";
    if ( feature == "QCtrlBodegas" )
	return "Siscom Electronica3";
    if ( feature == "QCtrlCmbBodegas" )
	return "Siscom Electronica3";
    if ( feature == "QCtrlAlumnos" )
	return "Siscom Electronica3";
    if ( feature == "QCtrlMotivoInventario" )
	return "Siscom Electronica3";

    if ( feature == "QCtrlCursos" )
	return "Siscom Electronica3";
    if ( feature == "QCtrlFechasCursos" )
	return "Siscom Electronica3";

    if ( feature == "QCtrlServiciosSiscom" )
	return "Siscom Electronica3";

    if ( feature == "QCtrlProgramacionCursos" )
	return "Siscom Electronica3";

    if ( feature == "QCtrlEstadisticasSemanalesVentas" )
	return "Siscom Electronica3";


    if ( feature == "QCtrlExplicacionPromocion" )
	return "Siscom Electronica3";
    if ( feature == "QCtrlOrigenCompra" )
	return "Siscom Electronica3";
    if ( feature == "QCtrlProductosSE" )
	return "Siscom Electronica3";
    if ( feature == "QCtrlEscuelasSE" )
	return "Siscom Electronica3";
    if ( feature == "QCtrlEstadosImpresosSE" )
	return "Siscom Electronica3";


    if ( feature == "QCtrlTiposProductoSE" )
	return "Siscom Electronica3";
    if ( feature == "QCtrlGastosSE" )
	return "Siscom Electronica3";

    if ( feature == "QCtrlCuentaDinero" )
	return "Siscom Electronica3";

    if ( feature == "QCtrlExpendiosSE" )
	return "Siscom Electronica3";

    if ( feature == "QCtrlProveedoresSE" )
	return "Siscom Electronica3";

    if ( feature == "QCtrlClientesMayoreo" )
	return "Siscom Electronica3";
    if ( feature == "QCtrlFormaPagoSat" )
	return "Siscom Electronica3";
    if ( feature == "QCtrlUsoCFDISat" )
	return "Siscom Electronica3";
    if ( feature == "QCtrlMetodoPagoSat" )
	return "Siscom Electronica3";

    if ( feature == "QCtrlRFCs" )
	return "Siscom Electronica3";

    if ( feature == "QCtrlMateriasSE" )
	return "Siscom Electronica3";

    if ( feature == "QCtrlCajasUbicacion" )
	return "Siscom Electronica3";

    if ( feature == "QCtrlEstantes" )
	return "Siscom Electronica3";
    if ( feature == "QCtrlOrdenesFavoritas" )
	return "Siscom Electronica3";

    if ( feature == "QCtrlEstadosPedidosClienteSE" )
	return "Siscom Electronica3";

    if ( feature == "QCtrlRegimenFiscal" )
	return "Siscom Electronica3";
    if ( feature == "QCtrlBodegas4" )
	return "Siscom Electronica3";

    if ( feature == "QCtrlCmbBodegas4" )
	return "Siscom Electronica3";


    return QString::null;
}

QIconSet QCtrlPluginSiscomElectronica3::iconSet( const QString& ) const
{
    return QIconSet( QPixmap( filechooser_pixmap ) );
}

QString QCtrlPluginSiscomElectronica3::includeFile( const QString& feature ) const
{
    if ( feature == "QCtrlProdSiscomElectronica" )
	return "QCtrlProdSiscomElectronica.h";
    if ( feature == "QCtrlEmpleados" )
	return "QCtrlEmpleados.h";
    if ( feature == "QCtrlExpendios" )
	return "QCtrlExpendios.h";
    if ( feature == "QCtrlBodegas" )
	return "QCtrlBodegas.h";

    if ( feature == "QCtrlCmbBodegas" )
	return "QCtrlCmbBodegas.h";
    if ( feature == "QCtrlAlumnos" )
	return "QCtrlAlumnos.h";
    if ( feature == "QCtrlMotivoInventario" )
	return "QCtrlMotivoInventario.h";

    if ( feature == "QCtrlCursos" )
	return "QCtrlCursos.h";
    if ( feature == "QCtrlFechasCursos" )
	return "QCtrlFechasCursos.h";

    if ( feature == "QCtrlServiciosSiscom" )
	return "QCtrlServiciosSiscom.h";

    if ( feature == "QCtrlProgramacionCursos" )
	return "QCtrlProgramacionCursos.h";

    if ( feature == "QCtrlEstadisticasSemanalesVentas" )
	return "QCtrlEstadisticasSemanalesVentas.h";


    if ( feature == "QCtrlExplicacionPromocion" )
	return "QCtrlExplicacionPromocion.h";
    if ( feature == "QCtrlOrigenCompra" )
	return "QCtrlOrigenCompra.h";
    if ( feature == "QCtrlProductosSE" )
	return "QCtrlProductosSE.h";
    if ( feature == "QCtrlEscuelasSE" )
	return "QCtrlEscuelasSE.h";
    if ( feature == "QCtrlEstadosImpresosSE" )
	return "QCtrlEstadosImpresosSE.h";

    if ( feature == "QCtrlTiposProductoSE" )
	return "QCtrlTiposProductoSE.h";
    if ( feature == "QCtrlGastosSE" )
	return "QCtrlGastosSE.h";

    if ( feature == "QCtrlCuentaDinero" )
	return "QCtrlCuentaDinero.h";

    if ( feature == "QCtrlExpendiosSE" )
	return "QCtrlExpendiosSE.h";

    if ( feature == "QCtrlProveedoresSE" )
	return "QCtrlProveedoresSE.h";

    if ( feature == "QCtrlClientesMayoreo" )
	return "QCtrlClientesMayoreo.h";
    if ( feature == "QCtrlFormaPagoSat" )
	return "QCtrlFormaPagoSat.h";

    if ( feature == "QCtrlUsoCFDISat" )
	return "QCtrlUsoCFDISat.h";

    if ( feature == "QCtrlMetodoPagoSat" )
	return "QCtrlMetodoPagoSat.h";
    if ( feature == "QCtrlRFCs" )
	return "QCtrlRFCs.h";

    if ( feature == "QCtrlMateriasSE" )
	return "QCtrlMateriasSE.h";
  
    if ( feature == "QCtrlCajasUbicacion" )
	return "QCtrlCajasUbicacion.h";
    if ( feature == "QCtrlEstantes" )
	return "QCtrlEstantes.h";


    if ( feature == "QCtrlOrdenesFavoritas" )
	return "QCtrlOrdenesFavoritas.h";

    if ( feature == "QCtrlEstadosPedidosClienteSE" )
	return "QCtrlEstadosPedidosClienteSE.h";

    if ( feature == "QCtrlRegimenFiscal" )
	return "QCtrlRegimenFiscal.h";

    if ( feature == "QCtrlBodegas4" )
	return "QCtrlBodegas4.h";

    if ( feature == "QCtrlCmbBodegas4" )
	return "QCtrlCmbBodegas4.h";

    return QString::null;
}

QString QCtrlPluginSiscomElectronica3::toolTip( const QString& feature ) const
{
    if ( feature == "QCtrlProdSiscomElectronica" )
	return "Selecciona Productos";
    if ( feature == "QCtrlEmpleados" )
	return "Selecciona un empleado";
    if ( feature == "QCtrlExpendios" )
	return "Selecciona un expendio";
    if ( feature == "QCtrlBodegas" )
	return "Selecciona una bodega";

    if ( feature == "QCtrlCmbBodegas" )
	return "Selecciona una bodega";
    if ( feature == "QCtrlAlumnoss" )
	return "Selecciona un alumno";
    if ( feature == "QCtrlMotivoInventario" )
	return "Selecciona un Motivo Inventario";

    if ( feature == "QCtrlCursos" )
	return "Selecciona un Curso";
    if ( feature == "QCtrlFechasCursos" )
	return "Selecciona Un Curso Programado";

    if ( feature == "QCtrlServiciosSiscom" )
	return "Selecciona Un Servicio Siscom";

    if ( feature == "QCtrlProgramacionCursos" )
	return "Selecciona Un Cursote";

    if ( feature == "QCtrlEstadisticasSemanalesVentas" )
	return "Selecciona Una Estadistica";

    if ( feature == "QCtrlExplicacionPromocion" )
	return "Selecciona Una Estadistica";
    if ( feature == "QCtrlExplicacionPromocion" )
	return "Selecciona Una Estadistica";
    if ( feature == "QCtrlProductosSE" )
	return "Selecciona un producto";

    if ( feature == "QCtrlEscuelasSE" )
	return "Selecciona un producto";
    if ( feature == "QCtrlEstadosImpresosSE" )
	return "Selecciona un producto";

    if ( feature == "QCtrlTiposProductoSE" )
	return "Siscom Electronica3";
    if ( feature == "QCtrlGastosSE" )
	return "Siscom Electronica3";
    if ( feature == "QCtrlCuentaDinero" )
	return "Siscom Electronica3";

    if ( feature == "QCtrlExpendiosSE" )
	return "Siscom Electronica3";

    if ( feature == "QCtrlProveedoresSE" )
	return "Siscom Electronica3";

    if ( feature == "QCtrlClientesMayoreo" )
	return "Siscom Electronica3";
    if ( feature == "QCtrlFormaPagoSat" )
	return "Siscom Electronica3";

    if ( feature == "QCtrlUsoCFIDSat" )
	return "Siscom Electronica3";

    if ( feature == "QCtrlEstadosPedidosClienteSE" )
	return "Siscom Electronica3";
    return QString::null;
}

QString QCtrlPluginSiscomElectronica3::whatsThis( const QString& feature ) const
{
    if ( feature == "QCtrlProdSiscomElectronica" )
	return "Selecciona un producto";
    if ( feature == "QCtrlEmpleados" )
	return "Selecciona un empleado";
    if ( feature == "QCtrlExpendios" )
	return "Selecciona un expendio";
    if ( feature == "QCtrlBodegas" )
	return "Selecciona una bodega";

    if ( feature == "QCtrlCmbBodegas" )
	return "Selecciona una bodega";
    if ( feature == "QCtrlAlumnoss" )
	return "Selecciona un alumno";

    if ( feature == "QCtrlMotivoInventario" )
	return "Selecciona un Motivo Inventario";


    if ( feature == "QCtrlCursos" )
	return "Selecciona Un Curso ";
    if ( feature == "QCtrlFechasCursos" )
	return "Selecciona Una Fecha Para Curso";

    if ( feature == "QCtrlServiciosSiscom" )
	return "Selecciona un servicio Siscom";

    if ( feature == "QCtrlProgramacionCursos" )
	return "Selecciona un periodo de cursos ";

    if ( feature == "QCtrlEstadisticasSemanalesVentas" )
	return "Selecciona una estadistica";

    if ( feature == "QCtrlExplicacionPromocion" )
	return "Selecciona una estadistica";
    if ( feature == "QCtrlOrigenCompra" )
	return "Selecciona una estadistica";
    if ( feature == "QCtrlProductosSE" )
	return "Selecciona una estadistica";

    if ( feature == "QCtrlEscuelasSE" )
	return "Selecciona una estadistica";
    if ( feature == "QCtrlEstadosImpresosSE" )
	return "Selecciona una estadistica";


    if ( feature == "QCtrlTiposProductoSE" )
	return "Selecciona Tipos Producto";
    if ( feature == "QCtrlGastosSE" )
	return "Selecciona Tipos Producto";
    if ( feature == "QCtrlCuentaDinero" )
	return "Selecciona Tipos Producto";

    if ( feature == "QCtrlExpendiosSE" )
	return "Selecciona Tipos Producto";

    if ( feature == "QCtrlProveedoresSE" )
	return "Selecciona Tipos Producto";

    if ( feature == "QCtrlClientesMayoreo" )
	return "Selecciona Tipos Producto";
    if ( feature == "QCtrlFormaPagoSat" )
	return "Selecciona Tipos Producto";
    if ( feature == "QCtrlUsoCFIDSat" )
	return "Selecciona Tipos Producto";

    if ( feature == "QCtrlEstadosPedidosClienteSE" )
	return "Selecciona Tipos Producto";

    return QString::null;
}

bool QCtrlPluginSiscomElectronica3::isContainer( const QString& ) const
{
    return FALSE;
}


Q_EXPORT_PLUGIN( QCtrlPluginSiscomElectronica3 )

