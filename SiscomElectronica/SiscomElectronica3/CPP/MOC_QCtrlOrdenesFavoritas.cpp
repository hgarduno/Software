/****************************************************************************
** QCtrlOrdenesFavoritas meta object code from reading C++ file 'QCtrlOrdenesFavoritas.h'
**
** Created: Sun Jan 28 15:36:12 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QCtrlOrdenesFavoritas.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCtrlOrdenesFavoritas::className() const
{
    return "QCtrlOrdenesFavoritas";
}

QMetaObject *QCtrlOrdenesFavoritas::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCtrlOrdenesFavoritas( "QCtrlOrdenesFavoritas", &QCtrlOrdenesFavoritas::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCtrlOrdenesFavoritas::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrlOrdenesFavoritas", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCtrlOrdenesFavoritas::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrlOrdenesFavoritas", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCtrlOrdenesFavoritas::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QGroupBox::staticMetaObject();
    static const QUMethod slot_0 = {"SlotOrden", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotOrden()", &slot_0, QMetaData::Public }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "QtSisBotonOrden", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalOrden", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_ptr, "zOrdenVenta", QUParameter::In }
    };
    static const QUMethod signal_1 = {"SignalOrdenVenta", 1, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ 0, &static_QUType_ptr, "QtSisBotonOrden", QUParameter::In }
    };
    static const QUMethod signal_2 = {"SignalEliminaOrden", 1, param_signal_2 };
    static const QMetaData signal_tbl[] = {
	{ "SignalOrden(QtSisBotonOrden*)", &signal_0, QMetaData::Public },
	{ "SignalOrdenVenta(zOrdenVenta*)", &signal_1, QMetaData::Public },
	{ "SignalEliminaOrden(QtSisBotonOrden*)", &signal_2, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCtrlOrdenesFavoritas", parentObject,
	slot_tbl, 1,
	signal_tbl, 3,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCtrlOrdenesFavoritas.setMetaObject( metaObj );
    return metaObj;
}

void* QCtrlOrdenesFavoritas::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCtrlOrdenesFavoritas" ) )
	return this;
    return QGroupBox::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalOrden
void QCtrlOrdenesFavoritas::SignalOrden( QtSisBotonOrden* t0 )
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

// SIGNAL SignalOrdenVenta
void QCtrlOrdenesFavoritas::SignalOrdenVenta( zOrdenVenta* t0 )
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

// SIGNAL SignalEliminaOrden
void QCtrlOrdenesFavoritas::SignalEliminaOrden( QtSisBotonOrden* t0 )
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

bool QCtrlOrdenesFavoritas::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotOrden(); break;
    default:
	return QGroupBox::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCtrlOrdenesFavoritas::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalOrden((QtSisBotonOrden*)static_QUType_ptr.get(_o+1)); break;
    case 1: SignalOrdenVenta((zOrdenVenta*)static_QUType_ptr.get(_o+1)); break;
    case 2: SignalEliminaOrden((QtSisBotonOrden*)static_QUType_ptr.get(_o+1)); break;
    default:
	return QGroupBox::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QCtrlOrdenesFavoritas::qt_property( int id, int f, QVariant* v)
{
    return QGroupBox::qt_property( id, f, v);
}

bool QCtrlOrdenesFavoritas::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
