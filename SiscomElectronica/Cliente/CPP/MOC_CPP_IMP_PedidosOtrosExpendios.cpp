/****************************************************************************
** QPedidosOtrosExpendios meta object code from reading C++ file 'IMP_PedidosOtrosExpendios.h'
**
** Created: Fri Apr 12 21:26:09 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_PedidosOtrosExpendios.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QPedidosOtrosExpendios::className() const
{
    return "QPedidosOtrosExpendios";
}

QMetaObject *QPedidosOtrosExpendios::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QPedidosOtrosExpendios( "QPedidosOtrosExpendios", &QPedidosOtrosExpendios::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QPedidosOtrosExpendios::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QPedidosOtrosExpendios", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QPedidosOtrosExpendios::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QPedidosOtrosExpendios", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QPedidosOtrosExpendios::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = PedidosOtrosExpendios::staticMetaObject();
    static const QUMethod slot_0 = {"SlotActualizar", 0, 0 };
    static const QUMethod slot_1 = {"SlotImprimir", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotActualizar()", &slot_0, QMetaData::Private },
	{ "SlotImprimir()", &slot_1, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QPedidosOtrosExpendios", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QPedidosOtrosExpendios.setMetaObject( metaObj );
    return metaObj;
}

void* QPedidosOtrosExpendios::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QPedidosOtrosExpendios" ) )
	return this;
    return PedidosOtrosExpendios::qt_cast( clname );
}

bool QPedidosOtrosExpendios::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotActualizar(); break;
    case 1: SlotImprimir(); break;
    default:
	return PedidosOtrosExpendios::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QPedidosOtrosExpendios::qt_emit( int _id, QUObject* _o )
{
    return PedidosOtrosExpendios::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QPedidosOtrosExpendios::qt_property( int id, int f, QVariant* v)
{
    return PedidosOtrosExpendios::qt_property( id, f, v);
}

bool QPedidosOtrosExpendios::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
