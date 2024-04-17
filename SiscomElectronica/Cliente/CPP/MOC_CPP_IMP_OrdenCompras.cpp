/****************************************************************************
** QOrdenCompras meta object code from reading C++ file 'IMP_OrdenCompras.h'
**
** Created: Fri Apr 12 21:26:09 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_OrdenCompras.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QOrdenCompras::className() const
{
    return "QOrdenCompras";
}

QMetaObject *QOrdenCompras::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QOrdenCompras( "QOrdenCompras", &QOrdenCompras::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QOrdenCompras::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QOrdenCompras", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QOrdenCompras::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QOrdenCompras", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QOrdenCompras::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = OrdenCompras::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "pProductoE", &static_QUType_ptr, "ProductoE", QUParameter::In }
    };
    static const QUMethod slot_0 = {"S_Producto", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_1 = {"S_SeleccionaProducto", 4, param_slot_1 };
    static const QUMethod slot_2 = {"SlotProductosFaltantes", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "S_Producto(ProductoE*)", &slot_0, QMetaData::Private },
	{ "S_SeleccionaProducto(int,int,int,const QPoint&)", &slot_1, QMetaData::Private },
	{ "SlotProductosFaltantes()", &slot_2, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QOrdenCompras", parentObject,
	slot_tbl, 3,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QOrdenCompras.setMetaObject( metaObj );
    return metaObj;
}

void* QOrdenCompras::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QOrdenCompras" ) )
	return this;
    return OrdenCompras::qt_cast( clname );
}

bool QOrdenCompras::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: S_Producto((ProductoE*)static_QUType_ptr.get(_o+1)); break;
    case 1: S_SeleccionaProducto((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 2: SlotProductosFaltantes(); break;
    default:
	return OrdenCompras::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QOrdenCompras::qt_emit( int _id, QUObject* _o )
{
    return OrdenCompras::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QOrdenCompras::qt_property( int id, int f, QVariant* v)
{
    return OrdenCompras::qt_property( id, f, v);
}

bool QOrdenCompras::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
