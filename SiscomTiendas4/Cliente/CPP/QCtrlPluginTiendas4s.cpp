#include <QCtrlPluginTiendas4s.h>
#include <QCtrlProductos.h>
#include <QCtrlPrecios.h>
#include <QCtrlFamilias.h>
#include <QCtrlMedComunicacion.h>
#include <QCtrlEmpresas.h>
#include <QCtrlContactos.h>
#include <QCtrlFormaPago.h>
#include <QCtrlClientes.h>
#include <QCtrlOrdenes.h>
#include <QCtrlCotizas.h>
#include <QCtrlProductos3Qt.h>
#include <QCtrlClientes3Qt.h>
#include <QCtrlContactos3Qt.h>
#include <QCtrlFormaPago3Qt.h>
#include <QCtrlPrecios3Qt.h>
#include <QCtrlPreciosProductos.h>

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

QCtrlPluginTiendas4s::QCtrlPluginTiendas4s()
{
}

QStringList QCtrlPluginTiendas4s::keys() const
{
    QStringList list;
    list 			<< 
    "QCtrlProductos"		<<
    "QCtrlPrecios"		<<
    "QCtrlFamilias"		<<
    "QCtrlMedComunicacion"	<<
    "QCtrlEmpresas"		<<
    "QCtrlContactos"		<<
    "QCtrlFormaPago"		<<
    "QCtrlClientes"		<<
    "QCtrlOrdenes"		<<
    "QCtrlCotizas"		<<
    "QCtrlProductos3Qt"		<<
    "QCtrlClientes3Qt"		<<
    "QCtrlContactos3Qt"		<<
    "QCtrlFormaPago3Qt"		<<
    "QCtrlPrecios3Qt"		<<
    "QCtrlPreciosProductos";
    return list;
}

QWidget* QCtrlPluginTiendas4s::create( const QString &key, QWidget* parent, const char* name )
{
    if ( key == "QCtrlProductos" )
	return new QCtrlProductos( parent, name );
    if ( key == "QCtrlPrecios" )
	return new QCtrlPrecios( parent, name );
    if ( key == "QCtrlFamilias" )
	return new QCtrlFamilias( parent, name );
    if ( key == "QCtrlMedComunicacion" )
	return new QCtrlMedComunicacion( parent, name );
    if ( key == "QCtrlEmpresas" )
	return new QCtrlEmpresas( parent, name );
    if ( key == "QCtrlContactos" )
	return new QCtrlContactos( parent, name );
    if ( key == "QCtrlFormaPago" )
	return new QCtrlFormaPago( parent, name );
    if ( key == "QCtrlClientes" )
	return new QCtrlClientes( parent, name );
    if ( key == "QCtrlOrdenes" )
	return new QCtrlOrdenes( parent, name );
    if ( key == "QCtrlCotizas" )
	return new QCtrlCotizas( parent, name );
    if ( key == "QCtrlProductos3Qt" )
	return new QCtrlProductos3Qt( parent, name );
    if ( key == "QCtrlClientes3Qt" )
	return new QCtrlClientes3Qt( parent, name );
    if ( key == "QCtrlContactos3Qt" )
	return new QCtrlContactos3Qt( parent, name );
    if ( key == "QCtrlFormaPago3Qt" )
	return new QCtrlFormaPago3Qt( parent, name );
    if ( key == "QCtrlPrecios3Qt" )
	return new QCtrlPrecios3Qt( parent, name );
    if ( key == "QCtrlPreciosProductos" )
	return new QCtrlPreciosProductos( parent, name );
    return 0;
}

QString QCtrlPluginTiendas4s::group( const QString& feature ) const
{
    if ( feature == "QCtrlProductos" )
	return "Siscom Tiendas4B";
    if ( feature == "QCtrlPrecios" )
	return "Siscom Tiendas4B";
    if ( feature == "QCtrlFamilias" )
	return "Siscom Tiendas4B";
    if ( feature == "QCtrlMedComunicacion" )
	return "Siscom Tiendas4B";
    if ( feature == "QCtrlEmpresas" )
	return "Siscom Tiendas4B";
    if ( feature == "QCtrlContactos" )
	return "Siscom Tiendas4B";
    if ( feature == "QCtrlFormaPago" )
	return "Siscom Tiendas4B";
    if ( feature == "QCtrlClientes" )
	return "Siscom Tiendas4B";
    if ( feature == "QCtrlOrdenes" )
	return "Siscom Tiendas4B";
    if ( feature == "QCtrlCotizas" )
	return "Siscom Tiendas4B";
    if ( feature == "QCtrlProductos3Qt" )
	return "Siscom Tiendas4B";
    if ( feature == "QCtrlClientes3Qt" )
	return "Siscom Tiendas4B";
    if ( feature == "QCtrlContactos3Qt" )
	return "Siscom Tiendas4B";
    if ( feature == "QCtrlFormaPago3Qt" )
	return "Siscom Tiendas4B";
    if ( feature == "QCtrlPrecios3Qt" )
	return "Siscom Tiendas4B";
    if ( feature == "QCtrlPreciosProductos" )
	return "Siscom Tiendas4B";
    return QString::null;
}

QIconSet QCtrlPluginTiendas4s::iconSet( const QString& ) const
{
    return QIconSet( QPixmap( filechooser_pixmap ) );
}

QString QCtrlPluginTiendas4s::includeFile( const QString& feature ) const
{
    if ( feature == "QCtrlProductos" )
	return "QCtrlProductos.h";

    if ( feature == "QCtrlPrecios" )
	return "QCtrlPrecios.h";

    if ( feature == "QCtrlFamilias" )
	return "QCtrlFamilias.h";
    if ( feature == "QCtrlMedComunicacion" )
	return "QCtrlMedComunicacion.h";
    if ( feature == "QCtrlMedComunicacion" )
	return "QCtrlEmpresas.h";
    if ( feature == "QCtrlEmpresas" )
	return "QCtrlContactos.h";
    if ( feature == "QCtrlContactos" )
	return "QCtrlFormaPago.h";
    if ( feature == "QCtrlFormaPago" )
	return "QCtrlClientes.h";
    if ( feature == "QCtrlClientes" )
	return "QCtrlClientes.h";
    if ( feature == "QCtrlOrdenes" )
	return "QCtrlOrdenes.h";
    if ( feature == "QCtrlCotizas" )
	return "QCtrlCotizas.h";
    if ( feature == "QCtrlProductos3Qt" )
	return "QCtrlProductos3Qt.h";
    if ( feature == "QCtrlClientes3Qt" )
	return "QCtrlClientes3Qt.h";
    if ( feature == "QCtrlContactos3Qt" )
	return "QCtrlContactos3Qt.h";
    if ( feature == "QCtrlFormaPago3Qt" )
	return "QCtrlFormaPago3Qt.h";
    if ( feature == "QCtrlPrecios3Qt" )
	return "QCtrlPrecios3Qt.h";
    if ( feature == "QCtrlPreciosProductos" )
	return "QCtrlPreciosProductos.h";
    return QString::null;
}

QString QCtrlPluginTiendas4s::toolTip( const QString& feature ) const
{
    if ( feature == "QCtrlProductos" )
	return "File Chooser Widget";

    if ( feature == "QCtrlPrecios" )
	return "File Chooser Widget";
    if ( feature == "QCtrlFamilias" )
	return "File Chooser Widget";
    if ( feature == "QCtrlMedComunicacion" )
	return "File Chooser Widget";
    if ( feature == "QCtrlEmpresas" )
	return "File Chooser Widget";
    if ( feature == "QCtrlContactos" )
	return "File Chooser Widget";
    if ( feature == "QCtrlFormaPago" )
	return "File Chooser Widget";
    if ( feature == "QCtrlClientes" )
	return "File Chooser Widget";
    if ( feature == "QCtrlOrdenes" )
	return "File Chooser Widget";
    if ( feature == "QCtrlCotizas" )
	return "File Chooser Widget";
    if ( feature == "QCtrlProductos3Qt" )
	return "Control para seleccionar productos 3Qt++";
    if ( feature == "QCtrlClientes3Qt" )
	return "Control para seleccionar Clientes 3Qt++";
    if ( feature == "QCtrlContactos3Qt" )
	return "Control para seleccionar Contactos 3Qt++";
    if ( feature == "QCtrlFormaPago3Qt" )
	return "Control para seleccionar la forma de pago 3Qt++";
    if ( feature == "QCtrlPrecios3Qt" )
	return "Control para seleccionar los precios 3Qt++";
    if ( feature == "QCtrlPreciosProductos" )
	return "Control para seleccionar los precios de un producto";
    return QString::null;
}

QString QCtrlPluginTiendas4s::whatsThis( const QString& feature ) const
{
    if ( feature == "QCtrlProductos" )
	return "A widget to choose a file or directory";

    if ( feature == "QCtrlPrecios" )
	return "A widget to choose a file or directory";
    if ( feature == "QCtrlFamilias" )
	return "A widget to choose a file or directory";
    if ( feature == "QCtrlMedComunicacion" )
	return "A widget to choose a file or directory";
    if ( feature == "QCtrlEmpresas" )
	return "A widget to choose a file or directory";
    if ( feature == "QCtrlContactos" )
	return "A widget to choose a file or directory";
    if ( feature == "QCtrlFormaPago" )
	return "A widget to choose a file or directory";
    if ( feature == "QCtrlClientes" )
	return "A widget to choose a file or directory";
    if ( feature == "QCtrlOrdenes" )
	return "A widget to choose a file or directory";
    if ( feature == "QCtrlCotizas" )
	return "A widget to choose a file or directory";
    if ( feature == "QCtrlProductos3Qt" )
	return "Control para seleccionar productos ";
    if ( feature == "QCtrlClientes3Qt" )
	return "Control para seleccionar Clientes";
    if ( feature == "QCtrlContactos3Qt" )
	return "Control para seleccionar Contactos";
    if ( feature == "QCtrlFormaPago3Qt" )
	return "Control para seleccionar la forma de pago";
    if ( feature == "QCtrlPrecios3Qt" )
	return "Control para seleccionar los precios";
    if ( feature == "QCtrlPreciosProductos" )
	return "Control para seleccionar los precios de un producto";
    return QString::null;
}

bool QCtrlPluginTiendas4s::isContainer( const QString& ) const
{
    return FALSE;
}


Q_EXPORT_PLUGIN( QCtrlPluginTiendas4s )

