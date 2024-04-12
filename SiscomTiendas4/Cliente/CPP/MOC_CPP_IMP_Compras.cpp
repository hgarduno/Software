/****************************************************************************
** QCompras meta object code from reading C++ file 'IMP_Compras.h'
**
** Created: Thu Apr 11 22:09:38 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_Compras.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCompras::className() const
{
    return "QCompras";
}

QMetaObject *QCompras::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCompras( "QCompras", &QCompras::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCompras::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCompras", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCompras::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCompras", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCompras::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = Compras::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "CQSisProducto", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotProducto", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_ptr, "CQSisEmpresa", QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotEmpresa", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_ptr, "CQSisContacto", QUParameter::In }
    };
    static const QUMethod slot_2 = {"SlotContacto", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_ptr, "CQSisFormaPago", QUParameter::In }
    };
    static const QUMethod slot_3 = {"SlotFormaPago", 1, param_slot_3 };
    static const QUMethod slot_4 = {"SlotPasaFocoAnexarCompra", 0, 0 };
    static const QUMethod slot_5 = {"SlotPasaFocoPrecioCompra", 0, 0 };
    static const QUMethod slot_6 = {"SlotPasaFocoNFactura", 0, 0 };
    static const QUMethod slot_7 = {"SlotAnexar", 0, 0 };
    static const QUMethod slot_8 = {"SlotRegistra", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotProducto(CQSisProducto*)", &slot_0, QMetaData::Private },
	{ "SlotEmpresa(CQSisEmpresa*)", &slot_1, QMetaData::Private },
	{ "SlotContacto(CQSisContacto*)", &slot_2, QMetaData::Private },
	{ "SlotFormaPago(CQSisFormaPago*)", &slot_3, QMetaData::Private },
	{ "SlotPasaFocoAnexarCompra()", &slot_4, QMetaData::Private },
	{ "SlotPasaFocoPrecioCompra()", &slot_5, QMetaData::Private },
	{ "SlotPasaFocoNFactura()", &slot_6, QMetaData::Private },
	{ "SlotAnexar()", &slot_7, QMetaData::Private },
	{ "SlotRegistra()", &slot_8, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalTerminar", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalTerminar(QWidget*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCompras", parentObject,
	slot_tbl, 9,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCompras.setMetaObject( metaObj );
    return metaObj;
}

void* QCompras::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCompras" ) )
	return this;
    return Compras::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalTerminar
void QCompras::SignalTerminar( QWidget* t0 )
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

bool QCompras::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotProducto((CQSisProducto*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotEmpresa((CQSisEmpresa*)static_QUType_ptr.get(_o+1)); break;
    case 2: SlotContacto((CQSisContacto*)static_QUType_ptr.get(_o+1)); break;
    case 3: SlotFormaPago((CQSisFormaPago*)static_QUType_ptr.get(_o+1)); break;
    case 4: SlotPasaFocoAnexarCompra(); break;
    case 5: SlotPasaFocoPrecioCompra(); break;
    case 6: SlotPasaFocoNFactura(); break;
    case 7: SlotAnexar(); break;
    case 8: SlotRegistra(); break;
    default:
	return Compras::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCompras::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalTerminar((QWidget*)static_QUType_ptr.get(_o+1)); break;
    default:
	return Compras::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QCompras::qt_property( int id, int f, QVariant* v)
{
    return Compras::qt_property( id, f, v);
}

bool QCompras::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
