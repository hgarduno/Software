/****************************************************************************
** QCtrlEstantes meta object code from reading C++ file 'QCtrlEstantes.h'
**
** Created: Fri Apr 12 21:24:42 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QCtrlEstantes.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCtrlEstantes::className() const
{
    return "QCtrlEstantes";
}

QMetaObject *QCtrlEstantes::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCtrlEstantes( "QCtrlEstantes", &QCtrlEstantes::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCtrlEstantes::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrlEstantes", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCtrlEstantes::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrlEstantes", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCtrlEstantes::staticMetaObject()
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
    static const QUMethod slot_2 = {"SlotSeleccionoRFC", 0, 0 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"SlotCambioRFC", 1, param_slot_3 };
    static const QUMethod slot_4 = {"SlotCapturoRfc", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotSeleccionando(int)", &slot_0, QMetaData::Private },
	{ "SlotSelecciono(int)", &slot_1, QMetaData::Private },
	{ "SlotSeleccionoRFC()", &slot_2, QMetaData::Private },
	{ "SlotCambioRFC(const QString&)", &slot_3, QMetaData::Private },
	{ "SlotCapturoRfc()", &slot_4, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalSeleccionando", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod signal_1 = {"SignalSelecciono", 1, param_signal_1 };
    static const QMetaData signal_tbl[] = {
	{ "SignalSeleccionando(zSiscomRegistro*)", &signal_0, QMetaData::Private },
	{ "SignalSelecciono(zSiscomRegistro*)", &signal_1, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCtrlEstantes", parentObject,
	slot_tbl, 5,
	signal_tbl, 2,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCtrlEstantes.setMetaObject( metaObj );
    return metaObj;
}

void* QCtrlEstantes::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCtrlEstantes" ) )
	return this;
    return QWidget::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalSeleccionando
void QCtrlEstantes::SignalSeleccionando( zSiscomRegistro* t0 )
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
void QCtrlEstantes::SignalSelecciono( zSiscomRegistro* t0 )
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

bool QCtrlEstantes::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotSeleccionando((int)static_QUType_int.get(_o+1)); break;
    case 1: SlotSelecciono((int)static_QUType_int.get(_o+1)); break;
    case 2: SlotSeleccionoRFC(); break;
    case 3: SlotCambioRFC((const QString&)static_QUType_QString.get(_o+1)); break;
    case 4: SlotCapturoRfc(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCtrlEstantes::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalSeleccionando((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 1: SignalSelecciono((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QCtrlEstantes::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool QCtrlEstantes::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
