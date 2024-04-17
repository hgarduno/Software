/****************************************************************************
** QListaPuntosEntrega meta object code from reading C++ file 'IMP_ListaPuntosEntrega.h'
**
** Created: Fri Apr 12 21:26:09 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_ListaPuntosEntrega.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QListaPuntosEntrega::className() const
{
    return "QListaPuntosEntrega";
}

QMetaObject *QListaPuntosEntrega::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QListaPuntosEntrega( "QListaPuntosEntrega", &QListaPuntosEntrega::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QListaPuntosEntrega::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QListaPuntosEntrega", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QListaPuntosEntrega::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QListaPuntosEntrega", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QListaPuntosEntrega::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QtListaPuntosEntrega::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QListaPuntosEntrega", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QListaPuntosEntrega.setMetaObject( metaObj );
    return metaObj;
}

void* QListaPuntosEntrega::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QListaPuntosEntrega" ) )
	return this;
    return QtListaPuntosEntrega::qt_cast( clname );
}

bool QListaPuntosEntrega::qt_invoke( int _id, QUObject* _o )
{
    return QtListaPuntosEntrega::qt_invoke(_id,_o);
}

bool QListaPuntosEntrega::qt_emit( int _id, QUObject* _o )
{
    return QtListaPuntosEntrega::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QListaPuntosEntrega::qt_property( int id, int f, QVariant* v)
{
    return QtListaPuntosEntrega::qt_property( id, f, v);
}

bool QListaPuntosEntrega::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
