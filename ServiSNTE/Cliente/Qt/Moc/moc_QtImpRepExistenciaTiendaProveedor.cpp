/****************************************************************************
** QtImpRepExistenciaTiendaProveedor meta object code from reading C++ file 'QtImpRepExistenciaTiendaProveedor.h'
**
** Created: Thu Aug 15 00:50:58 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpRepExistenciaTiendaProveedor.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpRepExistenciaTiendaProveedor::className() const
{
    return "QtImpRepExistenciaTiendaProveedor";
}

QMetaObject *QtImpRepExistenciaTiendaProveedor::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpRepExistenciaTiendaProveedor( "QtImpRepExistenciaTiendaProveedor", &QtImpRepExistenciaTiendaProveedor::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpRepExistenciaTiendaProveedor::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpRepExistenciaTiendaProveedor", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpRepExistenciaTiendaProveedor::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpRepExistenciaTiendaProveedor", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpRepExistenciaTiendaProveedor::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = RepExistenciaTiendaProveedor::staticMetaObject();
    static const QUMethod slot_0 = {"SlotImprimir", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotImprimir()", &slot_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpRepExistenciaTiendaProveedor", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpRepExistenciaTiendaProveedor.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpRepExistenciaTiendaProveedor::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpRepExistenciaTiendaProveedor" ) )
	return this;
    return RepExistenciaTiendaProveedor::qt_cast( clname );
}

bool QtImpRepExistenciaTiendaProveedor::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotImprimir(); break;
    default:
	return RepExistenciaTiendaProveedor::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpRepExistenciaTiendaProveedor::qt_emit( int _id, QUObject* _o )
{
    return RepExistenciaTiendaProveedor::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpRepExistenciaTiendaProveedor::qt_property( int id, int f, QVariant* v)
{
    return RepExistenciaTiendaProveedor::qt_property( id, f, v);
}

bool QtImpRepExistenciaTiendaProveedor::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
