/****************************************************************************
** QtImprimiendoRepStockTienda meta object code from reading C++ file 'QtImprimiendoRepStockTienda.h'
**
** Created: Thu Apr 11 21:08:47 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImprimiendoRepStockTienda.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImprimiendoRepStockTienda::className() const
{
    return "QtImprimiendoRepStockTienda";
}

QMetaObject *QtImprimiendoRepStockTienda::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImprimiendoRepStockTienda( "QtImprimiendoRepStockTienda", &QtImprimiendoRepStockTienda::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImprimiendoRepStockTienda::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImprimiendoRepStockTienda", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImprimiendoRepStockTienda::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImprimiendoRepStockTienda", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImprimiendoRepStockTienda::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QtImprimiendoReporte::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QtImprimiendoRepStockTienda", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImprimiendoRepStockTienda.setMetaObject( metaObj );
    return metaObj;
}

void* QtImprimiendoRepStockTienda::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImprimiendoRepStockTienda" ) )
	return this;
    return QtImprimiendoReporte::qt_cast( clname );
}

bool QtImprimiendoRepStockTienda::qt_invoke( int _id, QUObject* _o )
{
    return QtImprimiendoReporte::qt_invoke(_id,_o);
}

bool QtImprimiendoRepStockTienda::qt_emit( int _id, QUObject* _o )
{
    return QtImprimiendoReporte::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImprimiendoRepStockTienda::qt_property( int id, int f, QVariant* v)
{
    return QtImprimiendoReporte::qt_property( id, f, v);
}

bool QtImprimiendoRepStockTienda::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES