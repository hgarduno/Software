/****************************************************************************
** QCtrlPreciosProductos meta object code from reading C++ file 'QCtrlPreciosProductos.h'
**
** Created: Fri Apr 12 21:36:28 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QCtrlPreciosProductos.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCtrlPreciosProductos::className() const
{
    return "QCtrlPreciosProductos";
}

QMetaObject *QCtrlPreciosProductos::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCtrlPreciosProductos( "QCtrlPreciosProductos", &QCtrlPreciosProductos::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCtrlPreciosProductos::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrlPreciosProductos", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCtrlPreciosProductos::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrlPreciosProductos", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCtrlPreciosProductos::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotPrecioProducto", 1, param_slot_0 };
    static const QUMethod slot_1 = {"SlotPrecioProducto", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotPrecioProducto(int)", &slot_0, QMetaData::Private },
	{ "SlotPrecioProducto()", &slot_1, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCtrlPreciosProductos", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCtrlPreciosProductos.setMetaObject( metaObj );
    return metaObj;
}

void* QCtrlPreciosProductos::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCtrlPreciosProductos" ) )
	return this;
    return QWidget::qt_cast( clname );
}

bool QCtrlPreciosProductos::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotPrecioProducto((int)static_QUType_int.get(_o+1)); break;
    case 1: SlotPrecioProducto(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCtrlPreciosProductos::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QCtrlPreciosProductos::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool QCtrlPreciosProductos::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
