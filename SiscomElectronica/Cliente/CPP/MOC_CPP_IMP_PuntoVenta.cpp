/****************************************************************************
** QPuntoVenta meta object code from reading C++ file 'IMP_PuntoVenta.h'
**
** Created: Fri Apr 12 21:26:09 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_PuntoVenta.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QPuntoVenta::className() const
{
    return "QPuntoVenta";
}

QMetaObject *QPuntoVenta::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QPuntoVenta( "QPuntoVenta", &QPuntoVenta::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QPuntoVenta::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QPuntoVenta", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QPuntoVenta::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QPuntoVenta", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QPuntoVenta::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = PuntoVenta::staticMetaObject();
    static const QUMethod slot_0 = {"SlotCargaArchivoHtml", 0, 0 };
    static const QUParameter param_slot_1[] = {
	{ "pzSisRegProducto", &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotSeleccionoProducto", 1, param_slot_1 };
    static const QUMethod slot_2 = {"SlotFocoAProductos", 0, 0 };
    static const QUMethod slot_3 = {"SlotIncrementaTexto", 0, 0 };
    static const QUMethod slot_4 = {"SlotDecrementaTexto", 0, 0 };
    static const QUParameter param_slot_5[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"SlotSeleccionoLink", 1, param_slot_5 };
    static const QUParameter param_slot_6[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_6 = {"SlotClicked", 2, param_slot_6 };
    static const QUParameter param_slot_7[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_7 = {"SlotSeleccionoLink", 2, param_slot_7 };
    static const QUMethod slot_8 = {"SlotAnexarOrden", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotCargaArchivoHtml()", &slot_0, QMetaData::Private },
	{ "SlotSeleccionoProducto(zSiscomRegistro*)", &slot_1, QMetaData::Private },
	{ "SlotFocoAProductos()", &slot_2, QMetaData::Private },
	{ "SlotIncrementaTexto()", &slot_3, QMetaData::Private },
	{ "SlotDecrementaTexto()", &slot_4, QMetaData::Private },
	{ "SlotSeleccionoLink(const QString&)", &slot_5, QMetaData::Private },
	{ "SlotClicked(int,int)", &slot_6, QMetaData::Private },
	{ "SlotSeleccionoLink(const QString&,const QString&)", &slot_7, QMetaData::Private },
	{ "SlotAnexarOrden()", &slot_8, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QPuntoVenta", parentObject,
	slot_tbl, 9,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QPuntoVenta.setMetaObject( metaObj );
    return metaObj;
}

void* QPuntoVenta::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QPuntoVenta" ) )
	return this;
    return PuntoVenta::qt_cast( clname );
}

bool QPuntoVenta::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotCargaArchivoHtml(); break;
    case 1: SlotSeleccionoProducto((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 2: SlotFocoAProductos(); break;
    case 3: SlotIncrementaTexto(); break;
    case 4: SlotDecrementaTexto(); break;
    case 5: SlotSeleccionoLink((const QString&)static_QUType_QString.get(_o+1)); break;
    case 6: SlotClicked((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 7: SlotSeleccionoLink((const QString&)static_QUType_QString.get(_o+1),(const QString&)static_QUType_QString.get(_o+2)); break;
    case 8: SlotAnexarOrden(); break;
    default:
	return PuntoVenta::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QPuntoVenta::qt_emit( int _id, QUObject* _o )
{
    return PuntoVenta::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QPuntoVenta::qt_property( int id, int f, QVariant* v)
{
    return PuntoVenta::qt_property( id, f, v);
}

bool QPuntoVenta::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
