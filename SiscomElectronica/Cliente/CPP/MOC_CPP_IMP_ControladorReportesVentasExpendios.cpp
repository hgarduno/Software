/****************************************************************************
** QControladorReportesVentasExpendios meta object code from reading C++ file 'IMP_ControladorReportesVentasExpendios.h'
**
** Created: Fri Apr 12 21:26:09 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_ControladorReportesVentasExpendios.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QControladorReportesVentasExpendios::className() const
{
    return "QControladorReportesVentasExpendios";
}

QMetaObject *QControladorReportesVentasExpendios::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QControladorReportesVentasExpendios( "QControladorReportesVentasExpendios", &QControladorReportesVentasExpendios::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QControladorReportesVentasExpendios::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QControladorReportesVentasExpendios", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QControladorReportesVentasExpendios::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QControladorReportesVentasExpendios", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QControladorReportesVentasExpendios::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ControladorReportesVentasExpendios::staticMetaObject();
    static const QUMethod slot_0 = {"SlotIniciaMuestreo", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotIniciaMuestreo()", &slot_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QControladorReportesVentasExpendios", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QControladorReportesVentasExpendios.setMetaObject( metaObj );
    return metaObj;
}

void* QControladorReportesVentasExpendios::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QControladorReportesVentasExpendios" ) )
	return this;
    return ControladorReportesVentasExpendios::qt_cast( clname );
}

bool QControladorReportesVentasExpendios::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotIniciaMuestreo(); break;
    default:
	return ControladorReportesVentasExpendios::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QControladorReportesVentasExpendios::qt_emit( int _id, QUObject* _o )
{
    return ControladorReportesVentasExpendios::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QControladorReportesVentasExpendios::qt_property( int id, int f, QVariant* v)
{
    return ControladorReportesVentasExpendios::qt_property( id, f, v);
}

bool QControladorReportesVentasExpendios::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
