/****************************************************************************
** QActualizaDatosAlumno meta object code from reading C++ file 'IMP_ActualizaDatosAlumno.h'
**
** Created: Wed Apr 10 20:52:39 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_ActualizaDatosAlumno.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QActualizaDatosAlumno::className() const
{
    return "QActualizaDatosAlumno";
}

QMetaObject *QActualizaDatosAlumno::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QActualizaDatosAlumno( "QActualizaDatosAlumno", &QActualizaDatosAlumno::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QActualizaDatosAlumno::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QActualizaDatosAlumno", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QActualizaDatosAlumno::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QActualizaDatosAlumno", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QActualizaDatosAlumno::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ActualizaDatosAlumno::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotAlumno", 1, param_slot_0 };
    static const QUMethod slot_1 = {"SlotActualiza", 0, 0 };
    static const QUMethod slot_2 = {"SlotCambiaEscuela", 0, 0 };
    static const QUMethod slot_3 = {"SlotSeleccionaAlumno", 0, 0 };
    static const QUMethod slot_4 = {"SlotPasaFocoAPaterno", 0, 0 };
    static const QUMethod slot_5 = {"SlotPasaFocoAMaterno", 0, 0 };
    static const QUMethod slot_6 = {"SlotPasaFocoBoleta", 0, 0 };
    static const QUMethod slot_7 = {"SlotPasaFocoCorreoE", 0, 0 };
    static const QUMethod slot_8 = {"SlotPasaFocoCelular", 0, 0 };
    static const QUMethod slot_9 = {"SlotPasaFocoTelefonoCasa", 0, 0 };
    static const QUMethod slot_10 = {"SlotPasaFocoActualizar", 0, 0 };
    static const QUMethod slot_11 = {"SlotPreguntaCambiaEscuela", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotAlumno(SiscomRegistro3*)", &slot_0, QMetaData::Private },
	{ "SlotActualiza()", &slot_1, QMetaData::Private },
	{ "SlotCambiaEscuela()", &slot_2, QMetaData::Private },
	{ "SlotSeleccionaAlumno()", &slot_3, QMetaData::Private },
	{ "SlotPasaFocoAPaterno()", &slot_4, QMetaData::Private },
	{ "SlotPasaFocoAMaterno()", &slot_5, QMetaData::Private },
	{ "SlotPasaFocoBoleta()", &slot_6, QMetaData::Private },
	{ "SlotPasaFocoCorreoE()", &slot_7, QMetaData::Private },
	{ "SlotPasaFocoCelular()", &slot_8, QMetaData::Private },
	{ "SlotPasaFocoTelefonoCasa()", &slot_9, QMetaData::Private },
	{ "SlotPasaFocoActualizar()", &slot_10, QMetaData::Private },
	{ "SlotPreguntaCambiaEscuela()", &slot_11, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalTerminar", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalTerminar(QWidget*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QActualizaDatosAlumno", parentObject,
	slot_tbl, 12,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QActualizaDatosAlumno.setMetaObject( metaObj );
    return metaObj;
}

void* QActualizaDatosAlumno::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QActualizaDatosAlumno" ) )
	return this;
    return ActualizaDatosAlumno::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalTerminar
void QActualizaDatosAlumno::SignalTerminar( QWidget* t0 )
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

bool QActualizaDatosAlumno::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotAlumno((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotActualiza(); break;
    case 2: SlotCambiaEscuela(); break;
    case 3: SlotSeleccionaAlumno(); break;
    case 4: SlotPasaFocoAPaterno(); break;
    case 5: SlotPasaFocoAMaterno(); break;
    case 6: SlotPasaFocoBoleta(); break;
    case 7: SlotPasaFocoCorreoE(); break;
    case 8: SlotPasaFocoCelular(); break;
    case 9: SlotPasaFocoTelefonoCasa(); break;
    case 10: SlotPasaFocoActualizar(); break;
    case 11: SlotPreguntaCambiaEscuela(); break;
    default:
	return ActualizaDatosAlumno::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QActualizaDatosAlumno::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalTerminar((QWidget*)static_QUType_ptr.get(_o+1)); break;
    default:
	return ActualizaDatosAlumno::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QActualizaDatosAlumno::qt_property( int id, int f, QVariant* v)
{
    return ActualizaDatosAlumno::qt_property( id, f, v);
}

bool QActualizaDatosAlumno::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
