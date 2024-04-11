/****************************************************************************
** QtImpCapturaDatosEmpleo meta object code from reading C++ file 'QtImpCapturaDatosEmpleo.h'
**
** Created: Sat Jan 27 16:39:11 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpCapturaDatosEmpleo.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpCapturaDatosEmpleo::className() const
{
    return "QtImpCapturaDatosEmpleo";
}

QMetaObject *QtImpCapturaDatosEmpleo::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpCapturaDatosEmpleo( "QtImpCapturaDatosEmpleo", &QtImpCapturaDatosEmpleo::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpCapturaDatosEmpleo::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpCapturaDatosEmpleo", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpCapturaDatosEmpleo::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpCapturaDatosEmpleo", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpCapturaDatosEmpleo::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CapturaDatosEmpleo::staticMetaObject();
    static const QUMethod slot_0 = {"reject", 0, 0 };
    static const QUMethod slot_1 = {"SlotAceptar", 0, 0 };
    static const QUMethod slot_2 = {"SlotCancelar", 0, 0 };
    static const QUMethod slot_3 = {"SlotRegistrar", 0, 0 };
    static const QUMethod slot_4 = {"SlotFocoAAntiguedad", 0, 0 };
    static const QUMethod slot_5 = {"SlotFocoAPuestoActual", 0, 0 };
    static const QUMethod slot_6 = {"SlotFocoAActividadGiro", 0, 0 };
    static const QUMethod slot_7 = {"SlotFocoANombre", 0, 0 };
    static const QUMethod slot_8 = {"SlotFocoAAPaterno", 0, 0 };
    static const QUMethod slot_9 = {"SlotFocoAAMaterno", 0, 0 };
    static const QUMethod slot_10 = {"SlotFocoACalle", 0, 0 };
    static const QUMethod slot_11 = {"SlotFocoANoExterior", 0, 0 };
    static const QUMethod slot_12 = {"SlotFocoANoInterior", 0, 0 };
    static const QUMethod slot_13 = {"SlotFocoAColonia", 0, 0 };
    static const QUMethod slot_14 = {"SlotFocoADelegacion", 0, 0 };
    static const QUMethod slot_15 = {"SlotFocoAEstado", 0, 0 };
    static const QUMethod slot_16 = {"SlotFocoACodigoPostal", 0, 0 };
    static const QUMethod slot_17 = {"SlotFocoAPais", 0, 0 };
    static const QUMethod slot_18 = {"SlotFocoATelefono", 0, 0 };
    static const QUMethod slot_19 = {"SlotFocoAExtension", 0, 0 };
    static const QUMethod slot_20 = {"SlotFocoACorreoElectronico", 0, 0 };
    static const QUMethod slot_21 = {"SlotFocoASueldo", 0, 0 };
    static const QUMethod slot_22 = {"SlotFocoAOtrosIngresos", 0, 0 };
    static const QUMethod slot_23 = {"SlotFocoAEspecificaOIngresos", 0, 0 };
    static const QUMethod slot_24 = {"SlotFocoATotalIngresos", 0, 0 };
    static const QUMethod slot_25 = {"SlotFocoAFrecuenciaPago", 0, 0 };
    static const QUParameter param_slot_26[] = {
	{ "pzSisRegFrecPago", &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_26 = {"SlotFrecuenciaPago", 1, param_slot_26 };
    static const QUMethod slot_27 = {"SlotFocoAAceptar", 0, 0 };
    static const QUMethod slot_28 = {"SlotFocoARegistrar", 0, 0 };
    static const QUMethod slot_29 = {"SlotActualizar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "reject()", &slot_0, QMetaData::Private },
	{ "SlotAceptar()", &slot_1, QMetaData::Private },
	{ "SlotCancelar()", &slot_2, QMetaData::Private },
	{ "SlotRegistrar()", &slot_3, QMetaData::Private },
	{ "SlotFocoAAntiguedad()", &slot_4, QMetaData::Private },
	{ "SlotFocoAPuestoActual()", &slot_5, QMetaData::Private },
	{ "SlotFocoAActividadGiro()", &slot_6, QMetaData::Private },
	{ "SlotFocoANombre()", &slot_7, QMetaData::Private },
	{ "SlotFocoAAPaterno()", &slot_8, QMetaData::Private },
	{ "SlotFocoAAMaterno()", &slot_9, QMetaData::Private },
	{ "SlotFocoACalle()", &slot_10, QMetaData::Private },
	{ "SlotFocoANoExterior()", &slot_11, QMetaData::Private },
	{ "SlotFocoANoInterior()", &slot_12, QMetaData::Private },
	{ "SlotFocoAColonia()", &slot_13, QMetaData::Private },
	{ "SlotFocoADelegacion()", &slot_14, QMetaData::Private },
	{ "SlotFocoAEstado()", &slot_15, QMetaData::Private },
	{ "SlotFocoACodigoPostal()", &slot_16, QMetaData::Private },
	{ "SlotFocoAPais()", &slot_17, QMetaData::Private },
	{ "SlotFocoATelefono()", &slot_18, QMetaData::Private },
	{ "SlotFocoAExtension()", &slot_19, QMetaData::Private },
	{ "SlotFocoACorreoElectronico()", &slot_20, QMetaData::Private },
	{ "SlotFocoASueldo()", &slot_21, QMetaData::Private },
	{ "SlotFocoAOtrosIngresos()", &slot_22, QMetaData::Private },
	{ "SlotFocoAEspecificaOIngresos()", &slot_23, QMetaData::Private },
	{ "SlotFocoATotalIngresos()", &slot_24, QMetaData::Private },
	{ "SlotFocoAFrecuenciaPago()", &slot_25, QMetaData::Private },
	{ "SlotFrecuenciaPago(zSiscomRegistro*)", &slot_26, QMetaData::Private },
	{ "SlotFocoAAceptar()", &slot_27, QMetaData::Private },
	{ "SlotFocoARegistrar()", &slot_28, QMetaData::Private },
	{ "SlotActualizar()", &slot_29, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpCapturaDatosEmpleo", parentObject,
	slot_tbl, 30,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpCapturaDatosEmpleo.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpCapturaDatosEmpleo::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpCapturaDatosEmpleo" ) )
	return this;
    return CapturaDatosEmpleo::qt_cast( clname );
}

bool QtImpCapturaDatosEmpleo::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: reject(); break;
    case 1: SlotAceptar(); break;
    case 2: SlotCancelar(); break;
    case 3: SlotRegistrar(); break;
    case 4: SlotFocoAAntiguedad(); break;
    case 5: SlotFocoAPuestoActual(); break;
    case 6: SlotFocoAActividadGiro(); break;
    case 7: SlotFocoANombre(); break;
    case 8: SlotFocoAAPaterno(); break;
    case 9: SlotFocoAAMaterno(); break;
    case 10: SlotFocoACalle(); break;
    case 11: SlotFocoANoExterior(); break;
    case 12: SlotFocoANoInterior(); break;
    case 13: SlotFocoAColonia(); break;
    case 14: SlotFocoADelegacion(); break;
    case 15: SlotFocoAEstado(); break;
    case 16: SlotFocoACodigoPostal(); break;
    case 17: SlotFocoAPais(); break;
    case 18: SlotFocoATelefono(); break;
    case 19: SlotFocoAExtension(); break;
    case 20: SlotFocoACorreoElectronico(); break;
    case 21: SlotFocoASueldo(); break;
    case 22: SlotFocoAOtrosIngresos(); break;
    case 23: SlotFocoAEspecificaOIngresos(); break;
    case 24: SlotFocoATotalIngresos(); break;
    case 25: SlotFocoAFrecuenciaPago(); break;
    case 26: SlotFrecuenciaPago((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 27: SlotFocoAAceptar(); break;
    case 28: SlotFocoARegistrar(); break;
    case 29: SlotActualizar(); break;
    default:
	return CapturaDatosEmpleo::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpCapturaDatosEmpleo::qt_emit( int _id, QUObject* _o )
{
    return CapturaDatosEmpleo::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpCapturaDatosEmpleo::qt_property( int id, int f, QVariant* v)
{
    return CapturaDatosEmpleo::qt_property( id, f, v);
}

bool QtImpCapturaDatosEmpleo::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
