/****************************************************************************
** QtImpTransferenciaAlmacen meta object code from reading C++ file 'QtImpTransferenciaAlmacen.h'
**
** Created: Sat Jan 27 16:38:58 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpTransferenciaAlmacen.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpTransferenciaAlmacen::className() const
{
    return "QtImpTransferenciaAlmacen";
}

QMetaObject *QtImpTransferenciaAlmacen::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpTransferenciaAlmacen( "QtImpTransferenciaAlmacen", &QtImpTransferenciaAlmacen::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpTransferenciaAlmacen::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpTransferenciaAlmacen", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpTransferenciaAlmacen::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpTransferenciaAlmacen", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpTransferenciaAlmacen::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = TransferenciaAlmacen::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "pzSiscomTiendasEntrega", &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotTienda", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "pzSiscomVendedor", &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotAlmacenista", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ "pzSiscomChofer", &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_2 = {"SlotChofer", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ "pzSiscomCamion", &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_3 = {"SlotCamion", 1, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ "pzSiscomProductos", &static_QUType_ptr, "zSiscomRegistros", QUParameter::In }
    };
    static const QUMethod slot_4 = {"SlotMuestraProductos", 1, param_slot_4 };
    static const QUMethod slot_5 = {"SlotRegistraTransferencia", 0, 0 };
    static const QUMethod slot_6 = {"SlotImprimeTransferencia", 0, 0 };
    static const QUParameter param_slot_7[] = {
	{ "pintFila", &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_7 = {"SlotCapturaCantidad", 4, param_slot_7 };
    static const QUMethod slot_8 = {"SlotAStock", 0, 0 };
    static const QUParameter param_slot_9[] = {
	{ "pzSisRegProveedor", &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_9 = {"SlotSeleccionaProveedor", 1, param_slot_9 };
    static const QUMethod slot_10 = {"SlotTransfiereAPiso", 0, 0 };
    static const QUMethod slot_11 = {"SlotEsStock", 0, 0 };
    static const QUMethod slot_12 = {"SlotCopiar", 0, 0 };
    static const QUMethod slot_13 = {"SlotAgregarProducto", 0, 0 };
    static const QUMethod slot_14 = {"SlotEliminar", 0, 0 };
    static const QUParameter param_slot_15[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_15 = {"SlotCambiandoCodigoBarras", 1, param_slot_15 };
    static const QMetaData slot_tbl[] = {
	{ "SlotTienda(zSiscomRegistro*)", &slot_0, QMetaData::Private },
	{ "SlotAlmacenista(zSiscomRegistro*)", &slot_1, QMetaData::Private },
	{ "SlotChofer(zSiscomRegistro*)", &slot_2, QMetaData::Private },
	{ "SlotCamion(zSiscomRegistro*)", &slot_3, QMetaData::Private },
	{ "SlotMuestraProductos(zSiscomRegistros*)", &slot_4, QMetaData::Private },
	{ "SlotRegistraTransferencia()", &slot_5, QMetaData::Private },
	{ "SlotImprimeTransferencia()", &slot_6, QMetaData::Private },
	{ "SlotCapturaCantidad(int,int,int,const QPoint&)", &slot_7, QMetaData::Private },
	{ "SlotAStock()", &slot_8, QMetaData::Private },
	{ "SlotSeleccionaProveedor(zSiscomRegistro*)", &slot_9, QMetaData::Private },
	{ "SlotTransfiereAPiso()", &slot_10, QMetaData::Private },
	{ "SlotEsStock()", &slot_11, QMetaData::Private },
	{ "SlotCopiar()", &slot_12, QMetaData::Private },
	{ "SlotAgregarProducto()", &slot_13, QMetaData::Private },
	{ "SlotEliminar()", &slot_14, QMetaData::Private },
	{ "SlotCambiandoCodigoBarras(const QString&)", &slot_15, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpTransferenciaAlmacen", parentObject,
	slot_tbl, 16,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpTransferenciaAlmacen.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpTransferenciaAlmacen::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpTransferenciaAlmacen" ) )
	return this;
    return TransferenciaAlmacen::qt_cast( clname );
}

bool QtImpTransferenciaAlmacen::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotTienda((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotAlmacenista((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 2: SlotChofer((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 3: SlotCamion((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 4: SlotMuestraProductos((zSiscomRegistros*)static_QUType_ptr.get(_o+1)); break;
    case 5: SlotRegistraTransferencia(); break;
    case 6: SlotImprimeTransferencia(); break;
    case 7: SlotCapturaCantidad((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 8: SlotAStock(); break;
    case 9: SlotSeleccionaProveedor((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 10: SlotTransfiereAPiso(); break;
    case 11: SlotEsStock(); break;
    case 12: SlotCopiar(); break;
    case 13: SlotAgregarProducto(); break;
    case 14: SlotEliminar(); break;
    case 15: SlotCambiandoCodigoBarras((const QString&)static_QUType_QString.get(_o+1)); break;
    default:
	return TransferenciaAlmacen::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpTransferenciaAlmacen::qt_emit( int _id, QUObject* _o )
{
    return TransferenciaAlmacen::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpTransferenciaAlmacen::qt_property( int id, int f, QVariant* v)
{
    return TransferenciaAlmacen::qt_property( id, f, v);
}

bool QtImpTransferenciaAlmacen::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
