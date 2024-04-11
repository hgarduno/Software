/****************************************************************************
** QCapturaContacto meta object code from reading C++ file 'IMP_CapturaContacto.h'
**
** Created: Wed Apr 10 21:11:55 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_CapturaContacto.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCapturaContacto::className() const
{
    return "QCapturaContacto";
}

QMetaObject *QCapturaContacto::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCapturaContacto( "QCapturaContacto", &QCapturaContacto::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCapturaContacto::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCapturaContacto", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCapturaContacto::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCapturaContacto", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCapturaContacto::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CapturaContacto::staticMetaObject();
    static const QUMethod slot_0 = {"S_PasaFocoAPaterno", 0, 0 };
    static const QUMethod slot_1 = {"S_PasaFocoAMaterno", 0, 0 };
    static const QUMethod slot_2 = {"S_PasaFocoDescripcion", 0, 0 };
    static const QUMethod slot_3 = {"S_PasaFocoAceptar", 0, 0 };
    static const QUMethod slot_4 = {"S_Aceptar", 0, 0 };
    static const QUMethod slot_5 = {"S_Cancelar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "S_PasaFocoAPaterno()", &slot_0, QMetaData::Private },
	{ "S_PasaFocoAMaterno()", &slot_1, QMetaData::Private },
	{ "S_PasaFocoDescripcion()", &slot_2, QMetaData::Private },
	{ "S_PasaFocoAceptar()", &slot_3, QMetaData::Private },
	{ "S_Aceptar()", &slot_4, QMetaData::Private },
	{ "S_Cancelar()", &slot_5, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCapturaContacto", parentObject,
	slot_tbl, 6,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCapturaContacto.setMetaObject( metaObj );
    return metaObj;
}

void* QCapturaContacto::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCapturaContacto" ) )
	return this;
    return CapturaContacto::qt_cast( clname );
}

bool QCapturaContacto::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: S_PasaFocoAPaterno(); break;
    case 1: S_PasaFocoAMaterno(); break;
    case 2: S_PasaFocoDescripcion(); break;
    case 3: S_PasaFocoAceptar(); break;
    case 4: S_Aceptar(); break;
    case 5: S_Cancelar(); break;
    default:
	return CapturaContacto::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCapturaContacto::qt_emit( int _id, QUObject* _o )
{
    return CapturaContacto::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QCapturaContacto::qt_property( int id, int f, QVariant* v)
{
    return CapturaContacto::qt_property( id, f, v);
}

bool QCapturaContacto::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
