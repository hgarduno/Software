/****************************************************************************
** QtImpCapturaDireccion meta object code from reading C++ file 'QtImpCapturaDireccion.h'
**
<<<<<<< HEAD
** Created: Mon Apr 1 17:29:52 2024
=======
** Created: Thu Apr 11 21:07:58 2024
>>>>>>> d8559e8a5b2006215346761b79004c9434166dbc
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpCapturaDireccion.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpCapturaDireccion::className() const
{
    return "QtImpCapturaDireccion";
}

QMetaObject *QtImpCapturaDireccion::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpCapturaDireccion( "QtImpCapturaDireccion", &QtImpCapturaDireccion::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpCapturaDireccion::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpCapturaDireccion", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpCapturaDireccion::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpCapturaDireccion", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpCapturaDireccion::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CapturaDireccion::staticMetaObject();
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
	{ "SlotFocoAReferencias()", &slot_9, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpCapturaDireccion", parentObject,
	slot_tbl, 10,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpCapturaDireccion.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpCapturaDireccion::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpCapturaDireccion" ) )
	return this;
    return CapturaDireccion::qt_cast( clname );
}

bool QtImpCapturaDireccion::qt_invoke( int _id, QUObject* _o )
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
    default:
	return CapturaDireccion::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpCapturaDireccion::qt_emit( int _id, QUObject* _o )
{
    return CapturaDireccion::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpCapturaDireccion::qt_property( int id, int f, QVariant* v)
{
    return CapturaDireccion::qt_property( id, f, v);
}

bool QtImpCapturaDireccion::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
