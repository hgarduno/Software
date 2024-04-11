/****************************************************************************
** QtImpCapturaDescuentos meta object code from reading C++ file 'QtImpCapturaDescuentos.h'
**
** Created: Sat Jan 27 16:40:10 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpCapturaDescuentos.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpCapturaDescuentos::className() const
{
    return "QtImpCapturaDescuentos";
}

QMetaObject *QtImpCapturaDescuentos::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpCapturaDescuentos( "QtImpCapturaDescuentos", &QtImpCapturaDescuentos::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpCapturaDescuentos::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpCapturaDescuentos", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpCapturaDescuentos::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpCapturaDescuentos", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpCapturaDescuentos::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CapturaDescuentos::staticMetaObject();
    static const QUMethod slot_0 = {"SlotFocoADescuento2", 0, 0 };
    static const QUMethod slot_1 = {"SlotFocoADescuento3", 0, 0 };
    static const QUMethod slot_2 = {"SlotFocoADescuento4", 0, 0 };
    static const QUMethod slot_3 = {"SlotFocoAAceptar", 0, 0 };
    static const QUMethod slot_4 = {"SlotAceptar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotFocoADescuento2()", &slot_0, QMetaData::Private },
	{ "SlotFocoADescuento3()", &slot_1, QMetaData::Private },
	{ "SlotFocoADescuento4()", &slot_2, QMetaData::Private },
	{ "SlotFocoAAceptar()", &slot_3, QMetaData::Private },
	{ "SlotAceptar()", &slot_4, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpCapturaDescuentos", parentObject,
	slot_tbl, 5,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpCapturaDescuentos.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpCapturaDescuentos::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpCapturaDescuentos" ) )
	return this;
    return CapturaDescuentos::qt_cast( clname );
}

bool QtImpCapturaDescuentos::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotFocoADescuento2(); break;
    case 1: SlotFocoADescuento3(); break;
    case 2: SlotFocoADescuento4(); break;
    case 3: SlotFocoAAceptar(); break;
    case 4: SlotAceptar(); break;
    default:
	return CapturaDescuentos::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpCapturaDescuentos::qt_emit( int _id, QUObject* _o )
{
    return CapturaDescuentos::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpCapturaDescuentos::qt_property( int id, int f, QVariant* v)
{
    return CapturaDescuentos::qt_property( id, f, v);
}

bool QtImpCapturaDescuentos::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
