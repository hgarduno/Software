/****************************************************************************
** QCtrlEscuelas meta object code from reading C++ file 'QCtrlEscuelas.h'
**
** Created: Thu Apr 11 21:37:49 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QCtrlEscuelas.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCtrlEscuelas::className() const
{
    return "QCtrlEscuelas";
}

QMetaObject *QCtrlEscuelas::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCtrlEscuelas( "QCtrlEscuelas", &QCtrlEscuelas::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCtrlEscuelas::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrlEscuelas", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCtrlEscuelas::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrlEscuelas", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCtrlEscuelas::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotEscuela", 1, param_slot_0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotEscuela(int)", &slot_0, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalEscuelas", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalEscuelas(SiscomRegistro3*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCtrlEscuelas", parentObject,
	slot_tbl, 1,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCtrlEscuelas.setMetaObject( metaObj );
    return metaObj;
}

void* QCtrlEscuelas::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCtrlEscuelas" ) )
	return this;
    return QWidget::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalEscuelas
void QCtrlEscuelas::SignalEscuelas( SiscomRegistro3* t0 )
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

bool QCtrlEscuelas::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotEscuela((int)static_QUType_int.get(_o+1)); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCtrlEscuelas::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalEscuelas((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QCtrlEscuelas::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool QCtrlEscuelas::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
