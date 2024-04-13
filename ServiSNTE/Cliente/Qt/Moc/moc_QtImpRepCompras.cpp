/****************************************************************************
** QtImpRepCompras meta object code from reading C++ file 'QtImpRepCompras.h'
**
** Created: Mon Apr 1 17:30:38 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpRepCompras.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpRepCompras::className() const
{
    return "QtImpRepCompras";
}

QMetaObject *QtImpRepCompras::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpRepCompras( "QtImpRepCompras", &QtImpRepCompras::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpRepCompras::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpRepCompras", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpRepCompras::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpRepCompras", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpRepCompras::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = RepCompras::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotDepartamento", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotProveedor", 1, param_slot_1 };
    static const QUMethod slot_2 = {"SlotImprimir", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotDepartamento(zSiscomRegistro*)", &slot_0, QMetaData::Private },
	{ "SlotProveedor(zSiscomRegistro*)", &slot_1, QMetaData::Private },
	{ "SlotImprimir()", &slot_2, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpRepCompras", parentObject,
	slot_tbl, 3,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpRepCompras.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpRepCompras::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpRepCompras" ) )
	return this;
    return RepCompras::qt_cast( clname );
}

bool QtImpRepCompras::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotDepartamento((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotProveedor((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 2: SlotImprimir(); break;
    default:
	return RepCompras::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpRepCompras::qt_emit( int _id, QUObject* _o )
{
    return RepCompras::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpRepCompras::qt_property( int id, int f, QVariant* v)
{
    return RepCompras::qt_property( id, f, v);
}

bool QtImpRepCompras::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
