/****************************************************************************
** QSalidaMaterial meta object code from reading C++ file 'IMP_SalidaMaterial.h'
**
** Created: Thu Apr 11 21:40:01 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_SalidaMaterial.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QSalidaMaterial::className() const
{
    return "QSalidaMaterial";
}

QMetaObject *QSalidaMaterial::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QSalidaMaterial( "QSalidaMaterial", &QSalidaMaterial::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QSalidaMaterial::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSalidaMaterial", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QSalidaMaterial::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSalidaMaterial", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QSalidaMaterial::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = SalidaMaterial::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotSeleccionoMotivo", 1, param_slot_0 };
    static const QUMethod slot_1 = {"SlotPasaFocoProductos", 0, 0 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_ptr, "ProductoE", QUParameter::In }
    };
    static const QUMethod slot_2 = {"SlotSeleccionoProducto", 1, param_slot_2 };
    static const QUMethod slot_3 = {"SlotAnexar", 0, 0 };
    static const QUMethod slot_4 = {"SlotRegistrar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotSeleccionoMotivo(int)", &slot_0, QMetaData::Private },
	{ "SlotPasaFocoProductos()", &slot_1, QMetaData::Private },
	{ "SlotSeleccionoProducto(ProductoE*)", &slot_2, QMetaData::Private },
	{ "SlotAnexar()", &slot_3, QMetaData::Private },
	{ "SlotRegistrar()", &slot_4, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QSalidaMaterial", parentObject,
	slot_tbl, 5,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QSalidaMaterial.setMetaObject( metaObj );
    return metaObj;
}

void* QSalidaMaterial::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QSalidaMaterial" ) )
	return this;
    return SalidaMaterial::qt_cast( clname );
}

bool QSalidaMaterial::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotSeleccionoMotivo((int)static_QUType_int.get(_o+1)); break;
    case 1: SlotPasaFocoProductos(); break;
    case 2: SlotSeleccionoProducto((ProductoE*)static_QUType_ptr.get(_o+1)); break;
    case 3: SlotAnexar(); break;
    case 4: SlotRegistrar(); break;
    default:
	return SalidaMaterial::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QSalidaMaterial::qt_emit( int _id, QUObject* _o )
{
    return SalidaMaterial::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QSalidaMaterial::qt_property( int id, int f, QVariant* v)
{
    return SalidaMaterial::qt_property( id, f, v);
}

bool QSalidaMaterial::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
