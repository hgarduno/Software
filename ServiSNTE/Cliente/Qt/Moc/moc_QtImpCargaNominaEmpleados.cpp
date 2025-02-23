/****************************************************************************
** QtImpCargaNominaEmpleados meta object code from reading C++ file 'QtImpCargaNominaEmpleados.h'
**
** Created: Sat Feb 22 23:13:23 2025
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpCargaNominaEmpleados.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpCargaNominaEmpleados::className() const
{
    return "QtImpCargaNominaEmpleados";
}

QMetaObject *QtImpCargaNominaEmpleados::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpCargaNominaEmpleados( "QtImpCargaNominaEmpleados", &QtImpCargaNominaEmpleados::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpCargaNominaEmpleados::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpCargaNominaEmpleados", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpCargaNominaEmpleados::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpCargaNominaEmpleados", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpCargaNominaEmpleados::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CargaNominaEmpleados::staticMetaObject();
    static const QUMethod slot_0 = {"SlotSelArchivo", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotSelArchivo()", &slot_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpCargaNominaEmpleados", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpCargaNominaEmpleados.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpCargaNominaEmpleados::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpCargaNominaEmpleados" ) )
	return this;
    return CargaNominaEmpleados::qt_cast( clname );
}

bool QtImpCargaNominaEmpleados::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotSelArchivo(); break;
    default:
	return CargaNominaEmpleados::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpCargaNominaEmpleados::qt_emit( int _id, QUObject* _o )
{
    return CargaNominaEmpleados::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpCargaNominaEmpleados::qt_property( int id, int f, QVariant* v)
{
    return CargaNominaEmpleados::qt_property( id, f, v);
}

bool QtImpCargaNominaEmpleados::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
