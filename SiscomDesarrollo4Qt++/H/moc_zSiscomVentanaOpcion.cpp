/****************************************************************************
** zSiscomVentanaOpcion meta object code from reading C++ file 'zSiscomVentanaOpcion.h'
**
** Created: Tue Apr 9 11:29:47 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "zSiscomVentanaOpcion.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *zSiscomVentanaOpcion::className() const
{
    return "zSiscomVentanaOpcion";
}

QMetaObject *zSiscomVentanaOpcion::metaObj = 0;
static QMetaObjectCleanUp cleanUp_zSiscomVentanaOpcion( "zSiscomVentanaOpcion", &zSiscomVentanaOpcion::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString zSiscomVentanaOpcion::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "zSiscomVentanaOpcion", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString zSiscomVentanaOpcion::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "zSiscomVentanaOpcion", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* zSiscomVentanaOpcion::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"zSiscomVentanaOpcion", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_zSiscomVentanaOpcion.setMetaObject( metaObj );
    return metaObj;
}

void* zSiscomVentanaOpcion::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "zSiscomVentanaOpcion" ) )
	return this;
    return QWidget::qt_cast( clname );
}

bool zSiscomVentanaOpcion::qt_invoke( int _id, QUObject* _o )
{
    return QWidget::qt_invoke(_id,_o);
}

bool zSiscomVentanaOpcion::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool zSiscomVentanaOpcion::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool zSiscomVentanaOpcion::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
