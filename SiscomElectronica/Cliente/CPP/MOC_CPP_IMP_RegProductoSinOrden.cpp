/****************************************************************************
** QRegProductoSinOrden meta object code from reading C++ file 'IMP_RegProductoSinOrden.h'
**
** Created: Wed Apr 10 20:52:39 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_RegProductoSinOrden.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QRegProductoSinOrden::className() const
{
    return "QRegProductoSinOrden";
}

QMetaObject *QRegProductoSinOrden::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QRegProductoSinOrden( "QRegProductoSinOrden", &QRegProductoSinOrden::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QRegProductoSinOrden::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRegProductoSinOrden", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QRegProductoSinOrden::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRegProductoSinOrden", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QRegProductoSinOrden::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = RegProductoSinOrden::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotSeleccionando", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotSelecciono", 1, param_slot_1 };
    static const QUMethod slot_2 = {"SlotPasaFocoRegistrar", 0, 0 };
    static const QUMethod slot_3 = {"SlotRegistrar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotSeleccionando(SiscomRegistro3*)", &slot_0, QMetaData::Private },
	{ "SlotSelecciono(SiscomRegistro3*)", &slot_1, QMetaData::Private },
	{ "SlotPasaFocoRegistrar()", &slot_2, QMetaData::Private },
	{ "SlotRegistrar()", &slot_3, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QRegProductoSinOrden", parentObject,
	slot_tbl, 4,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QRegProductoSinOrden.setMetaObject( metaObj );
    return metaObj;
}

void* QRegProductoSinOrden::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QRegProductoSinOrden" ) )
	return this;
    return RegProductoSinOrden::qt_cast( clname );
}

bool QRegProductoSinOrden::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotSeleccionando((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotSelecciono((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    case 2: SlotPasaFocoRegistrar(); break;
    case 3: SlotRegistrar(); break;
    default:
	return RegProductoSinOrden::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QRegProductoSinOrden::qt_emit( int _id, QUObject* _o )
{
    return RegProductoSinOrden::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QRegProductoSinOrden::qt_property( int id, int f, QVariant* v)
{
    return RegProductoSinOrden::qt_property( id, f, v);
}

bool QRegProductoSinOrden::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
