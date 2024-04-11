/****************************************************************************
** QPreciosExpendios meta object code from reading C++ file 'IMP_PreciosExpendios.h'
**
** Created: Wed Apr 10 20:52:40 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_PreciosExpendios.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QPreciosExpendios::className() const
{
    return "QPreciosExpendios";
}

QMetaObject *QPreciosExpendios::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QPreciosExpendios( "QPreciosExpendios", &QPreciosExpendios::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QPreciosExpendios::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QPreciosExpendios", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QPreciosExpendios::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QPreciosExpendios", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QPreciosExpendios::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = PreciosExpendios::staticMetaObject();
    static const QUMethod slot_0 = {"SlotExpendioO", 0, 0 };
    static const QUMethod slot_1 = {"SlotExpendioD", 0, 0 };
    static const QUMethod slot_2 = {"SlotConsultaPrecios", 0, 0 };
    static const QUMethod slot_3 = {"SlotConsulta2Precios", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotExpendioO()", &slot_0, QMetaData::Private },
	{ "SlotExpendioD()", &slot_1, QMetaData::Private },
	{ "SlotConsultaPrecios()", &slot_2, QMetaData::Private },
	{ "SlotConsulta2Precios()", &slot_3, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QPreciosExpendios", parentObject,
	slot_tbl, 4,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QPreciosExpendios.setMetaObject( metaObj );
    return metaObj;
}

void* QPreciosExpendios::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QPreciosExpendios" ) )
	return this;
    return PreciosExpendios::qt_cast( clname );
}

bool QPreciosExpendios::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotExpendioO(); break;
    case 1: SlotExpendioD(); break;
    case 2: SlotConsultaPrecios(); break;
    case 3: SlotConsulta2Precios(); break;
    default:
	return PreciosExpendios::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QPreciosExpendios::qt_emit( int _id, QUObject* _o )
{
    return PreciosExpendios::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QPreciosExpendios::qt_property( int id, int f, QVariant* v)
{
    return PreciosExpendios::qt_property( id, f, v);
}

bool QPreciosExpendios::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
