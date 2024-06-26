/****************************************************************************
** QtImpCatalogoStock meta object code from reading C++ file 'QtImpCatalogoStock.h'
**
<<<<<<< HEAD
** Created: Mon Apr 1 17:30:13 2024
=======
** Created: Thu Apr 11 21:08:19 2024
>>>>>>> d8559e8a5b2006215346761b79004c9434166dbc
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpCatalogoStock.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpCatalogoStock::className() const
{
    return "QtImpCatalogoStock";
}

QMetaObject *QtImpCatalogoStock::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpCatalogoStock( "QtImpCatalogoStock", &QtImpCatalogoStock::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpCatalogoStock::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpCatalogoStock", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpCatalogoStock::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpCatalogoStock", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpCatalogoStock::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CatalogoStock::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QtImpCatalogoStock", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpCatalogoStock.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpCatalogoStock::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpCatalogoStock" ) )
	return this;
    return CatalogoStock::qt_cast( clname );
}

bool QtImpCatalogoStock::qt_invoke( int _id, QUObject* _o )
{
    return CatalogoStock::qt_invoke(_id,_o);
}

bool QtImpCatalogoStock::qt_emit( int _id, QUObject* _o )
{
    return CatalogoStock::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpCatalogoStock::qt_property( int id, int f, QVariant* v)
{
    return CatalogoStock::qt_property( id, f, v);
}

bool QtImpCatalogoStock::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
