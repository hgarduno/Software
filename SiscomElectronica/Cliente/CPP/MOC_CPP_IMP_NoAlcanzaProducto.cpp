/****************************************************************************
** QNoAlcanzaProducto meta object code from reading C++ file 'IMP_NoAlcanzaProducto.h'
**
** Created: Wed Apr 10 20:52:40 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_NoAlcanzaProducto.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QNoAlcanzaProducto::className() const
{
    return "QNoAlcanzaProducto";
}

QMetaObject *QNoAlcanzaProducto::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QNoAlcanzaProducto( "QNoAlcanzaProducto", &QNoAlcanzaProducto::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QNoAlcanzaProducto::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QNoAlcanzaProducto", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QNoAlcanzaProducto::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QNoAlcanzaProducto", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QNoAlcanzaProducto::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = NoAlcanzaProducto::staticMetaObject();
    static const QUMethod slot_0 = {"SlotAceptar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotAceptar()", &slot_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QNoAlcanzaProducto", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QNoAlcanzaProducto.setMetaObject( metaObj );
    return metaObj;
}

void* QNoAlcanzaProducto::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QNoAlcanzaProducto" ) )
	return this;
    return NoAlcanzaProducto::qt_cast( clname );
}

bool QNoAlcanzaProducto::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotAceptar(); break;
    default:
	return NoAlcanzaProducto::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QNoAlcanzaProducto::qt_emit( int _id, QUObject* _o )
{
    return NoAlcanzaProducto::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QNoAlcanzaProducto::qt_property( int id, int f, QVariant* v)
{
    return NoAlcanzaProducto::qt_property( id, f, v);
}

bool QNoAlcanzaProducto::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
