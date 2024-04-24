/****************************************************************************
** QtCorteCajaImp meta object code from reading C++ file 'QtCorteCajaImp.h'
**
** Created: Tue Mar 26 12:12:44 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "QtCorteCajaImp.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtCorteCajaImp::className() const
{
    return "QtCorteCajaImp";
}

QMetaObject *QtCorteCajaImp::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtCorteCajaImp( "QtCorteCajaImp", &QtCorteCajaImp::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtCorteCajaImp::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtCorteCajaImp", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtCorteCajaImp::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtCorteCajaImp", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtCorteCajaImp::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QtCorteCaja::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotCaptura", 2, param_slot_0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotCaptura(int,int)", &slot_0, QMetaData::Private }
    };
    static const QUMethod signal_0 = {"SignalCapturoCantidadDenominacion", 0, 0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_1 = {"SignalAgregaGasto", 2, param_signal_1 };
    static const QUMethod signal_2 = {"SignalActualizaImporteGasto", 0, 0 };
    static const QUMethod signal_3 = {"SignalPagoTarjeta", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalCapturoCantidadDenominacion()", &signal_0, QMetaData::Private },
	{ "SignalAgregaGasto(int,int)", &signal_1, QMetaData::Private },
	{ "SignalActualizaImporteGasto()", &signal_2, QMetaData::Private },
	{ "SignalPagoTarjeta()", &signal_3, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtCorteCajaImp", parentObject,
	slot_tbl, 1,
	signal_tbl, 4,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtCorteCajaImp.setMetaObject( metaObj );
    return metaObj;
}

void* QtCorteCajaImp::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtCorteCajaImp" ) )
	return this;
    return QtCorteCaja::qt_cast( clname );
}

// SIGNAL SignalCapturoCantidadDenominacion
void QtCorteCajaImp::SignalCapturoCantidadDenominacion()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalAgregaGasto
void QtCorteCajaImp::SignalAgregaGasto( int t0, int t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 1 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_int.set(o+1,t0);
    static_QUType_int.set(o+2,t1);
    activate_signal( clist, o );
}

// SIGNAL SignalActualizaImporteGasto
void QtCorteCajaImp::SignalActualizaImporteGasto()
{
    activate_signal( staticMetaObject()->signalOffset() + 2 );
}

// SIGNAL SignalPagoTarjeta
void QtCorteCajaImp::SignalPagoTarjeta()
{
    activate_signal( staticMetaObject()->signalOffset() + 3 );
}

bool QtCorteCajaImp::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotCaptura((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    default:
	return QtCorteCaja::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtCorteCajaImp::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalCapturoCantidadDenominacion(); break;
    case 1: SignalAgregaGasto((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 2: SignalActualizaImporteGasto(); break;
    case 3: SignalPagoTarjeta(); break;
    default:
	return QtCorteCaja::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QtCorteCajaImp::qt_property( int id, int f, QVariant* v)
{
    return QtCorteCaja::qt_property( id, f, v);
}

bool QtCorteCajaImp::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
