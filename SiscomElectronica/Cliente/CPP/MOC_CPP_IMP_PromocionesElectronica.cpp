/****************************************************************************
** QPromocionesElectronica meta object code from reading C++ file 'IMP_PromocionesElectronica.h'
**
** Created: Wed Apr 10 20:52:39 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_PromocionesElectronica.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QPromocionesElectronica::className() const
{
    return "QPromocionesElectronica";
}

QMetaObject *QPromocionesElectronica::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QPromocionesElectronica( "QPromocionesElectronica", &QPromocionesElectronica::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QPromocionesElectronica::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QPromocionesElectronica", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QPromocionesElectronica::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QPromocionesElectronica", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QPromocionesElectronica::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = PromocionesElectronica::staticMetaObject();
    static const QUMethod slot_0 = {"SlotPasaFocoPuntosSiscom", 0, 0 };
    static const QUMethod slot_1 = {"SlotPasaFocoFechaIni", 0, 0 };
    static const QUMethod slot_2 = {"SlotPasaFocoFechaFin", 0, 0 };
    static const QUMethod slot_3 = {"SlotPasaFocoDescripcion", 0, 0 };
    static const QUMethod slot_4 = {"SlotRegistra", 0, 0 };
    static const QUMethod slot_5 = {"SlotActualiza", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotPasaFocoPuntosSiscom()", &slot_0, QMetaData::Private },
	{ "SlotPasaFocoFechaIni()", &slot_1, QMetaData::Private },
	{ "SlotPasaFocoFechaFin()", &slot_2, QMetaData::Private },
	{ "SlotPasaFocoDescripcion()", &slot_3, QMetaData::Private },
	{ "SlotRegistra()", &slot_4, QMetaData::Private },
	{ "SlotActualiza()", &slot_5, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QPromocionesElectronica", parentObject,
	slot_tbl, 6,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QPromocionesElectronica.setMetaObject( metaObj );
    return metaObj;
}

void* QPromocionesElectronica::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QPromocionesElectronica" ) )
	return this;
    return PromocionesElectronica::qt_cast( clname );
}

bool QPromocionesElectronica::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotPasaFocoPuntosSiscom(); break;
    case 1: SlotPasaFocoFechaIni(); break;
    case 2: SlotPasaFocoFechaFin(); break;
    case 3: SlotPasaFocoDescripcion(); break;
    case 4: SlotRegistra(); break;
    case 5: SlotActualiza(); break;
    default:
	return PromocionesElectronica::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QPromocionesElectronica::qt_emit( int _id, QUObject* _o )
{
    return PromocionesElectronica::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QPromocionesElectronica::qt_property( int id, int f, QVariant* v)
{
    return PromocionesElectronica::qt_property( id, f, v);
}

bool QPromocionesElectronica::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
