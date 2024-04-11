/****************************************************************************
** QCtrlPerfilesSS meta object code from reading C++ file 'QCtrlPerfilesSS.h'
**
** Created: Thu Apr 11 21:09:14 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QCtrlPerfilesSS.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCtrlPerfilesSS::className() const
{
    return "QCtrlPerfilesSS";
}

QMetaObject *QCtrlPerfilesSS::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCtrlPerfilesSS( "QCtrlPerfilesSS", &QCtrlPerfilesSS::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCtrlPerfilesSS::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrlPerfilesSS", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCtrlPerfilesSS::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrlPerfilesSS", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCtrlPerfilesSS::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotPerfil", 1, param_slot_0 };
    static const QUMethod slot_1 = {"SlotCapturo", 0, 0 };
    static const QUParameter param_slot_2[] = {
	{ "pQStrPerfil", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"SlotCapturandoPerfil", 1, param_slot_2 };
    static const QMetaData slot_tbl[] = {
	{ "SlotPerfil(int)", &slot_0, QMetaData::Private },
	{ "SlotCapturo()", &slot_1, QMetaData::Private },
	{ "SlotCapturandoPerfil(const QString&)", &slot_2, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalNuevoPerfil", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ "pzSisRegPerfil", &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod signal_1 = {"SignalPerfil", 1, param_signal_1 };
    static const QUMethod signal_2 = {"SignalPerfilVacia", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalNuevoPerfil(const QString&)", &signal_0, QMetaData::Private },
	{ "SignalPerfil(zSiscomRegistro*)", &signal_1, QMetaData::Private },
	{ "SignalPerfilVacia()", &signal_2, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCtrlPerfilesSS", parentObject,
	slot_tbl, 3,
	signal_tbl, 3,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCtrlPerfilesSS.setMetaObject( metaObj );
    return metaObj;
}

void* QCtrlPerfilesSS::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCtrlPerfilesSS" ) )
	return this;
    return QWidget::qt_cast( clname );
}

// SIGNAL SignalNuevoPerfil
void QCtrlPerfilesSS::SignalNuevoPerfil( const QString& t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalPerfil
void QCtrlPerfilesSS::SignalPerfil( zSiscomRegistro* t0 )
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

// SIGNAL SignalPerfilVacia
void QCtrlPerfilesSS::SignalPerfilVacia()
{
    activate_signal( staticMetaObject()->signalOffset() + 2 );
}

bool QCtrlPerfilesSS::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotPerfil((int)static_QUType_int.get(_o+1)); break;
    case 1: SlotCapturo(); break;
    case 2: SlotCapturandoPerfil((const QString&)static_QUType_QString.get(_o+1)); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCtrlPerfilesSS::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalNuevoPerfil((const QString&)static_QUType_QString.get(_o+1)); break;
    case 1: SignalPerfil((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 2: SignalPerfilVacia(); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QCtrlPerfilesSS::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool QCtrlPerfilesSS::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
