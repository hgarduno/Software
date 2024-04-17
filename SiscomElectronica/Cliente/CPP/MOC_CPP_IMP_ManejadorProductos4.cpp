/****************************************************************************
** QManejadorProductos4 meta object code from reading C++ file 'IMP_ManejadorProductos4.h'
**
** Created: Fri Apr 12 21:26:09 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_ManejadorProductos4.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QManejadorProductos4::className() const
{
    return "QManejadorProductos4";
}

QMetaObject *QManejadorProductos4::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QManejadorProductos4( "QManejadorProductos4", &QManejadorProductos4::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QManejadorProductos4::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QManejadorProductos4", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QManejadorProductos4::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QManejadorProductos4", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QManejadorProductos4::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ManejadorProductos4::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotProducto", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_ptr, "zProductos", QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotSeleccionados", 1, param_slot_1 };
    static const QUMethod slot_2 = {"SlotRegistrarCaja", 0, 0 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_3 = {"SlotSeleccionoCaja", 1, param_slot_3 };
    static const QUMethod slot_4 = {"SlotAsignarUbicacion", 0, 0 };
    static const QUMethod slot_5 = {"SlotAsignaCajaDeDescripcion", 0, 0 };
    static const QUParameter param_slot_6[] = {
	{ 0, &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_6 = {"SlotEstante", 1, param_slot_6 };
    static const QUParameter param_slot_7[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_7 = {"SlotProducto", 4, param_slot_7 };
    static const QMetaData slot_tbl[] = {
	{ "SlotProducto(zSiscomRegistro*)", &slot_0, QMetaData::Private },
	{ "SlotSeleccionados(zProductos*)", &slot_1, QMetaData::Private },
	{ "SlotRegistrarCaja()", &slot_2, QMetaData::Private },
	{ "SlotSeleccionoCaja(zSiscomRegistro*)", &slot_3, QMetaData::Private },
	{ "SlotAsignarUbicacion()", &slot_4, QMetaData::Private },
	{ "SlotAsignaCajaDeDescripcion()", &slot_5, QMetaData::Private },
	{ "SlotEstante(zSiscomRegistro*)", &slot_6, QMetaData::Private },
	{ "SlotProducto(int,int,int,const QPoint&)", &slot_7, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QManejadorProductos4", parentObject,
	slot_tbl, 8,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QManejadorProductos4.setMetaObject( metaObj );
    return metaObj;
}

void* QManejadorProductos4::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QManejadorProductos4" ) )
	return this;
    return ManejadorProductos4::qt_cast( clname );
}

bool QManejadorProductos4::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotProducto((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotSeleccionados((zProductos*)static_QUType_ptr.get(_o+1)); break;
    case 2: SlotRegistrarCaja(); break;
    case 3: SlotSeleccionoCaja((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 4: SlotAsignarUbicacion(); break;
    case 5: SlotAsignaCajaDeDescripcion(); break;
    case 6: SlotEstante((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 7: SlotProducto((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    default:
	return ManejadorProductos4::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QManejadorProductos4::qt_emit( int _id, QUObject* _o )
{
    return ManejadorProductos4::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QManejadorProductos4::qt_property( int id, int f, QVariant* v)
{
    return ManejadorProductos4::qt_property( id, f, v);
}

bool QManejadorProductos4::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
