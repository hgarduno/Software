/****************************************************************************
** QtImpBeneficiosIntegrales meta object code from reading C++ file 'QtImpBeneficiosIntegrales.h'
**
** Created: Tue Jun 24 08:59:34 2025
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpBeneficiosIntegrales.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpBeneficiosIntegrales::className() const
{
    return "QtImpBeneficiosIntegrales";
}

QMetaObject *QtImpBeneficiosIntegrales::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpBeneficiosIntegrales( "QtImpBeneficiosIntegrales", &QtImpBeneficiosIntegrales::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpBeneficiosIntegrales::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpBeneficiosIntegrales", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpBeneficiosIntegrales::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpBeneficiosIntegrales", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpBeneficiosIntegrales::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = BeneficiosIntegrales::staticMetaObject();
    static const QUMethod slot_0 = {"SlotSeleccionaCredito", 0, 0 };
    static const QUMethod slot_1 = {"SlotCapturaDatosEmpleo", 0, 0 };
    static const QUMethod slot_2 = {"SlotCapturaDireccionParticular", 0, 0 };
    static const QUMethod slot_3 = {"SlotCapturaDatosComplementarios", 0, 0 };
    static const QUMethod slot_4 = {"SlotImprimeContrato", 0, 0 };
    static const QUMethod slot_5 = {"SlotImprimeContratoAArchivo", 0, 0 };
    static const QUMethod slot_6 = {"SlotImprimeFrente", 0, 0 };
    static const QUMethod slot_7 = {"SlotImprimeAtras", 0, 0 };
    static const QUMethod slot_8 = {"SlotPosicionesBeneficios", 0, 0 };
    static const QUMethod slot_9 = {"SlotCapturaDatosGenerales", 0, 0 };
    static const QUMethod slot_10 = {"SlotCapturaDatosComunicacion", 0, 0 };
    static const QUMethod slot_11 = {"SlotGeneralesContrato", 0, 0 };
    static const QUMethod slot_12 = {"SlotCentroTrabajo", 0, 0 };
    static const QUMethod slot_13 = {"SlotCreditosBeneficiosIntegrales", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotSeleccionaCredito()", &slot_0, QMetaData::Private },
	{ "SlotCapturaDatosEmpleo()", &slot_1, QMetaData::Private },
	{ "SlotCapturaDireccionParticular()", &slot_2, QMetaData::Private },
	{ "SlotCapturaDatosComplementarios()", &slot_3, QMetaData::Private },
	{ "SlotImprimeContrato()", &slot_4, QMetaData::Private },
	{ "SlotImprimeContratoAArchivo()", &slot_5, QMetaData::Private },
	{ "SlotImprimeFrente()", &slot_6, QMetaData::Private },
	{ "SlotImprimeAtras()", &slot_7, QMetaData::Private },
	{ "SlotPosicionesBeneficios()", &slot_8, QMetaData::Private },
	{ "SlotCapturaDatosGenerales()", &slot_9, QMetaData::Private },
	{ "SlotCapturaDatosComunicacion()", &slot_10, QMetaData::Private },
	{ "SlotGeneralesContrato()", &slot_11, QMetaData::Private },
	{ "SlotCentroTrabajo()", &slot_12, QMetaData::Private },
	{ "SlotCreditosBeneficiosIntegrales()", &slot_13, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpBeneficiosIntegrales", parentObject,
	slot_tbl, 14,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpBeneficiosIntegrales.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpBeneficiosIntegrales::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpBeneficiosIntegrales" ) )
	return this;
    return BeneficiosIntegrales::qt_cast( clname );
}

bool QtImpBeneficiosIntegrales::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotSeleccionaCredito(); break;
    case 1: SlotCapturaDatosEmpleo(); break;
    case 2: SlotCapturaDireccionParticular(); break;
    case 3: SlotCapturaDatosComplementarios(); break;
    case 4: SlotImprimeContrato(); break;
    case 5: SlotImprimeContratoAArchivo(); break;
    case 6: SlotImprimeFrente(); break;
    case 7: SlotImprimeAtras(); break;
    case 8: SlotPosicionesBeneficios(); break;
    case 9: SlotCapturaDatosGenerales(); break;
    case 10: SlotCapturaDatosComunicacion(); break;
    case 11: SlotGeneralesContrato(); break;
    case 12: SlotCentroTrabajo(); break;
    case 13: SlotCreditosBeneficiosIntegrales(); break;
    default:
	return BeneficiosIntegrales::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpBeneficiosIntegrales::qt_emit( int _id, QUObject* _o )
{
    return BeneficiosIntegrales::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpBeneficiosIntegrales::qt_property( int id, int f, QVariant* v)
{
    return BeneficiosIntegrales::qt_property( id, f, v);
}

bool QtImpBeneficiosIntegrales::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
