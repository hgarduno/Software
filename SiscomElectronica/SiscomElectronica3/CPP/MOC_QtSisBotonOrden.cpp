/****************************************************************************
** QtSisBotonOrden meta object code from reading C++ file 'QtSisBotonOrden.h'
**
** Created: Fri Apr 12 21:24:42 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtSisBotonOrden.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtSisBotonOrden::className() const
{
    return "QtSisBotonOrden";
}

QMetaObject *QtSisBotonOrden::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtSisBotonOrden( "QtSisBotonOrden", &QtSisBotonOrden::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtSisBotonOrden::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtSisBotonOrden", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtSisBotonOrden::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtSisBotonOrden", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtSisBotonOrden::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QPushButton::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QtSisBotonOrden", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtSisBotonOrden.setMetaObject( metaObj );
    return metaObj;
}

void* QtSisBotonOrden::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtSisBotonOrden" ) )
	return this;
    return QPushButton::qt_cast( clname );
}

bool QtSisBotonOrden::qt_invoke( int _id, QUObject* _o )
{
    return QPushButton::qt_invoke(_id,_o);
}

bool QtSisBotonOrden::qt_emit( int _id, QUObject* _o )
{
    return QPushButton::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtSisBotonOrden::qt_property( int id, int f, QVariant* v)
{
    return QPushButton::qt_property( id, f, v);
}

bool QtSisBotonOrden::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
