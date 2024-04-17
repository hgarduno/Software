/****************************************************************************
** QCtrlProductos meta object code from reading C++ file 'QCtrlProductos.h'
**
** Created: Fri Apr 12 21:36:28 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QCtrlProductos.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCtrlProductos::className() const
{
    return "QCtrlProductos";
}

QMetaObject *QCtrlProductos::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCtrlProductos( "QCtrlProductos", &QCtrlProductos::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCtrlProductos::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrlProductos", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCtrlProductos::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrlProductos", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCtrlProductos::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotProducto", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotSeleccionandoProducto", 1, param_slot_1 };
    static const QMetaData slot_tbl[] = {
	{ "SlotProducto(int)", &slot_0, QMetaData::Private },
	{ "SlotSeleccionandoProducto(int)", &slot_1, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "CQSisProducto", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalProductos", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_ptr, "CQSisProducto", QUParameter::In }
    };
    static const QUMethod signal_1 = {"SignalSeleccionandoProducto", 1, param_signal_1 };
    static const QMetaData signal_tbl[] = {
	{ "SignalProductos(CQSisProducto*)", &signal_0, QMetaData::Private },
	{ "SignalSeleccionandoProducto(CQSisProducto*)", &signal_1, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCtrlProductos", parentObject,
	slot_tbl, 2,
	signal_tbl, 2,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCtrlProductos.setMetaObject( metaObj );
    return metaObj;
}

void* QCtrlProductos::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCtrlProductos" ) )
	return this;
    return QWidget::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalProductos
void QCtrlProductos::SignalProductos( CQSisProducto* t0 )
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

// SIGNAL SignalSeleccionandoProducto
void QCtrlProductos::SignalSeleccionandoProducto( CQSisProducto* t0 )
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

bool QCtrlProductos::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotProducto((int)static_QUType_int.get(_o+1)); break;
    case 1: SlotSeleccionandoProducto((int)static_QUType_int.get(_o+1)); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCtrlProductos::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalProductos((CQSisProducto*)static_QUType_ptr.get(_o+1)); break;
    case 1: SignalSeleccionandoProducto((CQSisProducto*)static_QUType_ptr.get(_o+1)); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QCtrlProductos::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool QCtrlProductos::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
