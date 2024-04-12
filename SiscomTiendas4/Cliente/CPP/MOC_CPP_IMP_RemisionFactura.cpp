/****************************************************************************
** QRemisionFactura meta object code from reading C++ file 'IMP_RemisionFactura.h'
**
** Created: Thu Apr 11 22:09:38 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_RemisionFactura.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QRemisionFactura::className() const
{
    return "QRemisionFactura";
}

QMetaObject *QRemisionFactura::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QRemisionFactura( "QRemisionFactura", &QRemisionFactura::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QRemisionFactura::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRemisionFactura", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QRemisionFactura::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRemisionFactura", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QRemisionFactura::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = RemisionFactura::staticMetaObject();
    static const QUMethod slot_0 = {"SlotPasaFocoAceptar", 0, 0 };
    static const QUMethod slot_1 = {"SlotAceptar", 0, 0 };
    static const QUMethod slot_2 = {"SlotCancelar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotPasaFocoAceptar()", &slot_0, QMetaData::Private },
	{ "SlotAceptar()", &slot_1, QMetaData::Private },
	{ "SlotCancelar()", &slot_2, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QRemisionFactura", parentObject,
	slot_tbl, 3,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QRemisionFactura.setMetaObject( metaObj );
    return metaObj;
}

void* QRemisionFactura::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QRemisionFactura" ) )
	return this;
    return RemisionFactura::qt_cast( clname );
}

bool QRemisionFactura::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotPasaFocoAceptar(); break;
    case 1: SlotAceptar(); break;
    case 2: SlotCancelar(); break;
    default:
	return RemisionFactura::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QRemisionFactura::qt_emit( int _id, QUObject* _o )
{
    return RemisionFactura::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QRemisionFactura::qt_property( int id, int f, QVariant* v)
{
    return RemisionFactura::qt_property( id, f, v);
}

bool QRemisionFactura::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
