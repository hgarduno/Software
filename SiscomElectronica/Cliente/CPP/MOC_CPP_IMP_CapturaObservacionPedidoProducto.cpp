/****************************************************************************
** QCapturaObservacionPedidoProducto meta object code from reading C++ file 'IMP_CapturaObservacionPedidoProducto.h'
**
** Created: Thu Apr 11 21:40:01 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_CapturaObservacionPedidoProducto.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCapturaObservacionPedidoProducto::className() const
{
    return "QCapturaObservacionPedidoProducto";
}

QMetaObject *QCapturaObservacionPedidoProducto::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCapturaObservacionPedidoProducto( "QCapturaObservacionPedidoProducto", &QCapturaObservacionPedidoProducto::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCapturaObservacionPedidoProducto::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCapturaObservacionPedidoProducto", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCapturaObservacionPedidoProducto::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCapturaObservacionPedidoProducto", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCapturaObservacionPedidoProducto::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CapturaObservacionPedidoProducto::staticMetaObject();
    static const QUMethod slot_0 = {"SlotAceptar", 0, 0 };
    static const QUMethod slot_1 = {"SlotCancelar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotAceptar()", &slot_0, QMetaData::Private },
	{ "SlotCancelar()", &slot_1, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCapturaObservacionPedidoProducto", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCapturaObservacionPedidoProducto.setMetaObject( metaObj );
    return metaObj;
}

void* QCapturaObservacionPedidoProducto::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCapturaObservacionPedidoProducto" ) )
	return this;
    return CapturaObservacionPedidoProducto::qt_cast( clname );
}

bool QCapturaObservacionPedidoProducto::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotAceptar(); break;
    case 1: SlotCancelar(); break;
    default:
	return CapturaObservacionPedidoProducto::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCapturaObservacionPedidoProducto::qt_emit( int _id, QUObject* _o )
{
    return CapturaObservacionPedidoProducto::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QCapturaObservacionPedidoProducto::qt_property( int id, int f, QVariant* v)
{
    return CapturaObservacionPedidoProducto::qt_property( id, f, v);
}

bool QCapturaObservacionPedidoProducto::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
