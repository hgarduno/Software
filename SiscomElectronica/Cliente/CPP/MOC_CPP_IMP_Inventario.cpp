/****************************************************************************
** QInventario meta object code from reading C++ file 'IMP_Inventario.h'
**
** Created: Fri Apr 12 21:35:11 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_Inventario.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QInventario::className() const
{
    return "QInventario";
}

QMetaObject *QInventario::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QInventario( "QInventario", &QInventario::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QInventario::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QInventario", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QInventario::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QInventario", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QInventario::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = Inventario::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "ProductoE", QUParameter::In }
    };
    static const QUMethod slot_0 = {"S_SelProducto", 1, param_slot_0 };
    static const QUMethod slot_1 = {"S_PasaFocoRegistrar", 0, 0 };
    static const QUMethod slot_2 = {"S_Registrar", 0, 0 };
    static const QUMethod slot_3 = {"S_Actualiza", 0, 0 };
    static const QUParameter param_slot_4[] = {
	{ 0, &static_QUType_charstar, 0, QUParameter::In }
    };
    static const QUMethod slot_4 = {"S_NoEstaClave", 1, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ 0, &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod slot_5 = {"SlotPasaFocoProductos", 1, param_slot_5 };
    static const QUMethod slot_6 = {"SlotActivaMotivoInventario", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "S_SelProducto(ProductoE*)", &slot_0, QMetaData::Private },
	{ "S_PasaFocoRegistrar()", &slot_1, QMetaData::Private },
	{ "S_Registrar()", &slot_2, QMetaData::Private },
	{ "S_Actualiza()", &slot_3, QMetaData::Private },
	{ "S_NoEstaClave(const char*)", &slot_4, QMetaData::Private },
	{ "SlotPasaFocoProductos(SiscomRegistro3*)", &slot_5, QMetaData::Private },
	{ "SlotActivaMotivoInventario()", &slot_6, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalTerminar", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalTerminar(QWidget*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QInventario", parentObject,
	slot_tbl, 7,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QInventario.setMetaObject( metaObj );
    return metaObj;
}

void* QInventario::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QInventario" ) )
	return this;
    return Inventario::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalTerminar
void QInventario::SignalTerminar( QWidget* t0 )
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

bool QInventario::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: S_SelProducto((ProductoE*)static_QUType_ptr.get(_o+1)); break;
    case 1: S_PasaFocoRegistrar(); break;
    case 2: S_Registrar(); break;
    case 3: S_Actualiza(); break;
    case 4: S_NoEstaClave((const char*)static_QUType_charstar.get(_o+1)); break;
    case 5: SlotPasaFocoProductos((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    case 6: SlotActivaMotivoInventario(); break;
    default:
	return Inventario::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QInventario::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalTerminar((QWidget*)static_QUType_ptr.get(_o+1)); break;
    default:
	return Inventario::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QInventario::qt_property( int id, int f, QVariant* v)
{
    return Inventario::qt_property( id, f, v);
}

bool QInventario::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
