/****************************************************************************
** zVentanaPrueba meta object code from reading C++ file 'ClasesMenus.h'
**
** Created: Tue May 25 13:25:17 2021
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "ClasesMenus.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *zVentanaPrueba::className() const
{
    return "zVentanaPrueba";
}

QMetaObject *zVentanaPrueba::metaObj = 0;
static QMetaObjectCleanUp cleanUp_zVentanaPrueba( "zVentanaPrueba", &zVentanaPrueba::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString zVentanaPrueba::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "zVentanaPrueba", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString zVentanaPrueba::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "zVentanaPrueba", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* zVentanaPrueba::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = zSiscomVentana::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"zVentanaPrueba", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_zVentanaPrueba.setMetaObject( metaObj );
    return metaObj;
}

void* zVentanaPrueba::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "zVentanaPrueba" ) )
	return this;
    return zSiscomVentana::qt_cast( clname );
}

bool zVentanaPrueba::qt_invoke( int _id, QUObject* _o )
{
    return zSiscomVentana::qt_invoke(_id,_o);
}

bool zVentanaPrueba::qt_emit( int _id, QUObject* _o )
{
    return zSiscomVentana::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool zVentanaPrueba::qt_property( int id, int f, QVariant* v)
{
    return zSiscomVentana::qt_property( id, f, v);
}

bool zVentanaPrueba::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
