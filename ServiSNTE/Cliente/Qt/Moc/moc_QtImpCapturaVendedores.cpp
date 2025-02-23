/****************************************************************************
** QtImpCapturaVendedores meta object code from reading C++ file 'QtImpCapturaVendedores.h'
**
** Created: Sat Feb 22 23:13:22 2025
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpCapturaVendedores.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpCapturaVendedores::className() const
{
    return "QtImpCapturaVendedores";
}

QMetaObject *QtImpCapturaVendedores::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpCapturaVendedores( "QtImpCapturaVendedores", &QtImpCapturaVendedores::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpCapturaVendedores::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpCapturaVendedores", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpCapturaVendedores::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpCapturaVendedores", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpCapturaVendedores::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CapturaVendedores::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QtImpCapturaVendedores", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpCapturaVendedores.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpCapturaVendedores::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpCapturaVendedores" ) )
	return this;
    return CapturaVendedores::qt_cast( clname );
}

bool QtImpCapturaVendedores::qt_invoke( int _id, QUObject* _o )
{
    return CapturaVendedores::qt_invoke(_id,_o);
}

bool QtImpCapturaVendedores::qt_emit( int _id, QUObject* _o )
{
    return CapturaVendedores::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpCapturaVendedores::qt_property( int id, int f, QVariant* v)
{
    return CapturaVendedores::qt_property( id, f, v);
}

bool QtImpCapturaVendedores::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
