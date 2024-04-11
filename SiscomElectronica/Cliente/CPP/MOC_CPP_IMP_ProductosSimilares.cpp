/****************************************************************************
** QProductosSimilares meta object code from reading C++ file 'IMP_ProductosSimilares.h'
**
** Created: Wed Apr 10 20:52:40 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_ProductosSimilares.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QProductosSimilares::className() const
{
    return "QProductosSimilares";
}

QMetaObject *QProductosSimilares::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QProductosSimilares( "QProductosSimilares", &QProductosSimilares::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QProductosSimilares::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QProductosSimilares", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QProductosSimilares::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QProductosSimilares", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QProductosSimilares::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ProductosSimilares::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotMostrando", 2, param_slot_0 };
    static const QUMethod slot_1 = {"SlotAceptar", 0, 0 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_2 = {"SlotSelecciono", 4, param_slot_2 };
    static const QUMethod slot_3 = {"SlotSeleccionando", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotMostrando(int,int)", &slot_0, QMetaData::Private },
	{ "SlotAceptar()", &slot_1, QMetaData::Private },
	{ "SlotSelecciono(int,int,int,const QPoint&)", &slot_2, QMetaData::Private },
	{ "SlotSeleccionando()", &slot_3, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QProductosSimilares", parentObject,
	slot_tbl, 4,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QProductosSimilares.setMetaObject( metaObj );
    return metaObj;
}

void* QProductosSimilares::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QProductosSimilares" ) )
	return this;
    return ProductosSimilares::qt_cast( clname );
}

bool QProductosSimilares::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotMostrando((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 1: SlotAceptar(); break;
    case 2: SlotSelecciono((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 3: SlotSeleccionando(); break;
    default:
	return ProductosSimilares::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QProductosSimilares::qt_emit( int _id, QUObject* _o )
{
    return ProductosSimilares::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QProductosSimilares::qt_property( int id, int f, QVariant* v)
{
    return ProductosSimilares::qt_property( id, f, v);
}

bool QProductosSimilares::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
