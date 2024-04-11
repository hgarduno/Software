/****************************************************************************
** QtImprimeSoporteCompras meta object code from reading C++ file 'QtImprimeSoporteCompras.h'
**
** Created: Sat Jan 27 16:39:34 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImprimeSoporteCompras.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImprimeSoporteCompras::className() const
{
    return "QtImprimeSoporteCompras";
}

QMetaObject *QtImprimeSoporteCompras::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImprimeSoporteCompras( "QtImprimeSoporteCompras", &QtImprimeSoporteCompras::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImprimeSoporteCompras::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImprimeSoporteCompras", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImprimeSoporteCompras::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImprimeSoporteCompras", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImprimeSoporteCompras::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QtImprimeReporte::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QtImprimeSoporteCompras", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImprimeSoporteCompras.setMetaObject( metaObj );
    return metaObj;
}

void* QtImprimeSoporteCompras::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImprimeSoporteCompras" ) )
	return this;
    return QtImprimeReporte::qt_cast( clname );
}

bool QtImprimeSoporteCompras::qt_invoke( int _id, QUObject* _o )
{
    return QtImprimeReporte::qt_invoke(_id,_o);
}

bool QtImprimeSoporteCompras::qt_emit( int _id, QUObject* _o )
{
    return QtImprimeReporte::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImprimeSoporteCompras::qt_property( int id, int f, QVariant* v)
{
    return QtImprimeReporte::qt_property( id, f, v);
}

bool QtImprimeSoporteCompras::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
