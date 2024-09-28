/****************************************************************************
** QtImpFolioApartado meta object code from reading C++ file 'QtImpFolioApartado.h'
**
** Created: Thu Aug 15 00:50:35 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpFolioApartado.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpFolioApartado::className() const
{
    return "QtImpFolioApartado";
}

QMetaObject *QtImpFolioApartado::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpFolioApartado( "QtImpFolioApartado", &QtImpFolioApartado::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpFolioApartado::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpFolioApartado", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpFolioApartado::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpFolioApartado", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpFolioApartado::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = FolioApartado::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "pzSisRegTienda", &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotTienda", 1, param_slot_0 };
    static const QUMethod slot_1 = {"SlotFocoAFolioFin", 0, 0 };
    static const QUMethod slot_2 = {"SlotFocoARegistrar", 0, 0 };
    static const QUMethod slot_3 = {"SlotRegistrar", 0, 0 };
    static const QUParameter param_slot_4[] = {
	{ "pzSisRegTipoFolio", &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_4 = {"SlotTipoFolio", 1, param_slot_4 };
    static const QMetaData slot_tbl[] = {
	{ "SlotTienda(zSiscomRegistro*)", &slot_0, QMetaData::Private },
	{ "SlotFocoAFolioFin()", &slot_1, QMetaData::Private },
	{ "SlotFocoARegistrar()", &slot_2, QMetaData::Private },
	{ "SlotRegistrar()", &slot_3, QMetaData::Private },
	{ "SlotTipoFolio(zSiscomRegistro*)", &slot_4, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpFolioApartado", parentObject,
	slot_tbl, 5,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpFolioApartado.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpFolioApartado::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpFolioApartado" ) )
	return this;
    return FolioApartado::qt_cast( clname );
}

bool QtImpFolioApartado::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotTienda((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotFocoAFolioFin(); break;
    case 2: SlotFocoARegistrar(); break;
    case 3: SlotRegistrar(); break;
    case 4: SlotTipoFolio((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    default:
	return FolioApartado::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpFolioApartado::qt_emit( int _id, QUObject* _o )
{
    return FolioApartado::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpFolioApartado::qt_property( int id, int f, QVariant* v)
{
    return FolioApartado::qt_property( id, f, v);
}

bool QtImpFolioApartado::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
