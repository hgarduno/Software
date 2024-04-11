/****************************************************************************
** QtImpCapturaCentroTrabajo meta object code from reading C++ file 'QtImpCapturaCentroTrabajo.h'
**
** Created: Sat Jan 27 16:39:19 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpCapturaCentroTrabajo.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpCapturaCentroTrabajo::className() const
{
    return "QtImpCapturaCentroTrabajo";
}

QMetaObject *QtImpCapturaCentroTrabajo::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpCapturaCentroTrabajo( "QtImpCapturaCentroTrabajo", &QtImpCapturaCentroTrabajo::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpCapturaCentroTrabajo::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpCapturaCentroTrabajo", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpCapturaCentroTrabajo::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpCapturaCentroTrabajo", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpCapturaCentroTrabajo::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CapturaCentroTrabajo::staticMetaObject();
    static const QUMethod slot_0 = {"SlotFocoAClavePresupuestal", 0, 0 };
    static const QUMethod slot_1 = {"SlotFocoARegistrar", 0, 0 };
    static const QUMethod slot_2 = {"SlotRegistrar", 0, 0 };
    static const QUMethod slot_3 = {"SlotAceptar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotFocoAClavePresupuestal()", &slot_0, QMetaData::Private },
	{ "SlotFocoARegistrar()", &slot_1, QMetaData::Private },
	{ "SlotRegistrar()", &slot_2, QMetaData::Private },
	{ "SlotAceptar()", &slot_3, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpCapturaCentroTrabajo", parentObject,
	slot_tbl, 4,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpCapturaCentroTrabajo.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpCapturaCentroTrabajo::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpCapturaCentroTrabajo" ) )
	return this;
    return CapturaCentroTrabajo::qt_cast( clname );
}

bool QtImpCapturaCentroTrabajo::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotFocoAClavePresupuestal(); break;
    case 1: SlotFocoARegistrar(); break;
    case 2: SlotRegistrar(); break;
    case 3: SlotAceptar(); break;
    default:
	return CapturaCentroTrabajo::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpCapturaCentroTrabajo::qt_emit( int _id, QUObject* _o )
{
    return CapturaCentroTrabajo::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpCapturaCentroTrabajo::qt_property( int id, int f, QVariant* v)
{
    return CapturaCentroTrabajo::qt_property( id, f, v);
}

bool QtImpCapturaCentroTrabajo::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
