/****************************************************************************
** QTotalComprasProducto meta object code from reading C++ file 'IMP_TotalComprasProducto.h'
**
** Created: Thu Apr 11 21:40:01 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_TotalComprasProducto.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QTotalComprasProducto::className() const
{
    return "QTotalComprasProducto";
}

QMetaObject *QTotalComprasProducto::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QTotalComprasProducto( "QTotalComprasProducto", &QTotalComprasProducto::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QTotalComprasProducto::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QTotalComprasProducto", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QTotalComprasProducto::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QTotalComprasProducto", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QTotalComprasProducto::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = TotalComprasProducto::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QTotalComprasProducto", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QTotalComprasProducto.setMetaObject( metaObj );
    return metaObj;
}

void* QTotalComprasProducto::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QTotalComprasProducto" ) )
	return this;
    return TotalComprasProducto::qt_cast( clname );
}

bool QTotalComprasProducto::qt_invoke( int _id, QUObject* _o )
{
    return TotalComprasProducto::qt_invoke(_id,_o);
}

bool QTotalComprasProducto::qt_emit( int _id, QUObject* _o )
{
    return TotalComprasProducto::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QTotalComprasProducto::qt_property( int id, int f, QVariant* v)
{
    return TotalComprasProducto::qt_property( id, f, v);
}

bool QTotalComprasProducto::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
