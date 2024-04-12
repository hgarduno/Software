/****************************************************************************
** QRangoPorcentaje meta object code from reading C++ file 'IMP_RangoPorcentaje.h'
**
** Created: Thu Apr 11 21:53:15 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_RangoPorcentaje.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QRangoPorcentaje::className() const
{
    return "QRangoPorcentaje";
}

QMetaObject *QRangoPorcentaje::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QRangoPorcentaje( "QRangoPorcentaje", &QRangoPorcentaje::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QRangoPorcentaje::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRangoPorcentaje", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QRangoPorcentaje::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRangoPorcentaje", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QRangoPorcentaje::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = RangoPorcentaje::staticMetaObject();
    static const QUMethod slot_0 = {"S_PasaFocoPorcentajeAlto", 0, 0 };
    static const QUMethod slot_1 = {"S_PasaFocoAceptar", 0, 0 };
    static const QUMethod slot_2 = {"S_Aceptar", 0, 0 };
    static const QUMethod slot_3 = {"S_Cancelar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "S_PasaFocoPorcentajeAlto()", &slot_0, QMetaData::Private },
	{ "S_PasaFocoAceptar()", &slot_1, QMetaData::Private },
	{ "S_Aceptar()", &slot_2, QMetaData::Private },
	{ "S_Cancelar()", &slot_3, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QRangoPorcentaje", parentObject,
	slot_tbl, 4,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QRangoPorcentaje.setMetaObject( metaObj );
    return metaObj;
}

void* QRangoPorcentaje::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QRangoPorcentaje" ) )
	return this;
    return RangoPorcentaje::qt_cast( clname );
}

bool QRangoPorcentaje::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: S_PasaFocoPorcentajeAlto(); break;
    case 1: S_PasaFocoAceptar(); break;
    case 2: S_Aceptar(); break;
    case 3: S_Cancelar(); break;
    default:
	return RangoPorcentaje::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QRangoPorcentaje::qt_emit( int _id, QUObject* _o )
{
    return RangoPorcentaje::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QRangoPorcentaje::qt_property( int id, int f, QVariant* v)
{
    return RangoPorcentaje::qt_property( id, f, v);
}

bool QRangoPorcentaje::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
