/****************************************************************************
** QActualizaProductos meta object code from reading C++ file 'IMP_ActualizaProductos.h'
**
** Created: Thu Apr 11 20:30:21 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_ActualizaProductos.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QActualizaProductos::className() const
{
    return "QActualizaProductos";
}

QMetaObject *QActualizaProductos::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QActualizaProductos( "QActualizaProductos", &QActualizaProductos::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QActualizaProductos::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QActualizaProductos", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QActualizaProductos::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QActualizaProductos", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QActualizaProductos::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ActualizaProductos::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "CQSisProducto", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotProducto", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_ptr, "CQSisFamilia", QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotFamilia", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"SlotCambiandoClave", 1, param_slot_2 };
    static const QUMethod slot_3 = {"SlotCambiandoDescripcion", 0, 0 };
    static const QUMethod slot_4 = {"SlotPasaFocoDsc", 0, 0 };
    static const QUMethod slot_5 = {"SlotActualiza", 0, 0 };
    static const QUParameter param_slot_6[] = {
	{ 0, &static_QUType_ptr, "QCloseEvent", QUParameter::In }
    };
    static const QUMethod slot_6 = {"closeEvent", 1, param_slot_6 };
    static const QMetaData slot_tbl[] = {
	{ "SlotProducto(CQSisProducto*)", &slot_0, QMetaData::Private },
	{ "SlotFamilia(CQSisFamilia*)", &slot_1, QMetaData::Private },
	{ "SlotCambiandoClave(const QString&)", &slot_2, QMetaData::Private },
	{ "SlotCambiandoDescripcion()", &slot_3, QMetaData::Private },
	{ "SlotPasaFocoDsc()", &slot_4, QMetaData::Private },
	{ "SlotActualiza()", &slot_5, QMetaData::Private },
	{ "closeEvent(QCloseEvent*)", &slot_6, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalTerminar", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalTerminar(QWidget*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QActualizaProductos", parentObject,
	slot_tbl, 7,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QActualizaProductos.setMetaObject( metaObj );
    return metaObj;
}

void* QActualizaProductos::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QActualizaProductos" ) )
	return this;
    return ActualizaProductos::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalTerminar
void QActualizaProductos::SignalTerminar( QWidget* t0 )
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

bool QActualizaProductos::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotProducto((CQSisProducto*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotFamilia((CQSisFamilia*)static_QUType_ptr.get(_o+1)); break;
    case 2: SlotCambiandoClave((const QString&)static_QUType_QString.get(_o+1)); break;
    case 3: SlotCambiandoDescripcion(); break;
    case 4: SlotPasaFocoDsc(); break;
    case 5: SlotActualiza(); break;
    case 6: closeEvent((QCloseEvent*)static_QUType_ptr.get(_o+1)); break;
    default:
	return ActualizaProductos::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QActualizaProductos::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalTerminar((QWidget*)static_QUType_ptr.get(_o+1)); break;
    default:
	return ActualizaProductos::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QActualizaProductos::qt_property( int id, int f, QVariant* v)
{
    return ActualizaProductos::qt_property( id, f, v);
}

bool QActualizaProductos::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
