/****************************************************************************
** QtImpExistenciasAlmacen meta object code from reading C++ file 'QtImpExistenciasAlmacen.h'
**
** Created: Tue Jun 24 08:59:40 2025
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpExistenciasAlmacen.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpExistenciasAlmacen::className() const
{
    return "QtImpExistenciasAlmacen";
}

QMetaObject *QtImpExistenciasAlmacen::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpExistenciasAlmacen( "QtImpExistenciasAlmacen", &QtImpExistenciasAlmacen::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpExistenciasAlmacen::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpExistenciasAlmacen", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpExistenciasAlmacen::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpExistenciasAlmacen", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpExistenciasAlmacen::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ExistenciasAlmacen::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "pzSisRegProveedor", &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotSeleccionoProveedor", 1, param_slot_0 };
    static const QUMethod slot_1 = {"SlotExistenciasProveedor", 0, 0 };
    static const QUMethod slot_2 = {"SlotExistenciasProducto", 0, 0 };
    static const QUMethod slot_3 = {"SlotExistenciasListaProductos", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotSeleccionoProveedor(zSiscomRegistro*)", &slot_0, QMetaData::Private },
	{ "SlotExistenciasProveedor()", &slot_1, QMetaData::Private },
	{ "SlotExistenciasProducto()", &slot_2, QMetaData::Private },
	{ "SlotExistenciasListaProductos()", &slot_3, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpExistenciasAlmacen", parentObject,
	slot_tbl, 4,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpExistenciasAlmacen.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpExistenciasAlmacen::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpExistenciasAlmacen" ) )
	return this;
    return ExistenciasAlmacen::qt_cast( clname );
}

bool QtImpExistenciasAlmacen::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotSeleccionoProveedor((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotExistenciasProveedor(); break;
    case 2: SlotExistenciasProducto(); break;
    case 3: SlotExistenciasListaProductos(); break;
    default:
	return ExistenciasAlmacen::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpExistenciasAlmacen::qt_emit( int _id, QUObject* _o )
{
    return ExistenciasAlmacen::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpExistenciasAlmacen::qt_property( int id, int f, QVariant* v)
{
    return ExistenciasAlmacen::qt_property( id, f, v);
}

bool QtImpExistenciasAlmacen::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
