/****************************************************************************
** QRegistroApartado meta object code from reading C++ file 'IMP_RegistroApartado.h'
**
** Created: Fri Apr 12 21:26:09 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_RegistroApartado.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QRegistroApartado::className() const
{
    return "QRegistroApartado";
}

QMetaObject *QRegistroApartado::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QRegistroApartado( "QRegistroApartado", &QRegistroApartado::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QRegistroApartado::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRegistroApartado", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QRegistroApartado::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRegistroApartado", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QRegistroApartado::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = RegistroApartado::staticMetaObject();
    static const QUMethod slot_0 = {"SlotAceptar", 0, 0 };
    static const QUMethod slot_1 = {"SlotFocoAAPaterno", 0, 0 };
    static const QUMethod slot_2 = {"SlotFocoAAMaterno", 0, 0 };
    static const QUMethod slot_3 = {"SlotFocoARegistraPersonales", 0, 0 };
    static const QUMethod slot_4 = {"SlotFocoACelular", 0, 0 };
    static const QUMethod slot_5 = {"SlotFocoAReCelular", 0, 0 };
    static const QUMethod slot_6 = {"SlotFocoARegistraCelular", 0, 0 };
    static const QUMethod slot_7 = {"SlotFocoACorreo", 0, 0 };
    static const QUMethod slot_8 = {"SlotFocoAReCorreo", 0, 0 };
    static const QUMethod slot_9 = {"SlotFocoARegistraCorreo", 0, 0 };
    static const QUMethod slot_10 = {"SlotFocoACuenta", 0, 0 };
    static const QUMethod slot_11 = {"SlotFocoAFechaEntrega", 0, 0 };
    static const QUMethod slot_12 = {"SlotFocoAObservaciones", 0, 0 };
    static const QUMethod slot_13 = {"SlotRegistraPersonales", 0, 0 };
    static const QUMethod slot_14 = {"SlotRegistraCelular", 0, 0 };
    static const QUMethod slot_15 = {"SlotRegistraCorreo", 0, 0 };
    static const QUParameter param_slot_16[] = {
	{ "pQStrCelular", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_16 = {"SlotCapturandoCelular", 1, param_slot_16 };
    static const QUParameter param_slot_17[] = {
	{ "pQStrCorreo", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_17 = {"SlotCapturandoCorreo", 1, param_slot_17 };
    static const QUParameter param_slot_18[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_18 = {"SlotCapturandoACuenta", 1, param_slot_18 };
    static const QUMethod slot_19 = {"SlotCancelar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotAceptar()", &slot_0, QMetaData::Private },
	{ "SlotFocoAAPaterno()", &slot_1, QMetaData::Private },
	{ "SlotFocoAAMaterno()", &slot_2, QMetaData::Private },
	{ "SlotFocoARegistraPersonales()", &slot_3, QMetaData::Private },
	{ "SlotFocoACelular()", &slot_4, QMetaData::Private },
	{ "SlotFocoAReCelular()", &slot_5, QMetaData::Private },
	{ "SlotFocoARegistraCelular()", &slot_6, QMetaData::Private },
	{ "SlotFocoACorreo()", &slot_7, QMetaData::Private },
	{ "SlotFocoAReCorreo()", &slot_8, QMetaData::Private },
	{ "SlotFocoARegistraCorreo()", &slot_9, QMetaData::Private },
	{ "SlotFocoACuenta()", &slot_10, QMetaData::Private },
	{ "SlotFocoAFechaEntrega()", &slot_11, QMetaData::Private },
	{ "SlotFocoAObservaciones()", &slot_12, QMetaData::Private },
	{ "SlotRegistraPersonales()", &slot_13, QMetaData::Private },
	{ "SlotRegistraCelular()", &slot_14, QMetaData::Private },
	{ "SlotRegistraCorreo()", &slot_15, QMetaData::Private },
	{ "SlotCapturandoCelular(const QString&)", &slot_16, QMetaData::Private },
	{ "SlotCapturandoCorreo(const QString&)", &slot_17, QMetaData::Private },
	{ "SlotCapturandoACuenta(const QString&)", &slot_18, QMetaData::Private },
	{ "SlotCancelar()", &slot_19, QMetaData::Private }
    };
    static const QUMethod signal_0 = {"SignalAceptar", 0, 0 };
    static const QUMethod signal_1 = {"SignalCancelar", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalAceptar()", &signal_0, QMetaData::Private },
	{ "SignalCancelar()", &signal_1, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QRegistroApartado", parentObject,
	slot_tbl, 20,
	signal_tbl, 2,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QRegistroApartado.setMetaObject( metaObj );
    return metaObj;
}

void* QRegistroApartado::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QRegistroApartado" ) )
	return this;
    return RegistroApartado::qt_cast( clname );
}

// SIGNAL SignalAceptar
void QRegistroApartado::SignalAceptar()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

// SIGNAL SignalCancelar
void QRegistroApartado::SignalCancelar()
{
    activate_signal( staticMetaObject()->signalOffset() + 1 );
}

bool QRegistroApartado::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotAceptar(); break;
    case 1: SlotFocoAAPaterno(); break;
    case 2: SlotFocoAAMaterno(); break;
    case 3: SlotFocoARegistraPersonales(); break;
    case 4: SlotFocoACelular(); break;
    case 5: SlotFocoAReCelular(); break;
    case 6: SlotFocoARegistraCelular(); break;
    case 7: SlotFocoACorreo(); break;
    case 8: SlotFocoAReCorreo(); break;
    case 9: SlotFocoARegistraCorreo(); break;
    case 10: SlotFocoACuenta(); break;
    case 11: SlotFocoAFechaEntrega(); break;
    case 12: SlotFocoAObservaciones(); break;
    case 13: SlotRegistraPersonales(); break;
    case 14: SlotRegistraCelular(); break;
    case 15: SlotRegistraCorreo(); break;
    case 16: SlotCapturandoCelular((const QString&)static_QUType_QString.get(_o+1)); break;
    case 17: SlotCapturandoCorreo((const QString&)static_QUType_QString.get(_o+1)); break;
    case 18: SlotCapturandoACuenta((const QString&)static_QUType_QString.get(_o+1)); break;
    case 19: SlotCancelar(); break;
    default:
	return RegistroApartado::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QRegistroApartado::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalAceptar(); break;
    case 1: SignalCancelar(); break;
    default:
	return RegistroApartado::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QRegistroApartado::qt_property( int id, int f, QVariant* v)
{
    return RegistroApartado::qt_property( id, f, v);
}

bool QRegistroApartado::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
