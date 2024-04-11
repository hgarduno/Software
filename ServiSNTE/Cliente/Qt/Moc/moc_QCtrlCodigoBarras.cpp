/****************************************************************************
** QCtrlCodigoBarras meta object code from reading C++ file 'QCtrlCodigoBarras.h'
**
** Created: Sat Jan 27 16:40:25 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QCtrlCodigoBarras.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCtrlCodigoBarras::className() const
{
    return "QCtrlCodigoBarras";
}

QMetaObject *QCtrlCodigoBarras::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCtrlCodigoBarras( "QCtrlCodigoBarras", &QCtrlCodigoBarras::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCtrlCodigoBarras::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrlCodigoBarras", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCtrlCodigoBarras::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrlCodigoBarras", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCtrlCodigoBarras::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUMethod slot_0 = {"SlotCapturo", 0, 0 };
    static const QUParameter param_slot_1[] = {
	{ "pQStrCodigoBarras", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotCapturandoCodigoBarras", 1, param_slot_1 };
    static const QMetaData slot_tbl[] = {
	{ "SlotCapturo()", &slot_0, QMetaData::Private },
	{ "SlotCapturandoCodigoBarras(const QString&)", &slot_1, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalNuevoCodigoBarras", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ "pzSisRegCodigoBarras", &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod signal_1 = {"SignalCodigoBarras", 1, param_signal_1 };
    static const QUMethod signal_2 = {"SignalCodigoBarrasVacia", 0, 0 };
    static const QUParameter param_signal_3[] = {
	{ 0, &static_QUType_ptr, "zSiscomRegistros", QUParameter::In }
    };
    static const QUMethod signal_3 = {"SignalCodigoBarrasContabilizados", 1, param_signal_3 };
    static const QMetaData signal_tbl[] = {
	{ "SignalNuevoCodigoBarras(const QString&)", &signal_0, QMetaData::Private },
	{ "SignalCodigoBarras(zSiscomRegistro*)", &signal_1, QMetaData::Private },
	{ "SignalCodigoBarrasVacia()", &signal_2, QMetaData::Private },
	{ "SignalCodigoBarrasContabilizados(zSiscomRegistros*)", &signal_3, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCtrlCodigoBarras", parentObject,
	slot_tbl, 2,
	signal_tbl, 4,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCtrlCodigoBarras.setMetaObject( metaObj );
    return metaObj;
}

void* QCtrlCodigoBarras::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCtrlCodigoBarras" ) )
	return this;
    return QWidget::qt_cast( clname );
}

// SIGNAL SignalNuevoCodigoBarras
void QCtrlCodigoBarras::SignalNuevoCodigoBarras( const QString& t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalCodigoBarras
void QCtrlCodigoBarras::SignalCodigoBarras( zSiscomRegistro* t0 )
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

// SIGNAL SignalCodigoBarrasVacia
void QCtrlCodigoBarras::SignalCodigoBarrasVacia()
{
    activate_signal( staticMetaObject()->signalOffset() + 2 );
}

// SIGNAL SignalCodigoBarrasContabilizados
void QCtrlCodigoBarras::SignalCodigoBarrasContabilizados( zSiscomRegistros* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 3 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

bool QCtrlCodigoBarras::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotCapturo(); break;
    case 1: SlotCapturandoCodigoBarras((const QString&)static_QUType_QString.get(_o+1)); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCtrlCodigoBarras::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalNuevoCodigoBarras((const QString&)static_QUType_QString.get(_o+1)); break;
    case 1: SignalCodigoBarras((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 2: SignalCodigoBarrasVacia(); break;
    case 3: SignalCodigoBarrasContabilizados((zSiscomRegistros*)static_QUType_ptr.get(_o+1)); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QCtrlCodigoBarras::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool QCtrlCodigoBarras::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
