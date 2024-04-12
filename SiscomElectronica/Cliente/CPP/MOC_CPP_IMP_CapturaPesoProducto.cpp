/****************************************************************************
** QCapturaPesoProducto meta object code from reading C++ file 'IMP_CapturaPesoProducto.h'
**
** Created: Thu Apr 11 21:40:02 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_CapturaPesoProducto.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCapturaPesoProducto::className() const
{
    return "QCapturaPesoProducto";
}

QMetaObject *QCapturaPesoProducto::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCapturaPesoProducto( "QCapturaPesoProducto", &QCapturaPesoProducto::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCapturaPesoProducto::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCapturaPesoProducto", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCapturaPesoProducto::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCapturaPesoProducto", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCapturaPesoProducto::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CapturaPesoProducto::staticMetaObject();
    static const QUMethod slot_0 = {"SlotFocoARegistrar", 0, 0 };
    static const QUMethod slot_1 = {"SlotRegistrar", 0, 0 };
    static const QUMethod slot_2 = {"SlotTerminar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotFocoARegistrar()", &slot_0, QMetaData::Private },
	{ "SlotRegistrar()", &slot_1, QMetaData::Private },
	{ "SlotTerminar()", &slot_2, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCapturaPesoProducto", parentObject,
	slot_tbl, 3,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCapturaPesoProducto.setMetaObject( metaObj );
    return metaObj;
}

void* QCapturaPesoProducto::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCapturaPesoProducto" ) )
	return this;
    return CapturaPesoProducto::qt_cast( clname );
}

bool QCapturaPesoProducto::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotFocoARegistrar(); break;
    case 1: SlotRegistrar(); break;
    case 2: SlotTerminar(); break;
    default:
	return CapturaPesoProducto::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCapturaPesoProducto::qt_emit( int _id, QUObject* _o )
{
    return CapturaPesoProducto::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QCapturaPesoProducto::qt_property( int id, int f, QVariant* v)
{
    return CapturaPesoProducto::qt_property( id, f, v);
}

bool QCapturaPesoProducto::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
