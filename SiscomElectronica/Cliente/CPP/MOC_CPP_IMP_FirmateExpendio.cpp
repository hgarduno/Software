/****************************************************************************
** QFirmateExpendio meta object code from reading C++ file 'IMP_FirmateExpendio.h'
**
** Created: Wed Apr 10 21:10:24 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_FirmateExpendio.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QFirmateExpendio::className() const
{
    return "QFirmateExpendio";
}

QMetaObject *QFirmateExpendio::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QFirmateExpendio( "QFirmateExpendio", &QFirmateExpendio::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QFirmateExpendio::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QFirmateExpendio", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QFirmateExpendio::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QFirmateExpendio", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QFirmateExpendio::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = FirmateExpendio::staticMetaObject();
    static const QUMethod slot_0 = {"S_IntrodujoPassword", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "S_IntrodujoPassword()", &slot_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QFirmateExpendio", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QFirmateExpendio.setMetaObject( metaObj );
    return metaObj;
}

void* QFirmateExpendio::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QFirmateExpendio" ) )
	return this;
    return FirmateExpendio::qt_cast( clname );
}

bool QFirmateExpendio::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: S_IntrodujoPassword(); break;
    default:
	return FirmateExpendio::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QFirmateExpendio::qt_emit( int _id, QUObject* _o )
{
    return FirmateExpendio::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QFirmateExpendio::qt_property( int id, int f, QVariant* v)
{
    return FirmateExpendio::qt_property( id, f, v);
}

bool QFirmateExpendio::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
