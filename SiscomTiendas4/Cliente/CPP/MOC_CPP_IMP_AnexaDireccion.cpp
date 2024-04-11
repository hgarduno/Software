/****************************************************************************
** QAnexaDireccion meta object code from reading C++ file 'IMP_AnexaDireccion.h'
**
** Created: Thu Apr 11 20:30:21 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_AnexaDireccion.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QAnexaDireccion::className() const
{
    return "QAnexaDireccion";
}

QMetaObject *QAnexaDireccion::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QAnexaDireccion( "QAnexaDireccion", &QAnexaDireccion::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QAnexaDireccion::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QAnexaDireccion", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QAnexaDireccion::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QAnexaDireccion", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QAnexaDireccion::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = AnexaDireccion::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotDireccion", 1, param_slot_0 };
    static const QUMethod slot_1 = {"SlotAnexa", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotDireccion(SiscomRegistro3*)", &slot_0, QMetaData::Private },
	{ "SlotAnexa()", &slot_1, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QAnexaDireccion", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QAnexaDireccion.setMetaObject( metaObj );
    return metaObj;
}

void* QAnexaDireccion::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QAnexaDireccion" ) )
	return this;
    return AnexaDireccion::qt_cast( clname );
}

bool QAnexaDireccion::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotDireccion((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotAnexa(); break;
    default:
	return AnexaDireccion::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QAnexaDireccion::qt_emit( int _id, QUObject* _o )
{
    return AnexaDireccion::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QAnexaDireccion::qt_property( int id, int f, QVariant* v)
{
    return AnexaDireccion::qt_property( id, f, v);
}

bool QAnexaDireccion::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
