/****************************************************************************
** QClientePedido meta object code from reading C++ file 'IMP_ClientePedido.h'
**
** Created: Thu Apr 11 21:40:01 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_ClientePedido.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QClientePedido::className() const
{
    return "QClientePedido";
}

QMetaObject *QClientePedido::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QClientePedido( "QClientePedido", &QClientePedido::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QClientePedido::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QClientePedido", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QClientePedido::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QClientePedido", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QClientePedido::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QtClientePedido::staticMetaObject();
    static const QUMethod slot_0 = {"SlotRegistraPersonales", 0, 0 };
    static const QUMethod slot_1 = {"SlotRegistraCelular", 0, 0 };
    static const QUMethod slot_2 = {"SlotAceptar", 0, 0 };
    static const QUMethod slot_3 = {"SlotCoberturaJTExpress", 0, 0 };
    static const QUMethod slot_4 = {"SlotRegistraDireccion", 0, 0 };
    static const QUParameter param_slot_5[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_5 = {"SlotDireccionEnvio", 4, param_slot_5 };
    static const QMetaData slot_tbl[] = {
	{ "SlotRegistraPersonales()", &slot_0, QMetaData::Private },
	{ "SlotRegistraCelular()", &slot_1, QMetaData::Private },
	{ "SlotAceptar()", &slot_2, QMetaData::Private },
	{ "SlotCoberturaJTExpress()", &slot_3, QMetaData::Private },
	{ "SlotRegistraDireccion()", &slot_4, QMetaData::Private },
	{ "SlotDireccionEnvio(int,int,int,const QPoint&)", &slot_5, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QClientePedido", parentObject,
	slot_tbl, 6,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QClientePedido.setMetaObject( metaObj );
    return metaObj;
}

void* QClientePedido::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QClientePedido" ) )
	return this;
    return QtClientePedido::qt_cast( clname );
}

bool QClientePedido::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotRegistraPersonales(); break;
    case 1: SlotRegistraCelular(); break;
    case 2: SlotAceptar(); break;
    case 3: SlotCoberturaJTExpress(); break;
    case 4: SlotRegistraDireccion(); break;
    case 5: SlotDireccionEnvio((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    default:
	return QtClientePedido::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QClientePedido::qt_emit( int _id, QUObject* _o )
{
    return QtClientePedido::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QClientePedido::qt_property( int id, int f, QVariant* v)
{
    return QtClientePedido::qt_property( id, f, v);
}

bool QClientePedido::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
