/****************************************************************************
** QCtrlPrecios3Qt meta object code from reading C++ file 'QCtrlPrecios3Qt.h'
**
** Created: Thu Apr 11 22:08:58 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QCtrlPrecios3Qt.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCtrlPrecios3Qt::className() const
{
    return "QCtrlPrecios3Qt";
}

QMetaObject *QCtrlPrecios3Qt::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCtrlPrecios3Qt( "QCtrlPrecios3Qt", &QCtrlPrecios3Qt::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCtrlPrecios3Qt::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrlPrecios3Qt", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCtrlPrecios3Qt::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrlPrecios3Qt", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCtrlPrecios3Qt::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotPrecio", 1, param_slot_0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotPrecio(int)", &slot_0, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalPrecio", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalPrecio(SiscomRegistro3*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCtrlPrecios3Qt", parentObject,
	slot_tbl, 1,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCtrlPrecios3Qt.setMetaObject( metaObj );
    return metaObj;
}

void* QCtrlPrecios3Qt::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCtrlPrecios3Qt" ) )
	return this;
    return QWidget::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalPrecio
void QCtrlPrecios3Qt::SignalPrecio( SiscomRegistro3* t0 )
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

bool QCtrlPrecios3Qt::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotPrecio((int)static_QUType_int.get(_o+1)); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCtrlPrecios3Qt::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalPrecio((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QCtrlPrecios3Qt::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool QCtrlPrecios3Qt::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
