/****************************************************************************
** QPedidos meta object code from reading C++ file 'IMP_Pedidos.h'
**
** Created: Fri Apr 12 21:26:09 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_Pedidos.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QPedidos::className() const
{
    return "QPedidos";
}

QMetaObject *QPedidos::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QPedidos( "QPedidos", &QPedidos::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QPedidos::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QPedidos", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QPedidos::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QPedidos", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QPedidos::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = Pedidos::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "pzSisRegProducto", &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotSeleccionoProducto", 1, param_slot_0 };
    static const QUMethod slot_1 = {"SlotAnexarOrden", 0, 0 };
    static const QUMethod slot_2 = {"SlotFocoAProducto", 0, 0 };
    static const QUMethod slot_3 = {"SlotDatosCliente", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotSeleccionoProducto(zSiscomRegistro*)", &slot_0, QMetaData::Private },
	{ "SlotAnexarOrden()", &slot_1, QMetaData::Private },
	{ "SlotFocoAProducto()", &slot_2, QMetaData::Private },
	{ "SlotDatosCliente()", &slot_3, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QPedidos", parentObject,
	slot_tbl, 4,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QPedidos.setMetaObject( metaObj );
    return metaObj;
}

void* QPedidos::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QPedidos" ) )
	return this;
    return Pedidos::qt_cast( clname );
}

bool QPedidos::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotSeleccionoProducto((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotAnexarOrden(); break;
    case 2: SlotFocoAProducto(); break;
    case 3: SlotDatosCliente(); break;
    default:
	return Pedidos::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QPedidos::qt_emit( int _id, QUObject* _o )
{
    return Pedidos::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QPedidos::qt_property( int id, int f, QVariant* v)
{
    return Pedidos::qt_property( id, f, v);
}

bool QPedidos::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
