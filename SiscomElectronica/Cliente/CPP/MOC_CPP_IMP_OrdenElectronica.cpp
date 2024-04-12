/****************************************************************************
** QOrdenElectronica meta object code from reading C++ file 'IMP_OrdenElectronica.h'
**
** Created: Thu Apr 11 21:39:40 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_OrdenElectronica.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QOrdenElectronica::className() const
{
    return "QOrdenElectronica";
}

QMetaObject *QOrdenElectronica::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QOrdenElectronica( "QOrdenElectronica", &QOrdenElectronica::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QOrdenElectronica::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QOrdenElectronica", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QOrdenElectronica::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QOrdenElectronica", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QOrdenElectronica::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = OrdenElectronica::staticMetaObject();
    static const QUMethod slot_0 = {"S_ImprimeTicket", 0, 0 };
    static const QUMethod slot_1 = {"S_ImprimeCotizacion", 0, 0 };
    static const QUMethod slot_2 = {"S_RealizaVenta", 0, 0 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_3 = {"S_OperacionCotizacion", 4, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_4 = {"S_CargaMenu", 3, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"S_CambioNumJuegos", 1, param_slot_5 };
    static const QUParameter param_slot_6[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_6 = {"S_JuegosSeparados", 1, param_slot_6 };
    static const QUMethod slot_7 = {"S_EliminaProductos", 0, 0 };
    static const QUMethod slot_8 = {"S_RCotizacion", 0, 0 };
    static const QUMethod slot_9 = {"S_VendeCotizacion", 0, 0 };
    static const QUMethod slot_10 = {"S_OrdenVendida", 0, 0 };
    static const QUMethod slot_11 = {"S_PorcentajeDescuento", 0, 0 };
    static const QUParameter param_slot_12[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_12 = {"S_PorcentajeDescuentoOrden", 1, param_slot_12 };
    static const QUMethod slot_13 = {"S_OrdenCaja", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "S_ImprimeTicket()", &slot_0, QMetaData::Public },
	{ "S_ImprimeCotizacion()", &slot_1, QMetaData::Public },
	{ "S_RealizaVenta()", &slot_2, QMetaData::Public },
	{ "S_OperacionCotizacion(int,int,int,const QPoint&)", &slot_3, QMetaData::Public },
	{ "S_CargaMenu(int,int,const QPoint&)", &slot_4, QMetaData::Public },
	{ "S_CambioNumJuegos(int)", &slot_5, QMetaData::Public },
	{ "S_JuegosSeparados(int)", &slot_6, QMetaData::Public },
	{ "S_EliminaProductos()", &slot_7, QMetaData::Public },
	{ "S_RCotizacion()", &slot_8, QMetaData::Public },
	{ "S_VendeCotizacion()", &slot_9, QMetaData::Public },
	{ "S_OrdenVendida()", &slot_10, QMetaData::Public },
	{ "S_PorcentajeDescuento()", &slot_11, QMetaData::Public },
	{ "S_PorcentajeDescuentoOrden(int)", &slot_12, QMetaData::Public },
	{ "S_OrdenCaja()", &slot_13, QMetaData::Public }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "QOrdenElectronica", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalVendeOrden", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_ptr, "ProductosE", QUParameter::InOut }
    };
    static const QUMethod signal_1 = {"SignalJuegosSeparados", 2, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ 0, &static_QUType_ptr, "QOrdenElectronica", QUParameter::In }
    };
    static const QUMethod signal_2 = {"SignalCancelarVenta", 1, param_signal_2 };
    static const QMetaData signal_tbl[] = {
	{ "SignalVendeOrden(QOrdenElectronica*)", &signal_0, QMetaData::Public },
	{ "SignalJuegosSeparados(int,ProductosE&)", &signal_1, QMetaData::Public },
	{ "SignalCancelarVenta(QOrdenElectronica*)", &signal_2, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"QOrdenElectronica", parentObject,
	slot_tbl, 14,
	signal_tbl, 3,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QOrdenElectronica.setMetaObject( metaObj );
    return metaObj;
}

void* QOrdenElectronica::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QOrdenElectronica" ) )
	return this;
    if ( !qstrcmp( clname, "Seguridad3Protocolo2" ) )
	return (Seguridad3Protocolo2*)this;
    return OrdenElectronica::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalVendeOrden
void QOrdenElectronica::SignalVendeOrden( QOrdenElectronica* t0 )
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

// SIGNAL SignalJuegosSeparados
void QOrdenElectronica::SignalJuegosSeparados( int t0, ProductosE& t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 1 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_int.set(o+1,t0);
    static_QUType_ptr.set(o+2,&t1);
    activate_signal( clist, o );
}

// SIGNAL SignalCancelarVenta
void QOrdenElectronica::SignalCancelarVenta( QOrdenElectronica* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 2 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

bool QOrdenElectronica::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: S_ImprimeTicket(); break;
    case 1: S_ImprimeCotizacion(); break;
    case 2: S_RealizaVenta(); break;
    case 3: S_OperacionCotizacion((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 4: S_CargaMenu((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+3))); break;
    case 5: S_CambioNumJuegos((int)static_QUType_int.get(_o+1)); break;
    case 6: S_JuegosSeparados((int)static_QUType_int.get(_o+1)); break;
    case 7: S_EliminaProductos(); break;
    case 8: S_RCotizacion(); break;
    case 9: S_VendeCotizacion(); break;
    case 10: S_OrdenVendida(); break;
    case 11: S_PorcentajeDescuento(); break;
    case 12: S_PorcentajeDescuentoOrden((int)static_QUType_int.get(_o+1)); break;
    case 13: S_OrdenCaja(); break;
    default:
	return OrdenElectronica::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QOrdenElectronica::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalVendeOrden((QOrdenElectronica*)static_QUType_ptr.get(_o+1)); break;
    case 1: SignalJuegosSeparados((int)static_QUType_int.get(_o+1),(ProductosE&)*((ProductosE*)static_QUType_ptr.get(_o+2))); break;
    case 2: SignalCancelarVenta((QOrdenElectronica*)static_QUType_ptr.get(_o+1)); break;
    default:
	return OrdenElectronica::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QOrdenElectronica::qt_property( int id, int f, QVariant* v)
{
    return OrdenElectronica::qt_property( id, f, v);
}

bool QOrdenElectronica::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
