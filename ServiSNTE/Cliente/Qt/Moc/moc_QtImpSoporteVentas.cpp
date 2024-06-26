/****************************************************************************
** QtImpSoporteVentas meta object code from reading C++ file 'QtImpSoporteVentas.h'
**
** Created: Thu Apr 11 21:08:54 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpSoporteVentas.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpSoporteVentas::className() const
{
    return "QtImpSoporteVentas";
}

QMetaObject *QtImpSoporteVentas::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpSoporteVentas( "QtImpSoporteVentas", &QtImpSoporteVentas::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpSoporteVentas::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpSoporteVentas", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpSoporteVentas::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpSoporteVentas", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpSoporteVentas::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = SoporteVentas::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "pzSisRegTienda", &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotTienda", 1, param_slot_0 };
    static const QUMethod slot_1 = {"SlotImprimir", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotTienda(zSiscomRegistro*)", &slot_0, QMetaData::Private },
	{ "SlotImprimir()", &slot_1, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpSoporteVentas", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpSoporteVentas.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpSoporteVentas::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpSoporteVentas" ) )
	return this;
    return SoporteVentas::qt_cast( clname );
}

bool QtImpSoporteVentas::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotTienda((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotImprimir(); break;
    default:
	return SoporteVentas::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpSoporteVentas::qt_emit( int _id, QUObject* _o )
{
    return SoporteVentas::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpSoporteVentas::qt_property( int id, int f, QVariant* v)
{
    return SoporteVentas::qt_property( id, f, v);
}

bool QtImpSoporteVentas::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
