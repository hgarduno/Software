/****************************************************************************
** QtImpRepListaPreciosComprador meta object code from reading C++ file 'QtImpRepListaPreciosComprador.h'
**
** Created: Tue Jun 24 08:59:57 2025
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpRepListaPreciosComprador.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpRepListaPreciosComprador::className() const
{
    return "QtImpRepListaPreciosComprador";
}

QMetaObject *QtImpRepListaPreciosComprador::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpRepListaPreciosComprador( "QtImpRepListaPreciosComprador", &QtImpRepListaPreciosComprador::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpRepListaPreciosComprador::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpRepListaPreciosComprador", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpRepListaPreciosComprador::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpRepListaPreciosComprador", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpRepListaPreciosComprador::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = RepListaPreciosComprador::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "pzSisRegProveedor", &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotProveedor", 1, param_slot_0 };
    static const QUMethod slot_1 = {"SlotConsulta", 0, 0 };
    static const QUMethod slot_2 = {"SlotImprimir", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotProveedor(zSiscomRegistro*)", &slot_0, QMetaData::Private },
	{ "SlotConsulta()", &slot_1, QMetaData::Private },
	{ "SlotImprimir()", &slot_2, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpRepListaPreciosComprador", parentObject,
	slot_tbl, 3,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpRepListaPreciosComprador.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpRepListaPreciosComprador::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpRepListaPreciosComprador" ) )
	return this;
    return RepListaPreciosComprador::qt_cast( clname );
}

bool QtImpRepListaPreciosComprador::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotProveedor((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotConsulta(); break;
    case 2: SlotImprimir(); break;
    default:
	return RepListaPreciosComprador::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpRepListaPreciosComprador::qt_emit( int _id, QUObject* _o )
{
    return RepListaPreciosComprador::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpRepListaPreciosComprador::qt_property( int id, int f, QVariant* v)
{
    return RepListaPreciosComprador::qt_property( id, f, v);
}

bool QtImpRepListaPreciosComprador::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
