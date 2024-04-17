/****************************************************************************
** QDatosPedido meta object code from reading C++ file 'IMP_DatosPedido.h'
**
** Created: Fri Apr 12 21:26:09 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_DatosPedido.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QDatosPedido::className() const
{
    return "QDatosPedido";
}

QMetaObject *QDatosPedido::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QDatosPedido( "QDatosPedido", &QDatosPedido::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QDatosPedido::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QDatosPedido", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QDatosPedido::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QDatosPedido", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QDatosPedido::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QtDatosPedido::staticMetaObject();
    static const QUMethod slot_0 = {"SlotAceptar", 0, 0 };
    static const QUMethod slot_1 = {"SlotCancelar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotAceptar()", &slot_0, QMetaData::Private },
	{ "SlotCancelar()", &slot_1, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QDatosPedido", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QDatosPedido.setMetaObject( metaObj );
    return metaObj;
}

void* QDatosPedido::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QDatosPedido" ) )
	return this;
    return QtDatosPedido::qt_cast( clname );
}

bool QDatosPedido::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotAceptar(); break;
    case 1: SlotCancelar(); break;
    default:
	return QtDatosPedido::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QDatosPedido::qt_emit( int _id, QUObject* _o )
{
    return QtDatosPedido::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QDatosPedido::qt_property( int id, int f, QVariant* v)
{
    return QtDatosPedido::qt_property( id, f, v);
}

bool QDatosPedido::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
