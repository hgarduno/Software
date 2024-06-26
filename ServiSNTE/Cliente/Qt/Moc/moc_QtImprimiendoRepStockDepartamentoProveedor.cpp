/****************************************************************************
** QtImprimiendoRepStockDepartamentoProveedor meta object code from reading C++ file 'QtImprimiendoRepStockDepartamentoProveedor.h'
**
** Created: Thu Apr 11 21:08:46 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImprimiendoRepStockDepartamentoProveedor.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImprimiendoRepStockDepartamentoProveedor::className() const
{
    return "QtImprimiendoRepStockDepartamentoProveedor";
}

QMetaObject *QtImprimiendoRepStockDepartamentoProveedor::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImprimiendoRepStockDepartamentoProveedor( "QtImprimiendoRepStockDepartamentoProveedor", &QtImprimiendoRepStockDepartamentoProveedor::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImprimiendoRepStockDepartamentoProveedor::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImprimiendoRepStockDepartamentoProveedor", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImprimiendoRepStockDepartamentoProveedor::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImprimiendoRepStockDepartamentoProveedor", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImprimiendoRepStockDepartamentoProveedor::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QtImprimiendoRepStockDepartamentoProveedor", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImprimiendoRepStockDepartamentoProveedor.setMetaObject( metaObj );
    return metaObj;
}

void* QtImprimiendoRepStockDepartamentoProveedor::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImprimiendoRepStockDepartamentoProveedor" ) )
	return this;
    return QDialog::qt_cast( clname );
}

bool QtImprimiendoRepStockDepartamentoProveedor::qt_invoke( int _id, QUObject* _o )
{
    return QDialog::qt_invoke(_id,_o);
}

bool QtImprimiendoRepStockDepartamentoProveedor::qt_emit( int _id, QUObject* _o )
{
    return QDialog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImprimiendoRepStockDepartamentoProveedor::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool QtImprimiendoRepStockDepartamentoProveedor::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
