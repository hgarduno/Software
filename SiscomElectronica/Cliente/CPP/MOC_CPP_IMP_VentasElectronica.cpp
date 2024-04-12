/****************************************************************************
** QVentasElectronica meta object code from reading C++ file 'IMP_VentasElectronica.h'
**
** Created: Thu Apr 11 21:52:16 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_VentasElectronica.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QVentasElectronica::className() const
{
    return "QVentasElectronica";
}

QMetaObject *QVentasElectronica::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QVentasElectronica( "QVentasElectronica", &QVentasElectronica::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QVentasElectronica::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QVentasElectronica", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QVentasElectronica::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QVentasElectronica", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QVentasElectronica::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = VentasElectronica::staticMetaObject();
    static const QUMethod slot_0 = {"S_NuevaOrden", 0, 0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_ptr, "QOrdenElectronica", QUParameter::In }
    };
    static const QUMethod slot_1 = {"S_VendeOrden", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_ptr, "QIconViewItem", QUParameter::In }
    };
    static const QUMethod slot_2 = {"S_SelOrden", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_ptr, "ProductoE", QUParameter::In }
    };
    static const QUMethod slot_3 = {"S_AnexarALaOrden", 1, param_slot_3 };
    static const QUMethod slot_4 = {"S_CotizaPractica", 0, 0 };
    static const QUParameter param_slot_5[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_ptr, "ProductosE", QUParameter::InOut }
    };
    static const QUMethod slot_5 = {"S_JuegosSeparados", 2, param_slot_5 };
    static const QUParameter param_slot_6[] = {
	{ 0, &static_QUType_ptr, "QOrdenElectronica", QUParameter::In }
    };
    static const QUMethod slot_6 = {"S_CancelarVenta", 1, param_slot_6 };
    static const QUMethod slot_7 = {"S_VenderTodo", 0, 0 };
    static const QUMethod slot_8 = {"S_RegProductoSinOrden", 0, 0 };
    static const QUParameter param_slot_9[] = {
	{ 0, &static_QUType_charstar, 0, QUParameter::In },
	{ 0, &static_QUType_ptr, "ProductosE", QUParameter::In },
	{ 0, &static_QUType_ptr, "Persona", QUParameter::In }
    };
    static const QUMethod slot_9 = {"S_ModificaOrdenCajaCentral", 3, param_slot_9 };
    static const QMetaData slot_tbl[] = {
	{ "S_NuevaOrden()", &slot_0, QMetaData::Private },
	{ "S_VendeOrden(QOrdenElectronica*)", &slot_1, QMetaData::Private },
	{ "S_SelOrden(QIconViewItem*)", &slot_2, QMetaData::Private },
	{ "S_AnexarALaOrden(ProductoE*)", &slot_3, QMetaData::Private },
	{ "S_CotizaPractica()", &slot_4, QMetaData::Private },
	{ "S_JuegosSeparados(int,ProductosE&)", &slot_5, QMetaData::Private },
	{ "S_CancelarVenta(QOrdenElectronica*)", &slot_6, QMetaData::Private },
	{ "S_VenderTodo()", &slot_7, QMetaData::Private },
	{ "S_RegProductoSinOrden()", &slot_8, QMetaData::Private },
	{ "S_ModificaOrdenCajaCentral(const char*,ProductosE*,Persona*)", &slot_9, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalTerminar", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalTerminar(QWidget*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QVentasElectronica", parentObject,
	slot_tbl, 10,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QVentasElectronica.setMetaObject( metaObj );
    return metaObj;
}

void* QVentasElectronica::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QVentasElectronica" ) )
	return this;
    return VentasElectronica::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalTerminar
void QVentasElectronica::SignalTerminar( QWidget* t0 )
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

bool QVentasElectronica::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: S_NuevaOrden(); break;
    case 1: S_VendeOrden((QOrdenElectronica*)static_QUType_ptr.get(_o+1)); break;
    case 2: S_SelOrden((QIconViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 3: S_AnexarALaOrden((ProductoE*)static_QUType_ptr.get(_o+1)); break;
    case 4: S_CotizaPractica(); break;
    case 5: S_JuegosSeparados((int)static_QUType_int.get(_o+1),(ProductosE&)*((ProductosE*)static_QUType_ptr.get(_o+2))); break;
    case 6: S_CancelarVenta((QOrdenElectronica*)static_QUType_ptr.get(_o+1)); break;
    case 7: S_VenderTodo(); break;
    case 8: S_RegProductoSinOrden(); break;
    case 9: S_ModificaOrdenCajaCentral((const char*)static_QUType_charstar.get(_o+1),(ProductosE*)static_QUType_ptr.get(_o+2),(Persona*)static_QUType_ptr.get(_o+3)); break;
    default:
	return VentasElectronica::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QVentasElectronica::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalTerminar((QWidget*)static_QUType_ptr.get(_o+1)); break;
    default:
	return VentasElectronica::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QVentasElectronica::qt_property( int id, int f, QVariant* v)
{
    return VentasElectronica::qt_property( id, f, v);
}

bool QVentasElectronica::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
