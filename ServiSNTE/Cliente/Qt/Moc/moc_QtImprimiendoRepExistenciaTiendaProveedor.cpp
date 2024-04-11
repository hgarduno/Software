/****************************************************************************
** QtImprimiendoRepExistenciaTiendaProveedor meta object code from reading C++ file 'QtImprimiendoRepExistenciaTiendaProveedor.h'
**
** Created: Sat Jan 27 16:39:54 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImprimiendoRepExistenciaTiendaProveedor.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImprimiendoRepExistenciaTiendaProveedor::className() const
{
    return "QtImprimiendoRepExistenciaTiendaProveedor";
}

QMetaObject *QtImprimiendoRepExistenciaTiendaProveedor::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImprimiendoRepExistenciaTiendaProveedor( "QtImprimiendoRepExistenciaTiendaProveedor", &QtImprimiendoRepExistenciaTiendaProveedor::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImprimiendoRepExistenciaTiendaProveedor::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImprimiendoRepExistenciaTiendaProveedor", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImprimiendoRepExistenciaTiendaProveedor::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImprimiendoRepExistenciaTiendaProveedor", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImprimiendoRepExistenciaTiendaProveedor::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QtImprimiendoReporte::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QtImprimiendoRepExistenciaTiendaProveedor", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImprimiendoRepExistenciaTiendaProveedor.setMetaObject( metaObj );
    return metaObj;
}

void* QtImprimiendoRepExistenciaTiendaProveedor::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImprimiendoRepExistenciaTiendaProveedor" ) )
	return this;
    return QtImprimiendoReporte::qt_cast( clname );
}

bool QtImprimiendoRepExistenciaTiendaProveedor::qt_invoke( int _id, QUObject* _o )
{
    return QtImprimiendoReporte::qt_invoke(_id,_o);
}

bool QtImprimiendoRepExistenciaTiendaProveedor::qt_emit( int _id, QUObject* _o )
{
    return QtImprimiendoReporte::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImprimiendoRepExistenciaTiendaProveedor::qt_property( int id, int f, QVariant* v)
{
    return QtImprimiendoReporte::qt_property( id, f, v);
}

bool QtImprimiendoRepExistenciaTiendaProveedor::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
