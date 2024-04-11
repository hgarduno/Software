/****************************************************************************
** QCaja meta object code from reading C++ file 'IMP_Caja.h'
**
** Created: Wed Apr 10 20:52:40 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_Caja.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCaja::className() const
{
    return "QCaja";
}

QMetaObject *QCaja::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCaja( "QCaja", &QCaja::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCaja::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCaja", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCaja::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCaja", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCaja::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = Caja::staticMetaObject();
    static const QUMethod slot_0 = {"SlotActualizaOrdenes", 0, 0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_ptr, "QIconViewItem", QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotSobreLaOrden", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_ptr, "QIconViewItem", QUParameter::In }
    };
    static const QUMethod slot_2 = {"SlotVendeOrden", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_ptr, "QIconViewItem", QUParameter::In }
    };
    static const QUMethod slot_3 = {"SlotCargaOrden", 1, param_slot_3 };
    static const QUMethod slot_4 = {"SlotModificaOrden", 0, 0 };
    static const QUParameter param_slot_5[] = {
	{ 0, &static_QUType_ptr, "QIconViewItem", QUParameter::In }
    };
    static const QUMethod slot_5 = {"SlotOtraOrdenSeleccionada", 1, param_slot_5 };
    static const QMetaData slot_tbl[] = {
	{ "SlotActualizaOrdenes()", &slot_0, QMetaData::Private },
	{ "SlotSobreLaOrden(QIconViewItem*)", &slot_1, QMetaData::Private },
	{ "SlotVendeOrden(QIconViewItem*)", &slot_2, QMetaData::Private },
	{ "SlotCargaOrden(QIconViewItem*)", &slot_3, QMetaData::Private },
	{ "SlotModificaOrden()", &slot_4, QMetaData::Private },
	{ "SlotOtraOrdenSeleccionada(QIconViewItem*)", &slot_5, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_charstar, 0, QUParameter::In },
	{ 0, &static_QUType_ptr, "ProductosE", QUParameter::In },
	{ 0, &static_QUType_ptr, "Persona", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalModificaOrdenCaja", 3, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalModificaOrdenCaja(const char*,ProductosE*,Persona*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCaja", parentObject,
	slot_tbl, 6,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCaja.setMetaObject( metaObj );
    return metaObj;
}

void* QCaja::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCaja" ) )
	return this;
    return Caja::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalModificaOrdenCaja
void QCaja::SignalModificaOrdenCaja( const char* t0, ProductosE* t1, Persona* t2 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[4];
    static_QUType_charstar.set(o+1,t0);
    static_QUType_ptr.set(o+2,t1);
    static_QUType_ptr.set(o+3,t2);
    activate_signal( clist, o );
}

bool QCaja::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotActualizaOrdenes(); break;
    case 1: SlotSobreLaOrden((QIconViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 2: SlotVendeOrden((QIconViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 3: SlotCargaOrden((QIconViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 4: SlotModificaOrden(); break;
    case 5: SlotOtraOrdenSeleccionada((QIconViewItem*)static_QUType_ptr.get(_o+1)); break;
    default:
	return Caja::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCaja::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalModificaOrdenCaja((const char*)static_QUType_charstar.get(_o+1),(ProductosE*)static_QUType_ptr.get(_o+2),(Persona*)static_QUType_ptr.get(_o+3)); break;
    default:
	return Caja::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QCaja::qt_property( int id, int f, QVariant* v)
{
    return Caja::qt_property( id, f, v);
}

bool QCaja::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
