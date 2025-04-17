/****************************************************************************
** QtImpCapturaGeneralesContratoBeneficios meta object code from reading C++ file 'QtImpCapturaGeneralesContratoBeneficios.h'
**
** Created: Sat Feb 22 23:13:32 2025
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpCapturaGeneralesContratoBeneficios.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpCapturaGeneralesContratoBeneficios::className() const
{
    return "QtImpCapturaGeneralesContratoBeneficios";
}

QMetaObject *QtImpCapturaGeneralesContratoBeneficios::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpCapturaGeneralesContratoBeneficios( "QtImpCapturaGeneralesContratoBeneficios", &QtImpCapturaGeneralesContratoBeneficios::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpCapturaGeneralesContratoBeneficios::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpCapturaGeneralesContratoBeneficios", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpCapturaGeneralesContratoBeneficios::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpCapturaGeneralesContratoBeneficios", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpCapturaGeneralesContratoBeneficios::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CapturaGeneralesContratoBeneficios::staticMetaObject();
    static const QUMethod slot_0 = {"SlotFocoAFecha", 0, 0 };
    static const QUMethod slot_1 = {"SlotFocoARegistrar", 0, 0 };
    static const QUMethod slot_2 = {"SlotRegistrar", 0, 0 };
    static const QUMethod slot_3 = {"SlotAceptar", 0, 0 };
    static const QUMethod slot_4 = {"SlotCancelar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotFocoAFecha()", &slot_0, QMetaData::Private },
	{ "SlotFocoARegistrar()", &slot_1, QMetaData::Private },
	{ "SlotRegistrar()", &slot_2, QMetaData::Private },
	{ "SlotAceptar()", &slot_3, QMetaData::Private },
	{ "SlotCancelar()", &slot_4, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpCapturaGeneralesContratoBeneficios", parentObject,
	slot_tbl, 5,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpCapturaGeneralesContratoBeneficios.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpCapturaGeneralesContratoBeneficios::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpCapturaGeneralesContratoBeneficios" ) )
	return this;
    return CapturaGeneralesContratoBeneficios::qt_cast( clname );
}

bool QtImpCapturaGeneralesContratoBeneficios::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotFocoAFecha(); break;
    case 1: SlotFocoARegistrar(); break;
    case 2: SlotRegistrar(); break;
    case 3: SlotAceptar(); break;
    case 4: SlotCancelar(); break;
    default:
	return CapturaGeneralesContratoBeneficios::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpCapturaGeneralesContratoBeneficios::qt_emit( int _id, QUObject* _o )
{
    return CapturaGeneralesContratoBeneficios::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpCapturaGeneralesContratoBeneficios::qt_property( int id, int f, QVariant* v)
{
    return CapturaGeneralesContratoBeneficios::qt_property( id, f, v);
}

bool QtImpCapturaGeneralesContratoBeneficios::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
