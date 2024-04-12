/****************************************************************************
** QPedidoMaterial meta object code from reading C++ file 'IMP_PedidoMaterial.h'
**
** Created: Thu Apr 11 21:40:01 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_PedidoMaterial.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QPedidoMaterial::className() const
{
    return "QPedidoMaterial";
}

QMetaObject *QPedidoMaterial::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QPedidoMaterial( "QPedidoMaterial", &QPedidoMaterial::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QPedidoMaterial::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QPedidoMaterial", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QPedidoMaterial::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QPedidoMaterial", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QPedidoMaterial::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = PedidoMaterial::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "ProductoE", QUParameter::In }
    };
    static const QUMethod slot_0 = {"S_Producto", 1, param_slot_0 };
    static const QUMethod slot_1 = {"S_Anexar", 0, 0 };
    static const QUMethod slot_2 = {"S_FocoAAnexar", 0, 0 };
    static const QUMethod slot_3 = {"S_RegistraPedidoMaterial", 0, 0 };
    static const QUParameter param_slot_4[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_4 = {"S_SeleccionoTabla", 4, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_5 = {"S_EliminaProducto", 4, param_slot_5 };
    static const QUMethod slot_6 = {"S_EliminaProducto", 0, 0 };
    static const QUMethod slot_7 = {"S_PedidosPendientes", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "S_Producto(ProductoE*)", &slot_0, QMetaData::Private },
	{ "S_Anexar()", &slot_1, QMetaData::Private },
	{ "S_FocoAAnexar()", &slot_2, QMetaData::Private },
	{ "S_RegistraPedidoMaterial()", &slot_3, QMetaData::Private },
	{ "S_SeleccionoTabla(int,int,int,const QPoint&)", &slot_4, QMetaData::Private },
	{ "S_EliminaProducto(int,int,int,const QPoint&)", &slot_5, QMetaData::Private },
	{ "S_EliminaProducto()", &slot_6, QMetaData::Private },
	{ "S_PedidosPendientes()", &slot_7, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QPedidoMaterial", parentObject,
	slot_tbl, 8,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QPedidoMaterial.setMetaObject( metaObj );
    return metaObj;
}

void* QPedidoMaterial::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QPedidoMaterial" ) )
	return this;
    return PedidoMaterial::qt_cast( clname );
}

bool QPedidoMaterial::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: S_Producto((ProductoE*)static_QUType_ptr.get(_o+1)); break;
    case 1: S_Anexar(); break;
    case 2: S_FocoAAnexar(); break;
    case 3: S_RegistraPedidoMaterial(); break;
    case 4: S_SeleccionoTabla((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 5: S_EliminaProducto((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 6: S_EliminaProducto(); break;
    case 7: S_PedidosPendientes(); break;
    default:
	return PedidoMaterial::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QPedidoMaterial::qt_emit( int _id, QUObject* _o )
{
    return PedidoMaterial::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QPedidoMaterial::qt_property( int id, int f, QVariant* v)
{
    return PedidoMaterial::qt_property( id, f, v);
}

bool QPedidoMaterial::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
