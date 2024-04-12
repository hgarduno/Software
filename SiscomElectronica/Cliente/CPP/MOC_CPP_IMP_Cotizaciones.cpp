/****************************************************************************
** QCotizaciones meta object code from reading C++ file 'IMP_Cotizaciones.h'
**
** Created: Thu Apr 11 21:40:01 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_Cotizaciones.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCotizaciones::className() const
{
    return "QCotizaciones";
}

QMetaObject *QCotizaciones::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCotizaciones( "QCotizaciones", &QCotizaciones::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCotizaciones::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCotizaciones", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCotizaciones::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCotizaciones", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCotizaciones::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QtCotizaciones::staticMetaObject();
    static const QUMethod slot_0 = {"SlotFocoAFechaFin", 0, 0 };
    static const QUMethod slot_1 = {"SlotFocoAConsultar", 0, 0 };
    static const QUMethod slot_2 = {"SlotAceptar", 0, 0 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"SlotCapturandoIdVenta", 1, param_slot_3 };
    static const QUMethod slot_4 = {"SlotCancelar", 0, 0 };
    static const QUParameter param_slot_5[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_5 = {"SlotOrden", 4, param_slot_5 };
    static const QUParameter param_slot_6[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_6 = {"SlotOrden", 2, param_slot_6 };
    static const QUParameter param_slot_7[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_7 = {"SlotSeleccionandoTipoOrden", 1, param_slot_7 };
    static const QUMethod slot_8 = {"SlotConsulta", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotFocoAFechaFin()", &slot_0, QMetaData::Private },
	{ "SlotFocoAConsultar()", &slot_1, QMetaData::Private },
	{ "SlotAceptar()", &slot_2, QMetaData::Private },
	{ "SlotCapturandoIdVenta(const QString&)", &slot_3, QMetaData::Private },
	{ "SlotCancelar()", &slot_4, QMetaData::Private },
	{ "SlotOrden(int,int,int,const QPoint&)", &slot_5, QMetaData::Private },
	{ "SlotOrden(int,int)", &slot_6, QMetaData::Private },
	{ "SlotSeleccionandoTipoOrden(int)", &slot_7, QMetaData::Private },
	{ "SlotConsulta()", &slot_8, QMetaData::Public }
    };
    static const QUParameter param_signal_0[] = {
	{ "pzOrdenVenta", &static_QUType_ptr, "zOrdenVenta", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalVendeOrden", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalVendeOrden(zOrdenVenta*)", &signal_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCotizaciones", parentObject,
	slot_tbl, 9,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCotizaciones.setMetaObject( metaObj );
    return metaObj;
}

void* QCotizaciones::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCotizaciones" ) )
	return this;
    return QtCotizaciones::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalVendeOrden
void QCotizaciones::SignalVendeOrden( zOrdenVenta* t0 )
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

bool QCotizaciones::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotFocoAFechaFin(); break;
    case 1: SlotFocoAConsultar(); break;
    case 2: SlotAceptar(); break;
    case 3: SlotCapturandoIdVenta((const QString&)static_QUType_QString.get(_o+1)); break;
    case 4: SlotCancelar(); break;
    case 5: SlotOrden((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 6: SlotOrden((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 7: SlotSeleccionandoTipoOrden((int)static_QUType_int.get(_o+1)); break;
    case 8: SlotConsulta(); break;
    default:
	return QtCotizaciones::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCotizaciones::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalVendeOrden((zOrdenVenta*)static_QUType_ptr.get(_o+1)); break;
    default:
	return QtCotizaciones::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QCotizaciones::qt_property( int id, int f, QVariant* v)
{
    return QtCotizaciones::qt_property( id, f, v);
}

bool QCotizaciones::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
