/****************************************************************************
** QCtrlServidoresSiscom meta object code from reading C++ file 'QCtrlServidoresSiscom.h'
**
** Created: Thu Apr 11 21:37:02 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QCtrlServidoresSiscom.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCtrlServidoresSiscom::className() const
{
    return "QCtrlServidoresSiscom";
}

QMetaObject *QCtrlServidoresSiscom::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCtrlServidoresSiscom( "QCtrlServidoresSiscom", &QCtrlServidoresSiscom::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCtrlServidoresSiscom::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrlServidoresSiscom", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCtrlServidoresSiscom::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrlServidoresSiscom", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCtrlServidoresSiscom::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "QIconViewItem", QUParameter::In }
    };
    static const QUMethod slot_0 = {"S_SeleccionoServidor", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_ptr, "QIconViewItem", QUParameter::In }
    };
    static const QUMethod slot_1 = {"S_MarcaServidor", 1, param_slot_1 };
    static const QMetaData slot_tbl[] = {
	{ "S_SeleccionoServidor(QIconViewItem*)", &slot_0, QMetaData::Private },
	{ "S_MarcaServidor(QIconViewItem*)", &slot_1, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "SiscomDatCom", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalServidor", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_ptr, "SiscomDatCom", QUParameter::In }
    };
    static const QUMethod signal_1 = {"SignalMarcaServidor", 1, param_signal_1 };
    static const QMetaData signal_tbl[] = {
	{ "SignalServidor(SiscomDatCom*)", &signal_0, QMetaData::Private },
	{ "SignalMarcaServidor(SiscomDatCom*)", &signal_1, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCtrlServidoresSiscom", parentObject,
	slot_tbl, 2,
	signal_tbl, 2,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCtrlServidoresSiscom.setMetaObject( metaObj );
    return metaObj;
}

void* QCtrlServidoresSiscom::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCtrlServidoresSiscom" ) )
	return this;
    return QWidget::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalServidor
void QCtrlServidoresSiscom::SignalServidor( SiscomDatCom* t0 )
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

// SIGNAL SignalMarcaServidor
void QCtrlServidoresSiscom::SignalMarcaServidor( SiscomDatCom* t0 )
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

bool QCtrlServidoresSiscom::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: S_SeleccionoServidor((QIconViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 1: S_MarcaServidor((QIconViewItem*)static_QUType_ptr.get(_o+1)); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCtrlServidoresSiscom::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalServidor((SiscomDatCom*)static_QUType_ptr.get(_o+1)); break;
    case 1: SignalMarcaServidor((SiscomDatCom*)static_QUType_ptr.get(_o+1)); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QCtrlServidoresSiscom::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool QCtrlServidoresSiscom::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
