/****************************************************************************
** QProductoApartados meta object code from reading C++ file 'IMP_ProductoApartados.h'
**
** Created: Fri Apr 12 21:26:09 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_ProductoApartados.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QProductoApartados::className() const
{
    return "QProductoApartados";
}

QMetaObject *QProductoApartados::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QProductoApartados( "QProductoApartados", &QProductoApartados::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QProductoApartados::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QProductoApartados", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QProductoApartados::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QProductoApartados", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QProductoApartados::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ProductoApartados::staticMetaObject();
    static const QUMethod slot_0 = {"SlotAceptar", 0, 0 };
    static const QUMethod slot_1 = {"SlotCancelar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotAceptar()", &slot_0, QMetaData::Private },
	{ "SlotCancelar()", &slot_1, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QProductoApartados", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QProductoApartados.setMetaObject( metaObj );
    return metaObj;
}

void* QProductoApartados::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QProductoApartados" ) )
	return this;
    return ProductoApartados::qt_cast( clname );
}

bool QProductoApartados::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotAceptar(); break;
    case 1: SlotCancelar(); break;
    default:
	return ProductoApartados::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QProductoApartados::qt_emit( int _id, QUObject* _o )
{
    return ProductoApartados::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QProductoApartados::qt_property( int id, int f, QVariant* v)
{
    return ProductoApartados::qt_property( id, f, v);
}

bool QProductoApartados::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
