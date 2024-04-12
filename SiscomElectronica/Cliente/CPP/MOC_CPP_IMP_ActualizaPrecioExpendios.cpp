/****************************************************************************
** QActualizaPrecioExpendios meta object code from reading C++ file 'IMP_ActualizaPrecioExpendios.h'
**
** Created: Thu Apr 11 21:40:02 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_ActualizaPrecioExpendios.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QActualizaPrecioExpendios::className() const
{
    return "QActualizaPrecioExpendios";
}

QMetaObject *QActualizaPrecioExpendios::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QActualizaPrecioExpendios( "QActualizaPrecioExpendios", &QActualizaPrecioExpendios::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QActualizaPrecioExpendios::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QActualizaPrecioExpendios", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QActualizaPrecioExpendios::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QActualizaPrecioExpendios", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QActualizaPrecioExpendios::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QtActualizaPrecioExpendios::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QActualizaPrecioExpendios", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QActualizaPrecioExpendios.setMetaObject( metaObj );
    return metaObj;
}

void* QActualizaPrecioExpendios::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QActualizaPrecioExpendios" ) )
	return this;
    return QtActualizaPrecioExpendios::qt_cast( clname );
}

bool QActualizaPrecioExpendios::qt_invoke( int _id, QUObject* _o )
{
    return QtActualizaPrecioExpendios::qt_invoke(_id,_o);
}

bool QActualizaPrecioExpendios::qt_emit( int _id, QUObject* _o )
{
    return QtActualizaPrecioExpendios::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QActualizaPrecioExpendios::qt_property( int id, int f, QVariant* v)
{
    return QtActualizaPrecioExpendios::qt_property( id, f, v);
}

bool QActualizaPrecioExpendios::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
