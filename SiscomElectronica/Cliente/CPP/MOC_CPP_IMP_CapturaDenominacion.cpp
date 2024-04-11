/****************************************************************************
** QCapturaDenominacion meta object code from reading C++ file 'IMP_CapturaDenominacion.h'
**
** Created: Wed Apr 10 20:52:39 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_CapturaDenominacion.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCapturaDenominacion::className() const
{
    return "QCapturaDenominacion";
}

QMetaObject *QCapturaDenominacion::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCapturaDenominacion( "QCapturaDenominacion", &QCapturaDenominacion::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCapturaDenominacion::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCapturaDenominacion", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCapturaDenominacion::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCapturaDenominacion", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCapturaDenominacion::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CapturaDenominacion::staticMetaObject();
    static const QUMethod slot_0 = {"SlotAceptar", 0, 0 };
    static const QUMethod slot_1 = {"SlotCancelar", 0, 0 };
    static const QUMethod slot_2 = {"SlotPasaFocoCantidad", 0, 0 };
    static const QUMethod slot_3 = {"SlotPasaFocoAceptar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotAceptar()", &slot_0, QMetaData::Private },
	{ "SlotCancelar()", &slot_1, QMetaData::Private },
	{ "SlotPasaFocoCantidad()", &slot_2, QMetaData::Private },
	{ "SlotPasaFocoAceptar()", &slot_3, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCapturaDenominacion", parentObject,
	slot_tbl, 4,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCapturaDenominacion.setMetaObject( metaObj );
    return metaObj;
}

void* QCapturaDenominacion::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCapturaDenominacion" ) )
	return this;
    return CapturaDenominacion::qt_cast( clname );
}

bool QCapturaDenominacion::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotAceptar(); break;
    case 1: SlotCancelar(); break;
    case 2: SlotPasaFocoCantidad(); break;
    case 3: SlotPasaFocoAceptar(); break;
    default:
	return CapturaDenominacion::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCapturaDenominacion::qt_emit( int _id, QUObject* _o )
{
    return CapturaDenominacion::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QCapturaDenominacion::qt_property( int id, int f, QVariant* v)
{
    return CapturaDenominacion::qt_property( id, f, v);
}

bool QCapturaDenominacion::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
