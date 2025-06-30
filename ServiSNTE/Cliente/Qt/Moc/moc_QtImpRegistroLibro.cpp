/****************************************************************************
** QtImpRegistroLibro meta object code from reading C++ file 'QtImpRegistroLibro.h'
**
** Created: Tue Jun 24 08:59:57 2025
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpRegistroLibro.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpRegistroLibro::className() const
{
    return "QtImpRegistroLibro";
}

QMetaObject *QtImpRegistroLibro::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpRegistroLibro( "QtImpRegistroLibro", &QtImpRegistroLibro::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpRegistroLibro::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpRegistroLibro", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpRegistroLibro::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpRegistroLibro", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpRegistroLibro::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = RegistroLibro::staticMetaObject();
    static const QUMethod slot_0 = {"SlotImprimir", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotImprimir()", &slot_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpRegistroLibro", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpRegistroLibro.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpRegistroLibro::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpRegistroLibro" ) )
	return this;
    return RegistroLibro::qt_cast( clname );
}

bool QtImpRegistroLibro::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotImprimir(); break;
    default:
	return RegistroLibro::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpRegistroLibro::qt_emit( int _id, QUObject* _o )
{
    return RegistroLibro::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpRegistroLibro::qt_property( int id, int f, QVariant* v)
{
    return RegistroLibro::qt_property( id, f, v);
}

bool QtImpRegistroLibro::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
