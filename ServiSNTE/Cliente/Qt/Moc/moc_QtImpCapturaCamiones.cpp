/****************************************************************************
** QtImpCapturaCamiones meta object code from reading C++ file 'QtImpCapturaCamiones.h'
**
** Created: Thu Apr 11 21:07:59 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpCapturaCamiones.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpCapturaCamiones::className() const
{
    return "QtImpCapturaCamiones";
}

QMetaObject *QtImpCapturaCamiones::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpCapturaCamiones( "QtImpCapturaCamiones", &QtImpCapturaCamiones::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpCapturaCamiones::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpCapturaCamiones", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpCapturaCamiones::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpCapturaCamiones", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpCapturaCamiones::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CapturaCamiones::staticMetaObject();
    static const QUMethod slot_0 = {"reject", 0, 0 };
    static const QUMethod slot_1 = {"SlotCrear", 0, 0 };
    static const QUMethod slot_2 = {"SlotCancelar", 0, 0 };
    static const QUMethod slot_3 = {"SlotFocoANombre", 0, 0 };
    static const QUMethod slot_4 = {"SlotFocoAMarca", 0, 0 };
    static const QUMethod slot_5 = {"SlotFocoATipo", 0, 0 };
    static const QUMethod slot_6 = {"SlotFocoAModelo", 0, 0 };
    static const QUMethod slot_7 = {"SlotFocoAPlacas", 0, 0 };
    static const QUMethod slot_8 = {"SlotFocoACrear", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "reject()", &slot_0, QMetaData::Private },
	{ "SlotCrear()", &slot_1, QMetaData::Private },
	{ "SlotCancelar()", &slot_2, QMetaData::Private },
	{ "SlotFocoANombre()", &slot_3, QMetaData::Private },
	{ "SlotFocoAMarca()", &slot_4, QMetaData::Private },
	{ "SlotFocoATipo()", &slot_5, QMetaData::Private },
	{ "SlotFocoAModelo()", &slot_6, QMetaData::Private },
	{ "SlotFocoAPlacas()", &slot_7, QMetaData::Private },
	{ "SlotFocoACrear()", &slot_8, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpCapturaCamiones", parentObject,
	slot_tbl, 9,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpCapturaCamiones.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpCapturaCamiones::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpCapturaCamiones" ) )
	return this;
    return CapturaCamiones::qt_cast( clname );
}

bool QtImpCapturaCamiones::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: reject(); break;
    case 1: SlotCrear(); break;
    case 2: SlotCancelar(); break;
    case 3: SlotFocoANombre(); break;
    case 4: SlotFocoAMarca(); break;
    case 5: SlotFocoATipo(); break;
    case 6: SlotFocoAModelo(); break;
    case 7: SlotFocoAPlacas(); break;
    case 8: SlotFocoACrear(); break;
    default:
	return CapturaCamiones::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpCapturaCamiones::qt_emit( int _id, QUObject* _o )
{
    return CapturaCamiones::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpCapturaCamiones::qt_property( int id, int f, QVariant* v)
{
    return CapturaCamiones::qt_property( id, f, v);
}

bool QtImpCapturaCamiones::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
