/****************************************************************************
** QExtNoAlcanzan meta object code from reading C++ file 'IMP_ExtNoAlcanzan.h'
**
** Created: Thu Apr 11 21:51:25 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_ExtNoAlcanzan.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QExtNoAlcanzan::className() const
{
    return "QExtNoAlcanzan";
}

QMetaObject *QExtNoAlcanzan::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QExtNoAlcanzan( "QExtNoAlcanzan", &QExtNoAlcanzan::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QExtNoAlcanzan::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QExtNoAlcanzan", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QExtNoAlcanzan::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QExtNoAlcanzan", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QExtNoAlcanzan::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ExtNoAlcanzan::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QExtNoAlcanzan", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QExtNoAlcanzan.setMetaObject( metaObj );
    return metaObj;
}

void* QExtNoAlcanzan::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QExtNoAlcanzan" ) )
	return this;
    return ExtNoAlcanzan::qt_cast( clname );
}

bool QExtNoAlcanzan::qt_invoke( int _id, QUObject* _o )
{
    return ExtNoAlcanzan::qt_invoke(_id,_o);
}

bool QExtNoAlcanzan::qt_emit( int _id, QUObject* _o )
{
    return ExtNoAlcanzan::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QExtNoAlcanzan::qt_property( int id, int f, QVariant* v)
{
    return ExtNoAlcanzan::qt_property( id, f, v);
}

bool QExtNoAlcanzan::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
