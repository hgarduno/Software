/****************************************************************************
** QCaja meta object code from reading C++ file 'IMP_Caja.h'
**
** Created: Thu Apr 11 20:30:21 2024
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
    static const QUMethod slot_0 = {"SlotOrdenes", 0, 0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_ptr, "CQSisOrden", QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotOrden", 1, param_slot_1 };
    static const QUMethod slot_2 = {"SlotMOrden", 0, 0 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_ptr, "QVentas", QUParameter::In }
    };
    static const QUMethod slot_3 = {"SlotRealizoOperacion", 1, param_slot_3 };
    static const QUMethod slot_4 = {"SlotRegistraVenta", 0, 0 };
    static const QUMethod slot_5 = {"SlotPasaFocoFechaFin", 0, 0 };
    static const QUMethod slot_6 = {"SlotPasaFocoOrdenes", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotOrdenes()", &slot_0, QMetaData::Private },
	{ "SlotOrden(CQSisOrden*)", &slot_1, QMetaData::Private },
	{ "SlotMOrden()", &slot_2, QMetaData::Private },
	{ "SlotRealizoOperacion(QVentas*)", &slot_3, QMetaData::Private },
	{ "SlotRegistraVenta()", &slot_4, QMetaData::Private },
	{ "SlotPasaFocoFechaFin()", &slot_5, QMetaData::Private },
	{ "SlotPasaFocoOrdenes()", &slot_6, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalTerminar", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalTerminar(QWidget*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCaja", parentObject,
	slot_tbl, 7,
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

// SIGNAL SignalTerminar
void QCaja::SignalTerminar( QWidget* t0 )
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

bool QCaja::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotOrdenes(); break;
    case 1: SlotOrden((CQSisOrden*)static_QUType_ptr.get(_o+1)); break;
    case 2: SlotMOrden(); break;
    case 3: SlotRealizoOperacion((QVentas*)static_QUType_ptr.get(_o+1)); break;
    case 4: SlotRegistraVenta(); break;
    case 5: SlotPasaFocoFechaFin(); break;
    case 6: SlotPasaFocoOrdenes(); break;
    default:
	return Caja::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCaja::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalTerminar((QWidget*)static_QUType_ptr.get(_o+1)); break;
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
