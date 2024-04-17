/****************************************************************************
** QDispositivosVendidos meta object code from reading C++ file 'IMP_DispositivosVendidos.h'
**
** Created: Fri Apr 12 21:26:09 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_DispositivosVendidos.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QDispositivosVendidos::className() const
{
    return "QDispositivosVendidos";
}

QMetaObject *QDispositivosVendidos::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QDispositivosVendidos( "QDispositivosVendidos", &QDispositivosVendidos::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QDispositivosVendidos::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QDispositivosVendidos", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QDispositivosVendidos::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QDispositivosVendidos", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QDispositivosVendidos::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = DispositivosVendidos::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QDispositivosVendidos", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QDispositivosVendidos.setMetaObject( metaObj );
    return metaObj;
}

void* QDispositivosVendidos::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QDispositivosVendidos" ) )
	return this;
    return DispositivosVendidos::qt_cast( clname );
}

bool QDispositivosVendidos::qt_invoke( int _id, QUObject* _o )
{
    return DispositivosVendidos::qt_invoke(_id,_o);
}

bool QDispositivosVendidos::qt_emit( int _id, QUObject* _o )
{
    return DispositivosVendidos::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QDispositivosVendidos::qt_property( int id, int f, QVariant* v)
{
    return DispositivosVendidos::qt_property( id, f, v);
}

bool QDispositivosVendidos::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
