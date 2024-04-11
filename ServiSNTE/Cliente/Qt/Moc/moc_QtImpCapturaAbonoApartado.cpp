/****************************************************************************
** QtImpCapturaAbonoApartado meta object code from reading C++ file 'QtImpCapturaAbonoApartado.h'
**
** Created: Sat Jan 27 16:39:21 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpCapturaAbonoApartado.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpCapturaAbonoApartado::className() const
{
    return "QtImpCapturaAbonoApartado";
}

QMetaObject *QtImpCapturaAbonoApartado::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpCapturaAbonoApartado( "QtImpCapturaAbonoApartado", &QtImpCapturaAbonoApartado::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpCapturaAbonoApartado::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpCapturaAbonoApartado", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpCapturaAbonoApartado::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpCapturaAbonoApartado", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpCapturaAbonoApartado::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CapturaAbonoApartado::staticMetaObject();
    static const QUMethod slot_0 = {"reject", 0, 0 };
    static const QUMethod slot_1 = {"SlotAceptar", 0, 0 };
    static const QUMethod slot_2 = {"SlotCancelar", 0, 0 };
    static const QUMethod slot_3 = {"SlotCantidad", 0, 0 };
    static const QUMethod slot_4 = {"SlotFocoACantidad", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "reject()", &slot_0, QMetaData::Private },
	{ "SlotAceptar()", &slot_1, QMetaData::Private },
	{ "SlotCancelar()", &slot_2, QMetaData::Private },
	{ "SlotCantidad()", &slot_3, QMetaData::Private },
	{ "SlotFocoACantidad()", &slot_4, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpCapturaAbonoApartado", parentObject,
	slot_tbl, 5,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpCapturaAbonoApartado.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpCapturaAbonoApartado::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpCapturaAbonoApartado" ) )
	return this;
    return CapturaAbonoApartado::qt_cast( clname );
}

bool QtImpCapturaAbonoApartado::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: reject(); break;
    case 1: SlotAceptar(); break;
    case 2: SlotCancelar(); break;
    case 3: SlotCantidad(); break;
    case 4: SlotFocoACantidad(); break;
    default:
	return CapturaAbonoApartado::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpCapturaAbonoApartado::qt_emit( int _id, QUObject* _o )
{
    return CapturaAbonoApartado::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpCapturaAbonoApartado::qt_property( int id, int f, QVariant* v)
{
    return CapturaAbonoApartado::qt_property( id, f, v);
}

bool QtImpCapturaAbonoApartado::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
