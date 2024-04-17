/****************************************************************************
** QCompras meta object code from reading C++ file 'IMP_Compras.h'
**
** Created: Fri Apr 12 21:35:06 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_Compras.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCompras::className() const
{
    return "QCompras";
}

QMetaObject *QCompras::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCompras( "QCompras", &QCompras::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCompras::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCompras", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCompras::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCompras", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCompras::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = Compras::staticMetaObject();
    static const QUMethod slot_0 = {"S_PasaFocoProductos", 0, 0 };
    static const QUMethod slot_1 = {"S_PasaFocoProveedor", 0, 0 };
    static const QUParameter param_slot_2[] = {
	{ "pSisReg3Bodega", &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod slot_2 = {"S_SeleccionoBodega", 1, param_slot_2 };
    static const QUMethod slot_3 = {"S_PasaFocoCantidad", 0, 0 };
    static const QUMethod slot_4 = {"S_PasaFocoPrecioCompra", 0, 0 };
    static const QUMethod slot_5 = {"S_PasaFocoFormaPago", 0, 0 };
    static const QUMethod slot_6 = {"S_SeleccionoFormaPago", 0, 0 };
    static const QUMethod slot_7 = {"S_PasaFocoFechaPago", 0, 0 };
    static const QUMethod slot_8 = {"S_PasaFocoAnexar", 0, 0 };
    static const QUMethod slot_9 = {"S_PasaFocoPrecioVenta", 0, 0 };
    static const QUMethod slot_10 = {"S_PasaFocoTipoPrecio", 0, 0 };
    static const QUMethod slot_11 = {"S_PasaFocoNumFactura", 0, 0 };
    static const QUMethod slot_12 = {"S_PasaFocoMasIVA", 0, 0 };
    static const QUMethod slot_13 = {"S_Anexar", 0, 0 };
    static const QUMethod slot_14 = {"S_Registrar", 0, 0 };
    static const QUParameter param_slot_15[] = {
	{ 0, &static_QUType_ptr, "ProductoE", QUParameter::In }
    };
    static const QUMethod slot_15 = {"S_SelProducto", 1, param_slot_15 };
    static const QUParameter param_slot_16[] = {
	{ 0, &static_QUType_charstar, 0, QUParameter::In }
    };
    static const QUMethod slot_16 = {"S_NoEstaLaClave", 1, param_slot_16 };
    static const QUParameter param_slot_17[] = {
	{ 0, &static_QUType_ptr, "TipoPrecio", QUParameter::In }
    };
    static const QUMethod slot_17 = {"S_SelTipoPrecio", 1, param_slot_17 };
    static const QUMethod slot_18 = {"S_MasIva", 0, 0 };
    static const QUParameter param_slot_19[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_19 = {"S_ModificarDatos", 4, param_slot_19 };
    static const QUMethod slot_20 = {"S_EliminaProductos", 0, 0 };
    static const QUMethod slot_21 = {"S_PasaFocoBodegas", 0, 0 };
    static const QUParameter param_slot_22[] = {
	{ "pSisReg3OrigenCompra", &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod slot_22 = {"SlotOrigenCompra", 1, param_slot_22 };
    static const QUMethod slot_23 = {"SlotFocoACantidadTransfiereZacatenco", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "S_PasaFocoProductos()", &slot_0, QMetaData::Private },
	{ "S_PasaFocoProveedor()", &slot_1, QMetaData::Private },
	{ "S_SeleccionoBodega(SiscomRegistro3*)", &slot_2, QMetaData::Private },
	{ "S_PasaFocoCantidad()", &slot_3, QMetaData::Private },
	{ "S_PasaFocoPrecioCompra()", &slot_4, QMetaData::Private },
	{ "S_PasaFocoFormaPago()", &slot_5, QMetaData::Private },
	{ "S_SeleccionoFormaPago()", &slot_6, QMetaData::Private },
	{ "S_PasaFocoFechaPago()", &slot_7, QMetaData::Private },
	{ "S_PasaFocoAnexar()", &slot_8, QMetaData::Private },
	{ "S_PasaFocoPrecioVenta()", &slot_9, QMetaData::Private },
	{ "S_PasaFocoTipoPrecio()", &slot_10, QMetaData::Private },
	{ "S_PasaFocoNumFactura()", &slot_11, QMetaData::Private },
	{ "S_PasaFocoMasIVA()", &slot_12, QMetaData::Private },
	{ "S_Anexar()", &slot_13, QMetaData::Private },
	{ "S_Registrar()", &slot_14, QMetaData::Private },
	{ "S_SelProducto(ProductoE*)", &slot_15, QMetaData::Private },
	{ "S_NoEstaLaClave(const char*)", &slot_16, QMetaData::Private },
	{ "S_SelTipoPrecio(TipoPrecio*)", &slot_17, QMetaData::Private },
	{ "S_MasIva()", &slot_18, QMetaData::Private },
	{ "S_ModificarDatos(int,int,int,const QPoint&)", &slot_19, QMetaData::Private },
	{ "S_EliminaProductos()", &slot_20, QMetaData::Private },
	{ "S_PasaFocoBodegas()", &slot_21, QMetaData::Private },
	{ "SlotOrigenCompra(SiscomRegistro3*)", &slot_22, QMetaData::Private },
	{ "SlotFocoACantidadTransfiereZacatenco()", &slot_23, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalTerminar", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalTerminar(QWidget*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCompras", parentObject,
	slot_tbl, 24,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCompras.setMetaObject( metaObj );
    return metaObj;
}

void* QCompras::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCompras" ) )
	return this;
    return Compras::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalTerminar
void QCompras::SignalTerminar( QWidget* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

bool QCompras::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: S_PasaFocoProductos(); break;
    case 1: S_PasaFocoProveedor(); break;
    case 2: S_SeleccionoBodega((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    case 3: S_PasaFocoCantidad(); break;
    case 4: S_PasaFocoPrecioCompra(); break;
    case 5: S_PasaFocoFormaPago(); break;
    case 6: S_SeleccionoFormaPago(); break;
    case 7: S_PasaFocoFechaPago(); break;
    case 8: S_PasaFocoAnexar(); break;
    case 9: S_PasaFocoPrecioVenta(); break;
    case 10: S_PasaFocoTipoPrecio(); break;
    case 11: S_PasaFocoNumFactura(); break;
    case 12: S_PasaFocoMasIVA(); break;
    case 13: S_Anexar(); break;
    case 14: S_Registrar(); break;
    case 15: S_SelProducto((ProductoE*)static_QUType_ptr.get(_o+1)); break;
    case 16: S_NoEstaLaClave((const char*)static_QUType_charstar.get(_o+1)); break;
    case 17: S_SelTipoPrecio((TipoPrecio*)static_QUType_ptr.get(_o+1)); break;
    case 18: S_MasIva(); break;
    case 19: S_ModificarDatos((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 20: S_EliminaProductos(); break;
    case 21: S_PasaFocoBodegas(); break;
    case 22: SlotOrigenCompra((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    case 23: SlotFocoACantidadTransfiereZacatenco(); break;
    default:
	return Compras::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCompras::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalTerminar((QWidget*)static_QUType_ptr.get(_o+1)); break;
    default:
	return Compras::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QCompras::qt_property( int id, int f, QVariant* v)
{
    return Compras::qt_property( id, f, v);
}

bool QCompras::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
