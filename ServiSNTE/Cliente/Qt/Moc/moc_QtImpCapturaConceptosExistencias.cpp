/****************************************************************************
** QtImpCapturaConceptosExistencias meta object code from reading C++ file 'QtImpCapturaConceptosExistencias.h'
**
** Created: Mon Apr 1 17:29:56 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpCapturaConceptosExistencias.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpCapturaConceptosExistencias::className() const
{
    return "QtImpCapturaConceptosExistencias";
}

QMetaObject *QtImpCapturaConceptosExistencias::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpCapturaConceptosExistencias( "QtImpCapturaConceptosExistencias", &QtImpCapturaConceptosExistencias::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpCapturaConceptosExistencias::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpCapturaConceptosExistencias", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpCapturaConceptosExistencias::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpCapturaConceptosExistencias", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpCapturaConceptosExistencias::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CapturaConceptosExistencias::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QtImpCapturaConceptosExistencias", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpCapturaConceptosExistencias.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpCapturaConceptosExistencias::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpCapturaConceptosExistencias" ) )
	return this;
    return CapturaConceptosExistencias::qt_cast( clname );
}

bool QtImpCapturaConceptosExistencias::qt_invoke( int _id, QUObject* _o )
{
    return CapturaConceptosExistencias::qt_invoke(_id,_o);
}

bool QtImpCapturaConceptosExistencias::qt_emit( int _id, QUObject* _o )
{
    return CapturaConceptosExistencias::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpCapturaConceptosExistencias::qt_property( int id, int f, QVariant* v)
{
    return CapturaConceptosExistencias::qt_property( id, f, v);
}

bool QtImpCapturaConceptosExistencias::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
