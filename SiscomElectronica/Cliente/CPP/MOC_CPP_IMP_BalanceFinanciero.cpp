/****************************************************************************
** QBalanceFinanciero meta object code from reading C++ file 'IMP_BalanceFinanciero.h'
**
** Created: Wed Apr 10 20:52:40 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_BalanceFinanciero.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QBalanceFinanciero::className() const
{
    return "QBalanceFinanciero";
}

QMetaObject *QBalanceFinanciero::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QBalanceFinanciero( "QBalanceFinanciero", &QBalanceFinanciero::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QBalanceFinanciero::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QBalanceFinanciero", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QBalanceFinanciero::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QBalanceFinanciero", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QBalanceFinanciero::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = BalanceFinanciero::staticMetaObject();
    static const QUMethod slot_0 = {"SlotCargaArchivoHtml", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotCargaArchivoHtml()", &slot_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QBalanceFinanciero", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QBalanceFinanciero.setMetaObject( metaObj );
    return metaObj;
}

void* QBalanceFinanciero::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QBalanceFinanciero" ) )
	return this;
    return BalanceFinanciero::qt_cast( clname );
}

bool QBalanceFinanciero::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotCargaArchivoHtml(); break;
    default:
	return BalanceFinanciero::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QBalanceFinanciero::qt_emit( int _id, QUObject* _o )
{
    return BalanceFinanciero::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QBalanceFinanciero::qt_property( int id, int f, QVariant* v)
{
    return BalanceFinanciero::qt_property( id, f, v);
}

bool QBalanceFinanciero::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
