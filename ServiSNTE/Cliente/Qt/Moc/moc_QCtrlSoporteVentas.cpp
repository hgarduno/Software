/****************************************************************************
** QCtrlSoporteVentas meta object code from reading C++ file 'QCtrlSoporteVentas.h'
**
** Created: Sat Jan 27 16:40:33 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QCtrlSoporteVentas.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCtrlSoporteVentas::className() const
{
    return "QCtrlSoporteVentas";
}

QMetaObject *QCtrlSoporteVentas::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCtrlSoporteVentas( "QCtrlSoporteVentas", &QCtrlSoporteVentas::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCtrlSoporteVentas::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrlSoporteVentas", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCtrlSoporteVentas::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrlSoporteVentas", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCtrlSoporteVentas::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QTable::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QCtrlSoporteVentas", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCtrlSoporteVentas.setMetaObject( metaObj );
    return metaObj;
}

void* QCtrlSoporteVentas::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCtrlSoporteVentas" ) )
	return this;
    return QTable::qt_cast( clname );
}

bool QCtrlSoporteVentas::qt_invoke( int _id, QUObject* _o )
{
    return QTable::qt_invoke(_id,_o);
}

bool QCtrlSoporteVentas::qt_emit( int _id, QUObject* _o )
{
    return QTable::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QCtrlSoporteVentas::qt_property( int id, int f, QVariant* v)
{
    return QTable::qt_property( id, f, v);
}

bool QCtrlSoporteVentas::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
