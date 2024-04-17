/****************************************************************************
** QMantenProductos meta object code from reading C++ file 'IMP_MantenProductos.h'
**
** Created: Fri Apr 12 21:35:30 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_MantenProductos.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QMantenProductos::className() const
{
    return "QMantenProductos";
}

QMetaObject *QMantenProductos::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QMantenProductos( "QMantenProductos", &QMantenProductos::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QMantenProductos::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QMantenProductos", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QMantenProductos::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QMantenProductos", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QMantenProductos::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = MantenProductos::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "ProductoE", QUParameter::In }
    };
    static const QUMethod slot_0 = {"S_SelProducto", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_ptr, "Familia", QUParameter::In }
    };
    static const QUMethod slot_1 = {"S_SelFamilia", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_ptr, "Unidad", QUParameter::In }
    };
    static const QUMethod slot_2 = {"S_SelUnidad", 1, param_slot_2 };
    static const QUMethod slot_3 = {"S_ModificaProducto", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "S_SelProducto(ProductoE*)", &slot_0, QMetaData::Private },
	{ "S_SelFamilia(Familia*)", &slot_1, QMetaData::Private },
	{ "S_SelUnidad(Unidad*)", &slot_2, QMetaData::Private },
	{ "S_ModificaProducto()", &slot_3, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QMantenProductos", parentObject,
	slot_tbl, 4,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QMantenProductos.setMetaObject( metaObj );
    return metaObj;
}

void* QMantenProductos::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QMantenProductos" ) )
	return this;
    return MantenProductos::qt_cast( clname );
}

bool QMantenProductos::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: S_SelProducto((ProductoE*)static_QUType_ptr.get(_o+1)); break;
    case 1: S_SelFamilia((Familia*)static_QUType_ptr.get(_o+1)); break;
    case 2: S_SelUnidad((Unidad*)static_QUType_ptr.get(_o+1)); break;
    case 3: S_ModificaProducto(); break;
    default:
	return MantenProductos::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QMantenProductos::qt_emit( int _id, QUObject* _o )
{
    return MantenProductos::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QMantenProductos::qt_property( int id, int f, QVariant* v)
{
    return MantenProductos::qt_property( id, f, v);
}

bool QMantenProductos::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
