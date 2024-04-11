/****************************************************************************
** QGastosExpendio meta object code from reading C++ file 'IMP_GastosExpendio.h'
**
** Created: Wed Apr 10 20:52:40 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_GastosExpendio.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QGastosExpendio::className() const
{
    return "QGastosExpendio";
}

QMetaObject *QGastosExpendio::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QGastosExpendio( "QGastosExpendio", &QGastosExpendio::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QGastosExpendio::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QGastosExpendio", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QGastosExpendio::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QGastosExpendio", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QGastosExpendio::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = GastosExpendio::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QGastosExpendio", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QGastosExpendio.setMetaObject( metaObj );
    return metaObj;
}

void* QGastosExpendio::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QGastosExpendio" ) )
	return this;
    return GastosExpendio::qt_cast( clname );
}

bool QGastosExpendio::qt_invoke( int _id, QUObject* _o )
{
    return GastosExpendio::qt_invoke(_id,_o);
}

bool QGastosExpendio::qt_emit( int _id, QUObject* _o )
{
    return GastosExpendio::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QGastosExpendio::qt_property( int id, int f, QVariant* v)
{
    return GastosExpendio::qt_property( id, f, v);
}

bool QGastosExpendio::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
