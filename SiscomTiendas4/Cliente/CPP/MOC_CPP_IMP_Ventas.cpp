/****************************************************************************
** QVentas meta object code from reading C++ file 'IMP_Ventas.h'
**
** Created: Thu Apr 11 22:09:38 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_Ventas.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QVentas::className() const
{
    return "QVentas";
}

QMetaObject *QVentas::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QVentas( "QVentas", &QVentas::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QVentas::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QVentas", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QVentas::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QVentas", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QVentas::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = Ventas::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "CQSisCliente", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotFisica", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_ptr, "CQSisCliente", QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotMoral", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_ptr, "CQSisProducto", QUParameter::In }
    };
    static const QUMethod slot_2 = {"SlotProducto", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_ptr, "CQSisPrecio", QUParameter::In }
    };
    static const QUMethod slot_3 = {"SlotPrecio", 1, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ 0, &static_QUType_ptr, "CQSisFormaPago", QUParameter::In }
    };
    static const QUMethod slot_4 = {"SlotFormaPago", 1, param_slot_4 };
    static const QUMethod slot_5 = {"SlotCotiza", 0, 0 };
    static const QUMethod slot_6 = {"SlotAnexar", 0, 0 };
    static const QUParameter param_slot_7[] = {
	{ 0, &static_QUType_ptr, "CQSisContacto", QUParameter::In }
    };
    static const QUMethod slot_7 = {"SlotContacto", 1, param_slot_7 };
    static const QUMethod slot_8 = {"SlotRegistra", 0, 0 };
    static const QUMethod slot_9 = {"SlotImprime", 0, 0 };
    static const QUMethod slot_10 = {"SlotEliminar", 0, 0 };
    static const QUParameter param_slot_11[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_11 = {"SlotCambiaDato", 4, param_slot_11 };
    static const QUMethod slot_12 = {"SlotCalculaCantidad", 0, 0 };
    static const QUParameter param_slot_13[] = {
	{ 0, &static_QUType_ptr, "CQSisPrecio", QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_13 = {"SlotCambiaPrecio", 3, param_slot_13 };
    static const QUParameter param_slot_14[] = {
	{ 0, &static_QUType_ptr, "CQSisProducto", QUParameter::In }
    };
    static const QUMethod slot_14 = {"SlotSeleccionandoProducto", 1, param_slot_14 };
    static const QMetaData slot_tbl[] = {
	{ "SlotFisica(CQSisCliente*)", &slot_0, QMetaData::Private },
	{ "SlotMoral(CQSisCliente*)", &slot_1, QMetaData::Private },
	{ "SlotProducto(CQSisProducto*)", &slot_2, QMetaData::Private },
	{ "SlotPrecio(CQSisPrecio*)", &slot_3, QMetaData::Private },
	{ "SlotFormaPago(CQSisFormaPago*)", &slot_4, QMetaData::Private },
	{ "SlotCotiza()", &slot_5, QMetaData::Private },
	{ "SlotAnexar()", &slot_6, QMetaData::Private },
	{ "SlotContacto(CQSisContacto*)", &slot_7, QMetaData::Private },
	{ "SlotRegistra()", &slot_8, QMetaData::Private },
	{ "SlotImprime()", &slot_9, QMetaData::Private },
	{ "SlotEliminar()", &slot_10, QMetaData::Private },
	{ "SlotCambiaDato(int,int,int,const QPoint&)", &slot_11, QMetaData::Private },
	{ "SlotCalculaCantidad()", &slot_12, QMetaData::Private },
	{ "SlotCambiaPrecio(CQSisPrecio*,int,int)", &slot_13, QMetaData::Private },
	{ "SlotSeleccionandoProducto(CQSisProducto*)", &slot_14, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "QVentas", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalRealizoOperacion", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod signal_1 = {"SignalTerminar", 1, param_signal_1 };
    static const QMetaData signal_tbl[] = {
	{ "SignalRealizoOperacion(QVentas*)", &signal_0, QMetaData::Private },
	{ "SignalTerminar(QWidget*)", &signal_1, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QVentas", parentObject,
	slot_tbl, 15,
	signal_tbl, 2,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QVentas.setMetaObject( metaObj );
    return metaObj;
}

void* QVentas::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QVentas" ) )
	return this;
    return Ventas::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalRealizoOperacion
void QVentas::SignalRealizoOperacion( QVentas* t0 )
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

// SIGNAL SignalTerminar
void QVentas::SignalTerminar( QWidget* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 1 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

bool QVentas::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotFisica((CQSisCliente*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotMoral((CQSisCliente*)static_QUType_ptr.get(_o+1)); break;
    case 2: SlotProducto((CQSisProducto*)static_QUType_ptr.get(_o+1)); break;
    case 3: SlotPrecio((CQSisPrecio*)static_QUType_ptr.get(_o+1)); break;
    case 4: SlotFormaPago((CQSisFormaPago*)static_QUType_ptr.get(_o+1)); break;
    case 5: SlotCotiza(); break;
    case 6: SlotAnexar(); break;
    case 7: SlotContacto((CQSisContacto*)static_QUType_ptr.get(_o+1)); break;
    case 8: SlotRegistra(); break;
    case 9: SlotImprime(); break;
    case 10: SlotEliminar(); break;
    case 11: SlotCambiaDato((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 12: SlotCalculaCantidad(); break;
    case 13: SlotCambiaPrecio((CQSisPrecio*)static_QUType_ptr.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3)); break;
    case 14: SlotSeleccionandoProducto((CQSisProducto*)static_QUType_ptr.get(_o+1)); break;
    default:
	return Ventas::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QVentas::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalRealizoOperacion((QVentas*)static_QUType_ptr.get(_o+1)); break;
    case 1: SignalTerminar((QWidget*)static_QUType_ptr.get(_o+1)); break;
    default:
	return Ventas::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QVentas::qt_property( int id, int f, QVariant* v)
{
    return Ventas::qt_property( id, f, v);
}

bool QVentas::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
