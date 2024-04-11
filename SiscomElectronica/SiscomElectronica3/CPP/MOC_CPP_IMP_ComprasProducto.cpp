/****************************************************************************
** QComprasProducto meta object code from reading C++ file 'IMP_ComprasProducto.h'
**
** Created: Wed Jan 31 10:47:33 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_ComprasProducto.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QComprasProducto::className() const
{
    return "QComprasProducto";
}

QMetaObject *QComprasProducto::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QComprasProducto( "QComprasProducto", &QComprasProducto::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QComprasProducto::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QComprasProducto", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QComprasProducto::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QComprasProducto", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QComprasProducto::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ComprasProducto::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotSeleccionando", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotSelecciono", 1, param_slot_1 };
    static const QUMethod slot_2 = {"SlotHistorico", 0, 0 };
    static const QUMethod slot_3 = {"SlotPorcentajes", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotSeleccionando(SiscomRegistro3*)", &slot_0, QMetaData::Private },
	{ "SlotSelecciono(SiscomRegistro3*)", &slot_1, QMetaData::Private },
	{ "SlotHistorico()", &slot_2, QMetaData::Private },
	{ "SlotPorcentajes()", &slot_3, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalTerminar", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalTerminar(QWidget*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QComprasProducto", parentObject,
	slot_tbl, 4,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QComprasProducto.setMetaObject( metaObj );
    return metaObj;
}

void* QComprasProducto::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QComprasProducto" ) )
	return this;
    return ComprasProducto::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalTerminar
void QComprasProducto::SignalTerminar( QWidget* t0 )
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

bool QComprasProducto::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotSeleccionando((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotSelecciono((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    case 2: SlotHistorico(); break;
    case 3: SlotPorcentajes(); break;
    default:
	return ComprasProducto::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QComprasProducto::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalTerminar((QWidget*)static_QUType_ptr.get(_o+1)); break;
    default:
	return ComprasProducto::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QComprasProducto::qt_property( int id, int f, QVariant* v)
{
    return ComprasProducto::qt_property( id, f, v);
}

bool QComprasProducto::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
