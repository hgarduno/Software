/****************************************************************************
** QtImpMantenimientoProductos meta object code from reading C++ file 'QtImpMantenimientoProductos.h'
**
** Created: Sat Jan 27 16:40:11 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpMantenimientoProductos.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpMantenimientoProductos::className() const
{
    return "QtImpMantenimientoProductos";
}

QMetaObject *QtImpMantenimientoProductos::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpMantenimientoProductos( "QtImpMantenimientoProductos", &QtImpMantenimientoProductos::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpMantenimientoProductos::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpMantenimientoProductos", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpMantenimientoProductos::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpMantenimientoProductos", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpMantenimientoProductos::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = MantenimientoProductos::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "pzSisRegProveedor", &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotProveedor", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "pzSisRegDepartamento", &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotDepartamento", 1, param_slot_1 };
    static const QUMethod slot_2 = {"SlotFocoANombreProducto", 0, 0 };
    static const QUMethod slot_3 = {"SlotFocoAModelo", 0, 0 };
    static const QUMethod slot_4 = {"SlotFocoAPrecio", 0, 0 };
    static const QUMethod slot_5 = {"SlotFocoAIva", 0, 0 };
    static const QUMethod slot_6 = {"SlotFocoADepartamento", 0, 0 };
    static const QUMethod slot_7 = {"SlotFocoAPorUtilidad", 0, 0 };
    static const QUMethod slot_8 = {"SlotFocoAPrecioForaneo", 0, 0 };
    static const QUMethod slot_9 = {"SlotFocoAPorUtilidadForaneo", 0, 0 };
    static const QUMethod slot_10 = {"SlotFocoADescuento1", 0, 0 };
    static const QUMethod slot_11 = {"SlotFocoADescuento2", 0, 0 };
    static const QUMethod slot_12 = {"SlotFocoADescuento3", 0, 0 };
    static const QUMethod slot_13 = {"SlotFocoADescuento4", 0, 0 };
    static const QUMethod slot_14 = {"SlotUtilidad", 0, 0 };
    static const QUMethod slot_15 = {"SlotGananciaPrecioForaneo", 0, 0 };
    static const QUMethod slot_16 = {"SlotRegistrar", 0, 0 };
    static const QUMethod slot_17 = {"SlotFocoARegistrar", 0, 0 };
    static const QUParameter param_slot_18[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_18 = {"SlotNuevoProducto", 1, param_slot_18 };
    static const QMetaData slot_tbl[] = {
	{ "SlotProveedor(zSiscomRegistro*)", &slot_0, QMetaData::Private },
	{ "SlotDepartamento(zSiscomRegistro*)", &slot_1, QMetaData::Private },
	{ "SlotFocoANombreProducto()", &slot_2, QMetaData::Private },
	{ "SlotFocoAModelo()", &slot_3, QMetaData::Private },
	{ "SlotFocoAPrecio()", &slot_4, QMetaData::Private },
	{ "SlotFocoAIva()", &slot_5, QMetaData::Private },
	{ "SlotFocoADepartamento()", &slot_6, QMetaData::Private },
	{ "SlotFocoAPorUtilidad()", &slot_7, QMetaData::Private },
	{ "SlotFocoAPrecioForaneo()", &slot_8, QMetaData::Private },
	{ "SlotFocoAPorUtilidadForaneo()", &slot_9, QMetaData::Private },
	{ "SlotFocoADescuento1()", &slot_10, QMetaData::Private },
	{ "SlotFocoADescuento2()", &slot_11, QMetaData::Private },
	{ "SlotFocoADescuento3()", &slot_12, QMetaData::Private },
	{ "SlotFocoADescuento4()", &slot_13, QMetaData::Private },
	{ "SlotUtilidad()", &slot_14, QMetaData::Private },
	{ "SlotGananciaPrecioForaneo()", &slot_15, QMetaData::Private },
	{ "SlotRegistrar()", &slot_16, QMetaData::Private },
	{ "SlotFocoARegistrar()", &slot_17, QMetaData::Private },
	{ "SlotNuevoProducto(const QString&)", &slot_18, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpMantenimientoProductos", parentObject,
	slot_tbl, 19,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpMantenimientoProductos.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpMantenimientoProductos::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpMantenimientoProductos" ) )
	return this;
    return MantenimientoProductos::qt_cast( clname );
}

bool QtImpMantenimientoProductos::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotProveedor((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotDepartamento((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 2: SlotFocoANombreProducto(); break;
    case 3: SlotFocoAModelo(); break;
    case 4: SlotFocoAPrecio(); break;
    case 5: SlotFocoAIva(); break;
    case 6: SlotFocoADepartamento(); break;
    case 7: SlotFocoAPorUtilidad(); break;
    case 8: SlotFocoAPrecioForaneo(); break;
    case 9: SlotFocoAPorUtilidadForaneo(); break;
    case 10: SlotFocoADescuento1(); break;
    case 11: SlotFocoADescuento2(); break;
    case 12: SlotFocoADescuento3(); break;
    case 13: SlotFocoADescuento4(); break;
    case 14: SlotUtilidad(); break;
    case 15: SlotGananciaPrecioForaneo(); break;
    case 16: SlotRegistrar(); break;
    case 17: SlotFocoARegistrar(); break;
    case 18: SlotNuevoProducto((const QString&)static_QUType_QString.get(_o+1)); break;
    default:
	return MantenimientoProductos::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpMantenimientoProductos::qt_emit( int _id, QUObject* _o )
{
    return MantenimientoProductos::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpMantenimientoProductos::qt_property( int id, int f, QVariant* v)
{
    return MantenimientoProductos::qt_property( id, f, v);
}

bool QtImpMantenimientoProductos::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
