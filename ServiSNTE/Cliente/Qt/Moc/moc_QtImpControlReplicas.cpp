/****************************************************************************
** QtImpControlReplicas meta object code from reading C++ file 'QtImpControlReplicas.h'
**
** Created: Tue Jun 24 08:59:35 2025
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpControlReplicas.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpControlReplicas::className() const
{
    return "QtImpControlReplicas";
}

QMetaObject *QtImpControlReplicas::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpControlReplicas( "QtImpControlReplicas", &QtImpControlReplicas::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpControlReplicas::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpControlReplicas", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpControlReplicas::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpControlReplicas", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpControlReplicas::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ControlReplicas::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QtImpControlReplicas", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpControlReplicas.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpControlReplicas::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpControlReplicas" ) )
	return this;
    return ControlReplicas::qt_cast( clname );
}

bool QtImpControlReplicas::qt_invoke( int _id, QUObject* _o )
{
    return ControlReplicas::qt_invoke(_id,_o);
}

bool QtImpControlReplicas::qt_emit( int _id, QUObject* _o )
{
    return ControlReplicas::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpControlReplicas::qt_property( int id, int f, QVariant* v)
{
    return ControlReplicas::qt_property( id, f, v);
}

bool QtImpControlReplicas::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
