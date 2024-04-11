/****************************************************************************
** QCorteCajaSucursal meta object code from reading C++ file 'IMP_CorteCajaSucursal.h'
**
** Created: Wed Apr 10 20:52:40 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_CorteCajaSucursal.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCorteCajaSucursal::className() const
{
    return "QCorteCajaSucursal";
}

QMetaObject *QCorteCajaSucursal::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCorteCajaSucursal( "QCorteCajaSucursal", &QCorteCajaSucursal::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCorteCajaSucursal::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCorteCajaSucursal", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCorteCajaSucursal::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCorteCajaSucursal", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCorteCajaSucursal::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CorteCajaSucursal::staticMetaObject();
    static const QUMethod slot_0 = {"SlotCapturoCantidad", 0, 0 };
    static const QUMethod slot_1 = {"SlotActualizaCorteCaja", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotCapturoCantidad()", &slot_0, QMetaData::Private },
	{ "SlotActualizaCorteCaja()", &slot_1, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCorteCajaSucursal", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCorteCajaSucursal.setMetaObject( metaObj );
    return metaObj;
}

void* QCorteCajaSucursal::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCorteCajaSucursal" ) )
	return this;
    return CorteCajaSucursal::qt_cast( clname );
}

bool QCorteCajaSucursal::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotCapturoCantidad(); break;
    case 1: SlotActualizaCorteCaja(); break;
    default:
	return CorteCajaSucursal::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCorteCajaSucursal::qt_emit( int _id, QUObject* _o )
{
    return CorteCajaSucursal::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QCorteCajaSucursal::qt_property( int id, int f, QVariant* v)
{
    return CorteCajaSucursal::qt_property( id, f, v);
}

bool QCorteCajaSucursal::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
