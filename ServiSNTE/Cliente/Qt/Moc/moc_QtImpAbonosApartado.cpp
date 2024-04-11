/****************************************************************************
** QtImpAbonosApartado meta object code from reading C++ file 'QtImpAbonosApartado.h'
**
** Created: Sat Jan 27 16:39:03 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpAbonosApartado.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpAbonosApartado::className() const
{
    return "QtImpAbonosApartado";
}

QMetaObject *QtImpAbonosApartado::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpAbonosApartado( "QtImpAbonosApartado", &QtImpAbonosApartado::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpAbonosApartado::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpAbonosApartado", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpAbonosApartado::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpAbonosApartado", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpAbonosApartado::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = AbonosApartado::staticMetaObject();
    static const QUMethod slot_0 = {"SlotRFC", 0, 0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotSeleccionaApartado", 4, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_2 = {"SlotSeleccionaAbono", 4, param_slot_2 };
    static const QUMethod slot_3 = {"SlotCapturaAbono", 0, 0 };
    static const QUMethod slot_4 = {"SlotCancelaAbono", 0, 0 };
    static const QUMethod slot_5 = {"SlotCancelaApartado", 0, 0 };
    static const QUMethod slot_6 = {"SlotImprimeRecibo", 0, 0 };
    static const QUMethod slot_7 = {"SlotCancelarFolioAbono", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotRFC()", &slot_0, QMetaData::Private },
	{ "SlotSeleccionaApartado(int,int,int,const QPoint&)", &slot_1, QMetaData::Private },
	{ "SlotSeleccionaAbono(int,int,int,const QPoint&)", &slot_2, QMetaData::Private },
	{ "SlotCapturaAbono()", &slot_3, QMetaData::Private },
	{ "SlotCancelaAbono()", &slot_4, QMetaData::Private },
	{ "SlotCancelaApartado()", &slot_5, QMetaData::Private },
	{ "SlotImprimeRecibo()", &slot_6, QMetaData::Private },
	{ "SlotCancelarFolioAbono()", &slot_7, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpAbonosApartado", parentObject,
	slot_tbl, 8,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpAbonosApartado.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpAbonosApartado::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpAbonosApartado" ) )
	return this;
    return AbonosApartado::qt_cast( clname );
}

bool QtImpAbonosApartado::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotRFC(); break;
    case 1: SlotSeleccionaApartado((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 2: SlotSeleccionaAbono((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 3: SlotCapturaAbono(); break;
    case 4: SlotCancelaAbono(); break;
    case 5: SlotCancelaApartado(); break;
    case 6: SlotImprimeRecibo(); break;
    case 7: SlotCancelarFolioAbono(); break;
    default:
	return AbonosApartado::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpAbonosApartado::qt_emit( int _id, QUObject* _o )
{
    return AbonosApartado::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpAbonosApartado::qt_property( int id, int f, QVariant* v)
{
    return AbonosApartado::qt_property( id, f, v);
}

bool QtImpAbonosApartado::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
