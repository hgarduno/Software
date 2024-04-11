/****************************************************************************
** QtImpSoporteTransferencias meta object code from reading C++ file 'QtImpSoporteTransferencias.h'
**
** Created: Sat Jan 27 16:40:04 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpSoporteTransferencias.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpSoporteTransferencias::className() const
{
    return "QtImpSoporteTransferencias";
}

QMetaObject *QtImpSoporteTransferencias::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpSoporteTransferencias( "QtImpSoporteTransferencias", &QtImpSoporteTransferencias::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpSoporteTransferencias::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpSoporteTransferencias", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpSoporteTransferencias::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpSoporteTransferencias", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpSoporteTransferencias::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = SoporteTransferencias::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "pzSisRegTienda", &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotTienda", 1, param_slot_0 };
    static const QUMethod slot_1 = {"SlotImprimir", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotTienda(zSiscomRegistro*)", &slot_0, QMetaData::Private },
	{ "SlotImprimir()", &slot_1, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpSoporteTransferencias", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpSoporteTransferencias.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpSoporteTransferencias::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpSoporteTransferencias" ) )
	return this;
    return SoporteTransferencias::qt_cast( clname );
}

bool QtImpSoporteTransferencias::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotTienda((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotImprimir(); break;
    default:
	return SoporteTransferencias::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpSoporteTransferencias::qt_emit( int _id, QUObject* _o )
{
    return SoporteTransferencias::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpSoporteTransferencias::qt_property( int id, int f, QVariant* v)
{
    return SoporteTransferencias::qt_property( id, f, v);
}

bool QtImpSoporteTransferencias::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
