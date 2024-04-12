/****************************************************************************
** QPrecioProducto meta object code from reading C++ file 'IMP_PrecioProducto.h'
**
** Created: Thu Apr 11 22:09:38 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_PrecioProducto.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QPrecioProducto::className() const
{
    return "QPrecioProducto";
}

QMetaObject *QPrecioProducto::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QPrecioProducto( "QPrecioProducto", &QPrecioProducto::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QPrecioProducto::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QPrecioProducto", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QPrecioProducto::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QPrecioProducto", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QPrecioProducto::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = PrecioProducto::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "CQSisPrecio", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotPrecio", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_ptr, "CQSisProducto", QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotProducto", 1, param_slot_1 };
    static const QUMethod slot_2 = {"SlotIniciaPrecios", 0, 0 };
    static const QUMethod slot_3 = {"SlotPasaFocoActualiza", 0, 0 };
    static const QUMethod slot_4 = {"SlotActualiza", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotPrecio(CQSisPrecio*)", &slot_0, QMetaData::Private },
	{ "SlotProducto(CQSisProducto*)", &slot_1, QMetaData::Private },
	{ "SlotIniciaPrecios()", &slot_2, QMetaData::Private },
	{ "SlotPasaFocoActualiza()", &slot_3, QMetaData::Private },
	{ "SlotActualiza()", &slot_4, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalTerminar", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalTerminar(QWidget*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QPrecioProducto", parentObject,
	slot_tbl, 5,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QPrecioProducto.setMetaObject( metaObj );
    return metaObj;
}

void* QPrecioProducto::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QPrecioProducto" ) )
	return this;
    return PrecioProducto::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalTerminar
void QPrecioProducto::SignalTerminar( QWidget* t0 )
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

bool QPrecioProducto::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotPrecio((CQSisPrecio*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotProducto((CQSisProducto*)static_QUType_ptr.get(_o+1)); break;
    case 2: SlotIniciaPrecios(); break;
    case 3: SlotPasaFocoActualiza(); break;
    case 4: SlotActualiza(); break;
    default:
	return PrecioProducto::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QPrecioProducto::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalTerminar((QWidget*)static_QUType_ptr.get(_o+1)); break;
    default:
	return PrecioProducto::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QPrecioProducto::qt_property( int id, int f, QVariant* v)
{
    return PrecioProducto::qt_property( id, f, v);
}

bool QPrecioProducto::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
