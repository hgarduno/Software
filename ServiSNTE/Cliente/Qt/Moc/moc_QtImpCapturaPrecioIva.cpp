/****************************************************************************
** QtImpCapturaPrecioIva meta object code from reading C++ file 'QtImpCapturaPrecioIva.h'
**
** Created: Mon Apr 1 17:30:15 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpCapturaPrecioIva.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpCapturaPrecioIva::className() const
{
    return "QtImpCapturaPrecioIva";
}

QMetaObject *QtImpCapturaPrecioIva::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpCapturaPrecioIva( "QtImpCapturaPrecioIva", &QtImpCapturaPrecioIva::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpCapturaPrecioIva::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpCapturaPrecioIva", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpCapturaPrecioIva::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpCapturaPrecioIva", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpCapturaPrecioIva::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CapturaPrecioIva::staticMetaObject();
    static const QUMethod slot_0 = {"reject", 0, 0 };
    static const QUMethod slot_1 = {"SlotAceptar", 0, 0 };
    static const QUMethod slot_2 = {"SlotCancelar", 0, 0 };
    static const QUMethod slot_3 = {"SlotCantidad", 0, 0 };
    static const QUMethod slot_4 = {"SlotFocoAIva", 0, 0 };
    static const QUMethod slot_5 = {"SlotFocoAceptar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "reject()", &slot_0, QMetaData::Private },
	{ "SlotAceptar()", &slot_1, QMetaData::Private },
	{ "SlotCancelar()", &slot_2, QMetaData::Private },
	{ "SlotCantidad()", &slot_3, QMetaData::Private },
	{ "SlotFocoAIva()", &slot_4, QMetaData::Private },
	{ "SlotFocoAceptar()", &slot_5, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpCapturaPrecioIva", parentObject,
	slot_tbl, 6,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpCapturaPrecioIva.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpCapturaPrecioIva::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpCapturaPrecioIva" ) )
	return this;
    return CapturaPrecioIva::qt_cast( clname );
}

bool QtImpCapturaPrecioIva::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: reject(); break;
    case 1: SlotAceptar(); break;
    case 2: SlotCancelar(); break;
    case 3: SlotCantidad(); break;
    case 4: SlotFocoAIva(); break;
    case 5: SlotFocoAceptar(); break;
    default:
	return CapturaPrecioIva::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpCapturaPrecioIva::qt_emit( int _id, QUObject* _o )
{
    return CapturaPrecioIva::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpCapturaPrecioIva::qt_property( int id, int f, QVariant* v)
{
    return CapturaPrecioIva::qt_property( id, f, v);
}

bool QtImpCapturaPrecioIva::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
