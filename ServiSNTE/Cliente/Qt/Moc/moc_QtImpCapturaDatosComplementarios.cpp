/****************************************************************************
** QtImpCapturaDatosComplementarios meta object code from reading C++ file 'QtImpCapturaDatosComplementarios.h'
**
** Created: Sat Feb 22 23:13:30 2025
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpCapturaDatosComplementarios.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpCapturaDatosComplementarios::className() const
{
    return "QtImpCapturaDatosComplementarios";
}

QMetaObject *QtImpCapturaDatosComplementarios::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpCapturaDatosComplementarios( "QtImpCapturaDatosComplementarios", &QtImpCapturaDatosComplementarios::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpCapturaDatosComplementarios::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpCapturaDatosComplementarios", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpCapturaDatosComplementarios::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpCapturaDatosComplementarios", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpCapturaDatosComplementarios::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CapturaDatosComplementarios::staticMetaObject();
    static const QUMethod slot_0 = {"reject", 0, 0 };
    static const QUMethod slot_1 = {"SlotAceptar", 0, 0 };
    static const QUMethod slot_2 = {"SlotCancelar", 0, 0 };
    static const QUMethod slot_3 = {"SlotFocoAEspecificar", 0, 0 };
    static const QUMethod slot_4 = {"SlotFocoADependencia", 0, 0 };
    static const QUMethod slot_5 = {"SlotFocoAPuesto", 0, 0 };
    static const QUMethod slot_6 = {"SlotFocoAFunciones", 0, 0 };
    static const QUMethod slot_7 = {"SlotFocoAPeriodo", 0, 0 };
    static const QUMethod slot_8 = {"SlotFocoAAceptar", 0, 0 };
    static const QUMethod slot_9 = {"SlotFocoARegistrar", 0, 0 };
    static const QUParameter param_slot_10[] = {
	{ "pintBoton", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_10 = {"SlotCargoPublico", 1, param_slot_10 };
    static const QUParameter param_slot_11[] = {
	{ "pintBeneficios", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_11 = {"SlotBeneficios", 1, param_slot_11 };
    static const QUParameter param_slot_12[] = {
	{ "pintSiNo", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_12 = {"SlotAportaTercero", 1, param_slot_12 };
    static const QUMethod slot_13 = {"SlotRegistrar", 0, 0 };
    static const QUParameter param_slot_14[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod slot_14 = {"SlotCambioPagina", 1, param_slot_14 };
    static const QUMethod slot_15 = {"SlotFocoAAPaterno", 0, 0 };
    static const QUMethod slot_16 = {"SlotFocoAAMaterno", 0, 0 };
    static const QUMethod slot_17 = {"SlotFocoANombre", 0, 0 };
    static const QUMethod slot_18 = {"SlotFocoACalle", 0, 0 };
    static const QUMethod slot_19 = {"SlotFocoANoExterior", 0, 0 };
    static const QUMethod slot_20 = {"SlotFocoANoInterior", 0, 0 };
    static const QUMethod slot_21 = {"SlotFocoAColonia", 0, 0 };
    static const QUMethod slot_22 = {"SlotFocoADelegacion", 0, 0 };
    static const QUMethod slot_23 = {"SlotFocoAEstado", 0, 0 };
    static const QUMethod slot_24 = {"SlotFocoACodigoPostal", 0, 0 };
    static const QUMethod slot_25 = {"SlotFocoAAgregarReferencia", 0, 0 };
    static const QUMethod slot_26 = {"SlotAgregarReferencia", 0, 0 };
    static const QUMethod slot_27 = {"SlotFocoATelefono", 0, 0 };
    static const QUMethod slot_28 = {"SlotFocoAParentesco", 0, 0 };
    static const QUParameter param_slot_29[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_29 = {"SlotCambioTextoEdit", 1, param_slot_29 };
    static const QMetaData slot_tbl[] = {
	{ "reject()", &slot_0, QMetaData::Private },
	{ "SlotAceptar()", &slot_1, QMetaData::Private },
	{ "SlotCancelar()", &slot_2, QMetaData::Private },
	{ "SlotFocoAEspecificar()", &slot_3, QMetaData::Private },
	{ "SlotFocoADependencia()", &slot_4, QMetaData::Private },
	{ "SlotFocoAPuesto()", &slot_5, QMetaData::Private },
	{ "SlotFocoAFunciones()", &slot_6, QMetaData::Private },
	{ "SlotFocoAPeriodo()", &slot_7, QMetaData::Private },
	{ "SlotFocoAAceptar()", &slot_8, QMetaData::Private },
	{ "SlotFocoARegistrar()", &slot_9, QMetaData::Private },
	{ "SlotCargoPublico(int)", &slot_10, QMetaData::Private },
	{ "SlotBeneficios(int)", &slot_11, QMetaData::Private },
	{ "SlotAportaTercero(int)", &slot_12, QMetaData::Private },
	{ "SlotRegistrar()", &slot_13, QMetaData::Private },
	{ "SlotCambioPagina(QWidget*)", &slot_14, QMetaData::Private },
	{ "SlotFocoAAPaterno()", &slot_15, QMetaData::Private },
	{ "SlotFocoAAMaterno()", &slot_16, QMetaData::Private },
	{ "SlotFocoANombre()", &slot_17, QMetaData::Private },
	{ "SlotFocoACalle()", &slot_18, QMetaData::Private },
	{ "SlotFocoANoExterior()", &slot_19, QMetaData::Private },
	{ "SlotFocoANoInterior()", &slot_20, QMetaData::Private },
	{ "SlotFocoAColonia()", &slot_21, QMetaData::Private },
	{ "SlotFocoADelegacion()", &slot_22, QMetaData::Private },
	{ "SlotFocoAEstado()", &slot_23, QMetaData::Private },
	{ "SlotFocoACodigoPostal()", &slot_24, QMetaData::Private },
	{ "SlotFocoAAgregarReferencia()", &slot_25, QMetaData::Private },
	{ "SlotAgregarReferencia()", &slot_26, QMetaData::Private },
	{ "SlotFocoATelefono()", &slot_27, QMetaData::Private },
	{ "SlotFocoAParentesco()", &slot_28, QMetaData::Private },
	{ "SlotCambioTextoEdit(const QString&)", &slot_29, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpCapturaDatosComplementarios", parentObject,
	slot_tbl, 30,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpCapturaDatosComplementarios.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpCapturaDatosComplementarios::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpCapturaDatosComplementarios" ) )
	return this;
    return CapturaDatosComplementarios::qt_cast( clname );
}

bool QtImpCapturaDatosComplementarios::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: reject(); break;
    case 1: SlotAceptar(); break;
    case 2: SlotCancelar(); break;
    case 3: SlotFocoAEspecificar(); break;
    case 4: SlotFocoADependencia(); break;
    case 5: SlotFocoAPuesto(); break;
    case 6: SlotFocoAFunciones(); break;
    case 7: SlotFocoAPeriodo(); break;
    case 8: SlotFocoAAceptar(); break;
    case 9: SlotFocoARegistrar(); break;
    case 10: SlotCargoPublico((int)static_QUType_int.get(_o+1)); break;
    case 11: SlotBeneficios((int)static_QUType_int.get(_o+1)); break;
    case 12: SlotAportaTercero((int)static_QUType_int.get(_o+1)); break;
    case 13: SlotRegistrar(); break;
    case 14: SlotCambioPagina((QWidget*)static_QUType_ptr.get(_o+1)); break;
    case 15: SlotFocoAAPaterno(); break;
    case 16: SlotFocoAAMaterno(); break;
    case 17: SlotFocoANombre(); break;
    case 18: SlotFocoACalle(); break;
    case 19: SlotFocoANoExterior(); break;
    case 20: SlotFocoANoInterior(); break;
    case 21: SlotFocoAColonia(); break;
    case 22: SlotFocoADelegacion(); break;
    case 23: SlotFocoAEstado(); break;
    case 24: SlotFocoACodigoPostal(); break;
    case 25: SlotFocoAAgregarReferencia(); break;
    case 26: SlotAgregarReferencia(); break;
    case 27: SlotFocoATelefono(); break;
    case 28: SlotFocoAParentesco(); break;
    case 29: SlotCambioTextoEdit((const QString&)static_QUType_QString.get(_o+1)); break;
    default:
	return CapturaDatosComplementarios::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpCapturaDatosComplementarios::qt_emit( int _id, QUObject* _o )
{
    return CapturaDatosComplementarios::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpCapturaDatosComplementarios::qt_property( int id, int f, QVariant* v)
{
    return CapturaDatosComplementarios::qt_property( id, f, v);
}

bool QtImpCapturaDatosComplementarios::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
