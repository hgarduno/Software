/****************************************************************************
** CQSisAplicaciones meta object code from reading C++ file 'IMP_Aplicaciones.h'
**
** Created: Thu Apr 11 21:36:10 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_Aplicaciones.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *CQSisAplicaciones::className() const
{
    return "CQSisAplicaciones";
}

QMetaObject *CQSisAplicaciones::metaObj = 0;
static QMetaObjectCleanUp cleanUp_CQSisAplicaciones( "CQSisAplicaciones", &CQSisAplicaciones::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString CQSisAplicaciones::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CQSisAplicaciones", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString CQSisAplicaciones::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CQSisAplicaciones", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* CQSisAplicaciones::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = Aplicaciones::staticMetaObject();
    static const QUMethod slot_0 = {"SlotVerificaIdentificador", 0, 0 };
    static const QUMethod slot_1 = {"SlotSeleccionaDirectorio", 0, 0 };
    static const QUMethod slot_2 = {"SlotRegistraAplicacion", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotVerificaIdentificador()", &slot_0, QMetaData::Private },
	{ "SlotSeleccionaDirectorio()", &slot_1, QMetaData::Private },
	{ "SlotRegistraAplicacion()", &slot_2, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalEstanRegLasPantallas", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_ptr, "QSiscomListaPantallasBD", QUParameter::In }
    };
    static const QUMethod signal_1 = {"SignalLasPantallas", 1, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ 0, &static_QUType_ptr, "QSiscomListaContXForma", QUParameter::In }
    };
    static const QUMethod signal_2 = {"SignalPantallasYControles", 1, param_signal_2 };
    static const QUParameter param_signal_3[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_ptr, "QSiscomListaPantallasBD", QUParameter::In },
	{ 0, &static_QUType_ptr, "CQPerfiles", QUParameter::In }
    };
    static const QUMethod signal_3 = {"SignalConsultaAplicacion", 3, param_signal_3 };
    static const QMetaData signal_tbl[] = {
	{ "SignalEstanRegLasPantallas(int)", &signal_0, QMetaData::Private },
	{ "SignalLasPantallas(const QSiscomListaPantallasBD&)", &signal_1, QMetaData::Private },
	{ "SignalPantallasYControles(const QSiscomListaContXForma&)", &signal_2, QMetaData::Private },
	{ "SignalConsultaAplicacion(int,const QSiscomListaPantallasBD&,CQPerfiles*)", &signal_3, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"CQSisAplicaciones", parentObject,
	slot_tbl, 3,
	signal_tbl, 4,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_CQSisAplicaciones.setMetaObject( metaObj );
    return metaObj;
}

void* CQSisAplicaciones::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "CQSisAplicaciones" ) )
	return this;
    if ( !qstrcmp( clname, "QSiscomSeguridad3" ) )
	return (QSiscomSeguridad3*)this;
    return Aplicaciones::qt_cast( clname );
}

// SIGNAL SignalEstanRegLasPantallas
void CQSisAplicaciones::SignalEstanRegLasPantallas( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalLasPantallas
void CQSisAplicaciones::SignalLasPantallas( const QSiscomListaPantallasBD& t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 1 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL SignalPantallasYControles
void CQSisAplicaciones::SignalPantallasYControles( const QSiscomListaContXForma& t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 2 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL SignalConsultaAplicacion
void CQSisAplicaciones::SignalConsultaAplicacion( int t0, const QSiscomListaPantallasBD& t1, CQPerfiles* t2 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 3 );
    if ( !clist )
	return;
    QUObject o[4];
    static_QUType_int.set(o+1,t0);
    static_QUType_ptr.set(o+2,&t1);
    static_QUType_ptr.set(o+3,t2);
    activate_signal( clist, o );
}

bool CQSisAplicaciones::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotVerificaIdentificador(); break;
    case 1: SlotSeleccionaDirectorio(); break;
    case 2: SlotRegistraAplicacion(); break;
    default:
	return Aplicaciones::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool CQSisAplicaciones::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalEstanRegLasPantallas((int)static_QUType_int.get(_o+1)); break;
    case 1: SignalLasPantallas((const QSiscomListaPantallasBD&)*((const QSiscomListaPantallasBD*)static_QUType_ptr.get(_o+1))); break;
    case 2: SignalPantallasYControles((const QSiscomListaContXForma&)*((const QSiscomListaContXForma*)static_QUType_ptr.get(_o+1))); break;
    case 3: SignalConsultaAplicacion((int)static_QUType_int.get(_o+1),(const QSiscomListaPantallasBD&)*((const QSiscomListaPantallasBD*)static_QUType_ptr.get(_o+2)),(CQPerfiles*)static_QUType_ptr.get(_o+3)); break;
    default:
	return Aplicaciones::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool CQSisAplicaciones::qt_property( int id, int f, QVariant* v)
{
    return Aplicaciones::qt_property( id, f, v);
}

bool CQSisAplicaciones::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
