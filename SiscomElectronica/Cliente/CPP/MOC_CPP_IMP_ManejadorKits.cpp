/****************************************************************************
** QManejadorKits meta object code from reading C++ file 'IMP_ManejadorKits.h'
**
** Created: Wed Apr 10 20:52:40 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_ManejadorKits.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QManejadorKits::className() const
{
    return "QManejadorKits";
}

QMetaObject *QManejadorKits::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QManejadorKits( "QManejadorKits", &QManejadorKits::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QManejadorKits::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QManejadorKits", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QManejadorKits::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QManejadorKits", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QManejadorKits::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ManejadorKits::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "ProductoE", QUParameter::In }
    };
    static const QUMethod slot_0 = {"S_Producto", 1, param_slot_0 };
    static const QUMethod slot_1 = {"S_RegistraKit", 0, 0 };
    static const QUMethod slot_2 = {"S_Anexar", 0, 0 };
    static const QUMethod slot_3 = {"S_FocoAAnexar", 0, 0 };
    static const QUMethod slot_4 = {"S_RegistraProductos", 0, 0 };
    static const QUParameter param_slot_5[] = {
	{ 0, &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_5 = {"S_SeleccionoTipoProducto", 1, param_slot_5 };
    static const QUParameter param_slot_6[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_6 = {"S_Producto", 4, param_slot_6 };
    static const QUParameter param_slot_7[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_7 = {"S_CambiaCantidad", 4, param_slot_7 };
    static const QUMethod slot_8 = {"S_FocoACantidad", 0, 0 };
    static const QUMethod slot_9 = {"S_EliminaProducto", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "S_Producto(ProductoE*)", &slot_0, QMetaData::Private },
	{ "S_RegistraKit()", &slot_1, QMetaData::Private },
	{ "S_Anexar()", &slot_2, QMetaData::Private },
	{ "S_FocoAAnexar()", &slot_3, QMetaData::Private },
	{ "S_RegistraProductos()", &slot_4, QMetaData::Private },
	{ "S_SeleccionoTipoProducto(zSiscomRegistro*)", &slot_5, QMetaData::Private },
	{ "S_Producto(int,int,int,const QPoint&)", &slot_6, QMetaData::Private },
	{ "S_CambiaCantidad(int,int,int,const QPoint&)", &slot_7, QMetaData::Private },
	{ "S_FocoACantidad()", &slot_8, QMetaData::Private },
	{ "S_EliminaProducto()", &slot_9, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QManejadorKits", parentObject,
	slot_tbl, 10,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QManejadorKits.setMetaObject( metaObj );
    return metaObj;
}

void* QManejadorKits::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QManejadorKits" ) )
	return this;
    return ManejadorKits::qt_cast( clname );
}

bool QManejadorKits::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: S_Producto((ProductoE*)static_QUType_ptr.get(_o+1)); break;
    case 1: S_RegistraKit(); break;
    case 2: S_Anexar(); break;
    case 3: S_FocoAAnexar(); break;
    case 4: S_RegistraProductos(); break;
    case 5: S_SeleccionoTipoProducto((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 6: S_Producto((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 7: S_CambiaCantidad((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 8: S_FocoACantidad(); break;
    case 9: S_EliminaProducto(); break;
    default:
	return ManejadorKits::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QManejadorKits::qt_emit( int _id, QUObject* _o )
{
    return ManejadorKits::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QManejadorKits::qt_property( int id, int f, QVariant* v)
{
    return ManejadorKits::qt_property( id, f, v);
}

bool QManejadorKits::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
