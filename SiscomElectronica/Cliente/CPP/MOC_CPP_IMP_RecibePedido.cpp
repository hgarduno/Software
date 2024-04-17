/****************************************************************************
** QRecibePedido meta object code from reading C++ file 'IMP_RecibePedido.h'
**
** Created: Fri Apr 12 21:26:09 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_RecibePedido.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QRecibePedido::className() const
{
    return "QRecibePedido";
}

QMetaObject *QRecibePedido::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QRecibePedido( "QRecibePedido", &QRecibePedido::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QRecibePedido::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRecibePedido", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QRecibePedido::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRecibePedido", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QRecibePedido::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = RecibePedido::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QRecibePedido", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QRecibePedido.setMetaObject( metaObj );
    return metaObj;
}

void* QRecibePedido::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QRecibePedido" ) )
	return this;
    return RecibePedido::qt_cast( clname );
}

bool QRecibePedido::qt_invoke( int _id, QUObject* _o )
{
    return RecibePedido::qt_invoke(_id,_o);
}

bool QRecibePedido::qt_emit( int _id, QUObject* _o )
{
    return RecibePedido::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QRecibePedido::qt_property( int id, int f, QVariant* v)
{
    return RecibePedido::qt_property( id, f, v);
}

bool QRecibePedido::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
