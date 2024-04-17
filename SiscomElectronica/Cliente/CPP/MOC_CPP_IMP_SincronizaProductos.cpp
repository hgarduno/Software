/****************************************************************************
** QSincronizaProductos meta object code from reading C++ file 'IMP_SincronizaProductos.h'
**
** Created: Fri Apr 12 21:26:09 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_SincronizaProductos.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QSincronizaProductos::className() const
{
    return "QSincronizaProductos";
}

QMetaObject *QSincronizaProductos::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QSincronizaProductos( "QSincronizaProductos", &QSincronizaProductos::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QSincronizaProductos::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSincronizaProductos", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QSincronizaProductos::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSincronizaProductos", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QSincronizaProductos::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QtSincronizaProductos::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QSincronizaProductos", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QSincronizaProductos.setMetaObject( metaObj );
    return metaObj;
}

void* QSincronizaProductos::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QSincronizaProductos" ) )
	return this;
    return QtSincronizaProductos::qt_cast( clname );
}

bool QSincronizaProductos::qt_invoke( int _id, QUObject* _o )
{
    return QtSincronizaProductos::qt_invoke(_id,_o);
}

bool QSincronizaProductos::qt_emit( int _id, QUObject* _o )
{
    return QtSincronizaProductos::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QSincronizaProductos::qt_property( int id, int f, QVariant* v)
{
    return QtSincronizaProductos::qt_property( id, f, v);
}

bool QSincronizaProductos::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
