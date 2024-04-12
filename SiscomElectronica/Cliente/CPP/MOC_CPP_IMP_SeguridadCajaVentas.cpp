/****************************************************************************
** QSeguridadCajaVentas meta object code from reading C++ file 'IMP_SeguridadCajaVentas.h'
**
** Created: Thu Apr 11 21:40:01 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_SeguridadCajaVentas.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QSeguridadCajaVentas::className() const
{
    return "QSeguridadCajaVentas";
}

QMetaObject *QSeguridadCajaVentas::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QSeguridadCajaVentas( "QSeguridadCajaVentas", &QSeguridadCajaVentas::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QSeguridadCajaVentas::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSeguridadCajaVentas", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QSeguridadCajaVentas::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSeguridadCajaVentas", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QSeguridadCajaVentas::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = SeguridadCajaVentas::staticMetaObject();
    static const QUMethod slot_0 = {"SlotActualizar", 0, 0 };
    static const QUMethod slot_1 = {"SlotRegistrar", 0, 0 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_2 = {"SlotSeleccionoCaja", 1, param_slot_2 };
    static const QMetaData slot_tbl[] = {
	{ "SlotActualizar()", &slot_0, QMetaData::Private },
	{ "SlotRegistrar()", &slot_1, QMetaData::Private },
	{ "SlotSeleccionoCaja(QListViewItem*)", &slot_2, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalTerminar", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalTerminar(QWidget*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QSeguridadCajaVentas", parentObject,
	slot_tbl, 3,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QSeguridadCajaVentas.setMetaObject( metaObj );
    return metaObj;
}

void* QSeguridadCajaVentas::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QSeguridadCajaVentas" ) )
	return this;
    return SeguridadCajaVentas::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalTerminar
void QSeguridadCajaVentas::SignalTerminar( QWidget* t0 )
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

bool QSeguridadCajaVentas::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotActualizar(); break;
    case 1: SlotRegistrar(); break;
    case 2: SlotSeleccionoCaja((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    default:
	return SeguridadCajaVentas::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QSeguridadCajaVentas::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalTerminar((QWidget*)static_QUType_ptr.get(_o+1)); break;
    default:
	return SeguridadCajaVentas::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QSeguridadCajaVentas::qt_property( int id, int f, QVariant* v)
{
    return SeguridadCajaVentas::qt_property( id, f, v);
}

bool QSeguridadCajaVentas::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
