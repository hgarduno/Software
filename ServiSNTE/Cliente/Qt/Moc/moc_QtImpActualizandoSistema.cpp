/****************************************************************************
** QtImpActualizandoSistema meta object code from reading C++ file 'QtImpActualizandoSistema.h'
**
** Created: Sat Jan 27 16:41:51 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpActualizandoSistema.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpActualizandoSistema::className() const
{
    return "QtImpActualizandoSistema";
}

QMetaObject *QtImpActualizandoSistema::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpActualizandoSistema( "QtImpActualizandoSistema", &QtImpActualizandoSistema::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpActualizandoSistema::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpActualizandoSistema", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpActualizandoSistema::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpActualizandoSistema", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpActualizandoSistema::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ActualizandoSistema::staticMetaObject();
    static const QUMethod slot_0 = {"reject", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "reject()", &slot_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpActualizandoSistema", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpActualizandoSistema.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpActualizandoSistema::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpActualizandoSistema" ) )
	return this;
    return ActualizandoSistema::qt_cast( clname );
}

bool QtImpActualizandoSistema::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: reject(); break;
    default:
	return ActualizandoSistema::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpActualizandoSistema::qt_emit( int _id, QUObject* _o )
{
    return ActualizandoSistema::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpActualizandoSistema::qt_property( int id, int f, QVariant* v)
{
    return ActualizandoSistema::qt_property( id, f, v);
}

bool QtImpActualizandoSistema::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
