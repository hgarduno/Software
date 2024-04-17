/****************************************************************************
** QDatosFacturacion meta object code from reading C++ file 'IMP_DatosFacturacion.h'
**
** Created: Fri Apr 12 21:26:09 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_DatosFacturacion.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QDatosFacturacion::className() const
{
    return "QDatosFacturacion";
}

QMetaObject *QDatosFacturacion::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QDatosFacturacion( "QDatosFacturacion", &QDatosFacturacion::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QDatosFacturacion::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QDatosFacturacion", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QDatosFacturacion::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QDatosFacturacion", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QDatosFacturacion::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = DatosFacturacion::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotFocoARazonSocial", 1, param_slot_0 };
    static const QUMethod slot_1 = {"SlotFocoANombre", 0, 0 };
    static const QUMethod slot_2 = {"SlotFocoAAPaterno", 0, 0 };
    static const QUMethod slot_3 = {"SlotFocoAAMaterno", 0, 0 };
    static const QUMethod slot_4 = {"SlotFocoARegimenFiscal", 0, 0 };
    static const QUMethod slot_5 = {"SlotFocoACalle", 0, 0 };
    static const QUMethod slot_6 = {"SlotFocoANumero", 0, 0 };
    static const QUMethod slot_7 = {"SlotFocoANumeroInt", 0, 0 };
    static const QUMethod slot_8 = {"SlotFocoADelegacion", 0, 0 };
    static const QUMethod slot_9 = {"SlotFocoAColonia", 0, 0 };
    static const QUMethod slot_10 = {"SlotFocoAEstado", 0, 0 };
    static const QUMethod slot_11 = {"SlotFocoACP", 0, 0 };
    static const QUMethod slot_12 = {"SlotFocoACorreo", 0, 0 };
    static const QUMethod slot_13 = {"SlotFocoACorreoOtraVez", 0, 0 };
    static const QUMethod slot_14 = {"SlotFocoAAceptar", 0, 0 };
    static const QUMethod slot_15 = {"SlotFocoATelefono", 0, 0 };
    static const QUMethod slot_16 = {"SlotFocoAAgregarCorreo", 0, 0 };
    static const QUMethod slot_17 = {"SlotFocoARegistrarDatos", 0, 0 };
    static const QUParameter param_slot_18[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_18 = {"SlotCapturandoRazonSocial", 1, param_slot_18 };
    static const QUParameter param_slot_19[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_19 = {"SlotCapturandoRegimenFiscal", 1, param_slot_19 };
    static const QUParameter param_slot_20[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_20 = {"SlotCapturandoNombre", 1, param_slot_20 };
    static const QUParameter param_slot_21[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_21 = {"SlotCapturandoAPaterno", 1, param_slot_21 };
    static const QUParameter param_slot_22[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_22 = {"SlotCapturandoAMaterno", 1, param_slot_22 };
    static const QUParameter param_slot_23[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_23 = {"SlotCapturandoRFC", 1, param_slot_23 };
    static const QUParameter param_slot_24[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_24 = {"SlotCapturandoCalle", 1, param_slot_24 };
    static const QUParameter param_slot_25[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_25 = {"SlotCapturandoNumero", 1, param_slot_25 };
    static const QUParameter param_slot_26[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_26 = {"SlotCapturandoNumeroInt", 1, param_slot_26 };
    static const QUParameter param_slot_27[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_27 = {"SlotCapturandoDelegacion", 1, param_slot_27 };
    static const QUParameter param_slot_28[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_28 = {"SlotCapturandoColonia", 1, param_slot_28 };
    static const QUParameter param_slot_29[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_29 = {"SlotCapturandoEstado", 1, param_slot_29 };
    static const QUParameter param_slot_30[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_30 = {"SlotCapturandoCP", 1, param_slot_30 };
    static const QUParameter param_slot_31[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_31 = {"SlotCapturandoCorreo", 1, param_slot_31 };
    static const QUParameter param_slot_32[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_32 = {"SlotCapturandoCorreoOtraVez", 1, param_slot_32 };
    static const QUMethod slot_33 = {"SlotAceptar", 0, 0 };
    static const QUMethod slot_34 = {"SlotCancelar", 0, 0 };
    static const QUMethod slot_35 = {"SlotRegistrar", 0, 0 };
    static const QUMethod slot_36 = {"SlotAgregarCorreo", 0, 0 };
    static const QUParameter param_slot_37[] = {
	{ "pintCorreo", &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_37 = {"SlotSeleccionoCorreo", 4, param_slot_37 };
    static const QUParameter param_slot_38[] = {
	{ 0, &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_38 = {"SlotFormaPago", 1, param_slot_38 };
    static const QUParameter param_slot_39[] = {
	{ 0, &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_39 = {"SlotMetodoPago", 1, param_slot_39 };
    static const QUParameter param_slot_40[] = {
	{ 0, &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_40 = {"SlotUsoCFDI", 1, param_slot_40 };
    static const QUParameter param_slot_41[] = {
	{ 0, &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_41 = {"SlotRegimenFiscal", 1, param_slot_41 };
    static const QMetaData slot_tbl[] = {
	{ "SlotFocoARazonSocial(zSiscomRegistro*)", &slot_0, QMetaData::Private },
	{ "SlotFocoANombre()", &slot_1, QMetaData::Private },
	{ "SlotFocoAAPaterno()", &slot_2, QMetaData::Private },
	{ "SlotFocoAAMaterno()", &slot_3, QMetaData::Private },
	{ "SlotFocoARegimenFiscal()", &slot_4, QMetaData::Private },
	{ "SlotFocoACalle()", &slot_5, QMetaData::Private },
	{ "SlotFocoANumero()", &slot_6, QMetaData::Private },
	{ "SlotFocoANumeroInt()", &slot_7, QMetaData::Private },
	{ "SlotFocoADelegacion()", &slot_8, QMetaData::Private },
	{ "SlotFocoAColonia()", &slot_9, QMetaData::Private },
	{ "SlotFocoAEstado()", &slot_10, QMetaData::Private },
	{ "SlotFocoACP()", &slot_11, QMetaData::Private },
	{ "SlotFocoACorreo()", &slot_12, QMetaData::Private },
	{ "SlotFocoACorreoOtraVez()", &slot_13, QMetaData::Private },
	{ "SlotFocoAAceptar()", &slot_14, QMetaData::Private },
	{ "SlotFocoATelefono()", &slot_15, QMetaData::Private },
	{ "SlotFocoAAgregarCorreo()", &slot_16, QMetaData::Private },
	{ "SlotFocoARegistrarDatos()", &slot_17, QMetaData::Private },
	{ "SlotCapturandoRazonSocial(const QString&)", &slot_18, QMetaData::Private },
	{ "SlotCapturandoRegimenFiscal(const QString&)", &slot_19, QMetaData::Private },
	{ "SlotCapturandoNombre(const QString&)", &slot_20, QMetaData::Private },
	{ "SlotCapturandoAPaterno(const QString&)", &slot_21, QMetaData::Private },
	{ "SlotCapturandoAMaterno(const QString&)", &slot_22, QMetaData::Private },
	{ "SlotCapturandoRFC(const QString&)", &slot_23, QMetaData::Private },
	{ "SlotCapturandoCalle(const QString&)", &slot_24, QMetaData::Private },
	{ "SlotCapturandoNumero(const QString&)", &slot_25, QMetaData::Private },
	{ "SlotCapturandoNumeroInt(const QString&)", &slot_26, QMetaData::Private },
	{ "SlotCapturandoDelegacion(const QString&)", &slot_27, QMetaData::Private },
	{ "SlotCapturandoColonia(const QString&)", &slot_28, QMetaData::Private },
	{ "SlotCapturandoEstado(const QString&)", &slot_29, QMetaData::Private },
	{ "SlotCapturandoCP(const QString&)", &slot_30, QMetaData::Private },
	{ "SlotCapturandoCorreo(const QString&)", &slot_31, QMetaData::Private },
	{ "SlotCapturandoCorreoOtraVez(const QString&)", &slot_32, QMetaData::Private },
	{ "SlotAceptar()", &slot_33, QMetaData::Private },
	{ "SlotCancelar()", &slot_34, QMetaData::Private },
	{ "SlotRegistrar()", &slot_35, QMetaData::Private },
	{ "SlotAgregarCorreo()", &slot_36, QMetaData::Private },
	{ "SlotSeleccionoCorreo(int,int,int,const QPoint&)", &slot_37, QMetaData::Private },
	{ "SlotFormaPago(zSiscomRegistro*)", &slot_38, QMetaData::Private },
	{ "SlotMetodoPago(zSiscomRegistro*)", &slot_39, QMetaData::Private },
	{ "SlotUsoCFDI(zSiscomRegistro*)", &slot_40, QMetaData::Private },
	{ "SlotRegimenFiscal(zSiscomRegistro*)", &slot_41, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QDatosFacturacion", parentObject,
	slot_tbl, 42,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QDatosFacturacion.setMetaObject( metaObj );
    return metaObj;
}

void* QDatosFacturacion::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QDatosFacturacion" ) )
	return this;
    return DatosFacturacion::qt_cast( clname );
}

bool QDatosFacturacion::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotFocoARazonSocial((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotFocoANombre(); break;
    case 2: SlotFocoAAPaterno(); break;
    case 3: SlotFocoAAMaterno(); break;
    case 4: SlotFocoARegimenFiscal(); break;
    case 5: SlotFocoACalle(); break;
    case 6: SlotFocoANumero(); break;
    case 7: SlotFocoANumeroInt(); break;
    case 8: SlotFocoADelegacion(); break;
    case 9: SlotFocoAColonia(); break;
    case 10: SlotFocoAEstado(); break;
    case 11: SlotFocoACP(); break;
    case 12: SlotFocoACorreo(); break;
    case 13: SlotFocoACorreoOtraVez(); break;
    case 14: SlotFocoAAceptar(); break;
    case 15: SlotFocoATelefono(); break;
    case 16: SlotFocoAAgregarCorreo(); break;
    case 17: SlotFocoARegistrarDatos(); break;
    case 18: SlotCapturandoRazonSocial((const QString&)static_QUType_QString.get(_o+1)); break;
    case 19: SlotCapturandoRegimenFiscal((const QString&)static_QUType_QString.get(_o+1)); break;
    case 20: SlotCapturandoNombre((const QString&)static_QUType_QString.get(_o+1)); break;
    case 21: SlotCapturandoAPaterno((const QString&)static_QUType_QString.get(_o+1)); break;
    case 22: SlotCapturandoAMaterno((const QString&)static_QUType_QString.get(_o+1)); break;
    case 23: SlotCapturandoRFC((const QString&)static_QUType_QString.get(_o+1)); break;
    case 24: SlotCapturandoCalle((const QString&)static_QUType_QString.get(_o+1)); break;
    case 25: SlotCapturandoNumero((const QString&)static_QUType_QString.get(_o+1)); break;
    case 26: SlotCapturandoNumeroInt((const QString&)static_QUType_QString.get(_o+1)); break;
    case 27: SlotCapturandoDelegacion((const QString&)static_QUType_QString.get(_o+1)); break;
    case 28: SlotCapturandoColonia((const QString&)static_QUType_QString.get(_o+1)); break;
    case 29: SlotCapturandoEstado((const QString&)static_QUType_QString.get(_o+1)); break;
    case 30: SlotCapturandoCP((const QString&)static_QUType_QString.get(_o+1)); break;
    case 31: SlotCapturandoCorreo((const QString&)static_QUType_QString.get(_o+1)); break;
    case 32: SlotCapturandoCorreoOtraVez((const QString&)static_QUType_QString.get(_o+1)); break;
    case 33: SlotAceptar(); break;
    case 34: SlotCancelar(); break;
    case 35: SlotRegistrar(); break;
    case 36: SlotAgregarCorreo(); break;
    case 37: SlotSeleccionoCorreo((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 38: SlotFormaPago((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 39: SlotMetodoPago((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 40: SlotUsoCFDI((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 41: SlotRegimenFiscal((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    default:
	return DatosFacturacion::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QDatosFacturacion::qt_emit( int _id, QUObject* _o )
{
    return DatosFacturacion::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QDatosFacturacion::qt_property( int id, int f, QVariant* v)
{
    return DatosFacturacion::qt_property( id, f, v);
}

bool QDatosFacturacion::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
