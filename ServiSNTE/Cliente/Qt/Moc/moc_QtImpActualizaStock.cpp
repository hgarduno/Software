/****************************************************************************
** QtImpActualizaStock meta object code from reading C++ file 'QtImpActualizaStock.h'
**
<<<<<<< HEAD
** Created: Mon Apr 1 17:30:22 2024
=======
** Created: Thu Apr 11 21:08:28 2024
>>>>>>> d8559e8a5b2006215346761b79004c9434166dbc
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpActualizaStock.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpActualizaStock::className() const
{
    return "QtImpActualizaStock";
}

QMetaObject *QtImpActualizaStock::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpActualizaStock( "QtImpActualizaStock", &QtImpActualizaStock::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpActualizaStock::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpActualizaStock", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpActualizaStock::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpActualizaStock", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpActualizaStock::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ActualizaStock::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "pzSisRegProveedor", &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotProveedor", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "pzSisRegTienda", &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotTienda", 1, param_slot_1 };
    static const QUMethod slot_2 = {"SlotFocoANumeroProducto", 0, 0 };
    static const QUMethod slot_3 = {"SlotStock", 0, 0 };
    static const QUMethod slot_4 = {"SlotConsultando", 0, 0 };
    static const QUMethod slot_5 = {"SlotFocoAStock", 0, 0 };
    static const QUMethod slot_6 = {"SlotFocoAActualizar", 0, 0 };
    static const QUMethod slot_7 = {"SlotActualizar", 0, 0 };
    static const QUParameter param_slot_8[] = {
	{ 0, &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_8 = {"SlotProducto", 1, param_slot_8 };
    static const QMetaData slot_tbl[] = {
	{ "SlotProveedor(zSiscomRegistro*)", &slot_0, QMetaData::Private },
	{ "SlotTienda(zSiscomRegistro*)", &slot_1, QMetaData::Private },
	{ "SlotFocoANumeroProducto()", &slot_2, QMetaData::Private },
	{ "SlotStock()", &slot_3, QMetaData::Private },
	{ "SlotConsultando()", &slot_4, QMetaData::Private },
	{ "SlotFocoAStock()", &slot_5, QMetaData::Private },
	{ "SlotFocoAActualizar()", &slot_6, QMetaData::Private },
	{ "SlotActualizar()", &slot_7, QMetaData::Private },
	{ "SlotProducto(zSiscomRegistro*)", &slot_8, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpActualizaStock", parentObject,
	slot_tbl, 9,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpActualizaStock.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpActualizaStock::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpActualizaStock" ) )
	return this;
    return ActualizaStock::qt_cast( clname );
}

bool QtImpActualizaStock::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotProveedor((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotTienda((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 2: SlotFocoANumeroProducto(); break;
    case 3: SlotStock(); break;
    case 4: SlotConsultando(); break;
    case 5: SlotFocoAStock(); break;
    case 6: SlotFocoAActualizar(); break;
    case 7: SlotActualizar(); break;
    case 8: SlotProducto((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    default:
	return ActualizaStock::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpActualizaStock::qt_emit( int _id, QUObject* _o )
{
    return ActualizaStock::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpActualizaStock::qt_property( int id, int f, QVariant* v)
{
    return ActualizaStock::qt_property( id, f, v);
}

bool QtImpActualizaStock::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
