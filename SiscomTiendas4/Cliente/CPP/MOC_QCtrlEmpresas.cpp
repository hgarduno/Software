/****************************************************************************
** QCtrlEmpresas meta object code from reading C++ file 'QCtrlEmpresas.h'
**
** Created: Thu Apr 11 20:29:41 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QCtrlEmpresas.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCtrlEmpresas::className() const
{
    return "QCtrlEmpresas";
}

QMetaObject *QCtrlEmpresas::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCtrlEmpresas( "QCtrlEmpresas", &QCtrlEmpresas::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCtrlEmpresas::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrlEmpresas", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCtrlEmpresas::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrlEmpresas", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCtrlEmpresas::staticMetaObject()
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
	{ 0, &static_QUType_ptr, "CQSisEmpresa", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalEmpresas", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalEmpresas(CQSisEmpresa*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCtrlEmpresas", parentObject,
	slot_tbl, 1,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCtrlEmpresas.setMetaObject( metaObj );
    return metaObj;
}

void* QCtrlEmpresas::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCtrlEmpresas" ) )
	return this;
    return QWidget::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalEmpresas
void QCtrlEmpresas::SignalEmpresas( CQSisEmpresa* t0 )
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

bool QCtrlEmpresas::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotProducto((int)static_QUType_int.get(_o+1)); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCtrlEmpresas::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalEmpresas((CQSisEmpresa*)static_QUType_ptr.get(_o+1)); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QCtrlEmpresas::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool QCtrlEmpresas::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
