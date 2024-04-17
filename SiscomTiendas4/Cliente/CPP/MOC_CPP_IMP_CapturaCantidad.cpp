/****************************************************************************
** QCapturaCantidad meta object code from reading C++ file 'IMP_CapturaCantidad.h'
**
** Created: Fri Apr 12 21:36:43 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_CapturaCantidad.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCapturaCantidad::className() const
{
    return "QCapturaCantidad";
}

QMetaObject *QCapturaCantidad::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCapturaCantidad( "QCapturaCantidad", &QCapturaCantidad::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCapturaCantidad::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCapturaCantidad", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCapturaCantidad::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCapturaCantidad", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCapturaCantidad::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CapturaCantidad::staticMetaObject();
    static const QUMethod slot_0 = {"SlotPasaFocoAceptar", 0, 0 };
    static const QUMethod slot_1 = {"SlotAceptar", 0, 0 };
    static const QUMethod slot_2 = {"SlotCancelar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotPasaFocoAceptar()", &slot_0, QMetaData::Private },
	{ "SlotAceptar()", &slot_1, QMetaData::Private },
	{ "SlotCancelar()", &slot_2, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCapturaCantidad", parentObject,
	slot_tbl, 3,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCapturaCantidad.setMetaObject( metaObj );
    return metaObj;
}

void* QCapturaCantidad::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCapturaCantidad" ) )
	return this;
    return CapturaCantidad::qt_cast( clname );
}

bool QCapturaCantidad::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotPasaFocoAceptar(); break;
    case 1: SlotAceptar(); break;
    case 2: SlotCancelar(); break;
    default:
	return CapturaCantidad::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCapturaCantidad::qt_emit( int _id, QUObject* _o )
{
    return CapturaCantidad::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QCapturaCantidad::qt_property( int id, int f, QVariant* v)
{
    return CapturaCantidad::qt_property( id, f, v);
}

bool QCapturaCantidad::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
