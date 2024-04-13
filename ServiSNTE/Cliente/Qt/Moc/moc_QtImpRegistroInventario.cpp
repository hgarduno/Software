/****************************************************************************
** QtImpRegistroInventario meta object code from reading C++ file 'QtImpRegistroInventario.h'
**
** Created: Mon Apr 1 17:30:51 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpRegistroInventario.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpRegistroInventario::className() const
{
    return "QtImpRegistroInventario";
}

QMetaObject *QtImpRegistroInventario::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpRegistroInventario( "QtImpRegistroInventario", &QtImpRegistroInventario::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpRegistroInventario::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpRegistroInventario", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpRegistroInventario::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpRegistroInventario", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpRegistroInventario::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = RegistroInventario::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QtImpRegistroInventario", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpRegistroInventario.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpRegistroInventario::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpRegistroInventario" ) )
	return this;
    return RegistroInventario::qt_cast( clname );
}

bool QtImpRegistroInventario::qt_invoke( int _id, QUObject* _o )
{
    return RegistroInventario::qt_invoke(_id,_o);
}

bool QtImpRegistroInventario::qt_emit( int _id, QUObject* _o )
{
    return RegistroInventario::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpRegistroInventario::qt_property( int id, int f, QVariant* v)
{
    return RegistroInventario::qt_property( id, f, v);
}

bool QtImpRegistroInventario::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
