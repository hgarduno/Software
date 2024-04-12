/****************************************************************************
** QInventarioBodega meta object code from reading C++ file 'IMP_InventarioBodega.h'
**
** Created: Thu Apr 11 21:40:01 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_InventarioBodega.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QInventarioBodega::className() const
{
    return "QInventarioBodega";
}

QMetaObject *QInventarioBodega::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QInventarioBodega( "QInventarioBodega", &QInventarioBodega::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QInventarioBodega::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QInventarioBodega", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QInventarioBodega::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QInventarioBodega", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QInventarioBodega::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = InventarioBodega::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotSeleccionando", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotSelecciono", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod slot_2 = {"SlotBodega", 1, param_slot_2 };
    static const QUMethod slot_3 = {"SlotPasaFocoRegistra", 0, 0 };
    static const QUMethod slot_4 = {"SlotRegistra", 0, 0 };
    static const QUMethod slot_5 = {"SlotActivaBodegas", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotSeleccionando(SiscomRegistro3*)", &slot_0, QMetaData::Private },
	{ "SlotSelecciono(SiscomRegistro3*)", &slot_1, QMetaData::Private },
	{ "SlotBodega(SiscomRegistro3*)", &slot_2, QMetaData::Private },
	{ "SlotPasaFocoRegistra()", &slot_3, QMetaData::Private },
	{ "SlotRegistra()", &slot_4, QMetaData::Private },
	{ "SlotActivaBodegas()", &slot_5, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalTerminar", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalTerminar(QWidget*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QInventarioBodega", parentObject,
	slot_tbl, 6,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QInventarioBodega.setMetaObject( metaObj );
    return metaObj;
}

void* QInventarioBodega::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QInventarioBodega" ) )
	return this;
    return InventarioBodega::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalTerminar
void QInventarioBodega::SignalTerminar( QWidget* t0 )
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

bool QInventarioBodega::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotSeleccionando((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotSelecciono((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    case 2: SlotBodega((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    case 3: SlotPasaFocoRegistra(); break;
    case 4: SlotRegistra(); break;
    case 5: SlotActivaBodegas(); break;
    default:
	return InventarioBodega::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QInventarioBodega::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalTerminar((QWidget*)static_QUType_ptr.get(_o+1)); break;
    default:
	return InventarioBodega::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QInventarioBodega::qt_property( int id, int f, QVariant* v)
{
    return InventarioBodega::qt_property( id, f, v);
}

bool QInventarioBodega::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
