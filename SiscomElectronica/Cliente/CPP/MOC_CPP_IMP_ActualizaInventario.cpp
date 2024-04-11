/****************************************************************************
** QActualizaInventario meta object code from reading C++ file 'IMP_ActualizaInventario.h'
**
** Created: Wed Apr 10 21:11:23 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_ActualizaInventario.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QActualizaInventario::className() const
{
    return "QActualizaInventario";
}

QMetaObject *QActualizaInventario::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QActualizaInventario( "QActualizaInventario", &QActualizaInventario::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QActualizaInventario::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QActualizaInventario", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QActualizaInventario::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QActualizaInventario", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QActualizaInventario::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ActualizaInventario::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QActualizaInventario", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QActualizaInventario.setMetaObject( metaObj );
    return metaObj;
}

void* QActualizaInventario::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QActualizaInventario" ) )
	return this;
    return ActualizaInventario::qt_cast( clname );
}

bool QActualizaInventario::qt_invoke( int _id, QUObject* _o )
{
    return ActualizaInventario::qt_invoke(_id,_o);
}

bool QActualizaInventario::qt_emit( int _id, QUObject* _o )
{
    return ActualizaInventario::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QActualizaInventario::qt_property( int id, int f, QVariant* v)
{
    return ActualizaInventario::qt_property( id, f, v);
}

bool QActualizaInventario::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
