/****************************************************************************
** QRegistraKit meta object code from reading C++ file 'IMP_RegistraKit.h'
**
** Created: Wed Apr 10 20:52:40 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_RegistraKit.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QRegistraKit::className() const
{
    return "QRegistraKit";
}

QMetaObject *QRegistraKit::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QRegistraKit( "QRegistraKit", &QRegistraKit::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QRegistraKit::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRegistraKit", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QRegistraKit::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRegistraKit", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QRegistraKit::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = RegistraKit::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "ProductoE", QUParameter::In }
    };
    static const QUMethod slot_0 = {"S_Producto", 1, param_slot_0 };
    static const QUMethod slot_1 = {"S_Registra", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "S_Producto(ProductoE*)", &slot_0, QMetaData::Private },
	{ "S_Registra()", &slot_1, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QRegistraKit", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QRegistraKit.setMetaObject( metaObj );
    return metaObj;
}

void* QRegistraKit::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QRegistraKit" ) )
	return this;
    return RegistraKit::qt_cast( clname );
}

bool QRegistraKit::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: S_Producto((ProductoE*)static_QUType_ptr.get(_o+1)); break;
    case 1: S_Registra(); break;
    default:
	return RegistraKit::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QRegistraKit::qt_emit( int _id, QUObject* _o )
{
    return RegistraKit::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QRegistraKit::qt_property( int id, int f, QVariant* v)
{
    return RegistraKit::qt_property( id, f, v);
}

bool QRegistraKit::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
