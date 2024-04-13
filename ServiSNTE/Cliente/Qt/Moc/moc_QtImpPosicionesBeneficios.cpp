/****************************************************************************
** QtImpPosicionesBeneficios meta object code from reading C++ file 'QtImpPosicionesBeneficios.h'
**
** Created: Mon Apr 1 17:30:16 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpPosicionesBeneficios.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpPosicionesBeneficios::className() const
{
    return "QtImpPosicionesBeneficios";
}

QMetaObject *QtImpPosicionesBeneficios::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpPosicionesBeneficios( "QtImpPosicionesBeneficios", &QtImpPosicionesBeneficios::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpPosicionesBeneficios::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpPosicionesBeneficios", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpPosicionesBeneficios::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpPosicionesBeneficios", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpPosicionesBeneficios::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = PosicionesBeneficios::staticMetaObject();
    static const QUMethod slot_0 = {"SlotIncrementaX", 0, 0 };
    static const QUMethod slot_1 = {"SlotIncrementaY", 0, 0 };
    static const QUMethod slot_2 = {"SlotAceptar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotIncrementaX()", &slot_0, QMetaData::Private },
	{ "SlotIncrementaY()", &slot_1, QMetaData::Private },
	{ "SlotAceptar()", &slot_2, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpPosicionesBeneficios", parentObject,
	slot_tbl, 3,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpPosicionesBeneficios.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpPosicionesBeneficios::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpPosicionesBeneficios" ) )
	return this;
    return PosicionesBeneficios::qt_cast( clname );
}

bool QtImpPosicionesBeneficios::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotIncrementaX(); break;
    case 1: SlotIncrementaY(); break;
    case 2: SlotAceptar(); break;
    default:
	return PosicionesBeneficios::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpPosicionesBeneficios::qt_emit( int _id, QUObject* _o )
{
    return PosicionesBeneficios::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpPosicionesBeneficios::qt_property( int id, int f, QVariant* v)
{
    return PosicionesBeneficios::qt_property( id, f, v);
}

bool QtImpPosicionesBeneficios::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
