/****************************************************************************
** QExpendioOrigen meta object code from reading C++ file 'IMP_ExpendioOrigen.h'
**
** Created: Wed Apr 10 20:52:40 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_ExpendioOrigen.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QExpendioOrigen::className() const
{
    return "QExpendioOrigen";
}

QMetaObject *QExpendioOrigen::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QExpendioOrigen( "QExpendioOrigen", &QExpendioOrigen::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QExpendioOrigen::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QExpendioOrigen", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QExpendioOrigen::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QExpendioOrigen", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QExpendioOrigen::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QtExpendioOrigen::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QExpendioOrigen", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QExpendioOrigen.setMetaObject( metaObj );
    return metaObj;
}

void* QExpendioOrigen::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QExpendioOrigen" ) )
	return this;
    return QtExpendioOrigen::qt_cast( clname );
}

bool QExpendioOrigen::qt_invoke( int _id, QUObject* _o )
{
    return QtExpendioOrigen::qt_invoke(_id,_o);
}

bool QExpendioOrigen::qt_emit( int _id, QUObject* _o )
{
    return QtExpendioOrigen::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QExpendioOrigen::qt_property( int id, int f, QVariant* v)
{
    return QtExpendioOrigen::qt_property( id, f, v);
}

bool QExpendioOrigen::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
