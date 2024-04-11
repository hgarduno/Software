/****************************************************************************
** QtImpCapturaDatosGenerales meta object code from reading C++ file 'QtImpCapturaDatosGenerales.h'
**
** Created: Sat Jan 27 16:39:10 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpCapturaDatosGenerales.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpCapturaDatosGenerales::className() const
{
    return "QtImpCapturaDatosGenerales";
}

QMetaObject *QtImpCapturaDatosGenerales::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpCapturaDatosGenerales( "QtImpCapturaDatosGenerales", &QtImpCapturaDatosGenerales::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpCapturaDatosGenerales::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpCapturaDatosGenerales", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpCapturaDatosGenerales::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpCapturaDatosGenerales", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpCapturaDatosGenerales::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CapturaDatosGenerales::staticMetaObject();
    static const QUMethod slot_0 = {"reject", 0, 0 };
    static const QUMethod slot_1 = {"SlotAceptar", 0, 0 };
    static const QUMethod slot_2 = {"SlotCancelar", 0, 0 };
    static const QUMethod slot_3 = {"SlotRegistrar", 0, 0 };
    static const QUMethod slot_4 = {"SlotFocoACurp", 0, 0 };
    static const QUMethod slot_5 = {"SlotFocoAEstadoNacimiento", 0, 0 };
    static const QUMethod slot_6 = {"SlotFocoAPaisNacimiento", 0, 0 };
    static const QUMethod slot_7 = {"SlotFocoAMasculino", 0, 0 };
    static const QUMethod slot_8 = {"SlotFocoAFechaNacimiento", 0, 0 };
    static const QUMethod slot_9 = {"SlotFocoAIdentificacion", 0, 0 };
    static const QUMethod slot_10 = {"SlotFocoANoIdentificacion", 0, 0 };
    static const QUMethod slot_11 = {"SlotFocoAOcupacion", 0, 0 };
    static const QUMethod slot_12 = {"SlotFocoANacionalidad", 0, 0 };
    static const QUMethod slot_13 = {"SlotFocoARegistrar", 0, 0 };
    static const QUParameter param_slot_14[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_14 = {"SlotSeleccionaSexo", 1, param_slot_14 };
    static const QUMethod slot_15 = {"SlotActualizaGenerales", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "reject()", &slot_0, QMetaData::Private },
	{ "SlotAceptar()", &slot_1, QMetaData::Private },
	{ "SlotCancelar()", &slot_2, QMetaData::Private },
	{ "SlotRegistrar()", &slot_3, QMetaData::Private },
	{ "SlotFocoACurp()", &slot_4, QMetaData::Private },
	{ "SlotFocoAEstadoNacimiento()", &slot_5, QMetaData::Private },
	{ "SlotFocoAPaisNacimiento()", &slot_6, QMetaData::Private },
	{ "SlotFocoAMasculino()", &slot_7, QMetaData::Private },
	{ "SlotFocoAFechaNacimiento()", &slot_8, QMetaData::Private },
	{ "SlotFocoAIdentificacion()", &slot_9, QMetaData::Private },
	{ "SlotFocoANoIdentificacion()", &slot_10, QMetaData::Private },
	{ "SlotFocoAOcupacion()", &slot_11, QMetaData::Private },
	{ "SlotFocoANacionalidad()", &slot_12, QMetaData::Private },
	{ "SlotFocoARegistrar()", &slot_13, QMetaData::Private },
	{ "SlotSeleccionaSexo(int)", &slot_14, QMetaData::Private },
	{ "SlotActualizaGenerales()", &slot_15, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpCapturaDatosGenerales", parentObject,
	slot_tbl, 16,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpCapturaDatosGenerales.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpCapturaDatosGenerales::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpCapturaDatosGenerales" ) )
	return this;
    return CapturaDatosGenerales::qt_cast( clname );
}

bool QtImpCapturaDatosGenerales::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: reject(); break;
    case 1: SlotAceptar(); break;
    case 2: SlotCancelar(); break;
    case 3: SlotRegistrar(); break;
    case 4: SlotFocoACurp(); break;
    case 5: SlotFocoAEstadoNacimiento(); break;
    case 6: SlotFocoAPaisNacimiento(); break;
    case 7: SlotFocoAMasculino(); break;
    case 8: SlotFocoAFechaNacimiento(); break;
    case 9: SlotFocoAIdentificacion(); break;
    case 10: SlotFocoANoIdentificacion(); break;
    case 11: SlotFocoAOcupacion(); break;
    case 12: SlotFocoANacionalidad(); break;
    case 13: SlotFocoARegistrar(); break;
    case 14: SlotSeleccionaSexo((int)static_QUType_int.get(_o+1)); break;
    case 15: SlotActualizaGenerales(); break;
    default:
	return CapturaDatosGenerales::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpCapturaDatosGenerales::qt_emit( int _id, QUObject* _o )
{
    return CapturaDatosGenerales::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpCapturaDatosGenerales::qt_property( int id, int f, QVariant* v)
{
    return CapturaDatosGenerales::qt_property( id, f, v);
}

bool QtImpCapturaDatosGenerales::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
