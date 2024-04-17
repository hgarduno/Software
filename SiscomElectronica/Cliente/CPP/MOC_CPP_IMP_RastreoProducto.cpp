/****************************************************************************
** QRastreoProducto meta object code from reading C++ file 'IMP_RastreoProducto.h'
**
** Created: Fri Apr 12 21:26:09 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_RastreoProducto.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QRastreoProducto::className() const
{
    return "QRastreoProducto";
}

QMetaObject *QRastreoProducto::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QRastreoProducto( "QRastreoProducto", &QRastreoProducto::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QRastreoProducto::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRastreoProducto", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QRastreoProducto::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRastreoProducto", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QRastreoProducto::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = RastreoProducto::staticMetaObject();
    static const QUMethod slot_0 = {"SlotPasaFocoProductos", 0, 0 };
    static const QUMethod slot_1 = {"SlotPasaFocoFechaFin", 0, 0 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod slot_2 = {"SlotProducto", 1, param_slot_2 };
    static const QUMethod slot_3 = {"SlotProductosConDesajuste", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotPasaFocoProductos()", &slot_0, QMetaData::Private },
	{ "SlotPasaFocoFechaFin()", &slot_1, QMetaData::Private },
	{ "SlotProducto(SiscomRegistro3*)", &slot_2, QMetaData::Private },
	{ "SlotProductosConDesajuste()", &slot_3, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalTerminar", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalTerminar(QWidget*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QRastreoProducto", parentObject,
	slot_tbl, 4,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QRastreoProducto.setMetaObject( metaObj );
    return metaObj;
}

void* QRastreoProducto::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QRastreoProducto" ) )
	return this;
    return RastreoProducto::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalTerminar
void QRastreoProducto::SignalTerminar( QWidget* t0 )
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

bool QRastreoProducto::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotPasaFocoProductos(); break;
    case 1: SlotPasaFocoFechaFin(); break;
    case 2: SlotProducto((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    case 3: SlotProductosConDesajuste(); break;
    default:
	return RastreoProducto::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QRastreoProducto::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalTerminar((QWidget*)static_QUType_ptr.get(_o+1)); break;
    default:
	return RastreoProducto::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QRastreoProducto::qt_property( int id, int f, QVariant* v)
{
    return RastreoProducto::qt_property( id, f, v);
}

bool QRastreoProducto::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
