/****************************************************************************
** QCtrlTipoViviendaSS meta object code from reading C++ file 'QCtrlTipoViviendaSS.h'
**
** Created: Tue Jun 24 09:00:04 2025
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QCtrlTipoViviendaSS.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCtrlTipoViviendaSS::className() const
{
    return "QCtrlTipoViviendaSS";
}

QMetaObject *QCtrlTipoViviendaSS::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCtrlTipoViviendaSS( "QCtrlTipoViviendaSS", &QCtrlTipoViviendaSS::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCtrlTipoViviendaSS::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrlTipoViviendaSS", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCtrlTipoViviendaSS::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrlTipoViviendaSS", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCtrlTipoViviendaSS::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotTipoVivienda", 1, param_slot_0 };
    static const QUMethod slot_1 = {"SlotCapturo", 0, 0 };
    static const QUParameter param_slot_2[] = {
	{ "pQStrTipoDocumento", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"SlotCapturandoTipoVivienda", 1, param_slot_2 };
    static const QMetaData slot_tbl[] = {
	{ "SlotTipoVivienda(int)", &slot_0, QMetaData::Private },
	{ "SlotCapturo()", &slot_1, QMetaData::Private },
	{ "SlotCapturandoTipoVivienda(const QString&)", &slot_2, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalNuevoTipoVivienda", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ "pzSisRegTipoDocumento", &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod signal_1 = {"SignalTipoVivienda", 1, param_signal_1 };
    static const QUMethod signal_2 = {"SignalTipoViviendaVacia", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalNuevoTipoVivienda(const QString&)", &signal_0, QMetaData::Private },
	{ "SignalTipoVivienda(zSiscomRegistro*)", &signal_1, QMetaData::Private },
	{ "SignalTipoViviendaVacia()", &signal_2, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCtrlTipoViviendaSS", parentObject,
	slot_tbl, 3,
	signal_tbl, 3,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCtrlTipoViviendaSS.setMetaObject( metaObj );
    return metaObj;
}

void* QCtrlTipoViviendaSS::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCtrlTipoViviendaSS" ) )
	return this;
    return QWidget::qt_cast( clname );
}

// SIGNAL SignalNuevoTipoVivienda
void QCtrlTipoViviendaSS::SignalNuevoTipoVivienda( const QString& t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalTipoVivienda
void QCtrlTipoViviendaSS::SignalTipoVivienda( zSiscomRegistro* t0 )
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

// SIGNAL SignalTipoViviendaVacia
void QCtrlTipoViviendaSS::SignalTipoViviendaVacia()
{
    activate_signal( staticMetaObject()->signalOffset() + 2 );
}

bool QCtrlTipoViviendaSS::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotTipoVivienda((int)static_QUType_int.get(_o+1)); break;
    case 1: SlotCapturo(); break;
    case 2: SlotCapturandoTipoVivienda((const QString&)static_QUType_QString.get(_o+1)); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCtrlTipoViviendaSS::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalNuevoTipoVivienda((const QString&)static_QUType_QString.get(_o+1)); break;
    case 1: SignalTipoVivienda((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 2: SignalTipoViviendaVacia(); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QCtrlTipoViviendaSS::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool QCtrlTipoViviendaSS::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
