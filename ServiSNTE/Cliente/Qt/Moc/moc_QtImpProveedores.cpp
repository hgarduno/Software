/****************************************************************************
** QtImpProveedores meta object code from reading C++ file 'QtImpProveedores.h'
**
** Created: Mon Apr 1 17:29:51 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpProveedores.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpProveedores::className() const
{
    return "QtImpProveedores";
}

QMetaObject *QtImpProveedores::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpProveedores( "QtImpProveedores", &QtImpProveedores::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpProveedores::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpProveedores", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpProveedores::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpProveedores", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpProveedores::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = Proveedores::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QtImpProveedores", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpProveedores.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpProveedores::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpProveedores" ) )
	return this;
    return Proveedores::qt_cast( clname );
}

bool QtImpProveedores::qt_invoke( int _id, QUObject* _o )
{
    return Proveedores::qt_invoke(_id,_o);
}

bool QtImpProveedores::qt_emit( int _id, QUObject* _o )
{
    return Proveedores::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpProveedores::qt_property( int id, int f, QVariant* v)
{
    return Proveedores::qt_property( id, f, v);
}

bool QtImpProveedores::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
