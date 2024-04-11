/****************************************************************************
** QtImpCambioPrecio meta object code from reading C++ file 'QtImpCambioPrecio.h'
**
** Created: Sat Jan 27 16:39:01 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpCambioPrecio.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpCambioPrecio::className() const
{
    return "QtImpCambioPrecio";
}

QMetaObject *QtImpCambioPrecio::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpCambioPrecio( "QtImpCambioPrecio", &QtImpCambioPrecio::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpCambioPrecio::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpCambioPrecio", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpCambioPrecio::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpCambioPrecio", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpCambioPrecio::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CambioPrecio::staticMetaObject();
    static const QUMethod slot_0 = {"reject", 0, 0 };
    static const QUMethod slot_1 = {"SlotAceptar", 0, 0 };
    static const QUMethod slot_2 = {"SlotCancelar", 0, 0 };
    static const QUMethod slot_3 = {"SlotAMotivoCambio", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "reject()", &slot_0, QMetaData::Private },
	{ "SlotAceptar()", &slot_1, QMetaData::Private },
	{ "SlotCancelar()", &slot_2, QMetaData::Private },
	{ "SlotAMotivoCambio()", &slot_3, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpCambioPrecio", parentObject,
	slot_tbl, 4,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpCambioPrecio.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpCambioPrecio::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpCambioPrecio" ) )
	return this;
    return CambioPrecio::qt_cast( clname );
}

bool QtImpCambioPrecio::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: reject(); break;
    case 1: SlotAceptar(); break;
    case 2: SlotCancelar(); break;
    case 3: SlotAMotivoCambio(); break;
    default:
	return CambioPrecio::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpCambioPrecio::qt_emit( int _id, QUObject* _o )
{
    return CambioPrecio::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpCambioPrecio::qt_property( int id, int f, QVariant* v)
{
    return CambioPrecio::qt_property( id, f, v);
}

bool QtImpCambioPrecio::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
