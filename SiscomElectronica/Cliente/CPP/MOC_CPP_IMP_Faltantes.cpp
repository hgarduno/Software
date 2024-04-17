/****************************************************************************
** QFaltantes meta object code from reading C++ file 'IMP_Faltantes.h'
**
** Created: Fri Apr 12 21:26:09 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_Faltantes.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QFaltantes::className() const
{
    return "QFaltantes";
}

QMetaObject *QFaltantes::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QFaltantes( "QFaltantes", &QFaltantes::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QFaltantes::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QFaltantes", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QFaltantes::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QFaltantes", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QFaltantes::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = Faltantes::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QFaltantes", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QFaltantes.setMetaObject( metaObj );
    return metaObj;
}

void* QFaltantes::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QFaltantes" ) )
	return this;
    return Faltantes::qt_cast( clname );
}

bool QFaltantes::qt_invoke( int _id, QUObject* _o )
{
    return Faltantes::qt_invoke(_id,_o);
}

bool QFaltantes::qt_emit( int _id, QUObject* _o )
{
    return Faltantes::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QFaltantes::qt_property( int id, int f, QVariant* v)
{
    return Faltantes::qt_property( id, f, v);
}

bool QFaltantes::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
