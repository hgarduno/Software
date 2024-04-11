/****************************************************************************
** QtImpReporteVentas meta object code from reading C++ file 'QtImpReporteVentas.h'
**
** Created: Sat Jan 27 16:39:02 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpReporteVentas.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpReporteVentas::className() const
{
    return "QtImpReporteVentas";
}

QMetaObject *QtImpReporteVentas::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpReporteVentas( "QtImpReporteVentas", &QtImpReporteVentas::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpReporteVentas::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpReporteVentas", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpReporteVentas::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpReporteVentas", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpReporteVentas::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ReporteVentas::staticMetaObject();
    static const QUMethod slot_0 = {"SlotFocoATiendas", 0, 0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotTipoVenta", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_2 = {"SlotTienda", 1, param_slot_2 };
    static const QUMethod slot_3 = {"SlotConsulta", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotFocoATiendas()", &slot_0, QMetaData::Private },
	{ "SlotTipoVenta(zSiscomRegistro*)", &slot_1, QMetaData::Private },
	{ "SlotTienda(zSiscomRegistro*)", &slot_2, QMetaData::Private },
	{ "SlotConsulta()", &slot_3, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpReporteVentas", parentObject,
	slot_tbl, 4,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpReporteVentas.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpReporteVentas::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpReporteVentas" ) )
	return this;
    return ReporteVentas::qt_cast( clname );
}

bool QtImpReporteVentas::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotFocoATiendas(); break;
    case 1: SlotTipoVenta((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 2: SlotTienda((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 3: SlotConsulta(); break;
    default:
	return ReporteVentas::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpReporteVentas::qt_emit( int _id, QUObject* _o )
{
    return ReporteVentas::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpReporteVentas::qt_property( int id, int f, QVariant* v)
{
    return ReporteVentas::qt_property( id, f, v);
}

bool QtImpReporteVentas::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
