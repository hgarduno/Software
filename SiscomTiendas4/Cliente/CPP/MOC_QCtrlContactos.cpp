/****************************************************************************
** QCtrlContactos meta object code from reading C++ file 'QCtrlContactos.h'
**
** Created: Thu Apr 11 22:08:58 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QCtrlContactos.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCtrlContactos::className() const
{
    return "QCtrlContactos";
}

QMetaObject *QCtrlContactos::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCtrlContactos( "QCtrlContactos", &QCtrlContactos::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCtrlContactos::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrlContactos", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCtrlContactos::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrlContactos", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCtrlContactos::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotProducto", 1, param_slot_0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotProducto(int)", &slot_0, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "CQSisContacto", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalContactos", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalContactos(CQSisContacto*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCtrlContactos", parentObject,
	slot_tbl, 1,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCtrlContactos.setMetaObject( metaObj );
    return metaObj;
}

void* QCtrlContactos::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCtrlContactos" ) )
	return this;
    return QWidget::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalContactos
void QCtrlContactos::SignalContactos( CQSisContacto* t0 )
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

bool QCtrlContactos::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotProducto((int)static_QUType_int.get(_o+1)); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCtrlContactos::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalContactos((CQSisContacto*)static_QUType_ptr.get(_o+1)); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QCtrlContactos::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool QCtrlContactos::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
