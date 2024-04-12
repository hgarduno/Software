/****************************************************************************
** QCtrExpendios meta object code from reading C++ file 'IMP_CtrExpendios.h'
**
** Created: Thu Apr 11 21:53:17 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_CtrExpendios.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCtrExpendios::className() const
{
    return "QCtrExpendios";
}

QMetaObject *QCtrExpendios::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCtrExpendios( "QCtrExpendios", &QCtrExpendios::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCtrExpendios::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrExpendios", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCtrExpendios::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrExpendios", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCtrExpendios::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CtrExpendios::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "QIconViewItem", QUParameter::In }
    };
    static const QUMethod slot_0 = {"S_SeleccionoExpendio", 1, param_slot_0 };
    static const QUMethod slot_1 = {"S_CreaEspacioExpendioActual", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "S_SeleccionoExpendio(QIconViewItem*)", &slot_0, QMetaData::Private },
	{ "S_CreaEspacioExpendioActual()", &slot_1, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalTerminar", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalTerminar(QWidget*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCtrExpendios", parentObject,
	slot_tbl, 2,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCtrExpendios.setMetaObject( metaObj );
    return metaObj;
}

void* QCtrExpendios::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCtrExpendios" ) )
	return this;
    return CtrExpendios::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalTerminar
void QCtrExpendios::SignalTerminar( QWidget* t0 )
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

bool QCtrExpendios::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: S_SeleccionoExpendio((QIconViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 1: S_CreaEspacioExpendioActual(); break;
    default:
	return CtrExpendios::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCtrExpendios::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalTerminar((QWidget*)static_QUType_ptr.get(_o+1)); break;
    default:
	return CtrExpendios::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QCtrExpendios::qt_property( int id, int f, QVariant* v)
{
    return CtrExpendios::qt_property( id, f, v);
}

bool QCtrExpendios::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
