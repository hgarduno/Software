/****************************************************************************
** QtImpRepStockProveedorCosto meta object code from reading C++ file 'QtImpRepStockProveedorCosto.h'
**
** Created: Sat Jan 27 16:39:46 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpRepStockProveedorCosto.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpRepStockProveedorCosto::className() const
{
    return "QtImpRepStockProveedorCosto";
}

QMetaObject *QtImpRepStockProveedorCosto::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpRepStockProveedorCosto( "QtImpRepStockProveedorCosto", &QtImpRepStockProveedorCosto::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpRepStockProveedorCosto::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpRepStockProveedorCosto", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpRepStockProveedorCosto::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpRepStockProveedorCosto", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpRepStockProveedorCosto::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = RepStockProveedorCosto::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotProveedor", 1, param_slot_0 };
    static const QUMethod slot_1 = {"SlotConsulta", 0, 0 };
    static const QUMethod slot_2 = {"SlotImprimir", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotProveedor(zSiscomRegistro*)", &slot_0, QMetaData::Private },
	{ "SlotConsulta()", &slot_1, QMetaData::Private },
	{ "SlotImprimir()", &slot_2, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpRepStockProveedorCosto", parentObject,
	slot_tbl, 3,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpRepStockProveedorCosto.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpRepStockProveedorCosto::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpRepStockProveedorCosto" ) )
	return this;
    return RepStockProveedorCosto::qt_cast( clname );
}

bool QtImpRepStockProveedorCosto::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotProveedor((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotConsulta(); break;
    case 2: SlotImprimir(); break;
    default:
	return RepStockProveedorCosto::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpRepStockProveedorCosto::qt_emit( int _id, QUObject* _o )
{
    return RepStockProveedorCosto::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpRepStockProveedorCosto::qt_property( int id, int f, QVariant* v)
{
    return RepStockProveedorCosto::qt_property( id, f, v);
}

bool QtImpRepStockProveedorCosto::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
