/****************************************************************************
** QCapturaContactoE meta object code from reading C++ file 'IMP_CapturaContactoE.h'
**
** Created: Thu Apr 11 22:09:38 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_CapturaContactoE.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCapturaContactoE::className() const
{
    return "QCapturaContactoE";
}

QMetaObject *QCapturaContactoE::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCapturaContactoE( "QCapturaContactoE", &QCapturaContactoE::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCapturaContactoE::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCapturaContactoE", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCapturaContactoE::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCapturaContactoE", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCapturaContactoE::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CapturaContactoE::staticMetaObject();
    static const QUMethod slot_0 = {"SlotPasaFocoNombre", 0, 0 };
    static const QUMethod slot_1 = {"SlotPasaFocoAPaterno", 0, 0 };
    static const QUMethod slot_2 = {"SlotPasaFocoAMaterno", 0, 0 };
    static const QUMethod slot_3 = {"SlotPasaFocoDescripcion", 0, 0 };
    static const QUMethod slot_4 = {"SlotAceptar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotPasaFocoNombre()", &slot_0, QMetaData::Private },
	{ "SlotPasaFocoAPaterno()", &slot_1, QMetaData::Private },
	{ "SlotPasaFocoAMaterno()", &slot_2, QMetaData::Private },
	{ "SlotPasaFocoDescripcion()", &slot_3, QMetaData::Private },
	{ "SlotAceptar()", &slot_4, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCapturaContactoE", parentObject,
	slot_tbl, 5,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCapturaContactoE.setMetaObject( metaObj );
    return metaObj;
}

void* QCapturaContactoE::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCapturaContactoE" ) )
	return this;
    return CapturaContactoE::qt_cast( clname );
}

bool QCapturaContactoE::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotPasaFocoNombre(); break;
    case 1: SlotPasaFocoAPaterno(); break;
    case 2: SlotPasaFocoAMaterno(); break;
    case 3: SlotPasaFocoDescripcion(); break;
    case 4: SlotAceptar(); break;
    default:
	return CapturaContactoE::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCapturaContactoE::qt_emit( int _id, QUObject* _o )
{
    return CapturaContactoE::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QCapturaContactoE::qt_property( int id, int f, QVariant* v)
{
    return CapturaContactoE::qt_property( id, f, v);
}

bool QCapturaContactoE::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
