/****************************************************************************
** QtImpVolteaContrato meta object code from reading C++ file 'QtImpVolteaContrato.h'
**
** Created: Sat Jan 27 16:39:19 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpVolteaContrato.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpVolteaContrato::className() const
{
    return "QtImpVolteaContrato";
}

QMetaObject *QtImpVolteaContrato::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpVolteaContrato( "QtImpVolteaContrato", &QtImpVolteaContrato::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpVolteaContrato::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpVolteaContrato", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpVolteaContrato::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpVolteaContrato", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpVolteaContrato::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = VolteaContrato::staticMetaObject();
    static const QUMethod slot_0 = {"SlotSeVolteoElContrato", 0, 0 };
    static const QUMethod slot_1 = {"SlotImprimir", 0, 0 };
    static const QUMethod slot_2 = {"SlotTerminar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotSeVolteoElContrato()", &slot_0, QMetaData::Private },
	{ "SlotImprimir()", &slot_1, QMetaData::Private },
	{ "SlotTerminar()", &slot_2, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpVolteaContrato", parentObject,
	slot_tbl, 3,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpVolteaContrato.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpVolteaContrato::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpVolteaContrato" ) )
	return this;
    return VolteaContrato::qt_cast( clname );
}

bool QtImpVolteaContrato::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotSeVolteoElContrato(); break;
    case 1: SlotImprimir(); break;
    case 2: SlotTerminar(); break;
    default:
	return VolteaContrato::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpVolteaContrato::qt_emit( int _id, QUObject* _o )
{
    return VolteaContrato::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpVolteaContrato::qt_property( int id, int f, QVariant* v)
{
    return VolteaContrato::qt_property( id, f, v);
}

bool QtImpVolteaContrato::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
