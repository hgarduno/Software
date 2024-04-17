/****************************************************************************
** QVendiendoOrden meta object code from reading C++ file 'IMP_VendiendoOrden.h'
**
** Created: Fri Apr 12 21:26:09 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_VendiendoOrden.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QVendiendoOrden::className() const
{
    return "QVendiendoOrden";
}

QMetaObject *QVendiendoOrden::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QVendiendoOrden( "QVendiendoOrden", &QVendiendoOrden::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QVendiendoOrden::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QVendiendoOrden", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QVendiendoOrden::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QVendiendoOrden", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QVendiendoOrden::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = VendiendoOrden::staticMetaObject();
    static const QUMethod slot_0 = {"SlotImprimir", 0, 0 };
    static const QUMethod slot_1 = {"SlotVender", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotImprimir()", &slot_0, QMetaData::Private },
	{ "SlotVender()", &slot_1, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QVendiendoOrden", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QVendiendoOrden.setMetaObject( metaObj );
    return metaObj;
}

void* QVendiendoOrden::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QVendiendoOrden" ) )
	return this;
    return VendiendoOrden::qt_cast( clname );
}

bool QVendiendoOrden::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotImprimir(); break;
    case 1: SlotVender(); break;
    default:
	return VendiendoOrden::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QVendiendoOrden::qt_emit( int _id, QUObject* _o )
{
    return VendiendoOrden::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QVendiendoOrden::qt_property( int id, int f, QVariant* v)
{
    return VendiendoOrden::qt_property( id, f, v);
}

bool QVendiendoOrden::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
