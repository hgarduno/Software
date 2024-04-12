/****************************************************************************
** QManejadorExpendios meta object code from reading C++ file 'IMP_ManejadorExpendios.h'
**
** Created: Thu Apr 11 21:40:01 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_ManejadorExpendios.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QManejadorExpendios::className() const
{
    return "QManejadorExpendios";
}

QMetaObject *QManejadorExpendios::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QManejadorExpendios( "QManejadorExpendios", &QManejadorExpendios::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QManejadorExpendios::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QManejadorExpendios", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QManejadorExpendios::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QManejadorExpendios", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QManejadorExpendios::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ManejadorExpendios::staticMetaObject();
    static const QUMethod slot_0 = {"SlotPasaFocoRFC", 0, 0 };
    static const QUMethod slot_1 = {"SlotPasaFocoDireccionIp", 0, 0 };
    static const QUMethod slot_2 = {"SlotPasaFocoPuerto", 0, 0 };
    static const QUMethod slot_3 = {"SlotPasaFocoBase", 0, 0 };
    static const QUMethod slot_4 = {"SlotPasaFocoRegistra", 0, 0 };
    static const QUMethod slot_5 = {"SlotRegistra", 0, 0 };
    static const QUParameter param_slot_6[] = {
	{ "pSisReg3Expendio", &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod slot_6 = {"SlotExpendio", 1, param_slot_6 };
    static const QUMethod slot_7 = {"SlotActualiza", 0, 0 };
    static const QUMethod slot_8 = {"SlotInicia", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotPasaFocoRFC()", &slot_0, QMetaData::Private },
	{ "SlotPasaFocoDireccionIp()", &slot_1, QMetaData::Private },
	{ "SlotPasaFocoPuerto()", &slot_2, QMetaData::Private },
	{ "SlotPasaFocoBase()", &slot_3, QMetaData::Private },
	{ "SlotPasaFocoRegistra()", &slot_4, QMetaData::Private },
	{ "SlotRegistra()", &slot_5, QMetaData::Private },
	{ "SlotExpendio(SiscomRegistro3*)", &slot_6, QMetaData::Private },
	{ "SlotActualiza()", &slot_7, QMetaData::Private },
	{ "SlotInicia()", &slot_8, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QManejadorExpendios", parentObject,
	slot_tbl, 9,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QManejadorExpendios.setMetaObject( metaObj );
    return metaObj;
}

void* QManejadorExpendios::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QManejadorExpendios" ) )
	return this;
    return ManejadorExpendios::qt_cast( clname );
}

bool QManejadorExpendios::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotPasaFocoRFC(); break;
    case 1: SlotPasaFocoDireccionIp(); break;
    case 2: SlotPasaFocoPuerto(); break;
    case 3: SlotPasaFocoBase(); break;
    case 4: SlotPasaFocoRegistra(); break;
    case 5: SlotRegistra(); break;
    case 6: SlotExpendio((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    case 7: SlotActualiza(); break;
    case 8: SlotInicia(); break;
    default:
	return ManejadorExpendios::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QManejadorExpendios::qt_emit( int _id, QUObject* _o )
{
    return ManejadorExpendios::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QManejadorExpendios::qt_property( int id, int f, QVariant* v)
{
    return ManejadorExpendios::qt_property( id, f, v);
}

bool QManejadorExpendios::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
