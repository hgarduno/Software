/****************************************************************************
** QCotizacionImportacionCierre meta object code from reading C++ file 'IMP_CotizacionImportacionCierre.h'
**
** Created: Fri Apr 12 21:26:09 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_CotizacionImportacionCierre.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCotizacionImportacionCierre::className() const
{
    return "QCotizacionImportacionCierre";
}

QMetaObject *QCotizacionImportacionCierre::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCotizacionImportacionCierre( "QCotizacionImportacionCierre", &QCotizacionImportacionCierre::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCotizacionImportacionCierre::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCotizacionImportacionCierre", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCotizacionImportacionCierre::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCotizacionImportacionCierre", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCotizacionImportacionCierre::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CotizacionImportacionCierre::staticMetaObject();
    static const QUMethod slot_0 = {"SlotCerrar", 0, 0 };
    static const QUMethod slot_1 = {"SlotOtraCotizacion", 0, 0 };
    static const QUMethod slot_2 = {"SlotRegistraCotizacion", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotCerrar()", &slot_0, QMetaData::Private },
	{ "SlotOtraCotizacion()", &slot_1, QMetaData::Private },
	{ "SlotRegistraCotizacion()", &slot_2, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCotizacionImportacionCierre", parentObject,
	slot_tbl, 3,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCotizacionImportacionCierre.setMetaObject( metaObj );
    return metaObj;
}

void* QCotizacionImportacionCierre::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCotizacionImportacionCierre" ) )
	return this;
    return CotizacionImportacionCierre::qt_cast( clname );
}

bool QCotizacionImportacionCierre::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotCerrar(); break;
    case 1: SlotOtraCotizacion(); break;
    case 2: SlotRegistraCotizacion(); break;
    default:
	return CotizacionImportacionCierre::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCotizacionImportacionCierre::qt_emit( int _id, QUObject* _o )
{
    return CotizacionImportacionCierre::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QCotizacionImportacionCierre::qt_property( int id, int f, QVariant* v)
{
    return CotizacionImportacionCierre::qt_property( id, f, v);
}

bool QCotizacionImportacionCierre::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
