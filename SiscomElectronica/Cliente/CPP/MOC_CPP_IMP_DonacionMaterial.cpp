/****************************************************************************
** QDonacionMaterial meta object code from reading C++ file 'IMP_DonacionMaterial.h'
**
** Created: Wed Apr 10 20:52:40 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_DonacionMaterial.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QDonacionMaterial::className() const
{
    return "QDonacionMaterial";
}

QMetaObject *QDonacionMaterial::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QDonacionMaterial( "QDonacionMaterial", &QDonacionMaterial::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QDonacionMaterial::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QDonacionMaterial", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QDonacionMaterial::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QDonacionMaterial", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QDonacionMaterial::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = DonacionMaterial::staticMetaObject();
    static const QUMethod slot_0 = {"SlotAceptar", 0, 0 };
    static const QUMethod slot_1 = {"SlotCancelar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotAceptar()", &slot_0, QMetaData::Private },
	{ "SlotCancelar()", &slot_1, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QDonacionMaterial", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QDonacionMaterial.setMetaObject( metaObj );
    return metaObj;
}

void* QDonacionMaterial::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QDonacionMaterial" ) )
	return this;
    return DonacionMaterial::qt_cast( clname );
}

bool QDonacionMaterial::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotAceptar(); break;
    case 1: SlotCancelar(); break;
    default:
	return DonacionMaterial::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QDonacionMaterial::qt_emit( int _id, QUObject* _o )
{
    return DonacionMaterial::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QDonacionMaterial::qt_property( int id, int f, QVariant* v)
{
    return DonacionMaterial::qt_property( id, f, v);
}

bool QDonacionMaterial::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
