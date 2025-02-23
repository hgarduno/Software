/****************************************************************************
** QtImpDesajusteInventario meta object code from reading C++ file 'QtImpDesajusteInventario.h'
**
** Created: Sat Feb 22 23:13:51 2025
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpDesajusteInventario.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpDesajusteInventario::className() const
{
    return "QtImpDesajusteInventario";
}

QMetaObject *QtImpDesajusteInventario::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpDesajusteInventario( "QtImpDesajusteInventario", &QtImpDesajusteInventario::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpDesajusteInventario::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpDesajusteInventario", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpDesajusteInventario::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpDesajusteInventario", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpDesajusteInventario::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = DesajusteInventario::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "pzSisRegProveedor", &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotTienda", 1, param_slot_0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotTienda(zSiscomRegistro*)", &slot_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpDesajusteInventario", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpDesajusteInventario.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpDesajusteInventario::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpDesajusteInventario" ) )
	return this;
    return DesajusteInventario::qt_cast( clname );
}

bool QtImpDesajusteInventario::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotTienda((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    default:
	return DesajusteInventario::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpDesajusteInventario::qt_emit( int _id, QUObject* _o )
{
    return DesajusteInventario::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpDesajusteInventario::qt_property( int id, int f, QVariant* v)
{
    return DesajusteInventario::qt_property( id, f, v);
}

bool QtImpDesajusteInventario::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
