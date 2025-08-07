/****************************************************************************
** QtImpConsultaVentas meta object code from reading C++ file 'QtImpConsultaVentas.h'
**
** Created: Tue Jun 24 08:59:46 2025
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpConsultaVentas.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpConsultaVentas::className() const
{
    return "QtImpConsultaVentas";
}

QMetaObject *QtImpConsultaVentas::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpConsultaVentas( "QtImpConsultaVentas", &QtImpConsultaVentas::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpConsultaVentas::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpConsultaVentas", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpConsultaVentas::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpConsultaVentas", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpConsultaVentas::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ConsultaVentas::staticMetaObject();
    static const QUMethod slot_0 = {"SlotFocoAConsultaVentas", 0, 0 };
    static const QUMethod slot_1 = {"SlotConsultaVentas", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotFocoAConsultaVentas()", &slot_0, QMetaData::Private },
	{ "SlotConsultaVentas()", &slot_1, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpConsultaVentas", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpConsultaVentas.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpConsultaVentas::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpConsultaVentas" ) )
	return this;
    return ConsultaVentas::qt_cast( clname );
}

bool QtImpConsultaVentas::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotFocoAConsultaVentas(); break;
    case 1: SlotConsultaVentas(); break;
    default:
	return ConsultaVentas::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpConsultaVentas::qt_emit( int _id, QUObject* _o )
{
    return ConsultaVentas::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpConsultaVentas::qt_property( int id, int f, QVariant* v)
{
    return ConsultaVentas::qt_property( id, f, v);
}

bool QtImpConsultaVentas::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
