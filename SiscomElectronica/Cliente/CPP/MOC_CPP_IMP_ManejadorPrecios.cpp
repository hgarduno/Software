/****************************************************************************
** QManejadorPrecios meta object code from reading C++ file 'IMP_ManejadorPrecios.h'
**
** Created: Fri Apr 12 21:35:46 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_ManejadorPrecios.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QManejadorPrecios::className() const
{
    return "QManejadorPrecios";
}

QMetaObject *QManejadorPrecios::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QManejadorPrecios( "QManejadorPrecios", &QManejadorPrecios::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QManejadorPrecios::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QManejadorPrecios", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QManejadorPrecios::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QManejadorPrecios", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QManejadorPrecios::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ManejadorPrecios::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "TipoPrecio", QUParameter::In }
    };
    static const QUMethod slot_0 = {"S_TipoPrecio", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_ptr, "ProductoE", QUParameter::In }
    };
    static const QUMethod slot_1 = {"S_Producto", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_charstar, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"S_NoEstaLaClave", 1, param_slot_2 };
    static const QUMethod slot_3 = {"S_RegistrarPrecio", 0, 0 };
    static const QUMethod slot_4 = {"S_PasaFocoRegistrarPrecio", 0, 0 };
    static const QUParameter param_slot_5[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"S_HabilitandoRegistro", 1, param_slot_5 };
    static const QMetaData slot_tbl[] = {
	{ "S_TipoPrecio(TipoPrecio*)", &slot_0, QMetaData::Private },
	{ "S_Producto(ProductoE*)", &slot_1, QMetaData::Private },
	{ "S_NoEstaLaClave(const char*)", &slot_2, QMetaData::Private },
	{ "S_RegistrarPrecio()", &slot_3, QMetaData::Private },
	{ "S_PasaFocoRegistrarPrecio()", &slot_4, QMetaData::Private },
	{ "S_HabilitandoRegistro(const QString&)", &slot_5, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalTerminar", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalTerminar(QWidget*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QManejadorPrecios", parentObject,
	slot_tbl, 6,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QManejadorPrecios.setMetaObject( metaObj );
    return metaObj;
}

void* QManejadorPrecios::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QManejadorPrecios" ) )
	return this;
    return ManejadorPrecios::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalTerminar
void QManejadorPrecios::SignalTerminar( QWidget* t0 )
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

bool QManejadorPrecios::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: S_TipoPrecio((TipoPrecio*)static_QUType_ptr.get(_o+1)); break;
    case 1: S_Producto((ProductoE*)static_QUType_ptr.get(_o+1)); break;
    case 2: S_NoEstaLaClave((const char*)static_QUType_charstar.get(_o+1)); break;
    case 3: S_RegistrarPrecio(); break;
    case 4: S_PasaFocoRegistrarPrecio(); break;
    case 5: S_HabilitandoRegistro((const QString&)static_QUType_QString.get(_o+1)); break;
    default:
	return ManejadorPrecios::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QManejadorPrecios::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalTerminar((QWidget*)static_QUType_ptr.get(_o+1)); break;
    default:
	return ManejadorPrecios::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QManejadorPrecios::qt_property( int id, int f, QVariant* v)
{
    return ManejadorPrecios::qt_property( id, f, v);
}

bool QManejadorPrecios::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
