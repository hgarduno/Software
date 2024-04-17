/****************************************************************************
** QCtrlCotizas meta object code from reading C++ file 'QCtrlCotizas.h'
**
** Created: Fri Apr 12 21:36:28 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QCtrlCotizas.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCtrlCotizas::className() const
{
    return "QCtrlCotizas";
}

QMetaObject *QCtrlCotizas::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCtrlCotizas( "QCtrlCotizas", &QCtrlCotizas::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCtrlCotizas::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrlCotizas", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCtrlCotizas::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrlCotizas", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCtrlCotizas::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "CQSisCliente", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotFisica", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_ptr, "CQSisCliente", QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotMoral", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_ptr, "CQSisFormaPago", QUParameter::In }
    };
    static const QUMethod slot_2 = {"SlotFormaPago", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_ptr, "CQSisPrecio", QUParameter::In }
    };
    static const QUMethod slot_3 = {"SlotPrecio", 1, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ 0, &static_QUType_ptr, "CQSisProducto", QUParameter::In }
    };
    static const QUMethod slot_4 = {"SlotProducto", 1, param_slot_4 };
    static const QUMethod slot_5 = {"SlotCotiza", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotFisica(CQSisCliente*)", &slot_0, QMetaData::Private },
	{ "SlotMoral(CQSisCliente*)", &slot_1, QMetaData::Private },
	{ "SlotFormaPago(CQSisFormaPago*)", &slot_2, QMetaData::Private },
	{ "SlotPrecio(CQSisPrecio*)", &slot_3, QMetaData::Private },
	{ "SlotProducto(CQSisProducto*)", &slot_4, QMetaData::Private },
	{ "SlotCotiza()", &slot_5, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "CQSisCliente", QUParameter::In },
	{ 0, &static_QUType_ptr, "CQSisFormaPago", QUParameter::In },
	{ 0, &static_QUType_ptr, "CQSisPrecio", QUParameter::In },
	{ 0, &static_QUType_ptr, "CQSisProducto", QUParameter::In },
	{ 0, &static_QUType_ptr, "CQSisProdCotiza", QUParameter::In },
	{ 0, &static_QUType_ptr, "CQSisContacto", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalCotizacion", 6, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_ptr, "CQSisCliente", QUParameter::In }
    };
    static const QUMethod signal_1 = {"SignalClienteFisica", 1, param_signal_1 };
    static const QMetaData signal_tbl[] = {
	{ "SignalCotizacion(CQSisCliente*,CQSisFormaPago*,CQSisPrecio*,CQSisProducto*,CQSisProdCotiza*,CQSisContacto*)", &signal_0, QMetaData::Private },
	{ "SignalClienteFisica(CQSisCliente*)", &signal_1, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCtrlCotizas", parentObject,
	slot_tbl, 6,
	signal_tbl, 2,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCtrlCotizas.setMetaObject( metaObj );
    return metaObj;
}

void* QCtrlCotizas::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCtrlCotizas" ) )
	return this;
    return QWidget::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalCotizacion
void QCtrlCotizas::SignalCotizacion( CQSisCliente* t0, CQSisFormaPago* t1, CQSisPrecio* t2, CQSisProducto* t3, CQSisProdCotiza* t4, CQSisContacto* t5 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[7];
    static_QUType_ptr.set(o+1,t0);
    static_QUType_ptr.set(o+2,t1);
    static_QUType_ptr.set(o+3,t2);
    static_QUType_ptr.set(o+4,t3);
    static_QUType_ptr.set(o+5,t4);
    static_QUType_ptr.set(o+6,t5);
    activate_signal( clist, o );
}

// SIGNAL SignalClienteFisica
void QCtrlCotizas::SignalClienteFisica( CQSisCliente* t0 )
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

bool QCtrlCotizas::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotFisica((CQSisCliente*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotMoral((CQSisCliente*)static_QUType_ptr.get(_o+1)); break;
    case 2: SlotFormaPago((CQSisFormaPago*)static_QUType_ptr.get(_o+1)); break;
    case 3: SlotPrecio((CQSisPrecio*)static_QUType_ptr.get(_o+1)); break;
    case 4: SlotProducto((CQSisProducto*)static_QUType_ptr.get(_o+1)); break;
    case 5: SlotCotiza(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCtrlCotizas::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalCotizacion((CQSisCliente*)static_QUType_ptr.get(_o+1),(CQSisFormaPago*)static_QUType_ptr.get(_o+2),(CQSisPrecio*)static_QUType_ptr.get(_o+3),(CQSisProducto*)static_QUType_ptr.get(_o+4),(CQSisProdCotiza*)static_QUType_ptr.get(_o+5),(CQSisContacto*)static_QUType_ptr.get(_o+6)); break;
    case 1: SignalClienteFisica((CQSisCliente*)static_QUType_ptr.get(_o+1)); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QCtrlCotizas::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool QCtrlCotizas::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
