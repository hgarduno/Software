/****************************************************************************
** QPedidos meta object code from reading C++ file 'IMP_Pedidos.h'
**
** Created: Thu Apr 11 20:30:21 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_Pedidos.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QPedidos::className() const
{
    return "QPedidos";
}

QMetaObject *QPedidos::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QPedidos( "QPedidos", &QPedidos::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QPedidos::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QPedidos", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QPedidos::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QPedidos", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QPedidos::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = Pedidos::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "CQSisCliente", QUParameter::In },
	{ 0, &static_QUType_ptr, "CQSisFormaPago", QUParameter::In },
	{ 0, &static_QUType_ptr, "CQSisPrecio", QUParameter::In },
	{ 0, &static_QUType_ptr, "CQSisProducto", QUParameter::In },
	{ 0, &static_QUType_ptr, "CQSisProdCotiza", QUParameter::In },
	{ 0, &static_QUType_ptr, "CQSisContacto", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotCotizando", 6, param_slot_0 };
    static const QUMethod slot_1 = {"SlotAnexar", 0, 0 };
    static const QUMethod slot_2 = {"SlotRegistrar", 0, 0 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_ptr, "CQSisCliente", QUParameter::In }
    };
    static const QUMethod slot_3 = {"SlotClienteFisica", 1, param_slot_3 };
    static const QMetaData slot_tbl[] = {
	{ "SlotCotizando(CQSisCliente*,CQSisFormaPago*,CQSisPrecio*,CQSisProducto*,CQSisProdCotiza*,CQSisContacto*)", &slot_0, QMetaData::Private },
	{ "SlotAnexar()", &slot_1, QMetaData::Private },
	{ "SlotRegistrar()", &slot_2, QMetaData::Private },
	{ "SlotClienteFisica(CQSisCliente*)", &slot_3, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalTerminar", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalTerminar(QWidget*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QPedidos", parentObject,
	slot_tbl, 4,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QPedidos.setMetaObject( metaObj );
    return metaObj;
}

void* QPedidos::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QPedidos" ) )
	return this;
    return Pedidos::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalTerminar
void QPedidos::SignalTerminar( QWidget* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

bool QPedidos::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotCotizando((CQSisCliente*)static_QUType_ptr.get(_o+1),(CQSisFormaPago*)static_QUType_ptr.get(_o+2),(CQSisPrecio*)static_QUType_ptr.get(_o+3),(CQSisProducto*)static_QUType_ptr.get(_o+4),(CQSisProdCotiza*)static_QUType_ptr.get(_o+5),(CQSisContacto*)static_QUType_ptr.get(_o+6)); break;
    case 1: SlotAnexar(); break;
    case 2: SlotRegistrar(); break;
    case 3: SlotClienteFisica((CQSisCliente*)static_QUType_ptr.get(_o+1)); break;
    default:
	return Pedidos::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QPedidos::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalTerminar((QWidget*)static_QUType_ptr.get(_o+1)); break;
    default:
	return Pedidos::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QPedidos::qt_property( int id, int f, QVariant* v)
{
    return Pedidos::qt_property( id, f, v);
}

bool QPedidos::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
