/****************************************************************************
** QtImpRepStockTienda meta object code from reading C++ file 'QtImpRepStockTienda.h'
**
** Created: Sat Jan 27 16:39:45 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpRepStockTienda.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpRepStockTienda::className() const
{
    return "QtImpRepStockTienda";
}

QMetaObject *QtImpRepStockTienda::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpRepStockTienda( "QtImpRepStockTienda", &QtImpRepStockTienda::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpRepStockTienda::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpRepStockTienda", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpRepStockTienda::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpRepStockTienda", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpRepStockTienda::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = RepStockTienda::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "pzSisRegTienda", &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotTienda", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "pzSisRegProveedor", &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotProveedor", 1, param_slot_1 };
    static const QUMethod slot_2 = {"SlotConsulta", 0, 0 };
    static const QUMethod slot_3 = {"SlotImprimir", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotTienda(zSiscomRegistro*)", &slot_0, QMetaData::Private },
	{ "SlotProveedor(zSiscomRegistro*)", &slot_1, QMetaData::Private },
	{ "SlotConsulta()", &slot_2, QMetaData::Private },
	{ "SlotImprimir()", &slot_3, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpRepStockTienda", parentObject,
	slot_tbl, 4,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpRepStockTienda.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpRepStockTienda::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpRepStockTienda" ) )
	return this;
    return RepStockTienda::qt_cast( clname );
}

bool QtImpRepStockTienda::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotTienda((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotProveedor((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 2: SlotConsulta(); break;
    case 3: SlotImprimir(); break;
    default:
	return RepStockTienda::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpRepStockTienda::qt_emit( int _id, QUObject* _o )
{
    return RepStockTienda::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpRepStockTienda::qt_property( int id, int f, QVariant* v)
{
    return RepStockTienda::qt_property( id, f, v);
}

bool QtImpRepStockTienda::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
