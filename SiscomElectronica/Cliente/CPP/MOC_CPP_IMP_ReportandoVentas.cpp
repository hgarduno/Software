/****************************************************************************
** QReportandoVentas meta object code from reading C++ file 'IMP_ReportandoVentas.h'
**
** Created: Thu Apr 11 21:40:01 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_ReportandoVentas.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QReportandoVentas::className() const
{
    return "QReportandoVentas";
}

QMetaObject *QReportandoVentas::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QReportandoVentas( "QReportandoVentas", &QReportandoVentas::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QReportandoVentas::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QReportandoVentas", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QReportandoVentas::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QReportandoVentas", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QReportandoVentas::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ReportandoVentas::staticMetaObject();
    static const QUMethod slot_0 = {"SlotFocoAFechaFin", 0, 0 };
    static const QUMethod slot_1 = {"SlotFocoConsultar", 0, 0 };
    static const QUMethod slot_2 = {"SlotConsultar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotFocoAFechaFin()", &slot_0, QMetaData::Private },
	{ "SlotFocoConsultar()", &slot_1, QMetaData::Private },
	{ "SlotConsultar()", &slot_2, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QReportandoVentas", parentObject,
	slot_tbl, 3,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QReportandoVentas.setMetaObject( metaObj );
    return metaObj;
}

void* QReportandoVentas::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QReportandoVentas" ) )
	return this;
    return ReportandoVentas::qt_cast( clname );
}

bool QReportandoVentas::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotFocoAFechaFin(); break;
    case 1: SlotFocoConsultar(); break;
    case 2: SlotConsultar(); break;
    default:
	return ReportandoVentas::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QReportandoVentas::qt_emit( int _id, QUObject* _o )
{
    return ReportandoVentas::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QReportandoVentas::qt_property( int id, int f, QVariant* v)
{
    return ReportandoVentas::qt_property( id, f, v);
}

bool QReportandoVentas::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
