/****************************************************************************
** QPaquetes meta object code from reading C++ file 'IMP_Paquetes.h'
**
** Created: Thu Apr 11 20:30:21 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_Paquetes.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QPaquetes::className() const
{
    return "QPaquetes";
}

QMetaObject *QPaquetes::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QPaquetes( "QPaquetes", &QPaquetes::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QPaquetes::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QPaquetes", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QPaquetes::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QPaquetes", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QPaquetes::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = Paquetes::staticMetaObject();
    static const QUMethod slot_0 = {"SlotPasaFocoDescripcion", 0, 0 };
    static const QUMethod slot_1 = {"SlotRegistraPaquete", 0, 0 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod slot_2 = {"SlotSeleccionandoProducto", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod slot_3 = {"SlotProducto", 1, param_slot_3 };
    static const QUMethod slot_4 = {"SlotPasaFocoAnexarProducto", 0, 0 };
    static const QUMethod slot_5 = {"SlotAnexarProducto", 0, 0 };
    static const QUMethod slot_6 = {"SlotRegistraProductos", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotPasaFocoDescripcion()", &slot_0, QMetaData::Private },
	{ "SlotRegistraPaquete()", &slot_1, QMetaData::Private },
	{ "SlotSeleccionandoProducto(SiscomRegistro3*)", &slot_2, QMetaData::Private },
	{ "SlotProducto(SiscomRegistro3*)", &slot_3, QMetaData::Private },
	{ "SlotPasaFocoAnexarProducto()", &slot_4, QMetaData::Private },
	{ "SlotAnexarProducto()", &slot_5, QMetaData::Private },
	{ "SlotRegistraProductos()", &slot_6, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalTerminar", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalTerminar(QWidget*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QPaquetes", parentObject,
	slot_tbl, 7,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QPaquetes.setMetaObject( metaObj );
    return metaObj;
}

void* QPaquetes::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QPaquetes" ) )
	return this;
    return Paquetes::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalTerminar
void QPaquetes::SignalTerminar( QWidget* t0 )
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

bool QPaquetes::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotPasaFocoDescripcion(); break;
    case 1: SlotRegistraPaquete(); break;
    case 2: SlotSeleccionandoProducto((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    case 3: SlotProducto((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    case 4: SlotPasaFocoAnexarProducto(); break;
    case 5: SlotAnexarProducto(); break;
    case 6: SlotRegistraProductos(); break;
    default:
	return Paquetes::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QPaquetes::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalTerminar((QWidget*)static_QUType_ptr.get(_o+1)); break;
    default:
	return Paquetes::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QPaquetes::qt_property( int id, int f, QVariant* v)
{
    return Paquetes::qt_property( id, f, v);
}

bool QPaquetes::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
