/****************************************************************************
** QPedidoMaterial4 meta object code from reading C++ file 'IMP_PedidoMaterial4.h'
**
** Created: Thu Apr 11 21:40:01 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_PedidoMaterial4.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QPedidoMaterial4::className() const
{
    return "QPedidoMaterial4";
}

QMetaObject *QPedidoMaterial4::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QPedidoMaterial4( "QPedidoMaterial4", &QPedidoMaterial4::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QPedidoMaterial4::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QPedidoMaterial4", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QPedidoMaterial4::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QPedidoMaterial4", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QPedidoMaterial4::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = PedidoMaterial4::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotSeleccionoProducto", 1, param_slot_0 };
    static const QUMethod slot_1 = {"SlotFocoAAnexar", 0, 0 };
    static const QUMethod slot_2 = {"SlotAnexarProducto", 0, 0 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_3 = {"SlotSeleccionaProducto", 4, param_slot_3 };
    static const QUMethod slot_4 = {"SlotEliminaProducto", 0, 0 };
    static const QUMethod slot_5 = {"SlotActualizaProducto", 0, 0 };
    static const QUMethod slot_6 = {"SlotRegistraPedido", 0, 0 };
    static const QUMethod slot_7 = {"SlotActualizaObservacionesPedido", 0, 0 };
    static const QUParameter param_slot_8[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_8 = {"SlotActualizaObsProducto", 2, param_slot_8 };
    static const QMetaData slot_tbl[] = {
	{ "SlotSeleccionoProducto(zSiscomRegistro*)", &slot_0, QMetaData::Private },
	{ "SlotFocoAAnexar()", &slot_1, QMetaData::Private },
	{ "SlotAnexarProducto()", &slot_2, QMetaData::Private },
	{ "SlotSeleccionaProducto(int,int,int,const QPoint&)", &slot_3, QMetaData::Private },
	{ "SlotEliminaProducto()", &slot_4, QMetaData::Private },
	{ "SlotActualizaProducto()", &slot_5, QMetaData::Private },
	{ "SlotRegistraPedido()", &slot_6, QMetaData::Private },
	{ "SlotActualizaObservacionesPedido()", &slot_7, QMetaData::Private },
	{ "SlotActualizaObsProducto(int,int)", &slot_8, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QPedidoMaterial4", parentObject,
	slot_tbl, 9,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QPedidoMaterial4.setMetaObject( metaObj );
    return metaObj;
}

void* QPedidoMaterial4::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QPedidoMaterial4" ) )
	return this;
    return PedidoMaterial4::qt_cast( clname );
}

bool QPedidoMaterial4::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotSeleccionoProducto((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotFocoAAnexar(); break;
    case 2: SlotAnexarProducto(); break;
    case 3: SlotSeleccionaProducto((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 4: SlotEliminaProducto(); break;
    case 5: SlotActualizaProducto(); break;
    case 6: SlotRegistraPedido(); break;
    case 7: SlotActualizaObservacionesPedido(); break;
    case 8: SlotActualizaObsProducto((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    default:
	return PedidoMaterial4::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QPedidoMaterial4::qt_emit( int _id, QUObject* _o )
{
    return PedidoMaterial4::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QPedidoMaterial4::qt_property( int id, int f, QVariant* v)
{
    return PedidoMaterial4::qt_property( id, f, v);
}

bool QPedidoMaterial4::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
