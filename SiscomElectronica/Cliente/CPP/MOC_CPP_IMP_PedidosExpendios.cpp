/****************************************************************************
** QPedidosExpendios meta object code from reading C++ file 'IMP_PedidosExpendios.h'
**
** Created: Wed Apr 10 20:52:40 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_PedidosExpendios.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QPedidosExpendios::className() const
{
    return "QPedidosExpendios";
}

QMetaObject *QPedidosExpendios::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QPedidosExpendios( "QPedidosExpendios", &QPedidosExpendios::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QPedidosExpendios::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QPedidosExpendios", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QPedidosExpendios::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QPedidosExpendios", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QPedidosExpendios::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = PedidosExpendios::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotSeleccionandoPedido", 4, param_slot_0 };
    static const QUMethod slot_1 = {"SlotTransfierePedido", 0, 0 };
    static const QUMethod slot_2 = {"SlotConsultaPedidos", 0, 0 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_3 = {"SlotSeleccionoProducto", 4, param_slot_3 };
    static const QUMethod slot_4 = {"SlotImprime", 0, 0 };
    static const QUMethod slot_5 = {"SlotFocoAFechaFin", 0, 0 };
    static const QUMethod slot_6 = {"SlotFocoAConsultar", 0, 0 };
    static const QUMethod slot_7 = {"SlotActualizaInventario", 0, 0 };
    static const QUMethod slot_8 = {"SlotDesactivaValCantidad", 0, 0 };
    static const QUMethod slot_9 = {"SlotTranBodegaExpendio", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotSeleccionandoPedido(int,int,int,const QPoint&)", &slot_0, QMetaData::Private },
	{ "SlotTransfierePedido()", &slot_1, QMetaData::Private },
	{ "SlotConsultaPedidos()", &slot_2, QMetaData::Private },
	{ "SlotSeleccionoProducto(int,int,int,const QPoint&)", &slot_3, QMetaData::Private },
	{ "SlotImprime()", &slot_4, QMetaData::Private },
	{ "SlotFocoAFechaFin()", &slot_5, QMetaData::Private },
	{ "SlotFocoAConsultar()", &slot_6, QMetaData::Private },
	{ "SlotActualizaInventario()", &slot_7, QMetaData::Private },
	{ "SlotDesactivaValCantidad()", &slot_8, QMetaData::Private },
	{ "SlotTranBodegaExpendio()", &slot_9, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QPedidosExpendios", parentObject,
	slot_tbl, 10,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QPedidosExpendios.setMetaObject( metaObj );
    return metaObj;
}

void* QPedidosExpendios::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QPedidosExpendios" ) )
	return this;
    return PedidosExpendios::qt_cast( clname );
}

bool QPedidosExpendios::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotSeleccionandoPedido((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 1: SlotTransfierePedido(); break;
    case 2: SlotConsultaPedidos(); break;
    case 3: SlotSeleccionoProducto((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 4: SlotImprime(); break;
    case 5: SlotFocoAFechaFin(); break;
    case 6: SlotFocoAConsultar(); break;
    case 7: SlotActualizaInventario(); break;
    case 8: SlotDesactivaValCantidad(); break;
    case 9: SlotTranBodegaExpendio(); break;
    default:
	return PedidosExpendios::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QPedidosExpendios::qt_emit( int _id, QUObject* _o )
{
    return PedidosExpendios::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QPedidosExpendios::qt_property( int id, int f, QVariant* v)
{
    return PedidosExpendios::qt_property( id, f, v);
}

bool QPedidosExpendios::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
