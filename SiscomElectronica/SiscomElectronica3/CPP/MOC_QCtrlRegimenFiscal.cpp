/****************************************************************************
** QCtrlRegimenFiscal meta object code from reading C++ file 'QCtrlRegimenFiscal.h'
**
** Created: Sun Jan 28 15:36:12 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QCtrlRegimenFiscal.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCtrlRegimenFiscal::className() const
{
    return "QCtrlRegimenFiscal";
}

QMetaObject *QCtrlRegimenFiscal::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCtrlRegimenFiscal( "QCtrlRegimenFiscal", &QCtrlRegimenFiscal::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCtrlRegimenFiscal::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrlRegimenFiscal", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCtrlRegimenFiscal::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrlRegimenFiscal", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCtrlRegimenFiscal::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotSeleccionando", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotSelecciono", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"SlotCapturandoRegimenFiscal", 1, param_slot_2 };
    static const QMetaData slot_tbl[] = {
	{ "SlotSeleccionando(int)", &slot_0, QMetaData::Private },
	{ "SlotSelecciono(int)", &slot_1, QMetaData::Private },
	{ "SlotCapturandoRegimenFiscal(const QString&)", &slot_2, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalSeleccionando", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod signal_1 = {"SignalSelecciono", 1, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_2 = {"SignalCapturandoRegimenFiscal", 1, param_signal_2 };
    static const QMetaData signal_tbl[] = {
	{ "SignalSeleccionando(zSiscomRegistro*)", &signal_0, QMetaData::Private },
	{ "SignalSelecciono(zSiscomRegistro*)", &signal_1, QMetaData::Private },
	{ "SignalCapturandoRegimenFiscal(const QString&)", &signal_2, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCtrlRegimenFiscal", parentObject,
	slot_tbl, 3,
	signal_tbl, 3,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCtrlRegimenFiscal.setMetaObject( metaObj );
    return metaObj;
}

void* QCtrlRegimenFiscal::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCtrlRegimenFiscal" ) )
	return this;
    return QWidget::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalSeleccionando
void QCtrlRegimenFiscal::SignalSeleccionando( zSiscomRegistro* t0 )
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

// SIGNAL SignalSelecciono
void QCtrlRegimenFiscal::SignalSelecciono( zSiscomRegistro* t0 )
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

// SIGNAL SignalCapturandoRegimenFiscal
void QCtrlRegimenFiscal::SignalCapturandoRegimenFiscal( const QString& t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 2, t0 );
}

bool QCtrlRegimenFiscal::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotSeleccionando((int)static_QUType_int.get(_o+1)); break;
    case 1: SlotSelecciono((int)static_QUType_int.get(_o+1)); break;
    case 2: SlotCapturandoRegimenFiscal((const QString&)static_QUType_QString.get(_o+1)); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCtrlRegimenFiscal::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalSeleccionando((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 1: SignalSelecciono((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 2: SignalCapturandoRegimenFiscal((const QString&)static_QUType_QString.get(_o+1)); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QCtrlRegimenFiscal::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool QCtrlRegimenFiscal::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
