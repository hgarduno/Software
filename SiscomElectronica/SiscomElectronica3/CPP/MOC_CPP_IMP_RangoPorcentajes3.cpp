/****************************************************************************
** QRangoPorcentajes3 meta object code from reading C++ file 'IMP_RangoPorcentajes3.h'
**
** Created: Wed Jan 31 10:47:33 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_RangoPorcentajes3.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QRangoPorcentajes3::className() const
{
    return "QRangoPorcentajes3";
}

QMetaObject *QRangoPorcentajes3::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QRangoPorcentajes3( "QRangoPorcentajes3", &QRangoPorcentajes3::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QRangoPorcentajes3::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRangoPorcentajes3", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QRangoPorcentajes3::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRangoPorcentajes3", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QRangoPorcentajes3::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = RangoPorcentajes3::staticMetaObject();
    static const QUMethod slot_0 = {"SlotPasaFocoAlto", 0, 0 };
    static const QUMethod slot_1 = {"SlotPasaFocoAceptar", 0, 0 };
    static const QUMethod slot_2 = {"SlotAceptar", 0, 0 };
    static const QUMethod slot_3 = {"SlotCancelar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotPasaFocoAlto()", &slot_0, QMetaData::Private },
	{ "SlotPasaFocoAceptar()", &slot_1, QMetaData::Private },
	{ "SlotAceptar()", &slot_2, QMetaData::Private },
	{ "SlotCancelar()", &slot_3, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QRangoPorcentajes3", parentObject,
	slot_tbl, 4,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QRangoPorcentajes3.setMetaObject( metaObj );
    return metaObj;
}

void* QRangoPorcentajes3::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QRangoPorcentajes3" ) )
	return this;
    return RangoPorcentajes3::qt_cast( clname );
}

bool QRangoPorcentajes3::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotPasaFocoAlto(); break;
    case 1: SlotPasaFocoAceptar(); break;
    case 2: SlotAceptar(); break;
    case 3: SlotCancelar(); break;
    default:
	return RangoPorcentajes3::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QRangoPorcentajes3::qt_emit( int _id, QUObject* _o )
{
    return RangoPorcentajes3::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QRangoPorcentajes3::qt_property( int id, int f, QVariant* v)
{
    return RangoPorcentajes3::qt_property( id, f, v);
}

bool QRangoPorcentajes3::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
