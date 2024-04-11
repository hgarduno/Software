/****************************************************************************
** QtImpExistenciasTienda meta object code from reading C++ file 'QtImpExistenciasTienda.h'
**
** Created: Thu Apr 11 21:08:25 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpExistenciasTienda.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpExistenciasTienda::className() const
{
    return "QtImpExistenciasTienda";
}

QMetaObject *QtImpExistenciasTienda::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpExistenciasTienda( "QtImpExistenciasTienda", &QtImpExistenciasTienda::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpExistenciasTienda::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpExistenciasTienda", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpExistenciasTienda::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpExistenciasTienda", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpExistenciasTienda::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ExistenciasTienda::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "pzSisRegProveedor", &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotSeleccionoProveedor", 1, param_slot_0 };
    static const QUMethod slot_1 = {"SlotExistenciasProveedor", 0, 0 };
    static const QUMethod slot_2 = {"SlotExistenciasProducto", 0, 0 };
    static const QUParameter param_slot_3[] = {
	{ "pzSisRegTienda", &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_3 = {"SlotTienda", 1, param_slot_3 };
    static const QUMethod slot_4 = {"SlotExistenciasListaProductos", 0, 0 };
    static const QUMethod slot_5 = {"SlotCopiar", 0, 0 };
    static const QUMethod slot_6 = {"SlotTodosLosProductos", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotSeleccionoProveedor(zSiscomRegistro*)", &slot_0, QMetaData::Private },
	{ "SlotExistenciasProveedor()", &slot_1, QMetaData::Private },
	{ "SlotExistenciasProducto()", &slot_2, QMetaData::Private },
	{ "SlotTienda(zSiscomRegistro*)", &slot_3, QMetaData::Private },
	{ "SlotExistenciasListaProductos()", &slot_4, QMetaData::Private },
	{ "SlotCopiar()", &slot_5, QMetaData::Private },
	{ "SlotTodosLosProductos()", &slot_6, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpExistenciasTienda", parentObject,
	slot_tbl, 7,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpExistenciasTienda.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpExistenciasTienda::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpExistenciasTienda" ) )
	return this;
    return ExistenciasTienda::qt_cast( clname );
}

bool QtImpExistenciasTienda::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotSeleccionoProveedor((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotExistenciasProveedor(); break;
    case 2: SlotExistenciasProducto(); break;
    case 3: SlotTienda((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 4: SlotExistenciasListaProductos(); break;
    case 5: SlotCopiar(); break;
    case 6: SlotTodosLosProductos(); break;
    default:
	return ExistenciasTienda::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpExistenciasTienda::qt_emit( int _id, QUObject* _o )
{
    return ExistenciasTienda::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpExistenciasTienda::qt_property( int id, int f, QVariant* v)
{
    return ExistenciasTienda::qt_property( id, f, v);
}

bool QtImpExistenciasTienda::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
