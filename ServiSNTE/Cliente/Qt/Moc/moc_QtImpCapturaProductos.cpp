/****************************************************************************
** QtImpCapturaProductos meta object code from reading C++ file 'QtImpCapturaProductos.h'
**
** Created: Sat Feb 22 23:13:20 2025
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpCapturaProductos.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpCapturaProductos::className() const
{
    return "QtImpCapturaProductos";
}

QMetaObject *QtImpCapturaProductos::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpCapturaProductos( "QtImpCapturaProductos", &QtImpCapturaProductos::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpCapturaProductos::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpCapturaProductos", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpCapturaProductos::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpCapturaProductos", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpCapturaProductos::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CapturaProductos::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotProveedor", 1, param_slot_0 };
    static const QUMethod slot_1 = {"SlotConsulta", 0, 0 };
    static const QUMethod slot_2 = {"SlotCCBruto", 0, 0 };
    static const QUMethod slot_3 = {"SlotCPGeneral", 0, 0 };
    static const QUMethod slot_4 = {"SlotCPForaneo", 0, 0 };
    static const QUMethod slot_5 = {"SlotCDescuento", 0, 0 };
    static const QUMethod slot_6 = {"SlotAgregarPrecios", 0, 0 };
    static const QUMethod slot_7 = {"SlotCrear", 0, 0 };
    static const QUParameter param_slot_8[] = {
	{ 0, &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_8 = {"SlotProveedorCrear", 1, param_slot_8 };
    static const QUParameter param_slot_9[] = {
	{ 0, &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_9 = {"SlotDepartamentoCrear", 1, param_slot_9 };
    static const QUMethod slot_10 = {"SlotFocoModelo", 0, 0 };
    static const QUMethod slot_11 = {"SlotFocoDepartamento", 0, 0 };
    static const QUMethod slot_12 = {"SlotFocoANombre", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotProveedor(zSiscomRegistro*)", &slot_0, QMetaData::Private },
	{ "SlotConsulta()", &slot_1, QMetaData::Private },
	{ "SlotCCBruto()", &slot_2, QMetaData::Private },
	{ "SlotCPGeneral()", &slot_3, QMetaData::Private },
	{ "SlotCPForaneo()", &slot_4, QMetaData::Private },
	{ "SlotCDescuento()", &slot_5, QMetaData::Private },
	{ "SlotAgregarPrecios()", &slot_6, QMetaData::Private },
	{ "SlotCrear()", &slot_7, QMetaData::Private },
	{ "SlotProveedorCrear(zSiscomRegistro*)", &slot_8, QMetaData::Private },
	{ "SlotDepartamentoCrear(zSiscomRegistro*)", &slot_9, QMetaData::Private },
	{ "SlotFocoModelo()", &slot_10, QMetaData::Private },
	{ "SlotFocoDepartamento()", &slot_11, QMetaData::Private },
	{ "SlotFocoANombre()", &slot_12, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpCapturaProductos", parentObject,
	slot_tbl, 13,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpCapturaProductos.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpCapturaProductos::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpCapturaProductos" ) )
	return this;
    return CapturaProductos::qt_cast( clname );
}

bool QtImpCapturaProductos::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotProveedor((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotConsulta(); break;
    case 2: SlotCCBruto(); break;
    case 3: SlotCPGeneral(); break;
    case 4: SlotCPForaneo(); break;
    case 5: SlotCDescuento(); break;
    case 6: SlotAgregarPrecios(); break;
    case 7: SlotCrear(); break;
    case 8: SlotProveedorCrear((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 9: SlotDepartamentoCrear((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 10: SlotFocoModelo(); break;
    case 11: SlotFocoDepartamento(); break;
    case 12: SlotFocoANombre(); break;
    default:
	return CapturaProductos::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpCapturaProductos::qt_emit( int _id, QUObject* _o )
{
    return CapturaProductos::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpCapturaProductos::qt_property( int id, int f, QVariant* v)
{
    return CapturaProductos::qt_property( id, f, v);
}

bool QtImpCapturaProductos::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
