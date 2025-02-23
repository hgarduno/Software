/****************************************************************************
** QtImpPuntoDeVenta meta object code from reading C++ file 'QtImpPuntoDeVenta.h'
**
** Created: Sat Feb 22 23:13:24 2025
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpPuntoDeVenta.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpPuntoDeVenta::className() const
{
    return "QtImpPuntoDeVenta";
}

QMetaObject *QtImpPuntoDeVenta::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpPuntoDeVenta( "QtImpPuntoDeVenta", &QtImpPuntoDeVenta::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpPuntoDeVenta::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpPuntoDeVenta", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpPuntoDeVenta::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpPuntoDeVenta", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpPuntoDeVenta::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = PuntoDeVenta::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "pzSiscomTipoVenta", &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotTipoVenta", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "pzSiscomFinanciadora", &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotFinanciadora", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ "pzSiscomPlazo", &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_2 = {"SlotPlazo", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ "pzSiscomConcepto", &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_3 = {"SlotConcepto", 1, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ "pzSiscomTiendasEntrega", &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_4 = {"SlotTienda", 1, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ "pzSiscomVendedor", &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_5 = {"SlotVendedor", 1, param_slot_5 };
    static const QUMethod slot_6 = {"SlotFocoAFecha", 0, 0 };
    static const QUMethod slot_7 = {"SlotCapturaCliente", 0, 0 };
    static const QUMethod slot_8 = {"SlotCapturaDireccion", 0, 0 };
    static const QUMethod slot_9 = {"SlotFocoACapturaCliente", 0, 0 };
    static const QUParameter param_slot_10[] = {
	{ "pzSisFormaEntrega", &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_10 = {"SlotFormaEntrega", 1, param_slot_10 };
    static const QUMethod slot_11 = {"SlotCodigoBarras", 0, 0 };
    static const QUMethod slot_12 = {"SlotAgregarOrden", 0, 0 };
    static const QUMethod slot_13 = {"SlotRegistraVenta", 0, 0 };
    static const QUMethod slot_14 = {"SlotImprimeFactura", 0, 0 };
    static const QUMethod slot_15 = {"SlotCambiarPrecio", 0, 0 };
    static const QUParameter param_slot_16[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_16 = {"SlotSeleccionaProducto", 4, param_slot_16 };
    static const QUMethod slot_17 = {"SlotFocoACodigoBarras", 0, 0 };
    static const QUMethod slot_18 = {"SlotNuevaOrden", 0, 0 };
    static const QUMethod slot_19 = {"SlotEliminaProducto", 0, 0 };
    static const QUParameter param_slot_20[] = {
	{ 0, &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_20 = {"SlotSeleccionaProveedor", 1, param_slot_20 };
    static const QUMethod slot_21 = {"SlotFocoAFormaEntrega", 0, 0 };
    static const QUMethod slot_22 = {"SlotProductosProveedor", 0, 0 };
    static const QUMethod slot_23 = {"SlotCapturoNumeroProducto", 0, 0 };
    static const QUMethod slot_24 = {"SlotCancelarFolio", 0, 0 };
    static const QUParameter param_slot_25[] = {
	{ "pQStrTelefono", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_25 = {"SlotCapturandoTelefono", 1, param_slot_25 };
    static const QMetaData slot_tbl[] = {
	{ "SlotTipoVenta(zSiscomRegistro*)", &slot_0, QMetaData::Private },
	{ "SlotFinanciadora(zSiscomRegistro*)", &slot_1, QMetaData::Private },
	{ "SlotPlazo(zSiscomRegistro*)", &slot_2, QMetaData::Private },
	{ "SlotConcepto(zSiscomRegistro*)", &slot_3, QMetaData::Private },
	{ "SlotTienda(zSiscomRegistro*)", &slot_4, QMetaData::Private },
	{ "SlotVendedor(zSiscomRegistro*)", &slot_5, QMetaData::Private },
	{ "SlotFocoAFecha()", &slot_6, QMetaData::Private },
	{ "SlotCapturaCliente()", &slot_7, QMetaData::Private },
	{ "SlotCapturaDireccion()", &slot_8, QMetaData::Private },
	{ "SlotFocoACapturaCliente()", &slot_9, QMetaData::Private },
	{ "SlotFormaEntrega(zSiscomRegistro*)", &slot_10, QMetaData::Private },
	{ "SlotCodigoBarras()", &slot_11, QMetaData::Private },
	{ "SlotAgregarOrden()", &slot_12, QMetaData::Private },
	{ "SlotRegistraVenta()", &slot_13, QMetaData::Private },
	{ "SlotImprimeFactura()", &slot_14, QMetaData::Private },
	{ "SlotCambiarPrecio()", &slot_15, QMetaData::Private },
	{ "SlotSeleccionaProducto(int,int,int,const QPoint&)", &slot_16, QMetaData::Private },
	{ "SlotFocoACodigoBarras()", &slot_17, QMetaData::Private },
	{ "SlotNuevaOrden()", &slot_18, QMetaData::Private },
	{ "SlotEliminaProducto()", &slot_19, QMetaData::Private },
	{ "SlotSeleccionaProveedor(zSiscomRegistro*)", &slot_20, QMetaData::Private },
	{ "SlotFocoAFormaEntrega()", &slot_21, QMetaData::Private },
	{ "SlotProductosProveedor()", &slot_22, QMetaData::Private },
	{ "SlotCapturoNumeroProducto()", &slot_23, QMetaData::Private },
	{ "SlotCancelarFolio()", &slot_24, QMetaData::Private },
	{ "SlotCapturandoTelefono(const QString&)", &slot_25, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpPuntoDeVenta", parentObject,
	slot_tbl, 26,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpPuntoDeVenta.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpPuntoDeVenta::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpPuntoDeVenta" ) )
	return this;
    return PuntoDeVenta::qt_cast( clname );
}

bool QtImpPuntoDeVenta::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotTipoVenta((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotFinanciadora((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 2: SlotPlazo((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 3: SlotConcepto((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 4: SlotTienda((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 5: SlotVendedor((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 6: SlotFocoAFecha(); break;
    case 7: SlotCapturaCliente(); break;
    case 8: SlotCapturaDireccion(); break;
    case 9: SlotFocoACapturaCliente(); break;
    case 10: SlotFormaEntrega((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 11: SlotCodigoBarras(); break;
    case 12: SlotAgregarOrden(); break;
    case 13: SlotRegistraVenta(); break;
    case 14: SlotImprimeFactura(); break;
    case 15: SlotCambiarPrecio(); break;
    case 16: SlotSeleccionaProducto((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 17: SlotFocoACodigoBarras(); break;
    case 18: SlotNuevaOrden(); break;
    case 19: SlotEliminaProducto(); break;
    case 20: SlotSeleccionaProveedor((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 21: SlotFocoAFormaEntrega(); break;
    case 22: SlotProductosProveedor(); break;
    case 23: SlotCapturoNumeroProducto(); break;
    case 24: SlotCancelarFolio(); break;
    case 25: SlotCapturandoTelefono((const QString&)static_QUType_QString.get(_o+1)); break;
    default:
	return PuntoDeVenta::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpPuntoDeVenta::qt_emit( int _id, QUObject* _o )
{
    return PuntoDeVenta::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpPuntoDeVenta::qt_property( int id, int f, QVariant* v)
{
    return PuntoDeVenta::qt_property( id, f, v);
}

bool QtImpPuntoDeVenta::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
