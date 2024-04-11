/****************************************************************************
** QReporteVentas4 meta object code from reading C++ file 'IMP_ReporteVentas4.h'
**
** Created: Wed Apr 10 20:52:40 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_ReporteVentas4.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QReporteVentas4::className() const
{
    return "QReporteVentas4";
}

QMetaObject *QReporteVentas4::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QReporteVentas4( "QReporteVentas4", &QReporteVentas4::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QReporteVentas4::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QReporteVentas4", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QReporteVentas4::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QReporteVentas4", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QReporteVentas4::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ReporteVentas4::staticMetaObject();
    static const QUMethod slot_0 = {"SlotFocoAFechaFin", 0, 0 };
    static const QUMethod slot_1 = {"SlotFocoAExpendio", 0, 0 };
    static const QUMethod slot_2 = {"SlotSeleccionaExpendio", 0, 0 };
    static const QUMethod slot_3 = {"SlotConsultar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotFocoAFechaFin()", &slot_0, QMetaData::Private },
	{ "SlotFocoAExpendio()", &slot_1, QMetaData::Private },
	{ "SlotSeleccionaExpendio()", &slot_2, QMetaData::Private },
	{ "SlotConsultar()", &slot_3, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QReporteVentas4", parentObject,
	slot_tbl, 4,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QReporteVentas4.setMetaObject( metaObj );
    return metaObj;
}

void* QReporteVentas4::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QReporteVentas4" ) )
	return this;
    return ReporteVentas4::qt_cast( clname );
}

bool QReporteVentas4::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotFocoAFechaFin(); break;
    case 1: SlotFocoAExpendio(); break;
    case 2: SlotSeleccionaExpendio(); break;
    case 3: SlotConsultar(); break;
    default:
	return ReporteVentas4::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QReporteVentas4::qt_emit( int _id, QUObject* _o )
{
    return ReporteVentas4::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QReporteVentas4::qt_property( int id, int f, QVariant* v)
{
    return ReporteVentas4::qt_property( id, f, v);
}

bool QReporteVentas4::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
