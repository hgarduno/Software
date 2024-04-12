/****************************************************************************
** MenuOrdenElectronica meta object code from reading C++ file 'MenuOrdenElectronica.h'
**
** Created: Thu Apr 11 21:51:32 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/MenuOrdenElectronica.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *MenuOrdenElectronica::className() const
{
    return "MenuOrdenElectronica";
}

QMetaObject *MenuOrdenElectronica::metaObj = 0;
static QMetaObjectCleanUp cleanUp_MenuOrdenElectronica( "MenuOrdenElectronica", &MenuOrdenElectronica::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString MenuOrdenElectronica::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "MenuOrdenElectronica", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString MenuOrdenElectronica::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "MenuOrdenElectronica", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* MenuOrdenElectronica::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QPopupMenu::staticMetaObject();
    static const QUMethod slot_0 = {"S_JuegosSeparados", 0, 0 };
    static const QUMethod slot_1 = {"S_Juegos", 0, 0 };
    static const QUMethod slot_2 = {"S_EliminaProductos", 0, 0 };
    static const QUMethod slot_3 = {"S_PorcentajeDescuento", 0, 0 };
    static const QUMethod slot_4 = {"S_PorcentajeDescuentoOrden", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "S_JuegosSeparados()", &slot_0, QMetaData::Private },
	{ "S_Juegos()", &slot_1, QMetaData::Private },
	{ "S_EliminaProductos()", &slot_2, QMetaData::Private },
	{ "S_PorcentajeDescuento()", &slot_3, QMetaData::Private },
	{ "S_PorcentajeDescuentoOrden()", &slot_4, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalCambioNumJuegos", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_1 = {"SignalJuegosSeparados", 1, param_signal_1 };
    static const QUMethod signal_2 = {"SignalEliminaProductos", 0, 0 };
    static const QUMethod signal_3 = {"SignalPorcentajeDescuento", 0, 0 };
    static const QUParameter param_signal_4[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_4 = {"SignalPorcentajeDescuentoOrden", 1, param_signal_4 };
    static const QMetaData signal_tbl[] = {
	{ "SignalCambioNumJuegos(int)", &signal_0, QMetaData::Private },
	{ "SignalJuegosSeparados(int)", &signal_1, QMetaData::Private },
	{ "SignalEliminaProductos()", &signal_2, QMetaData::Private },
	{ "SignalPorcentajeDescuento()", &signal_3, QMetaData::Private },
	{ "SignalPorcentajeDescuentoOrden(int)", &signal_4, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"MenuOrdenElectronica", parentObject,
	slot_tbl, 5,
	signal_tbl, 5,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_MenuOrdenElectronica.setMetaObject( metaObj );
    return metaObj;
}

void* MenuOrdenElectronica::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "MenuOrdenElectronica" ) )
	return this;
    return QPopupMenu::qt_cast( clname );
}

// SIGNAL SignalCambioNumJuegos
void MenuOrdenElectronica::SignalCambioNumJuegos( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

// SIGNAL SignalJuegosSeparados
void MenuOrdenElectronica::SignalJuegosSeparados( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 1, t0 );
}

// SIGNAL SignalEliminaProductos
void MenuOrdenElectronica::SignalEliminaProductos()
{
    activate_signal( staticMetaObject()->signalOffset() + 2 );
}

// SIGNAL SignalPorcentajeDescuento
void MenuOrdenElectronica::SignalPorcentajeDescuento()
{
    activate_signal( staticMetaObject()->signalOffset() + 3 );
}

// SIGNAL SignalPorcentajeDescuentoOrden
void MenuOrdenElectronica::SignalPorcentajeDescuentoOrden( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 4, t0 );
}

bool MenuOrdenElectronica::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: S_JuegosSeparados(); break;
    case 1: S_Juegos(); break;
    case 2: S_EliminaProductos(); break;
    case 3: S_PorcentajeDescuento(); break;
    case 4: S_PorcentajeDescuentoOrden(); break;
    default:
	return QPopupMenu::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool MenuOrdenElectronica::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalCambioNumJuegos((int)static_QUType_int.get(_o+1)); break;
    case 1: SignalJuegosSeparados((int)static_QUType_int.get(_o+1)); break;
    case 2: SignalEliminaProductos(); break;
    case 3: SignalPorcentajeDescuento(); break;
    case 4: SignalPorcentajeDescuentoOrden((int)static_QUType_int.get(_o+1)); break;
    default:
	return QPopupMenu::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool MenuOrdenElectronica::qt_property( int id, int f, QVariant* v)
{
    return QPopupMenu::qt_property( id, f, v);
}

bool MenuOrdenElectronica::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
