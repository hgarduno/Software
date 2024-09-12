/****************************************************************************
** QCtrlVendedores meta object code from reading C++ file 'QCtrlVendedores.h'
**
** Created: Thu Aug 15 00:51:09 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QCtrlVendedores.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCtrlVendedores::className() const
{
    return "QCtrlVendedores";
}

QMetaObject *QCtrlVendedores::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCtrlVendedores( "QCtrlVendedores", &QCtrlVendedores::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCtrlVendedores::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrlVendedores", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCtrlVendedores::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrlVendedores", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCtrlVendedores::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotVendedor", 1, param_slot_0 };
    static const QUMethod slot_1 = {"SlotCapturo", 0, 0 };
    static const QUParameter param_slot_2[] = {
	{ "pQStrVendedor", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"SlotCapturandoVendedor", 1, param_slot_2 };
    static const QMetaData slot_tbl[] = {
	{ "SlotVendedor(int)", &slot_0, QMetaData::Private },
	{ "SlotCapturo()", &slot_1, QMetaData::Private },
	{ "SlotCapturandoVendedor(const QString&)", &slot_2, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalNuevoVendedor", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ "pzSisRegVendedor", &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod signal_1 = {"SignalVendedor", 1, param_signal_1 };
    static const QUMethod signal_2 = {"SignalVendedorVacia", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalNuevoVendedor(const QString&)", &signal_0, QMetaData::Private },
	{ "SignalVendedor(zSiscomRegistro*)", &signal_1, QMetaData::Private },
	{ "SignalVendedorVacia()", &signal_2, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCtrlVendedores", parentObject,
	slot_tbl, 3,
	signal_tbl, 3,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCtrlVendedores.setMetaObject( metaObj );
    return metaObj;
}

void* QCtrlVendedores::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCtrlVendedores" ) )
	return this;
    return QWidget::qt_cast( clname );
}

// SIGNAL SignalNuevoVendedor
void QCtrlVendedores::SignalNuevoVendedor( const QString& t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalVendedor
void QCtrlVendedores::SignalVendedor( zSiscomRegistro* t0 )
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

// SIGNAL SignalVendedorVacia
void QCtrlVendedores::SignalVendedorVacia()
{
    activate_signal( staticMetaObject()->signalOffset() + 2 );
}

bool QCtrlVendedores::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotVendedor((int)static_QUType_int.get(_o+1)); break;
    case 1: SlotCapturo(); break;
    case 2: SlotCapturandoVendedor((const QString&)static_QUType_QString.get(_o+1)); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCtrlVendedores::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalNuevoVendedor((const QString&)static_QUType_QString.get(_o+1)); break;
    case 1: SignalVendedor((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 2: SignalVendedorVacia(); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QCtrlVendedores::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool QCtrlVendedores::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
