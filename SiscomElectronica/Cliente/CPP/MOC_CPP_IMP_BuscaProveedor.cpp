/****************************************************************************
** QBuscaProveedor meta object code from reading C++ file 'IMP_BuscaProveedor.h'
**
** Created: Wed Apr 10 20:52:39 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_BuscaProveedor.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QBuscaProveedor::className() const
{
    return "QBuscaProveedor";
}

QMetaObject *QBuscaProveedor::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QBuscaProveedor( "QBuscaProveedor", &QBuscaProveedor::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QBuscaProveedor::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QBuscaProveedor", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QBuscaProveedor::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QBuscaProveedor", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QBuscaProveedor::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = BuscaProveedor::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "pintProveedor", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotSeleccionando", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "pintProveedor", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotSelecciono", 1, param_slot_1 };
    static const QUMethod slot_2 = {"SlotAceptar", 0, 0 };
    static const QUMethod slot_3 = {"SlotCancelar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotSeleccionando(int)", &slot_0, QMetaData::Private },
	{ "SlotSelecciono(int)", &slot_1, QMetaData::Private },
	{ "SlotAceptar()", &slot_2, QMetaData::Private },
	{ "SlotCancelar()", &slot_3, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QBuscaProveedor", parentObject,
	slot_tbl, 4,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QBuscaProveedor.setMetaObject( metaObj );
    return metaObj;
}

void* QBuscaProveedor::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QBuscaProveedor" ) )
	return this;
    return BuscaProveedor::qt_cast( clname );
}

bool QBuscaProveedor::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotSeleccionando((int)static_QUType_int.get(_o+1)); break;
    case 1: SlotSelecciono((int)static_QUType_int.get(_o+1)); break;
    case 2: SlotAceptar(); break;
    case 3: SlotCancelar(); break;
    default:
	return BuscaProveedor::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QBuscaProveedor::qt_emit( int _id, QUObject* _o )
{
    return BuscaProveedor::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QBuscaProveedor::qt_property( int id, int f, QVariant* v)
{
    return BuscaProveedor::qt_property( id, f, v);
}

bool QBuscaProveedor::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
