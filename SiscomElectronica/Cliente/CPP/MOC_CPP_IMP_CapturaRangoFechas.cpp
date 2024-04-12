/****************************************************************************
** QCapturaRangoFechas meta object code from reading C++ file 'IMP_CapturaRangoFechas.h'
**
** Created: Thu Apr 11 21:39:28 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_CapturaRangoFechas.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCapturaRangoFechas::className() const
{
    return "QCapturaRangoFechas";
}

QMetaObject *QCapturaRangoFechas::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCapturaRangoFechas( "QCapturaRangoFechas", &QCapturaRangoFechas::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCapturaRangoFechas::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCapturaRangoFechas", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCapturaRangoFechas::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCapturaRangoFechas", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCapturaRangoFechas::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CapturaRangoFechas::staticMetaObject();
    static const QUMethod slot_0 = {"S_PasaFocoFechaFin", 0, 0 };
    static const QUMethod slot_1 = {"S_PasaFocoAceptar", 0, 0 };
    static const QUMethod slot_2 = {"S_Aceptar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "S_PasaFocoFechaFin()", &slot_0, QMetaData::Private },
	{ "S_PasaFocoAceptar()", &slot_1, QMetaData::Private },
	{ "S_Aceptar()", &slot_2, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCapturaRangoFechas", parentObject,
	slot_tbl, 3,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCapturaRangoFechas.setMetaObject( metaObj );
    return metaObj;
}

void* QCapturaRangoFechas::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCapturaRangoFechas" ) )
	return this;
    return CapturaRangoFechas::qt_cast( clname );
}

bool QCapturaRangoFechas::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: S_PasaFocoFechaFin(); break;
    case 1: S_PasaFocoAceptar(); break;
    case 2: S_Aceptar(); break;
    default:
	return CapturaRangoFechas::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCapturaRangoFechas::qt_emit( int _id, QUObject* _o )
{
    return CapturaRangoFechas::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QCapturaRangoFechas::qt_property( int id, int f, QVariant* v)
{
    return CapturaRangoFechas::qt_property( id, f, v);
}

bool QCapturaRangoFechas::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
