/****************************************************************************
** QCompraContenedor2 meta object code from reading C++ file 'IMP_CompraContenedor2.h'
**
** Created: Thu Apr 11 21:40:02 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_CompraContenedor2.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCompraContenedor2::className() const
{
    return "QCompraContenedor2";
}

QMetaObject *QCompraContenedor2::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCompraContenedor2( "QCompraContenedor2", &QCompraContenedor2::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCompraContenedor2::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCompraContenedor2", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCompraContenedor2::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCompraContenedor2", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCompraContenedor2::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QtCompraContenedor2::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QCompraContenedor2", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCompraContenedor2.setMetaObject( metaObj );
    return metaObj;
}

void* QCompraContenedor2::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCompraContenedor2" ) )
	return this;
    return QtCompraContenedor2::qt_cast( clname );
}

bool QCompraContenedor2::qt_invoke( int _id, QUObject* _o )
{
    return QtCompraContenedor2::qt_invoke(_id,_o);
}

bool QCompraContenedor2::qt_emit( int _id, QUObject* _o )
{
    return QtCompraContenedor2::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QCompraContenedor2::qt_property( int id, int f, QVariant* v)
{
    return QtCompraContenedor2::qt_property( id, f, v);
}

bool QCompraContenedor2::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
