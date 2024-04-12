/****************************************************************************
** QCapturaExistenciaFisica meta object code from reading C++ file 'IMP_CapturaExistenciaFisica.h'
**
** Created: Thu Apr 11 21:40:01 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_CapturaExistenciaFisica.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCapturaExistenciaFisica::className() const
{
    return "QCapturaExistenciaFisica";
}

QMetaObject *QCapturaExistenciaFisica::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCapturaExistenciaFisica( "QCapturaExistenciaFisica", &QCapturaExistenciaFisica::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCapturaExistenciaFisica::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCapturaExistenciaFisica", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCapturaExistenciaFisica::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCapturaExistenciaFisica", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCapturaExistenciaFisica::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CapturaExistenciaFisica::staticMetaObject();
    static const QUMethod slot_0 = {"SlotPasaFocoAceptar", 0, 0 };
    static const QUMethod slot_1 = {"SlotAceptar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotPasaFocoAceptar()", &slot_0, QMetaData::Private },
	{ "SlotAceptar()", &slot_1, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCapturaExistenciaFisica", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCapturaExistenciaFisica.setMetaObject( metaObj );
    return metaObj;
}

void* QCapturaExistenciaFisica::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCapturaExistenciaFisica" ) )
	return this;
    return CapturaExistenciaFisica::qt_cast( clname );
}

bool QCapturaExistenciaFisica::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotPasaFocoAceptar(); break;
    case 1: SlotAceptar(); break;
    default:
	return CapturaExistenciaFisica::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCapturaExistenciaFisica::qt_emit( int _id, QUObject* _o )
{
    return CapturaExistenciaFisica::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QCapturaExistenciaFisica::qt_property( int id, int f, QVariant* v)
{
    return CapturaExistenciaFisica::qt_property( id, f, v);
}

bool QCapturaExistenciaFisica::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
