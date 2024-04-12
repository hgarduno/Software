/****************************************************************************
** QComprasImportaciones meta object code from reading C++ file 'IMP_ComprasImportaciones.h'
**
** Created: Thu Apr 11 21:40:02 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_ComprasImportaciones.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QComprasImportaciones::className() const
{
    return "QComprasImportaciones";
}

QMetaObject *QComprasImportaciones::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QComprasImportaciones( "QComprasImportaciones", &QComprasImportaciones::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QComprasImportaciones::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QComprasImportaciones", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QComprasImportaciones::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QComprasImportaciones", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QComprasImportaciones::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ComprasImportaciones::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotCapturandoNumFactura", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotCapturandoCostoEnvio", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"SlotCapturandoCostoDolar", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"SlotCapturandoCostoAdministrativo", 1, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_4 = {"SlotCapturandoNumPartidas", 1, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"SlotCapturandoCantidad", 1, param_slot_5 };
    static const QUParameter param_slot_6[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_6 = {"SlotCapturandoCostoUnitario", 1, param_slot_6 };
    static const QUParameter param_slot_7[] = {
	{ 0, &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_7 = {"SlotSeleccionoProducto", 1, param_slot_7 };
    static const QUParameter param_slot_8[] = {
	{ 0, &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_8 = {"SlotSeleccionoProveedor", 1, param_slot_8 };
    static const QUMethod slot_9 = {"SlotFocoACostoUnitario", 0, 0 };
    static const QUMethod slot_10 = {"SlotFocoAAnexar", 0, 0 };
    static const QUMethod slot_11 = {"SlotFocoACotizacionDolar", 0, 0 };
    static const QUMethod slot_12 = {"SlotFocoACostoAdministrativo", 0, 0 };
    static const QUMethod slot_13 = {"SlotFocoANumPartidas", 0, 0 };
    static const QUMethod slot_14 = {"SlotFocoACostoEnvio", 0, 0 };
    static const QUMethod slot_15 = {"SlotFocoAProductos", 0, 0 };
    static const QUMethod slot_16 = {"SlotAnexarProducto", 0, 0 };
    static const QUMethod slot_17 = {"SlotRegistraCompra", 0, 0 };
    static const QUMethod slot_18 = {"SlotEliminar", 0, 0 };
    static const QUParameter param_slot_19[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_19 = {"SlotSeleccionaProducto", 4, param_slot_19 };
    static const QUMethod slot_20 = {"SlotProveedores", 0, 0 };
    static const QUMethod slot_21 = {"SlotActualiza", 0, 0 };
    static const QUMethod slot_22 = {"SlotGuardaCompra", 0, 0 };
    static const QUParameter param_slot_23[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_23 = {"SlotCapturandoDscCompra", 1, param_slot_23 };
    static const QUMethod slot_24 = {"SlotCargaCompra", 0, 0 };
    static const QUMethod slot_25 = {"SlotCapturoDescripcion", 0, 0 };
    static const QUMethod slot_26 = {"SlotGuardarComo", 0, 0 };
    static const QUMethod slot_27 = {"SlotOtroProveedor", 0, 0 };
    static const QUMethod slot_28 = {"SlotArchivoCompraProveedor", 0, 0 };
    static const QUParameter param_slot_29[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_29 = {"SlotAOtraCelda", 2, param_slot_29 };
    static const QUMethod slot_30 = {"SlotBodegas", 0, 0 };
    static const QUMethod slot_31 = {"SlotRegParProductos", 0, 0 };
    static const QUParameter param_slot_32[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_32 = {"SlotAgregandoParaRegistroParcial", 4, param_slot_32 };
    static const QMetaData slot_tbl[] = {
	{ "SlotCapturandoNumFactura(const QString&)", &slot_0, QMetaData::Private },
	{ "SlotCapturandoCostoEnvio(const QString&)", &slot_1, QMetaData::Private },
	{ "SlotCapturandoCostoDolar(const QString&)", &slot_2, QMetaData::Private },
	{ "SlotCapturandoCostoAdministrativo(const QString&)", &slot_3, QMetaData::Private },
	{ "SlotCapturandoNumPartidas(const QString&)", &slot_4, QMetaData::Private },
	{ "SlotCapturandoCantidad(const QString&)", &slot_5, QMetaData::Private },
	{ "SlotCapturandoCostoUnitario(const QString&)", &slot_6, QMetaData::Private },
	{ "SlotSeleccionoProducto(zSiscomRegistro*)", &slot_7, QMetaData::Private },
	{ "SlotSeleccionoProveedor(zSiscomRegistro*)", &slot_8, QMetaData::Private },
	{ "SlotFocoACostoUnitario()", &slot_9, QMetaData::Private },
	{ "SlotFocoAAnexar()", &slot_10, QMetaData::Private },
	{ "SlotFocoACotizacionDolar()", &slot_11, QMetaData::Private },
	{ "SlotFocoACostoAdministrativo()", &slot_12, QMetaData::Private },
	{ "SlotFocoANumPartidas()", &slot_13, QMetaData::Private },
	{ "SlotFocoACostoEnvio()", &slot_14, QMetaData::Private },
	{ "SlotFocoAProductos()", &slot_15, QMetaData::Private },
	{ "SlotAnexarProducto()", &slot_16, QMetaData::Private },
	{ "SlotRegistraCompra()", &slot_17, QMetaData::Private },
	{ "SlotEliminar()", &slot_18, QMetaData::Private },
	{ "SlotSeleccionaProducto(int,int,int,const QPoint&)", &slot_19, QMetaData::Private },
	{ "SlotProveedores()", &slot_20, QMetaData::Private },
	{ "SlotActualiza()", &slot_21, QMetaData::Private },
	{ "SlotGuardaCompra()", &slot_22, QMetaData::Private },
	{ "SlotCapturandoDscCompra(const QString&)", &slot_23, QMetaData::Private },
	{ "SlotCargaCompra()", &slot_24, QMetaData::Private },
	{ "SlotCapturoDescripcion()", &slot_25, QMetaData::Private },
	{ "SlotGuardarComo()", &slot_26, QMetaData::Private },
	{ "SlotOtroProveedor()", &slot_27, QMetaData::Private },
	{ "SlotArchivoCompraProveedor()", &slot_28, QMetaData::Private },
	{ "SlotAOtraCelda(int,int)", &slot_29, QMetaData::Private },
	{ "SlotBodegas()", &slot_30, QMetaData::Private },
	{ "SlotRegParProductos()", &slot_31, QMetaData::Private },
	{ "SlotAgregandoParaRegistroParcial(int,int,int,const QPoint&)", &slot_32, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QComprasImportaciones", parentObject,
	slot_tbl, 33,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QComprasImportaciones.setMetaObject( metaObj );
    return metaObj;
}

void* QComprasImportaciones::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QComprasImportaciones" ) )
	return this;
    return ComprasImportaciones::qt_cast( clname );
}

bool QComprasImportaciones::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotCapturandoNumFactura((const QString&)static_QUType_QString.get(_o+1)); break;
    case 1: SlotCapturandoCostoEnvio((const QString&)static_QUType_QString.get(_o+1)); break;
    case 2: SlotCapturandoCostoDolar((const QString&)static_QUType_QString.get(_o+1)); break;
    case 3: SlotCapturandoCostoAdministrativo((const QString&)static_QUType_QString.get(_o+1)); break;
    case 4: SlotCapturandoNumPartidas((const QString&)static_QUType_QString.get(_o+1)); break;
    case 5: SlotCapturandoCantidad((const QString&)static_QUType_QString.get(_o+1)); break;
    case 6: SlotCapturandoCostoUnitario((const QString&)static_QUType_QString.get(_o+1)); break;
    case 7: SlotSeleccionoProducto((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 8: SlotSeleccionoProveedor((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 9: SlotFocoACostoUnitario(); break;
    case 10: SlotFocoAAnexar(); break;
    case 11: SlotFocoACotizacionDolar(); break;
    case 12: SlotFocoACostoAdministrativo(); break;
    case 13: SlotFocoANumPartidas(); break;
    case 14: SlotFocoACostoEnvio(); break;
    case 15: SlotFocoAProductos(); break;
    case 16: SlotAnexarProducto(); break;
    case 17: SlotRegistraCompra(); break;
    case 18: SlotEliminar(); break;
    case 19: SlotSeleccionaProducto((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 20: SlotProveedores(); break;
    case 21: SlotActualiza(); break;
    case 22: SlotGuardaCompra(); break;
    case 23: SlotCapturandoDscCompra((const QString&)static_QUType_QString.get(_o+1)); break;
    case 24: SlotCargaCompra(); break;
    case 25: SlotCapturoDescripcion(); break;
    case 26: SlotGuardarComo(); break;
    case 27: SlotOtroProveedor(); break;
    case 28: SlotArchivoCompraProveedor(); break;
    case 29: SlotAOtraCelda((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 30: SlotBodegas(); break;
    case 31: SlotRegParProductos(); break;
    case 32: SlotAgregandoParaRegistroParcial((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    default:
	return ComprasImportaciones::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QComprasImportaciones::qt_emit( int _id, QUObject* _o )
{
    return ComprasImportaciones::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QComprasImportaciones::qt_property( int id, int f, QVariant* v)
{
    return ComprasImportaciones::qt_property( id, f, v);
}

bool QComprasImportaciones::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
