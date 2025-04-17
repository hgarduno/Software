/****************************************************************************
** QtImpImpresionCodigoBarras meta object code from reading C++ file 'QtImpImpresionCodigoBarras.h'
**
** Created: Sat Feb 22 23:13:24 2025
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpImpresionCodigoBarras.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpImpresionCodigoBarras::className() const
{
    return "QtImpImpresionCodigoBarras";
}

QMetaObject *QtImpImpresionCodigoBarras::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpImpresionCodigoBarras( "QtImpImpresionCodigoBarras", &QtImpImpresionCodigoBarras::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpImpresionCodigoBarras::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpImpresionCodigoBarras", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpImpresionCodigoBarras::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpImpresionCodigoBarras", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpImpresionCodigoBarras::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ImpresionCodigoBarras::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotProveedor", 1, param_slot_0 };
    static const QUMethod slot_1 = {"SlotFechaCompra", 0, 0 };
    static const QUMethod slot_2 = {"SlotTodosProductos", 0, 0 };
    static const QUMethod slot_3 = {"SlotImprimirCodigos", 0, 0 };
    static const QUMethod slot_4 = {"SlotImpresionTodaHoja", 0, 0 };
    static const QUMethod slot_5 = {"SlotImprimirCodigosX8", 0, 0 };
    static const QUParameter param_slot_6[] = {
	{ "pintFila", &static_QUType_int, 0, QUParameter::In },
	{ "pintColumna", &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_6 = {"SlotCapturaCantidad", 4, param_slot_6 };
    static const QMetaData slot_tbl[] = {
	{ "SlotProveedor(zSiscomRegistro*)", &slot_0, QMetaData::Private },
	{ "SlotFechaCompra()", &slot_1, QMetaData::Private },
	{ "SlotTodosProductos()", &slot_2, QMetaData::Private },
	{ "SlotImprimirCodigos()", &slot_3, QMetaData::Private },
	{ "SlotImpresionTodaHoja()", &slot_4, QMetaData::Private },
	{ "SlotImprimirCodigosX8()", &slot_5, QMetaData::Private },
	{ "SlotCapturaCantidad(int,int,int,const QPoint&)", &slot_6, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpImpresionCodigoBarras", parentObject,
	slot_tbl, 7,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpImpresionCodigoBarras.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpImpresionCodigoBarras::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpImpresionCodigoBarras" ) )
	return this;
    return ImpresionCodigoBarras::qt_cast( clname );
}

bool QtImpImpresionCodigoBarras::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotProveedor((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotFechaCompra(); break;
    case 2: SlotTodosProductos(); break;
    case 3: SlotImprimirCodigos(); break;
    case 4: SlotImpresionTodaHoja(); break;
    case 5: SlotImprimirCodigosX8(); break;
    case 6: SlotCapturaCantidad((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    default:
	return ImpresionCodigoBarras::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpImpresionCodigoBarras::qt_emit( int _id, QUObject* _o )
{
    return ImpresionCodigoBarras::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpImpresionCodigoBarras::qt_property( int id, int f, QVariant* v)
{
    return ImpresionCodigoBarras::qt_property( id, f, v);
}

bool QtImpImpresionCodigoBarras::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
