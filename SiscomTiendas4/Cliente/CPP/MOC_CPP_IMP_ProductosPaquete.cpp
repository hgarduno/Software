/****************************************************************************
** QProductosPaquete meta object code from reading C++ file 'IMP_ProductosPaquete.h'
**
** Created: Fri Apr 12 21:36:43 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_ProductosPaquete.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QProductosPaquete::className() const
{
    return "QProductosPaquete";
}

QMetaObject *QProductosPaquete::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QProductosPaquete( "QProductosPaquete", &QProductosPaquete::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QProductosPaquete::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QProductosPaquete", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QProductosPaquete::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QProductosPaquete", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QProductosPaquete::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ProductosPaquete::staticMetaObject();
    static const QUMethod slot_0 = {"SlotElimina", 0, 0 };
    static const QUMethod slot_1 = {"SlotAnexar", 0, 0 };
    static const QUMethod slot_2 = {"SlotCambiarCantidad", 0, 0 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_3 = {"SlotSeleccionaProducto", 4, param_slot_3 };
    static const QMetaData slot_tbl[] = {
	{ "SlotElimina()", &slot_0, QMetaData::Private },
	{ "SlotAnexar()", &slot_1, QMetaData::Private },
	{ "SlotCambiarCantidad()", &slot_2, QMetaData::Private },
	{ "SlotSeleccionaProducto(int,int,int,const QPoint&)", &slot_3, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QProductosPaquete", parentObject,
	slot_tbl, 4,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QProductosPaquete.setMetaObject( metaObj );
    return metaObj;
}

void* QProductosPaquete::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QProductosPaquete" ) )
	return this;
    return ProductosPaquete::qt_cast( clname );
}

bool QProductosPaquete::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotElimina(); break;
    case 1: SlotAnexar(); break;
    case 2: SlotCambiarCantidad(); break;
    case 3: SlotSeleccionaProducto((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    default:
	return ProductosPaquete::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QProductosPaquete::qt_emit( int _id, QUObject* _o )
{
    return ProductosPaquete::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QProductosPaquete::qt_property( int id, int f, QVariant* v)
{
    return ProductosPaquete::qt_property( id, f, v);
}

bool QProductosPaquete::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
