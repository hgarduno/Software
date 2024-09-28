/****************************************************************************
** QtImpCapturaInventarioAlmacen meta object code from reading C++ file 'QtImpCapturaInventarioAlmacen.h'
**
** Created: Thu Aug 15 00:49:54 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpCapturaInventarioAlmacen.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpCapturaInventarioAlmacen::className() const
{
    return "QtImpCapturaInventarioAlmacen";
}

QMetaObject *QtImpCapturaInventarioAlmacen::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpCapturaInventarioAlmacen( "QtImpCapturaInventarioAlmacen", &QtImpCapturaInventarioAlmacen::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpCapturaInventarioAlmacen::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpCapturaInventarioAlmacen", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpCapturaInventarioAlmacen::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpCapturaInventarioAlmacen", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpCapturaInventarioAlmacen::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CapturaInventarioAlmacen::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "pzSisProveedor", &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotProveedor", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "pzSisProducto", &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotProducto", 1, param_slot_1 };
    static const QUMethod slot_2 = {"SlotFocoAAnexar", 0, 0 };
    static const QUMethod slot_3 = {"SlotAnexar", 0, 0 };
    static const QUMethod slot_4 = {"SlotProgramarInventario", 0, 0 };
    static const QUMethod slot_5 = {"SlotProductoPorCodigoBarras", 0, 0 };
    static const QUMethod slot_6 = {"SlotRegistraInventario", 0, 0 };
    static const QUParameter param_slot_7[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_7 = {"SlotCapturaCantidad", 4, param_slot_7 };
    static const QMetaData slot_tbl[] = {
	{ "SlotProveedor(zSiscomRegistro*)", &slot_0, QMetaData::Private },
	{ "SlotProducto(zSiscomRegistro*)", &slot_1, QMetaData::Private },
	{ "SlotFocoAAnexar()", &slot_2, QMetaData::Private },
	{ "SlotAnexar()", &slot_3, QMetaData::Private },
	{ "SlotProgramarInventario()", &slot_4, QMetaData::Private },
	{ "SlotProductoPorCodigoBarras()", &slot_5, QMetaData::Private },
	{ "SlotRegistraInventario()", &slot_6, QMetaData::Private },
	{ "SlotCapturaCantidad(int,int,int,const QPoint&)", &slot_7, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpCapturaInventarioAlmacen", parentObject,
	slot_tbl, 8,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpCapturaInventarioAlmacen.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpCapturaInventarioAlmacen::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpCapturaInventarioAlmacen" ) )
	return this;
    return CapturaInventarioAlmacen::qt_cast( clname );
}

bool QtImpCapturaInventarioAlmacen::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotProveedor((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotProducto((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 2: SlotFocoAAnexar(); break;
    case 3: SlotAnexar(); break;
    case 4: SlotProgramarInventario(); break;
    case 5: SlotProductoPorCodigoBarras(); break;
    case 6: SlotRegistraInventario(); break;
    case 7: SlotCapturaCantidad((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    default:
	return CapturaInventarioAlmacen::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpCapturaInventarioAlmacen::qt_emit( int _id, QUObject* _o )
{
    return CapturaInventarioAlmacen::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpCapturaInventarioAlmacen::qt_property( int id, int f, QVariant* v)
{
    return CapturaInventarioAlmacen::qt_property( id, f, v);
}

bool QtImpCapturaInventarioAlmacen::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
