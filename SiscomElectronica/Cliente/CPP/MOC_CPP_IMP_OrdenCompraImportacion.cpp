/****************************************************************************
** QOrdenCompraImportacion meta object code from reading C++ file 'IMP_OrdenCompraImportacion.h'
**
** Created: Wed Apr 10 20:52:40 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_OrdenCompraImportacion.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QOrdenCompraImportacion::className() const
{
    return "QOrdenCompraImportacion";
}

QMetaObject *QOrdenCompraImportacion::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QOrdenCompraImportacion( "QOrdenCompraImportacion", &QOrdenCompraImportacion::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QOrdenCompraImportacion::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QOrdenCompraImportacion", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QOrdenCompraImportacion::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QOrdenCompraImportacion", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QOrdenCompraImportacion::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = OrdenCompraImportacion::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotProveedor", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotProducto", 1, param_slot_1 };
    static const QUMethod slot_2 = {"SlotFocoAPrecio", 0, 0 };
    static const QUMethod slot_3 = {"SlotFocoAAnexar", 0, 0 };
    static const QUParameter param_slot_4[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_4 = {"SlotCapturandoCantidad", 1, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"SlotCapturandoPrecio", 1, param_slot_5 };
    static const QMetaData slot_tbl[] = {
	{ "SlotProveedor(zSiscomRegistro*)", &slot_0, QMetaData::Private },
	{ "SlotProducto(zSiscomRegistro*)", &slot_1, QMetaData::Private },
	{ "SlotFocoAPrecio()", &slot_2, QMetaData::Private },
	{ "SlotFocoAAnexar()", &slot_3, QMetaData::Private },
	{ "SlotCapturandoCantidad(const QString&)", &slot_4, QMetaData::Private },
	{ "SlotCapturandoPrecio(const QString&)", &slot_5, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QOrdenCompraImportacion", parentObject,
	slot_tbl, 6,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QOrdenCompraImportacion.setMetaObject( metaObj );
    return metaObj;
}

void* QOrdenCompraImportacion::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QOrdenCompraImportacion" ) )
	return this;
    return OrdenCompraImportacion::qt_cast( clname );
}

bool QOrdenCompraImportacion::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotProveedor((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotProducto((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 2: SlotFocoAPrecio(); break;
    case 3: SlotFocoAAnexar(); break;
    case 4: SlotCapturandoCantidad((const QString&)static_QUType_QString.get(_o+1)); break;
    case 5: SlotCapturandoPrecio((const QString&)static_QUType_QString.get(_o+1)); break;
    default:
	return OrdenCompraImportacion::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QOrdenCompraImportacion::qt_emit( int _id, QUObject* _o )
{
    return OrdenCompraImportacion::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QOrdenCompraImportacion::qt_property( int id, int f, QVariant* v)
{
    return OrdenCompraImportacion::qt_property( id, f, v);
}

bool QOrdenCompraImportacion::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
