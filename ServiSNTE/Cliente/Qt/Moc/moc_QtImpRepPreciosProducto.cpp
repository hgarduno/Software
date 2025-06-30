/****************************************************************************
** QtImpRepPreciosProducto meta object code from reading C++ file 'QtImpRepPreciosProducto.h'
**
** Created: Tue Jun 24 08:59:47 2025
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpRepPreciosProducto.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpRepPreciosProducto::className() const
{
    return "QtImpRepPreciosProducto";
}

QMetaObject *QtImpRepPreciosProducto::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpRepPreciosProducto( "QtImpRepPreciosProducto", &QtImpRepPreciosProducto::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpRepPreciosProducto::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpRepPreciosProducto", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpRepPreciosProducto::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpRepPreciosProducto", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpRepPreciosProducto::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = RepPreciosProducto::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "pzSisRegTienda", &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotTienda", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "pzSisRegDepartamento", &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotDepartamento", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ "pzSisRegProveedor", &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_2 = {"SlotProveedor", 1, param_slot_2 };
    static const QUMethod slot_3 = {"SlotConsulta", 0, 0 };
    static const QUMethod slot_4 = {"SlotImprime", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotTienda(zSiscomRegistro*)", &slot_0, QMetaData::Private },
	{ "SlotDepartamento(zSiscomRegistro*)", &slot_1, QMetaData::Private },
	{ "SlotProveedor(zSiscomRegistro*)", &slot_2, QMetaData::Private },
	{ "SlotConsulta()", &slot_3, QMetaData::Private },
	{ "SlotImprime()", &slot_4, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpRepPreciosProducto", parentObject,
	slot_tbl, 5,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpRepPreciosProducto.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpRepPreciosProducto::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpRepPreciosProducto" ) )
	return this;
    return RepPreciosProducto::qt_cast( clname );
}

bool QtImpRepPreciosProducto::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotTienda((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotDepartamento((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 2: SlotProveedor((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 3: SlotConsulta(); break;
    case 4: SlotImprime(); break;
    default:
	return RepPreciosProducto::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpRepPreciosProducto::qt_emit( int _id, QUObject* _o )
{
    return RepPreciosProducto::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpRepPreciosProducto::qt_property( int id, int f, QVariant* v)
{
    return RepPreciosProducto::qt_property( id, f, v);
}

bool QtImpRepPreciosProducto::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
