/****************************************************************************
** QtImpSaldosMovimientos meta object code from reading C++ file 'QtImpSaldosMovimientos.h'
**
** Created: Thu Apr 11 21:09:01 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpSaldosMovimientos.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpSaldosMovimientos::className() const
{
    return "QtImpSaldosMovimientos";
}

QMetaObject *QtImpSaldosMovimientos::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpSaldosMovimientos( "QtImpSaldosMovimientos", &QtImpSaldosMovimientos::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpSaldosMovimientos::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpSaldosMovimientos", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpSaldosMovimientos::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpSaldosMovimientos", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpSaldosMovimientos::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = SaldosMovimientos::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "pzSisRegProveedor", &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotProveedor", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "pzSisRegTienda", &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotTienda", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ "pzSisRegProducto", &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_2 = {"SlotProducto", 1, param_slot_2 };
    static const QUMethod slot_3 = {"SlotConsultando", 0, 0 };
    static const QUParameter param_slot_4[] = {
	{ "pintMes", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_4 = {"SlotMes", 1, param_slot_4 };
    static const QMetaData slot_tbl[] = {
	{ "SlotProveedor(zSiscomRegistro*)", &slot_0, QMetaData::Private },
	{ "SlotTienda(zSiscomRegistro*)", &slot_1, QMetaData::Private },
	{ "SlotProducto(zSiscomRegistro*)", &slot_2, QMetaData::Private },
	{ "SlotConsultando()", &slot_3, QMetaData::Private },
	{ "SlotMes(int)", &slot_4, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpSaldosMovimientos", parentObject,
	slot_tbl, 5,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpSaldosMovimientos.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpSaldosMovimientos::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpSaldosMovimientos" ) )
	return this;
    return SaldosMovimientos::qt_cast( clname );
}

bool QtImpSaldosMovimientos::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotProveedor((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotTienda((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 2: SlotProducto((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 3: SlotConsultando(); break;
    case 4: SlotMes((int)static_QUType_int.get(_o+1)); break;
    default:
	return SaldosMovimientos::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpSaldosMovimientos::qt_emit( int _id, QUObject* _o )
{
    return SaldosMovimientos::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpSaldosMovimientos::qt_property( int id, int f, QVariant* v)
{
    return SaldosMovimientos::qt_property( id, f, v);
}

bool QtImpSaldosMovimientos::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
