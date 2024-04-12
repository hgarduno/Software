/****************************************************************************
** QCaja2 meta object code from reading C++ file 'IMP_Caja2.h'
**
** Created: Thu Apr 11 21:40:01 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_Caja2.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCaja2::className() const
{
    return "QCaja2";
}

QMetaObject *QCaja2::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCaja2( "QCaja2", &QCaja2::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCaja2::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCaja2", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCaja2::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCaja2", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCaja2::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = Caja2::staticMetaObject();
    static const QUMethod slot_0 = {"SlotOrdenesPendientes", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotOrdenesPendientes()", &slot_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCaja2", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCaja2.setMetaObject( metaObj );
    return metaObj;
}

void* QCaja2::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCaja2" ) )
	return this;
    return Caja2::qt_cast( clname );
}

bool QCaja2::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotOrdenesPendientes(); break;
    default:
	return Caja2::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCaja2::qt_emit( int _id, QUObject* _o )
{
    return Caja2::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QCaja2::qt_property( int id, int f, QVariant* v)
{
    return Caja2::qt_property( id, f, v);
}

bool QCaja2::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
