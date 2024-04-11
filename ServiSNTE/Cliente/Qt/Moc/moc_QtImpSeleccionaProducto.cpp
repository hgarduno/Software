/****************************************************************************
** QtImpSeleccionaProducto meta object code from reading C++ file 'QtImpSeleccionaProducto.h'
**
** Created: Sat Jan 27 16:38:52 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpSeleccionaProducto.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpSeleccionaProducto::className() const
{
    return "QtImpSeleccionaProducto";
}

QMetaObject *QtImpSeleccionaProducto::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpSeleccionaProducto( "QtImpSeleccionaProducto", &QtImpSeleccionaProducto::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpSeleccionaProducto::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpSeleccionaProducto", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpSeleccionaProducto::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpSeleccionaProducto", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpSeleccionaProducto::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = SeleccionaProducto::staticMetaObject();
    static const QUMethod slot_0 = {"reject", 0, 0 };
    static const QUMethod slot_1 = {"SlotAceptar", 0, 0 };
    static const QUMethod slot_2 = {"SlotCancelar", 0, 0 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_3 = {"SlotProducto", 1, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_4 = {"SlotProducto", 4, param_slot_4 };
    static const QMetaData slot_tbl[] = {
	{ "reject()", &slot_0, QMetaData::Private },
	{ "SlotAceptar()", &slot_1, QMetaData::Private },
	{ "SlotCancelar()", &slot_2, QMetaData::Private },
	{ "SlotProducto(zSiscomRegistro*)", &slot_3, QMetaData::Private },
	{ "SlotProducto(int,int,int,const QPoint&)", &slot_4, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpSeleccionaProducto", parentObject,
	slot_tbl, 5,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpSeleccionaProducto.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpSeleccionaProducto::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpSeleccionaProducto" ) )
	return this;
    return SeleccionaProducto::qt_cast( clname );
}

bool QtImpSeleccionaProducto::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: reject(); break;
    case 1: SlotAceptar(); break;
    case 2: SlotCancelar(); break;
    case 3: SlotProducto((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 4: SlotProducto((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    default:
	return SeleccionaProducto::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpSeleccionaProducto::qt_emit( int _id, QUObject* _o )
{
    return SeleccionaProducto::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpSeleccionaProducto::qt_property( int id, int f, QVariant* v)
{
    return SeleccionaProducto::qt_property( id, f, v);
}

bool QtImpSeleccionaProducto::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
