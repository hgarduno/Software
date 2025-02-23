/****************************************************************************
** QtImpCapturaChoferes meta object code from reading C++ file 'QtImpCapturaChoferes.h'
**
** Created: Sat Feb 22 23:13:22 2025
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpCapturaChoferes.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpCapturaChoferes::className() const
{
    return "QtImpCapturaChoferes";
}

QMetaObject *QtImpCapturaChoferes::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpCapturaChoferes( "QtImpCapturaChoferes", &QtImpCapturaChoferes::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpCapturaChoferes::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpCapturaChoferes", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpCapturaChoferes::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpCapturaChoferes", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpCapturaChoferes::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CapturaChoferes::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QtImpCapturaChoferes", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpCapturaChoferes.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpCapturaChoferes::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpCapturaChoferes" ) )
	return this;
    return CapturaChoferes::qt_cast( clname );
}

bool QtImpCapturaChoferes::qt_invoke( int _id, QUObject* _o )
{
    return CapturaChoferes::qt_invoke(_id,_o);
}

bool QtImpCapturaChoferes::qt_emit( int _id, QUObject* _o )
{
    return CapturaChoferes::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpCapturaChoferes::qt_property( int id, int f, QVariant* v)
{
    return CapturaChoferes::qt_property( id, f, v);
}

bool QtImpCapturaChoferes::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
