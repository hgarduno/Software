/****************************************************************************
** QtImpFijaFechaCompra meta object code from reading C++ file 'QtImpFijaFechaCompra.h'
**
** Created: Tue Jun 24 08:59:37 2025
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpFijaFechaCompra.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpFijaFechaCompra::className() const
{
    return "QtImpFijaFechaCompra";
}

QMetaObject *QtImpFijaFechaCompra::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpFijaFechaCompra( "QtImpFijaFechaCompra", &QtImpFijaFechaCompra::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpFijaFechaCompra::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpFijaFechaCompra", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpFijaFechaCompra::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpFijaFechaCompra", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpFijaFechaCompra::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = FijaFechaCompra::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotProveedor", 1, param_slot_0 };
    static const QUMethod slot_1 = {"SlotRegistraFecha", 0, 0 };
    static const QUMethod slot_2 = {"SlotFocoARegistraFecha", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotProveedor(zSiscomRegistro*)", &slot_0, QMetaData::Private },
	{ "SlotRegistraFecha()", &slot_1, QMetaData::Private },
	{ "SlotFocoARegistraFecha()", &slot_2, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpFijaFechaCompra", parentObject,
	slot_tbl, 3,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpFijaFechaCompra.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpFijaFechaCompra::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpFijaFechaCompra" ) )
	return this;
    return FijaFechaCompra::qt_cast( clname );
}

bool QtImpFijaFechaCompra::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotProveedor((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotRegistraFecha(); break;
    case 2: SlotFocoARegistraFecha(); break;
    default:
	return FijaFechaCompra::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpFijaFechaCompra::qt_emit( int _id, QUObject* _o )
{
    return FijaFechaCompra::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpFijaFechaCompra::qt_property( int id, int f, QVariant* v)
{
    return FijaFechaCompra::qt_property( id, f, v);
}

bool QtImpFijaFechaCompra::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
