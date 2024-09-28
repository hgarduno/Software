/****************************************************************************
** QtImpInventarioEnCurso meta object code from reading C++ file 'QtImpInventarioEnCurso.h'
**
** Created: Thu Aug 15 00:50:03 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpInventarioEnCurso.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpInventarioEnCurso::className() const
{
    return "QtImpInventarioEnCurso";
}

QMetaObject *QtImpInventarioEnCurso::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpInventarioEnCurso( "QtImpInventarioEnCurso", &QtImpInventarioEnCurso::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpInventarioEnCurso::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpInventarioEnCurso", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpInventarioEnCurso::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpInventarioEnCurso", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpInventarioEnCurso::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = InventarioEnCurso::staticMetaObject();
    static const QUMethod slot_0 = {"SlotAceptar", 0, 0 };
    static const QUMethod slot_1 = {"SlotCancelar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotAceptar()", &slot_0, QMetaData::Private },
	{ "SlotCancelar()", &slot_1, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpInventarioEnCurso", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpInventarioEnCurso.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpInventarioEnCurso::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpInventarioEnCurso" ) )
	return this;
    return InventarioEnCurso::qt_cast( clname );
}

bool QtImpInventarioEnCurso::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotAceptar(); break;
    case 1: SlotCancelar(); break;
    default:
	return InventarioEnCurso::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpInventarioEnCurso::qt_emit( int _id, QUObject* _o )
{
    return InventarioEnCurso::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpInventarioEnCurso::qt_property( int id, int f, QVariant* v)
{
    return InventarioEnCurso::qt_property( id, f, v);
}

bool QtImpInventarioEnCurso::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
