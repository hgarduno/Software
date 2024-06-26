/****************************************************************************
** QtImpRegistroCompras meta object code from reading C++ file 'QtImpRegistroCompras.h'
**
<<<<<<< HEAD
** Created: Mon Apr 1 17:31:13 2024
=======
** Created: Thu Apr 11 21:09:18 2024
>>>>>>> d8559e8a5b2006215346761b79004c9434166dbc
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpRegistroCompras.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpRegistroCompras::className() const
{
    return "QtImpRegistroCompras";
}

QMetaObject *QtImpRegistroCompras::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpRegistroCompras( "QtImpRegistroCompras", &QtImpRegistroCompras::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpRegistroCompras::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpRegistroCompras", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpRegistroCompras::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpRegistroCompras", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpRegistroCompras::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = RegistroCompras::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "pzSisProveedor", &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotProveedor", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "pzSisTipoDocumento", &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotTipoDocumento", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ "pzSisConcepto", &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_2 = {"SlotConcepto", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ "pzSisProducto", &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_3 = {"SlotProducto", 1, param_slot_3 };
    static const QUMethod slot_4 = {"SlotFocoAFolio", 0, 0 };
    static const QUMethod slot_5 = {"SlotFocoAConcepto", 0, 0 };
    static const QUMethod slot_6 = {"SlotFocoAAgregar", 0, 0 };
    static const QUMethod slot_7 = {"SlotFocoACantidad", 0, 0 };
    static const QUMethod slot_8 = {"SlotHabilitaBotonAgregar", 0, 0 };
    static const QUMethod slot_9 = {"SlotAgregarProducto", 0, 0 };
    static const QUMethod slot_10 = {"SlotRegistraCompra", 0, 0 };
    static const QUParameter param_slot_11[] = {
	{ "pintNFila", &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_11 = {"SlotProductoOrden", 4, param_slot_11 };
    static const QUMethod slot_12 = {"SlotEliminarProductoOrden", 0, 0 };
    static const QUParameter param_slot_13[] = {
	{ "pintFila", &static_QUType_int, 0, QUParameter::In },
	{ "pintColumna", &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_13 = {"SlotCambiaCantidad", 4, param_slot_13 };
    static const QUMethod slot_14 = {"SlotFocoATipoDocumento", 0, 0 };
    static const QUMethod slot_15 = {"SlotCopiar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotProveedor(zSiscomRegistro*)", &slot_0, QMetaData::Private },
	{ "SlotTipoDocumento(zSiscomRegistro*)", &slot_1, QMetaData::Private },
	{ "SlotConcepto(zSiscomRegistro*)", &slot_2, QMetaData::Private },
	{ "SlotProducto(zSiscomRegistro*)", &slot_3, QMetaData::Private },
	{ "SlotFocoAFolio()", &slot_4, QMetaData::Private },
	{ "SlotFocoAConcepto()", &slot_5, QMetaData::Private },
	{ "SlotFocoAAgregar()", &slot_6, QMetaData::Private },
	{ "SlotFocoACantidad()", &slot_7, QMetaData::Private },
	{ "SlotHabilitaBotonAgregar()", &slot_8, QMetaData::Private },
	{ "SlotAgregarProducto()", &slot_9, QMetaData::Private },
	{ "SlotRegistraCompra()", &slot_10, QMetaData::Private },
	{ "SlotProductoOrden(int,int,int,const QPoint&)", &slot_11, QMetaData::Private },
	{ "SlotEliminarProductoOrden()", &slot_12, QMetaData::Private },
	{ "SlotCambiaCantidad(int,int,int,const QPoint&)", &slot_13, QMetaData::Private },
	{ "SlotFocoATipoDocumento()", &slot_14, QMetaData::Private },
	{ "SlotCopiar()", &slot_15, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpRegistroCompras", parentObject,
	slot_tbl, 16,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpRegistroCompras.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpRegistroCompras::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpRegistroCompras" ) )
	return this;
    return RegistroCompras::qt_cast( clname );
}

bool QtImpRegistroCompras::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotProveedor((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotTipoDocumento((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 2: SlotConcepto((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 3: SlotProducto((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 4: SlotFocoAFolio(); break;
    case 5: SlotFocoAConcepto(); break;
    case 6: SlotFocoAAgregar(); break;
    case 7: SlotFocoACantidad(); break;
    case 8: SlotHabilitaBotonAgregar(); break;
    case 9: SlotAgregarProducto(); break;
    case 10: SlotRegistraCompra(); break;
    case 11: SlotProductoOrden((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 12: SlotEliminarProductoOrden(); break;
    case 13: SlotCambiaCantidad((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 14: SlotFocoATipoDocumento(); break;
    case 15: SlotCopiar(); break;
    default:
	return RegistroCompras::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpRegistroCompras::qt_emit( int _id, QUObject* _o )
{
    return RegistroCompras::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpRegistroCompras::qt_property( int id, int f, QVariant* v)
{
    return RegistroCompras::qt_property( id, f, v);
}

bool QtImpRegistroCompras::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
