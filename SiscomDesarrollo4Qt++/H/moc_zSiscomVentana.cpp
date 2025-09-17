/****************************************************************************
** zSiscomVentana meta object code from reading C++ file 'zSiscomVentana.h'
**
** Created: Thu Sep 11 19:12:20 2025
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "zSiscomVentana.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *zSiscomVentana::className() const
{
    return "zSiscomVentana";
}

QMetaObject *zSiscomVentana::metaObj = 0;
static QMetaObjectCleanUp cleanUp_zSiscomVentana( "zSiscomVentana", &zSiscomVentana::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString zSiscomVentana::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "zSiscomVentana", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString zSiscomVentana::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "zSiscomVentana", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* zSiscomVentana::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QMainWindow::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "zSiscomQAction", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotSelecciono", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "pzSisConexion", &static_QUType_ptr, "zSiscomConexion", QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotInicioPantalla", 1, param_slot_1 };
    static const QMetaData slot_tbl[] = {
	{ "SlotSelecciono(zSiscomQAction*)", &slot_0, QMetaData::Private },
	{ "SlotInicioPantalla(zSiscomConexion*)", &slot_1, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"zSiscomVentana", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_zSiscomVentana.setMetaObject( metaObj );
    return metaObj;
}

void* zSiscomVentana::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "zSiscomVentana" ) )
	return this;
    return QMainWindow::qt_cast( clname );
}

bool zSiscomVentana::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotSelecciono((zSiscomQAction*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotInicioPantalla((zSiscomConexion*)static_QUType_ptr.get(_o+1)); break;
    default:
	return QMainWindow::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool zSiscomVentana::qt_emit( int _id, QUObject* _o )
{
    return QMainWindow::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool zSiscomVentana::qt_property( int id, int f, QVariant* v)
{
    return QMainWindow::qt_property( id, f, v);
}

bool zSiscomVentana::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
