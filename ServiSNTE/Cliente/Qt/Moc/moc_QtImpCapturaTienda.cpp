/****************************************************************************
** QtImpCapturaTienda meta object code from reading C++ file 'QtImpCapturaTienda.h'
**
** Created: Sat Jan 27 16:38:48 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpCapturaTienda.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpCapturaTienda::className() const
{
    return "QtImpCapturaTienda";
}

QMetaObject *QtImpCapturaTienda::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpCapturaTienda( "QtImpCapturaTienda", &QtImpCapturaTienda::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpCapturaTienda::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpCapturaTienda", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpCapturaTienda::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpCapturaTienda", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpCapturaTienda::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CapturaTienda::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QtImpCapturaTienda", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpCapturaTienda.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpCapturaTienda::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpCapturaTienda" ) )
	return this;
    return CapturaTienda::qt_cast( clname );
}

bool QtImpCapturaTienda::qt_invoke( int _id, QUObject* _o )
{
    return CapturaTienda::qt_invoke(_id,_o);
}

bool QtImpCapturaTienda::qt_emit( int _id, QUObject* _o )
{
    return CapturaTienda::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpCapturaTienda::qt_property( int id, int f, QVariant* v)
{
    return CapturaTienda::qt_property( id, f, v);
}

bool QtImpCapturaTienda::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
