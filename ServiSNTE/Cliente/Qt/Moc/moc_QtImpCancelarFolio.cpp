/****************************************************************************
** QtImpCancelarFolio meta object code from reading C++ file 'QtImpCancelarFolio.h'
**
** Created: Sat Feb 22 23:13:40 2025
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpCancelarFolio.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpCancelarFolio::className() const
{
    return "QtImpCancelarFolio";
}

QMetaObject *QtImpCancelarFolio::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpCancelarFolio( "QtImpCancelarFolio", &QtImpCancelarFolio::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpCancelarFolio::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpCancelarFolio", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpCancelarFolio::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpCancelarFolio", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpCancelarFolio::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CancelarFolio::staticMetaObject();
    static const QUMethod slot_0 = {"reject", 0, 0 };
    static const QUMethod slot_1 = {"SlotAceptar", 0, 0 };
    static const QUMethod slot_2 = {"SlotCancelar", 0, 0 };
    static const QUMethod slot_3 = {"SlotRegistrarCancelacion", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "reject()", &slot_0, QMetaData::Private },
	{ "SlotAceptar()", &slot_1, QMetaData::Private },
	{ "SlotCancelar()", &slot_2, QMetaData::Private },
	{ "SlotRegistrarCancelacion()", &slot_3, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpCancelarFolio", parentObject,
	slot_tbl, 4,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpCancelarFolio.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpCancelarFolio::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpCancelarFolio" ) )
	return this;
    return CancelarFolio::qt_cast( clname );
}

bool QtImpCancelarFolio::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: reject(); break;
    case 1: SlotAceptar(); break;
    case 2: SlotCancelar(); break;
    case 3: SlotRegistrarCancelacion(); break;
    default:
	return CancelarFolio::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpCancelarFolio::qt_emit( int _id, QUObject* _o )
{
    return CancelarFolio::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpCancelarFolio::qt_property( int id, int f, QVariant* v)
{
    return CancelarFolio::qt_property( id, f, v);
}

bool QtImpCancelarFolio::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
