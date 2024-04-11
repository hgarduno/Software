/****************************************************************************
** QtImpRepProveedores meta object code from reading C++ file 'QtImpRepProveedores.h'
**
** Created: Sat Jan 27 16:40:13 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpRepProveedores.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpRepProveedores::className() const
{
    return "QtImpRepProveedores";
}

QMetaObject *QtImpRepProveedores::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpRepProveedores( "QtImpRepProveedores", &QtImpRepProveedores::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpRepProveedores::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpRepProveedores", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpRepProveedores::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpRepProveedores", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpRepProveedores::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = RepProveedores::staticMetaObject();
    static const QUMethod slot_0 = {"SlotConsultar", 0, 0 };
    static const QUMethod slot_1 = {"SlotImprimir", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotConsultar()", &slot_0, QMetaData::Private },
	{ "SlotImprimir()", &slot_1, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpRepProveedores", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpRepProveedores.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpRepProveedores::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpRepProveedores" ) )
	return this;
    return RepProveedores::qt_cast( clname );
}

bool QtImpRepProveedores::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotConsultar(); break;
    case 1: SlotImprimir(); break;
    default:
	return RepProveedores::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpRepProveedores::qt_emit( int _id, QUObject* _o )
{
    return RepProveedores::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpRepProveedores::qt_property( int id, int f, QVariant* v)
{
    return RepProveedores::qt_property( id, f, v);
}

bool QtImpRepProveedores::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
