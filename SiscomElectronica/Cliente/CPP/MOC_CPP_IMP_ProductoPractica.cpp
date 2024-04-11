/****************************************************************************
** QProductoPractica meta object code from reading C++ file 'IMP_ProductoPractica.h'
**
** Created: Wed Apr 10 21:11:28 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_ProductoPractica.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QProductoPractica::className() const
{
    return "QProductoPractica";
}

QMetaObject *QProductoPractica::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QProductoPractica( "QProductoPractica", &QProductoPractica::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QProductoPractica::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QProductoPractica", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QProductoPractica::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QProductoPractica", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QProductoPractica::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ProductoPractica::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "ProductoE", QUParameter::In }
    };
    static const QUMethod slot_0 = {"S_SeleccionoProducto", 1, param_slot_0 };
    static const QUMethod slot_1 = {"S_PasaFocoAnexar", 0, 0 };
    static const QUMethod slot_2 = {"S_Anexar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "S_SeleccionoProducto(ProductoE*)", &slot_0, QMetaData::Private },
	{ "S_PasaFocoAnexar()", &slot_1, QMetaData::Private },
	{ "S_Anexar()", &slot_2, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QProductoPractica", parentObject,
	slot_tbl, 3,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QProductoPractica.setMetaObject( metaObj );
    return metaObj;
}

void* QProductoPractica::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QProductoPractica" ) )
	return this;
    return ProductoPractica::qt_cast( clname );
}

bool QProductoPractica::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: S_SeleccionoProducto((ProductoE*)static_QUType_ptr.get(_o+1)); break;
    case 1: S_PasaFocoAnexar(); break;
    case 2: S_Anexar(); break;
    default:
	return ProductoPractica::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QProductoPractica::qt_emit( int _id, QUObject* _o )
{
    return ProductoPractica::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QProductoPractica::qt_property( int id, int f, QVariant* v)
{
    return ProductoPractica::qt_property( id, f, v);
}

bool QProductoPractica::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
