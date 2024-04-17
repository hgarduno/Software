/****************************************************************************
** QInformacionPedido meta object code from reading C++ file 'IMP_InformacionPedido.h'
**
** Created: Fri Apr 12 21:36:43 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_InformacionPedido.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QInformacionPedido::className() const
{
    return "QInformacionPedido";
}

QMetaObject *QInformacionPedido::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QInformacionPedido( "QInformacionPedido", &QInformacionPedido::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QInformacionPedido::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QInformacionPedido", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QInformacionPedido::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QInformacionPedido", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QInformacionPedido::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = InformacionPedido::staticMetaObject();
    static const QUMethod slot_0 = {"SlotRegistra", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotRegistra()", &slot_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QInformacionPedido", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QInformacionPedido.setMetaObject( metaObj );
    return metaObj;
}

void* QInformacionPedido::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QInformacionPedido" ) )
	return this;
    return InformacionPedido::qt_cast( clname );
}

bool QInformacionPedido::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotRegistra(); break;
    default:
	return InformacionPedido::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QInformacionPedido::qt_emit( int _id, QUObject* _o )
{
    return InformacionPedido::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QInformacionPedido::qt_property( int id, int f, QVariant* v)
{
    return InformacionPedido::qt_property( id, f, v);
}

bool QInformacionPedido::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
