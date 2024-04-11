/****************************************************************************
** QtImpCargaBaseDeDatosMaestros meta object code from reading C++ file 'QtImpCargaBaseDeDatosMaestros.h'
**
** Created: Thu Apr 11 21:08:03 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpCargaBaseDeDatosMaestros.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpCargaBaseDeDatosMaestros::className() const
{
    return "QtImpCargaBaseDeDatosMaestros";
}

QMetaObject *QtImpCargaBaseDeDatosMaestros::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpCargaBaseDeDatosMaestros( "QtImpCargaBaseDeDatosMaestros", &QtImpCargaBaseDeDatosMaestros::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpCargaBaseDeDatosMaestros::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpCargaBaseDeDatosMaestros", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpCargaBaseDeDatosMaestros::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpCargaBaseDeDatosMaestros", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpCargaBaseDeDatosMaestros::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CargaBaseDeDatosMaestros::staticMetaObject();
    static const QUMethod slot_0 = {"SlotSelArchivo", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotSelArchivo()", &slot_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpCargaBaseDeDatosMaestros", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpCargaBaseDeDatosMaestros.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpCargaBaseDeDatosMaestros::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpCargaBaseDeDatosMaestros" ) )
	return this;
    return CargaBaseDeDatosMaestros::qt_cast( clname );
}

bool QtImpCargaBaseDeDatosMaestros::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotSelArchivo(); break;
    default:
	return CargaBaseDeDatosMaestros::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpCargaBaseDeDatosMaestros::qt_emit( int _id, QUObject* _o )
{
    return CargaBaseDeDatosMaestros::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpCargaBaseDeDatosMaestros::qt_property( int id, int f, QVariant* v)
{
    return CargaBaseDeDatosMaestros::qt_property( id, f, v);
}

bool QtImpCargaBaseDeDatosMaestros::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
