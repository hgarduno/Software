/****************************************************************************
** QManejadorOrden meta object code from reading C++ file 'IMP_ManejadorOrden.h'
**
** Created: Thu Apr 11 21:50:50 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_ManejadorOrden.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QManejadorOrden::className() const
{
    return "QManejadorOrden";
}

QMetaObject *QManejadorOrden::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QManejadorOrden( "QManejadorOrden", &QManejadorOrden::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QManejadorOrden::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QManejadorOrden", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QManejadorOrden::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QManejadorOrden", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QManejadorOrden::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ManejadorOrden::staticMetaObject();
    static const QUMethod slot_0 = {"SlotAnexarOrden", 0, 0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotCantidad", 4, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ "pzSisRegProducto", &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_2 = {"SlotSeleccionoProducto", 1, param_slot_2 };
    static const QUMethod slot_3 = {"SlotFocoAProducto", 0, 0 };
    static const QUMethod slot_4 = {"SlotNuevaOrden", 0, 0 };
    static const QUMethod slot_5 = {"SlotRegistrar", 0, 0 };
    static const QUMethod slot_6 = {"SlotImprimir", 0, 0 };
    static const QUParameter param_slot_7[] = {
	{ "pintFila", &static_QUType_int, 0, QUParameter::In },
	{ "pintColumna", &static_QUType_int, 0, QUParameter::In },
	{ "pQPosicion", &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_7 = {"SlotActivaMenu", 3, param_slot_7 };
    static const QUParameter param_slot_8[] = {
	{ "pzProdCotizar", &static_QUType_ptr, "zProductoCotizar", QUParameter::In }
    };
    static const QUMethod slot_8 = {"SlotEliminaProducto", 1, param_slot_8 };
    static const QUParameter param_slot_9[] = {
	{ "pchrPtrNumeroJuegos", &static_QUType_charstar, 0, QUParameter::In }
    };
    static const QUMethod slot_9 = {"SlotNumeroJuegos", 1, param_slot_9 };
    static const QUParameter param_slot_10[] = {
	{ "pintJuegosSeparados", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_10 = {"SlotJuegosSeparados", 1, param_slot_10 };
    static const QUParameter param_slot_11[] = {
	{ "pchrPtrDecuentoOrden", &static_QUType_charstar, 0, QUParameter::In }
    };
    static const QUMethod slot_11 = {"SlotDescuentoOrden", 1, param_slot_11 };
    static const QUParameter param_slot_12[] = {
	{ "pchrPtrDesProducto", &static_QUType_charstar, 0, QUParameter::In }
    };
    static const QUMethod slot_12 = {"SlotDescuentoProducto", 1, param_slot_12 };
    static const QUMethod slot_13 = {"SlotPrecioProducto", 0, 0 };
    static const QUParameter param_slot_14[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_14 = {"SlotCapturandoCantidad", 1, param_slot_14 };
    static const QUMethod slot_15 = {"SlotPagoConTarjeta", 0, 0 };
    static const QUMethod slot_16 = {"SlotExistenciaExpendios", 0, 0 };
    static const QUMethod slot_17 = {"SlotCargaCotizacion", 0, 0 };
    static const QUMethod slot_18 = {"SlotImprimirPdf", 0, 0 };
    static const QUMethod slot_19 = {"SlotFaltante", 0, 0 };
    static const QUParameter param_slot_20[] = {
	{ 0, &static_QUType_ptr, "zProducto", QUParameter::In }
    };
    static const QUMethod slot_20 = {"SlotProductoNoValido", 1, param_slot_20 };
    static const QMetaData slot_tbl[] = {
	{ "SlotAnexarOrden()", &slot_0, QMetaData::Public },
	{ "SlotCantidad(int,int,int,const QPoint&)", &slot_1, QMetaData::Public },
	{ "SlotSeleccionoProducto(zSiscomRegistro*)", &slot_2, QMetaData::Private },
	{ "SlotFocoAProducto()", &slot_3, QMetaData::Private },
	{ "SlotNuevaOrden()", &slot_4, QMetaData::Private },
	{ "SlotRegistrar()", &slot_5, QMetaData::Private },
	{ "SlotImprimir()", &slot_6, QMetaData::Private },
	{ "SlotActivaMenu(int,int,const QPoint&)", &slot_7, QMetaData::Private },
	{ "SlotEliminaProducto(zProductoCotizar*)", &slot_8, QMetaData::Private },
	{ "SlotNumeroJuegos(const char*)", &slot_9, QMetaData::Private },
	{ "SlotJuegosSeparados(int)", &slot_10, QMetaData::Private },
	{ "SlotDescuentoOrden(const char*)", &slot_11, QMetaData::Private },
	{ "SlotDescuentoProducto(const char*)", &slot_12, QMetaData::Private },
	{ "SlotPrecioProducto()", &slot_13, QMetaData::Private },
	{ "SlotCapturandoCantidad(const QString&)", &slot_14, QMetaData::Private },
	{ "SlotPagoConTarjeta()", &slot_15, QMetaData::Private },
	{ "SlotExistenciaExpendios()", &slot_16, QMetaData::Private },
	{ "SlotCargaCotizacion()", &slot_17, QMetaData::Private },
	{ "SlotImprimirPdf()", &slot_18, QMetaData::Private },
	{ "SlotFaltante()", &slot_19, QMetaData::Private },
	{ "SlotProductoNoValido(zProducto*)", &slot_20, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ "pzProdCotizar", &static_QUType_ptr, "zProductoCotizar", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalNoSePuedeVender", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_1 = {"SignalActualizaMenu", 1, param_signal_1 };
    static const QMetaData signal_tbl[] = {
	{ "SignalNoSePuedeVender(zProductoCotizar*)", &signal_0, QMetaData::Private },
	{ "SignalActualizaMenu(const QString&)", &signal_1, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QManejadorOrden", parentObject,
	slot_tbl, 21,
	signal_tbl, 2,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QManejadorOrden.setMetaObject( metaObj );
    return metaObj;
}

void* QManejadorOrden::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QManejadorOrden" ) )
	return this;
    if ( !qstrcmp( clname, "QtManejadorOrden" ) )
	return (QtManejadorOrden*)this;
    return ManejadorOrden::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalNoSePuedeVender
void QManejadorOrden::SignalNoSePuedeVender( zProductoCotizar* t0 )
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

// SIGNAL SignalActualizaMenu
void QManejadorOrden::SignalActualizaMenu( const QString& t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 1, t0 );
}

bool QManejadorOrden::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotAnexarOrden(); break;
    case 1: SlotCantidad((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 2: SlotSeleccionoProducto((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 3: SlotFocoAProducto(); break;
    case 4: SlotNuevaOrden(); break;
    case 5: SlotRegistrar(); break;
    case 6: SlotImprimir(); break;
    case 7: SlotActivaMenu((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+3))); break;
    case 8: SlotEliminaProducto((zProductoCotizar*)static_QUType_ptr.get(_o+1)); break;
    case 9: SlotNumeroJuegos((const char*)static_QUType_charstar.get(_o+1)); break;
    case 10: SlotJuegosSeparados((int)static_QUType_int.get(_o+1)); break;
    case 11: SlotDescuentoOrden((const char*)static_QUType_charstar.get(_o+1)); break;
    case 12: SlotDescuentoProducto((const char*)static_QUType_charstar.get(_o+1)); break;
    case 13: SlotPrecioProducto(); break;
    case 14: SlotCapturandoCantidad((const QString&)static_QUType_QString.get(_o+1)); break;
    case 15: SlotPagoConTarjeta(); break;
    case 16: SlotExistenciaExpendios(); break;
    case 17: SlotCargaCotizacion(); break;
    case 18: SlotImprimirPdf(); break;
    case 19: SlotFaltante(); break;
    case 20: SlotProductoNoValido((zProducto*)static_QUType_ptr.get(_o+1)); break;
    default:
	return ManejadorOrden::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QManejadorOrden::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalNoSePuedeVender((zProductoCotizar*)static_QUType_ptr.get(_o+1)); break;
    case 1: SignalActualizaMenu((const QString&)static_QUType_QString.get(_o+1)); break;
    default:
	return ManejadorOrden::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QManejadorOrden::qt_property( int id, int f, QVariant* v)
{
    return ManejadorOrden::qt_property( id, f, v);
}

bool QManejadorOrden::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
