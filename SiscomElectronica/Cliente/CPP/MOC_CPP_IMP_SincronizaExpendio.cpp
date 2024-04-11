/****************************************************************************
** QSincronizaExpendio meta object code from reading C++ file 'IMP_SincronizaExpendio.h'
**
** Created: Wed Apr 10 20:52:39 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_SincronizaExpendio.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QSincronizaExpendio::className() const
{
    return "QSincronizaExpendio";
}

QMetaObject *QSincronizaExpendio::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QSincronizaExpendio( "QSincronizaExpendio", &QSincronizaExpendio::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QSincronizaExpendio::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSincronizaExpendio", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QSincronizaExpendio::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSincronizaExpendio", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QSincronizaExpendio::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QtSincronizaExpendio::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QSincronizaExpendio", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QSincronizaExpendio.setMetaObject( metaObj );
    return metaObj;
}

void* QSincronizaExpendio::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QSincronizaExpendio" ) )
	return this;
    return QtSincronizaExpendio::qt_cast( clname );
}

bool QSincronizaExpendio::qt_invoke( int _id, QUObject* _o )
{
    return QtSincronizaExpendio::qt_invoke(_id,_o);
}

bool QSincronizaExpendio::qt_emit( int _id, QUObject* _o )
{
    return QtSincronizaExpendio::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QSincronizaExpendio::qt_property( int id, int f, QVariant* v)
{
    return QtSincronizaExpendio::qt_property( id, f, v);
}

bool QSincronizaExpendio::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
