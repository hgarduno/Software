/****************************************************************************
** QAnexarProducto meta object code from reading C++ file 'IMP_AnexarProducto.h'
**
** Created: Fri Apr 12 21:36:43 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_AnexarProducto.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QAnexarProducto::className() const
{
    return "QAnexarProducto";
}

QMetaObject *QAnexarProducto::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QAnexarProducto( "QAnexarProducto", &QAnexarProducto::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QAnexarProducto::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QAnexarProducto", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QAnexarProducto::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QAnexarProducto", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QAnexarProducto::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = AnexarProducto::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotSeleccionandoProducto", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotProducto", 1, param_slot_1 };
    static const QUMethod slot_2 = {"SlotPasaFocoAnexarProducto", 0, 0 };
    static const QUMethod slot_3 = {"SlotAnexar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotSeleccionandoProducto(SiscomRegistro3*)", &slot_0, QMetaData::Private },
	{ "SlotProducto(SiscomRegistro3*)", &slot_1, QMetaData::Private },
	{ "SlotPasaFocoAnexarProducto()", &slot_2, QMetaData::Private },
	{ "SlotAnexar()", &slot_3, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QAnexarProducto", parentObject,
	slot_tbl, 4,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QAnexarProducto.setMetaObject( metaObj );
    return metaObj;
}

void* QAnexarProducto::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QAnexarProducto" ) )
	return this;
    return AnexarProducto::qt_cast( clname );
}

bool QAnexarProducto::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotSeleccionandoProducto((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotProducto((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    case 2: SlotPasaFocoAnexarProducto(); break;
    case 3: SlotAnexar(); break;
    default:
	return AnexarProducto::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QAnexarProducto::qt_emit( int _id, QUObject* _o )
{
    return AnexarProducto::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QAnexarProducto::qt_property( int id, int f, QVariant* v)
{
    return AnexarProducto::qt_property( id, f, v);
}

bool QAnexarProducto::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
