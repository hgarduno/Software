/****************************************************************************
** QInventarioBodega4 meta object code from reading C++ file 'IMP_InventarioBodega4.h'
**
** Created: Wed Apr 10 20:52:40 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_InventarioBodega4.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QInventarioBodega4::className() const
{
    return "QInventarioBodega4";
}

QMetaObject *QInventarioBodega4::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QInventarioBodega4( "QInventarioBodega4", &QInventarioBodega4::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QInventarioBodega4::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QInventarioBodega4", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QInventarioBodega4::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QInventarioBodega4", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QInventarioBodega4::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QtInventarioBodega4::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QInventarioBodega4", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QInventarioBodega4.setMetaObject( metaObj );
    return metaObj;
}

void* QInventarioBodega4::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QInventarioBodega4" ) )
	return this;
    return QtInventarioBodega4::qt_cast( clname );
}

bool QInventarioBodega4::qt_invoke( int _id, QUObject* _o )
{
    return QtInventarioBodega4::qt_invoke(_id,_o);
}

bool QInventarioBodega4::qt_emit( int _id, QUObject* _o )
{
    return QtInventarioBodega4::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QInventarioBodega4::qt_property( int id, int f, QVariant* v)
{
    return QtInventarioBodega4::qt_property( id, f, v);
}

bool QInventarioBodega4::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
