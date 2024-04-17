/****************************************************************************
** QEstadosPedido meta object code from reading C++ file 'IMP_EstadosPedido.h'
**
** Created: Fri Apr 12 21:26:09 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_EstadosPedido.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QEstadosPedido::className() const
{
    return "QEstadosPedido";
}

QMetaObject *QEstadosPedido::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QEstadosPedido( "QEstadosPedido", &QEstadosPedido::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QEstadosPedido::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QEstadosPedido", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QEstadosPedido::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QEstadosPedido", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QEstadosPedido::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = EstadosPedido::staticMetaObject();
    static const QUMethod slot_0 = {"SlotConsulta", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotConsulta()", &slot_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QEstadosPedido", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QEstadosPedido.setMetaObject( metaObj );
    return metaObj;
}

void* QEstadosPedido::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QEstadosPedido" ) )
	return this;
    return EstadosPedido::qt_cast( clname );
}

bool QEstadosPedido::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotConsulta(); break;
    default:
	return EstadosPedido::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QEstadosPedido::qt_emit( int _id, QUObject* _o )
{
    return EstadosPedido::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QEstadosPedido::qt_property( int id, int f, QVariant* v)
{
    return EstadosPedido::qt_property( id, f, v);
}

bool QEstadosPedido::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
