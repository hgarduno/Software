/****************************************************************************
** QImprimeReporteSemestral meta object code from reading C++ file 'IMP_ImprimeReporteSemestral.h'
**
** Created: Fri Apr 12 21:26:09 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_ImprimeReporteSemestral.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QImprimeReporteSemestral::className() const
{
    return "QImprimeReporteSemestral";
}

QMetaObject *QImprimeReporteSemestral::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QImprimeReporteSemestral( "QImprimeReporteSemestral", &QImprimeReporteSemestral::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QImprimeReporteSemestral::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QImprimeReporteSemestral", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QImprimeReporteSemestral::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QImprimeReporteSemestral", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QImprimeReporteSemestral::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ImprimeReporteSemestral::staticMetaObject();
    static const QUMethod slot_0 = {"SlotImprime", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotImprime()", &slot_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QImprimeReporteSemestral", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QImprimeReporteSemestral.setMetaObject( metaObj );
    return metaObj;
}

void* QImprimeReporteSemestral::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QImprimeReporteSemestral" ) )
	return this;
    return ImprimeReporteSemestral::qt_cast( clname );
}

bool QImprimeReporteSemestral::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotImprime(); break;
    default:
	return ImprimeReporteSemestral::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QImprimeReporteSemestral::qt_emit( int _id, QUObject* _o )
{
    return ImprimeReporteSemestral::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QImprimeReporteSemestral::qt_property( int id, int f, QVariant* v)
{
    return ImprimeReporteSemestral::qt_property( id, f, v);
}

bool QImprimeReporteSemestral::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
