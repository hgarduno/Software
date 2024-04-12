/****************************************************************************
** QVentas3Qt meta object code from reading C++ file 'IMP_Ventas3Qt.h'
**
** Created: Thu Apr 11 22:09:38 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_Ventas3Qt.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QVentas3Qt::className() const
{
    return "QVentas3Qt";
}

QMetaObject *QVentas3Qt::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QVentas3Qt( "QVentas3Qt", &QVentas3Qt::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QVentas3Qt::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QVentas3Qt", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QVentas3Qt::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QVentas3Qt", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QVentas3Qt::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = Ventas3Qt::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotMoral", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotFisica", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod slot_2 = {"SlotContacto", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod slot_3 = {"SlotFormaPago", 1, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ 0, &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod slot_4 = {"SlotPrecio", 1, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ 0, &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod slot_5 = {"SlotProducto", 1, param_slot_5 };
    static const QUParameter param_slot_6[] = {
	{ 0, &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod slot_6 = {"SlotSeleccionandoProducto", 1, param_slot_6 };
    static const QUMethod slot_7 = {"SlotCotiza", 0, 0 };
    static const QUMethod slot_8 = {"SlotAnexarProducto", 0, 0 };
    static const QUMethod slot_9 = {"SlotRegistra", 0, 0 };
    static const QUMethod slot_10 = {"SlotImprime", 0, 0 };
    static const QUParameter param_slot_11[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_11 = {"SlotCambiaDato", 4, param_slot_11 };
    static const QUParameter param_slot_12[] = {
	{ 0, &static_QUType_ptr, "SiscomRegistro3", QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_12 = {"SlotCambioTipoPrecio", 3, param_slot_12 };
    static const QUMethod slot_13 = {"SlotCambioSeleccion", 0, 0 };
    static const QUMethod slot_14 = {"SlotElimina", 0, 0 };
    static const QUParameter param_slot_15[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_15 = {"SlotTipoOrden", 1, param_slot_15 };
    static const QUParameter param_slot_16[] = {
	{ "pchrPtrTexto", &static_QUType_charstar, 0, QUParameter::In }
    };
    static const QUMethod slot_16 = {"SlotProductoNoEstaEnLaLista", 1, param_slot_16 };
    static const QMetaData slot_tbl[] = {
	{ "SlotMoral(SiscomRegistro3*)", &slot_0, QMetaData::Private },
	{ "SlotFisica(SiscomRegistro3*)", &slot_1, QMetaData::Private },
	{ "SlotContacto(SiscomRegistro3*)", &slot_2, QMetaData::Private },
	{ "SlotFormaPago(SiscomRegistro3*)", &slot_3, QMetaData::Private },
	{ "SlotPrecio(SiscomRegistro3*)", &slot_4, QMetaData::Private },
	{ "SlotProducto(SiscomRegistro3*)", &slot_5, QMetaData::Private },
	{ "SlotSeleccionandoProducto(SiscomRegistro3*)", &slot_6, QMetaData::Private },
	{ "SlotCotiza()", &slot_7, QMetaData::Private },
	{ "SlotAnexarProducto()", &slot_8, QMetaData::Private },
	{ "SlotRegistra()", &slot_9, QMetaData::Private },
	{ "SlotImprime()", &slot_10, QMetaData::Private },
	{ "SlotCambiaDato(int,int,int,const QPoint&)", &slot_11, QMetaData::Private },
	{ "SlotCambioTipoPrecio(SiscomRegistro3*,int,int)", &slot_12, QMetaData::Private },
	{ "SlotCambioSeleccion()", &slot_13, QMetaData::Private },
	{ "SlotElimina()", &slot_14, QMetaData::Private },
	{ "SlotTipoOrden(int)", &slot_15, QMetaData::Private },
	{ "SlotProductoNoEstaEnLaLista(const char*)", &slot_16, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalTerminar", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalTerminar(QWidget*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QVentas3Qt", parentObject,
	slot_tbl, 17,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QVentas3Qt.setMetaObject( metaObj );
    return metaObj;
}

void* QVentas3Qt::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QVentas3Qt" ) )
	return this;
    return Ventas3Qt::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalTerminar
void QVentas3Qt::SignalTerminar( QWidget* t0 )
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

bool QVentas3Qt::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotMoral((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotFisica((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    case 2: SlotContacto((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    case 3: SlotFormaPago((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    case 4: SlotPrecio((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    case 5: SlotProducto((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    case 6: SlotSeleccionandoProducto((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    case 7: SlotCotiza(); break;
    case 8: SlotAnexarProducto(); break;
    case 9: SlotRegistra(); break;
    case 10: SlotImprime(); break;
    case 11: SlotCambiaDato((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 12: SlotCambioTipoPrecio((SiscomRegistro3*)static_QUType_ptr.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3)); break;
    case 13: SlotCambioSeleccion(); break;
    case 14: SlotElimina(); break;
    case 15: SlotTipoOrden((int)static_QUType_int.get(_o+1)); break;
    case 16: SlotProductoNoEstaEnLaLista((const char*)static_QUType_charstar.get(_o+1)); break;
    default:
	return Ventas3Qt::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QVentas3Qt::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalTerminar((QWidget*)static_QUType_ptr.get(_o+1)); break;
    default:
	return Ventas3Qt::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QVentas3Qt::qt_property( int id, int f, QVariant* v)
{
    return Ventas3Qt::qt_property( id, f, v);
}

bool QVentas3Qt::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
