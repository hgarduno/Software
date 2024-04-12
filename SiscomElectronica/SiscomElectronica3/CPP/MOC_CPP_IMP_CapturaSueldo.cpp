/****************************************************************************
** QCapturaSueldo meta object code from reading C++ file 'IMP_CapturaSueldo.h'
**
** Created: Thu Apr 11 21:39:17 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_CapturaSueldo.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCapturaSueldo::className() const
{
    return "QCapturaSueldo";
}

QMetaObject *QCapturaSueldo::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCapturaSueldo( "QCapturaSueldo", &QCapturaSueldo::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCapturaSueldo::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCapturaSueldo", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCapturaSueldo::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCapturaSueldo", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCapturaSueldo::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CapturaSueldo::staticMetaObject();
    static const QUMethod slot_0 = {"SlotPasaFocoRegistra", 0, 0 };
    static const QUMethod slot_1 = {"SlotRegistra", 0, 0 };
    static const QUMethod slot_2 = {"SlotCancela", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotPasaFocoRegistra()", &slot_0, QMetaData::Private },
	{ "SlotRegistra()", &slot_1, QMetaData::Private },
	{ "SlotCancela()", &slot_2, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCapturaSueldo", parentObject,
	slot_tbl, 3,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCapturaSueldo.setMetaObject( metaObj );
    return metaObj;
}

void* QCapturaSueldo::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCapturaSueldo" ) )
	return this;
    return CapturaSueldo::qt_cast( clname );
}

bool QCapturaSueldo::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotPasaFocoRegistra(); break;
    case 1: SlotRegistra(); break;
    case 2: SlotCancela(); break;
    default:
	return CapturaSueldo::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCapturaSueldo::qt_emit( int _id, QUObject* _o )
{
    return CapturaSueldo::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QCapturaSueldo::qt_property( int id, int f, QVariant* v)
{
    return CapturaSueldo::qt_property( id, f, v);
}

bool QCapturaSueldo::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
