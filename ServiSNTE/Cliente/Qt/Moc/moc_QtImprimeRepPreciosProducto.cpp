/****************************************************************************
** QtImprimeRepPreciosProducto meta object code from reading C++ file 'QtImprimeRepPreciosProducto.h'
**
** Created: Thu Apr 11 21:08:30 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImprimeRepPreciosProducto.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImprimeRepPreciosProducto::className() const
{
    return "QtImprimeRepPreciosProducto";
}

QMetaObject *QtImprimeRepPreciosProducto::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImprimeRepPreciosProducto( "QtImprimeRepPreciosProducto", &QtImprimeRepPreciosProducto::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImprimeRepPreciosProducto::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImprimeRepPreciosProducto", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImprimeRepPreciosProducto::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImprimeRepPreciosProducto", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImprimeRepPreciosProducto::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QtImprimeReporte::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QtImprimeRepPreciosProducto", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImprimeRepPreciosProducto.setMetaObject( metaObj );
    return metaObj;
}

void* QtImprimeRepPreciosProducto::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImprimeRepPreciosProducto" ) )
	return this;
    return QtImprimeReporte::qt_cast( clname );
}

bool QtImprimeRepPreciosProducto::qt_invoke( int _id, QUObject* _o )
{
    return QtImprimeReporte::qt_invoke(_id,_o);
}

bool QtImprimeRepPreciosProducto::qt_emit( int _id, QUObject* _o )
{
    return QtImprimeReporte::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImprimeRepPreciosProducto::qt_property( int id, int f, QVariant* v)
{
    return QtImprimeReporte::qt_property( id, f, v);
}

bool QtImprimeRepPreciosProducto::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
