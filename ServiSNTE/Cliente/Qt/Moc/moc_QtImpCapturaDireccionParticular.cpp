/****************************************************************************
** QtImpCapturaDireccionParticular meta object code from reading C++ file 'QtImpCapturaDireccionParticular.h'
**
** Created: Tue Jun 24 08:59:36 2025
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpCapturaDireccionParticular.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpCapturaDireccionParticular::className() const
{
    return "QtImpCapturaDireccionParticular";
}

QMetaObject *QtImpCapturaDireccionParticular::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpCapturaDireccionParticular( "QtImpCapturaDireccionParticular", &QtImpCapturaDireccionParticular::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpCapturaDireccionParticular::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpCapturaDireccionParticular", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpCapturaDireccionParticular::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpCapturaDireccionParticular", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpCapturaDireccionParticular::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CapturaDireccionParticular::staticMetaObject();
    static const QUMethod slot_0 = {"reject", 0, 0 };
    static const QUMethod slot_1 = {"SlotAceptar", 0, 0 };
    static const QUMethod slot_2 = {"SlotCancelar", 0, 0 };
    static const QUMethod slot_3 = {"SlotFocoANoExterior", 0, 0 };
    static const QUMethod slot_4 = {"SlotFocoANoInterior", 0, 0 };
    static const QUMethod slot_5 = {"SlotFocoAColonia", 0, 0 };
    static const QUMethod slot_6 = {"SlotFocoADelegacionMunicipio", 0, 0 };
    static const QUMethod slot_7 = {"SlotFocoAEstado", 0, 0 };
    static const QUMethod slot_8 = {"SlotFocoACodigoPostal", 0, 0 };
    static const QUMethod slot_9 = {"SlotFocoAReferencias", 0, 0 };
    static const QUParameter param_slot_10[] = {
	{ "pzSisRegTVivienda", &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_10 = {"SlotTipoVivienda", 1, param_slot_10 };
    static const QUMethod slot_11 = {"SlotFocoATiempoResidir", 0, 0 };
    static const QUMethod slot_12 = {"SlotFocoAAceptar", 0, 0 };
    static const QUMethod slot_13 = {"SlotFocoARegistrar", 0, 0 };
    static const QUMethod slot_14 = {"SlotRegistrar", 0, 0 };
    static const QUParameter param_slot_15[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_15 = {"SlotCambiaTiempoResidir", 1, param_slot_15 };
    static const QMetaData slot_tbl[] = {
	{ "reject()", &slot_0, QMetaData::Private },
	{ "SlotAceptar()", &slot_1, QMetaData::Private },
	{ "SlotCancelar()", &slot_2, QMetaData::Private },
	{ "SlotFocoANoExterior()", &slot_3, QMetaData::Private },
	{ "SlotFocoANoInterior()", &slot_4, QMetaData::Private },
	{ "SlotFocoAColonia()", &slot_5, QMetaData::Private },
	{ "SlotFocoADelegacionMunicipio()", &slot_6, QMetaData::Private },
	{ "SlotFocoAEstado()", &slot_7, QMetaData::Private },
	{ "SlotFocoACodigoPostal()", &slot_8, QMetaData::Private },
	{ "SlotFocoAReferencias()", &slot_9, QMetaData::Private },
	{ "SlotTipoVivienda(zSiscomRegistro*)", &slot_10, QMetaData::Private },
	{ "SlotFocoATiempoResidir()", &slot_11, QMetaData::Private },
	{ "SlotFocoAAceptar()", &slot_12, QMetaData::Private },
	{ "SlotFocoARegistrar()", &slot_13, QMetaData::Private },
	{ "SlotRegistrar()", &slot_14, QMetaData::Private },
	{ "SlotCambiaTiempoResidir(const QString&)", &slot_15, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpCapturaDireccionParticular", parentObject,
	slot_tbl, 16,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpCapturaDireccionParticular.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpCapturaDireccionParticular::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpCapturaDireccionParticular" ) )
	return this;
    return CapturaDireccionParticular::qt_cast( clname );
}

bool QtImpCapturaDireccionParticular::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: reject(); break;
    case 1: SlotAceptar(); break;
    case 2: SlotCancelar(); break;
    case 3: SlotFocoANoExterior(); break;
    case 4: SlotFocoANoInterior(); break;
    case 5: SlotFocoAColonia(); break;
    case 6: SlotFocoADelegacionMunicipio(); break;
    case 7: SlotFocoAEstado(); break;
    case 8: SlotFocoACodigoPostal(); break;
    case 9: SlotFocoAReferencias(); break;
    case 10: SlotTipoVivienda((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 11: SlotFocoATiempoResidir(); break;
    case 12: SlotFocoAAceptar(); break;
    case 13: SlotFocoARegistrar(); break;
    case 14: SlotRegistrar(); break;
    case 15: SlotCambiaTiempoResidir((const QString&)static_QUType_QString.get(_o+1)); break;
    default:
	return CapturaDireccionParticular::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpCapturaDireccionParticular::qt_emit( int _id, QUObject* _o )
{
    return CapturaDireccionParticular::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpCapturaDireccionParticular::qt_property( int id, int f, QVariant* v)
{
    return CapturaDireccionParticular::qt_property( id, f, v);
}

bool QtImpCapturaDireccionParticular::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
