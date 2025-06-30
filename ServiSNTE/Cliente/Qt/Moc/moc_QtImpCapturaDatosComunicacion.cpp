/****************************************************************************
** QtImpCapturaDatosComunicacion meta object code from reading C++ file 'QtImpCapturaDatosComunicacion.h'
**
** Created: Tue Jun 24 08:59:37 2025
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpCapturaDatosComunicacion.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpCapturaDatosComunicacion::className() const
{
    return "QtImpCapturaDatosComunicacion";
}

QMetaObject *QtImpCapturaDatosComunicacion::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpCapturaDatosComunicacion( "QtImpCapturaDatosComunicacion", &QtImpCapturaDatosComunicacion::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpCapturaDatosComunicacion::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpCapturaDatosComunicacion", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpCapturaDatosComunicacion::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpCapturaDatosComunicacion", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpCapturaDatosComunicacion::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CapturaDatosComunicacion::staticMetaObject();
    static const QUMethod slot_0 = {"reject", 0, 0 };
    static const QUMethod slot_1 = {"SlotAceptar", 0, 0 };
    static const QUMethod slot_2 = {"SlotCancelar", 0, 0 };
    static const QUMethod slot_3 = {"SlotRegistrar", 0, 0 };
    static const QUMethod slot_4 = {"SlotFocoARegistrar", 0, 0 };
    static const QUMethod slot_5 = {"SlotFocoATelefonoCelular", 0, 0 };
    static const QUMethod slot_6 = {"SlotFocoATelefonoRecado", 0, 0 };
    static const QUMethod slot_7 = {"SlotFocoACorreoElectronico", 0, 0 };
    static const QUMethod slot_8 = {"SlotActualiza", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "reject()", &slot_0, QMetaData::Private },
	{ "SlotAceptar()", &slot_1, QMetaData::Private },
	{ "SlotCancelar()", &slot_2, QMetaData::Private },
	{ "SlotRegistrar()", &slot_3, QMetaData::Private },
	{ "SlotFocoARegistrar()", &slot_4, QMetaData::Private },
	{ "SlotFocoATelefonoCelular()", &slot_5, QMetaData::Private },
	{ "SlotFocoATelefonoRecado()", &slot_6, QMetaData::Private },
	{ "SlotFocoACorreoElectronico()", &slot_7, QMetaData::Private },
	{ "SlotActualiza()", &slot_8, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpCapturaDatosComunicacion", parentObject,
	slot_tbl, 9,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpCapturaDatosComunicacion.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpCapturaDatosComunicacion::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpCapturaDatosComunicacion" ) )
	return this;
    return CapturaDatosComunicacion::qt_cast( clname );
}

bool QtImpCapturaDatosComunicacion::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: reject(); break;
    case 1: SlotAceptar(); break;
    case 2: SlotCancelar(); break;
    case 3: SlotRegistrar(); break;
    case 4: SlotFocoARegistrar(); break;
    case 5: SlotFocoATelefonoCelular(); break;
    case 6: SlotFocoATelefonoRecado(); break;
    case 7: SlotFocoACorreoElectronico(); break;
    case 8: SlotActualiza(); break;
    default:
	return CapturaDatosComunicacion::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpCapturaDatosComunicacion::qt_emit( int _id, QUObject* _o )
{
    return CapturaDatosComunicacion::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpCapturaDatosComunicacion::qt_property( int id, int f, QVariant* v)
{
    return CapturaDatosComunicacion::qt_property( id, f, v);
}

bool QtImpCapturaDatosComunicacion::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
