/****************************************************************************
** QCapturaCantidad3Qt meta object code from reading C++ file 'IMP_CapturaCantidad3Qt.h'
**
** Created: Thu Apr 11 20:30:21 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_CapturaCantidad3Qt.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCapturaCantidad3Qt::className() const
{
    return "QCapturaCantidad3Qt";
}

QMetaObject *QCapturaCantidad3Qt::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCapturaCantidad3Qt( "QCapturaCantidad3Qt", &QCapturaCantidad3Qt::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCapturaCantidad3Qt::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCapturaCantidad3Qt", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCapturaCantidad3Qt::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCapturaCantidad3Qt", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCapturaCantidad3Qt::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CapturaCantidad::staticMetaObject();
    static const QUMethod slot_0 = {"SlotAceptar", 0, 0 };
    static const QUMethod slot_1 = {"SlotCancelar", 0, 0 };
    static const QUMethod slot_2 = {"SlotPasaFocoAceptar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotAceptar()", &slot_0, QMetaData::Private },
	{ "SlotCancelar()", &slot_1, QMetaData::Private },
	{ "SlotPasaFocoAceptar()", &slot_2, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCapturaCantidad3Qt", parentObject,
	slot_tbl, 3,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCapturaCantidad3Qt.setMetaObject( metaObj );
    return metaObj;
}

void* QCapturaCantidad3Qt::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCapturaCantidad3Qt" ) )
	return this;
    return CapturaCantidad::qt_cast( clname );
}

bool QCapturaCantidad3Qt::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotAceptar(); break;
    case 1: SlotCancelar(); break;
    case 2: SlotPasaFocoAceptar(); break;
    default:
	return CapturaCantidad::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCapturaCantidad3Qt::qt_emit( int _id, QUObject* _o )
{
    return CapturaCantidad::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QCapturaCantidad3Qt::qt_property( int id, int f, QVariant* v)
{
    return CapturaCantidad::qt_property( id, f, v);
}

bool QCapturaCantidad3Qt::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
