/****************************************************************************
** zDibujando meta object code from reading C++ file 'Dibujando.h'
**
** Created: Tue May 25 15:16:56 2021
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "Dibujando.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *zDibujando::className() const
{
    return "zDibujando";
}

QMetaObject *zDibujando::metaObj = 0;
static QMetaObjectCleanUp cleanUp_zDibujando( "zDibujando", &zDibujando::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString zDibujando::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "zDibujando", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString zDibujando::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "zDibujando", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* zDibujando::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = zSiscomDibujando::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"zDibujando", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_zDibujando.setMetaObject( metaObj );
    return metaObj;
}

void* zDibujando::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "zDibujando" ) )
	return this;
    return zSiscomDibujando::qt_cast( clname );
}

bool zDibujando::qt_invoke( int _id, QUObject* _o )
{
    return zSiscomDibujando::qt_invoke(_id,_o);
}

bool zDibujando::qt_emit( int _id, QUObject* _o )
{
    return zSiscomDibujando::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool zDibujando::qt_property( int id, int f, QVariant* v)
{
    return zSiscomDibujando::qt_property( id, f, v);
}

bool zDibujando::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES