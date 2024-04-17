/****************************************************************************
** QFacturas meta object code from reading C++ file 'IMP_Facturas.h'
**
** Created: Fri Apr 12 21:26:08 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_Facturas.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QFacturas::className() const
{
    return "QFacturas";
}

QMetaObject *QFacturas::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QFacturas( "QFacturas", &QFacturas::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QFacturas::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QFacturas", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QFacturas::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QFacturas", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QFacturas::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = Facturas::staticMetaObject();
    static const QUMethod slot_0 = {"SlotRangoFechas", 0, 0 };
    static const QUMethod slot_1 = {"SlotActualiza", 0, 0 };
    static const QUMethod slot_2 = {"SlotFiltroProveedor", 0, 0 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_3 = {"SlotSeleccionandoFactura", 4, param_slot_3 };
    static const QUMethod slot_4 = {"SlotActualizaNumFactura", 0, 0 };
    static const QUMethod slot_5 = {"SlotCopiar", 0, 0 };
    static const QUMethod slot_6 = {"SlotAnexarFactura", 0, 0 };
    static const QUMethod slot_7 = {"SlotAnexarFacturasPeriodoContable", 0, 0 };
    static const QUParameter param_slot_8[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_8 = {"SlotCambiandoFactura", 2, param_slot_8 };
    static const QMetaData slot_tbl[] = {
	{ "SlotRangoFechas()", &slot_0, QMetaData::Private },
	{ "SlotActualiza()", &slot_1, QMetaData::Private },
	{ "SlotFiltroProveedor()", &slot_2, QMetaData::Private },
	{ "SlotSeleccionandoFactura(int,int,int,const QPoint&)", &slot_3, QMetaData::Private },
	{ "SlotActualizaNumFactura()", &slot_4, QMetaData::Private },
	{ "SlotCopiar()", &slot_5, QMetaData::Private },
	{ "SlotAnexarFactura()", &slot_6, QMetaData::Private },
	{ "SlotAnexarFacturasPeriodoContable()", &slot_7, QMetaData::Private },
	{ "SlotCambiandoFactura(int,int)", &slot_8, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalTerminar", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalTerminar(QWidget*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QFacturas", parentObject,
	slot_tbl, 9,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QFacturas.setMetaObject( metaObj );
    return metaObj;
}

void* QFacturas::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QFacturas" ) )
	return this;
    return Facturas::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalTerminar
void QFacturas::SignalTerminar( QWidget* t0 )
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

bool QFacturas::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotRangoFechas(); break;
    case 1: SlotActualiza(); break;
    case 2: SlotFiltroProveedor(); break;
    case 3: SlotSeleccionandoFactura((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 4: SlotActualizaNumFactura(); break;
    case 5: SlotCopiar(); break;
    case 6: SlotAnexarFactura(); break;
    case 7: SlotAnexarFacturasPeriodoContable(); break;
    case 8: SlotCambiandoFactura((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    default:
	return Facturas::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QFacturas::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalTerminar((QWidget*)static_QUType_ptr.get(_o+1)); break;
    default:
	return Facturas::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QFacturas::qt_property( int id, int f, QVariant* v)
{
    return Facturas::qt_property( id, f, v);
}

bool QFacturas::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
