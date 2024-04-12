/****************************************************************************
** QClienteAlumno meta object code from reading C++ file 'IMP_ClienteAlumno.h'
**
** Created: Thu Apr 11 21:40:01 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_ClienteAlumno.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QClienteAlumno::className() const
{
    return "QClienteAlumno";
}

QMetaObject *QClienteAlumno::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QClienteAlumno( "QClienteAlumno", &QClienteAlumno::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QClienteAlumno::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QClienteAlumno", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QClienteAlumno::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QClienteAlumno", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QClienteAlumno::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ClienteAlumno::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "pzSisRegEscuela", &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotEscuela", 1, param_slot_0 };
    static const QUMethod slot_1 = {"SlotFocoAAceptar", 0, 0 };
    static const QUMethod slot_2 = {"SlotAceptar", 0, 0 };
    static const QUMethod slot_3 = {"SlotCancelar", 0, 0 };
    static const QUParameter param_slot_4[] = {
	{ "pintTipoOrden", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_4 = {"SlotTipoOrden", 1, param_slot_4 };
    static const QUMethod slot_5 = {"SlotAceptarApartado", 0, 0 };
    static const QUParameter param_slot_6[] = {
	{ "pzSisRegApartado", &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_6 = {"SlotPagar", 1, param_slot_6 };
    static const QUParameter param_slot_7[] = {
	{ "pzCotizacion", &static_QUType_ptr, "zCotizacion", QUParameter::In }
    };
    static const QUMethod slot_7 = {"SlotCotizacion", 1, param_slot_7 };
    static const QUMethod slot_8 = {"SlotOtroMovimiento", 0, 0 };
    static const QUMethod slot_9 = {"SlotCancelarApartado", 0, 0 };
    static const QUParameter param_slot_10[] = {
	{ "pzOrdenVenta", &static_QUType_ptr, "zOrdenVenta", QUParameter::In }
    };
    static const QUMethod slot_10 = {"SlotOrdenVenta", 1, param_slot_10 };
    static const QUParameter param_slot_11[] = {
	{ "pzOrdenVenta", &static_QUType_ptr, "zOrdenVenta", QUParameter::In }
    };
    static const QUMethod slot_11 = {"SlotModificaCotizacion", 1, param_slot_11 };
    static const QUMethod slot_12 = {"SlotNuevaOrden", 0, 0 };
    static const QUParameter param_slot_13[] = {
	{ 0, &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_13 = {"SlotClienteMayoreo", 1, param_slot_13 };
    static const QUMethod slot_14 = {"SlotCapturandoDesVenta", 0, 0 };
    static const QUParameter param_slot_15[] = {
	{ 0, &static_QUType_ptr, "zOrdenVenta", QUParameter::In }
    };
    static const QUMethod slot_15 = {"SlotOrdenFavorita", 1, param_slot_15 };
    static const QUMethod slot_16 = {"SlotCanceloRegistroApartado", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotEscuela(zSiscomRegistro*)", &slot_0, QMetaData::Private },
	{ "SlotFocoAAceptar()", &slot_1, QMetaData::Private },
	{ "SlotAceptar()", &slot_2, QMetaData::Private },
	{ "SlotCancelar()", &slot_3, QMetaData::Private },
	{ "SlotTipoOrden(int)", &slot_4, QMetaData::Private },
	{ "SlotAceptarApartado()", &slot_5, QMetaData::Private },
	{ "SlotPagar(zSiscomRegistro*)", &slot_6, QMetaData::Private },
	{ "SlotCotizacion(zCotizacion*)", &slot_7, QMetaData::Private },
	{ "SlotOtroMovimiento()", &slot_8, QMetaData::Private },
	{ "SlotCancelarApartado()", &slot_9, QMetaData::Private },
	{ "SlotOrdenVenta(zOrdenVenta*)", &slot_10, QMetaData::Private },
	{ "SlotModificaCotizacion(zOrdenVenta*)", &slot_11, QMetaData::Private },
	{ "SlotNuevaOrden()", &slot_12, QMetaData::Private },
	{ "SlotClienteMayoreo(zSiscomRegistro*)", &slot_13, QMetaData::Private },
	{ "SlotCapturandoDesVenta()", &slot_14, QMetaData::Private },
	{ "SlotOrdenFavorita(zOrdenVenta*)", &slot_15, QMetaData::Private },
	{ "SlotCanceloRegistroApartado()", &slot_16, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QClienteAlumno", parentObject,
	slot_tbl, 17,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QClienteAlumno.setMetaObject( metaObj );
    return metaObj;
}

void* QClienteAlumno::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QClienteAlumno" ) )
	return this;
    return ClienteAlumno::qt_cast( clname );
}

bool QClienteAlumno::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotEscuela((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotFocoAAceptar(); break;
    case 2: SlotAceptar(); break;
    case 3: SlotCancelar(); break;
    case 4: SlotTipoOrden((int)static_QUType_int.get(_o+1)); break;
    case 5: SlotAceptarApartado(); break;
    case 6: SlotPagar((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 7: SlotCotizacion((zCotizacion*)static_QUType_ptr.get(_o+1)); break;
    case 8: SlotOtroMovimiento(); break;
    case 9: SlotCancelarApartado(); break;
    case 10: SlotOrdenVenta((zOrdenVenta*)static_QUType_ptr.get(_o+1)); break;
    case 11: SlotModificaCotizacion((zOrdenVenta*)static_QUType_ptr.get(_o+1)); break;
    case 12: SlotNuevaOrden(); break;
    case 13: SlotClienteMayoreo((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 14: SlotCapturandoDesVenta(); break;
    case 15: SlotOrdenFavorita((zOrdenVenta*)static_QUType_ptr.get(_o+1)); break;
    case 16: SlotCanceloRegistroApartado(); break;
    default:
	return ClienteAlumno::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QClienteAlumno::qt_emit( int _id, QUObject* _o )
{
    return ClienteAlumno::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QClienteAlumno::qt_property( int id, int f, QVariant* v)
{
    return ClienteAlumno::qt_property( id, f, v);
}

bool QClienteAlumno::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
