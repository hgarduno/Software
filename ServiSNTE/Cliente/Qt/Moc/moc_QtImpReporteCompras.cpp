/****************************************************************************
** QtImpReporteCompras meta object code from reading C++ file 'QtImpReporteCompras.h'
**
** Created: Thu Apr 11 21:08:26 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpReporteCompras.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpReporteCompras::className() const
{
    return "QtImpReporteCompras";
}

QMetaObject *QtImpReporteCompras::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpReporteCompras( "QtImpReporteCompras", &QtImpReporteCompras::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpReporteCompras::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpReporteCompras", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpReporteCompras::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpReporteCompras", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpReporteCompras::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ReporteCompras::staticMetaObject();
    static const QUMethod slot_0 = {"SlotRangoFecha", 0, 0 };
    static const QUParameter param_slot_1[] = {
	{ "pintCompra", &static_QUType_int, 0, QUParameter::In },
	{ "pintColumna", &static_QUType_int, 0, QUParameter::In },
	{ "pintBoton", &static_QUType_int, 0, QUParameter::In },
	{ "pQPPosicion", &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotSeleccionaCompra", 4, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_2 = {"SlotSeleccionaProducto", 4, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"SlotSeleccionaProducto", 2, param_slot_3 };
    static const QMetaData slot_tbl[] = {
	{ "SlotRangoFecha()", &slot_0, QMetaData::Private },
	{ "SlotSeleccionaCompra(int,int,int,const QPoint&)", &slot_1, QMetaData::Private },
	{ "SlotSeleccionaProducto(int,int,int,const QPoint&)", &slot_2, QMetaData::Private },
	{ "SlotSeleccionaProducto(int,int)", &slot_3, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpReporteCompras", parentObject,
	slot_tbl, 4,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpReporteCompras.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpReporteCompras::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpReporteCompras" ) )
	return this;
    return ReporteCompras::qt_cast( clname );
}

bool QtImpReporteCompras::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotRangoFecha(); break;
    case 1: SlotSeleccionaCompra((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 2: SlotSeleccionaProducto((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 3: SlotSeleccionaProducto((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    default:
	return ReporteCompras::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpReporteCompras::qt_emit( int _id, QUObject* _o )
{
    return ReporteCompras::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpReporteCompras::qt_property( int id, int f, QVariant* v)
{
    return ReporteCompras::qt_property( id, f, v);
}

bool QtImpReporteCompras::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
