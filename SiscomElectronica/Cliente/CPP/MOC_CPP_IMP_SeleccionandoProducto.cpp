/****************************************************************************
** QSeleccionandoProducto meta object code from reading C++ file 'IMP_SeleccionandoProducto.h'
**
** Created: Thu Apr 11 21:40:01 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_SeleccionandoProducto.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QSeleccionandoProducto::className() const
{
    return "QSeleccionandoProducto";
}

QMetaObject *QSeleccionandoProducto::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QSeleccionandoProducto( "QSeleccionandoProducto", &QSeleccionandoProducto::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QSeleccionandoProducto::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSeleccionandoProducto", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QSeleccionandoProducto::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSeleccionandoProducto", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QSeleccionandoProducto::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = SeleccionandoProducto::staticMetaObject();
    static const QUMethod slot_0 = {"SlotAceptar", 0, 0 };
    static const QUMethod slot_1 = {"SlotCancelar", 0, 0 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_2 = {"SlotSeleccionoProducto", 1, param_slot_2 };
    static const QMetaData slot_tbl[] = {
	{ "SlotAceptar()", &slot_0, QMetaData::Private },
	{ "SlotCancelar()", &slot_1, QMetaData::Private },
	{ "SlotSeleccionoProducto(zSiscomRegistro*)", &slot_2, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QSeleccionandoProducto", parentObject,
	slot_tbl, 3,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QSeleccionandoProducto.setMetaObject( metaObj );
    return metaObj;
}

void* QSeleccionandoProducto::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QSeleccionandoProducto" ) )
	return this;
    return SeleccionandoProducto::qt_cast( clname );
}

bool QSeleccionandoProducto::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotAceptar(); break;
    case 1: SlotCancelar(); break;
    case 2: SlotSeleccionoProducto((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    default:
	return SeleccionandoProducto::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QSeleccionandoProducto::qt_emit( int _id, QUObject* _o )
{
    return SeleccionandoProducto::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QSeleccionandoProducto::qt_property( int id, int f, QVariant* v)
{
    return SeleccionandoProducto::qt_property( id, f, v);
}

bool QSeleccionandoProducto::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
