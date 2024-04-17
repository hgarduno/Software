/****************************************************************************
** QRegistroRapidoAlumno meta object code from reading C++ file 'IMP_RegistroRapidoAlumno.h'
**
** Created: Fri Apr 12 21:26:09 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_RegistroRapidoAlumno.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QRegistroRapidoAlumno::className() const
{
    return "QRegistroRapidoAlumno";
}

QMetaObject *QRegistroRapidoAlumno::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QRegistroRapidoAlumno( "QRegistroRapidoAlumno", &QRegistroRapidoAlumno::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QRegistroRapidoAlumno::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRegistroRapidoAlumno", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QRegistroRapidoAlumno::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRegistroRapidoAlumno", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QRegistroRapidoAlumno::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = RegistroRapidoAlumno::staticMetaObject();
    static const QUMethod slot_0 = {"SlotPasaFocoAPaterno", 0, 0 };
    static const QUMethod slot_1 = {"SlotPasaFocoAMaterno", 0, 0 };
    static const QUMethod slot_2 = {"SlotPasaFocoRegGenerales", 0, 0 };
    static const QUMethod slot_3 = {"SlotPasaFocoEscuelas", 0, 0 };
    static const QUMethod slot_4 = {"SlotPasaFocoCorreo", 0, 0 };
    static const QUMethod slot_5 = {"SlotPasaFocoCelular", 0, 0 };
    static const QUMethod slot_6 = {"SlotPasaFocoTCasa", 0, 0 };
    static const QUParameter param_slot_7[] = {
	{ 0, &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod slot_7 = {"SlotEscuelas", 1, param_slot_7 };
    static const QUMethod slot_8 = {"SlotPasaFocoRegistraGenerales", 0, 0 };
    static const QUMethod slot_9 = {"SlotRegistra", 0, 0 };
    static const QUMethod slot_10 = {"SlotPasaFocoBoleta", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotPasaFocoAPaterno()", &slot_0, QMetaData::Private },
	{ "SlotPasaFocoAMaterno()", &slot_1, QMetaData::Private },
	{ "SlotPasaFocoRegGenerales()", &slot_2, QMetaData::Private },
	{ "SlotPasaFocoEscuelas()", &slot_3, QMetaData::Private },
	{ "SlotPasaFocoCorreo()", &slot_4, QMetaData::Private },
	{ "SlotPasaFocoCelular()", &slot_5, QMetaData::Private },
	{ "SlotPasaFocoTCasa()", &slot_6, QMetaData::Private },
	{ "SlotEscuelas(SiscomRegistro3*)", &slot_7, QMetaData::Private },
	{ "SlotPasaFocoRegistraGenerales()", &slot_8, QMetaData::Private },
	{ "SlotRegistra()", &slot_9, QMetaData::Private },
	{ "SlotPasaFocoBoleta()", &slot_10, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ "pQSBoltea", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalRegistroAlumno", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalRegistroAlumno(const QString&)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QRegistroRapidoAlumno", parentObject,
	slot_tbl, 11,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QRegistroRapidoAlumno.setMetaObject( metaObj );
    return metaObj;
}

void* QRegistroRapidoAlumno::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QRegistroRapidoAlumno" ) )
	return this;
    return RegistroRapidoAlumno::qt_cast( clname );
}

// SIGNAL SignalRegistroAlumno
void QRegistroRapidoAlumno::SignalRegistroAlumno( const QString& t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

bool QRegistroRapidoAlumno::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotPasaFocoAPaterno(); break;
    case 1: SlotPasaFocoAMaterno(); break;
    case 2: SlotPasaFocoRegGenerales(); break;
    case 3: SlotPasaFocoEscuelas(); break;
    case 4: SlotPasaFocoCorreo(); break;
    case 5: SlotPasaFocoCelular(); break;
    case 6: SlotPasaFocoTCasa(); break;
    case 7: SlotEscuelas((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    case 8: SlotPasaFocoRegistraGenerales(); break;
    case 9: SlotRegistra(); break;
    case 10: SlotPasaFocoBoleta(); break;
    default:
	return RegistroRapidoAlumno::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QRegistroRapidoAlumno::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalRegistroAlumno((const QString&)static_QUType_QString.get(_o+1)); break;
    default:
	return RegistroRapidoAlumno::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QRegistroRapidoAlumno::qt_property( int id, int f, QVariant* v)
{
    return RegistroRapidoAlumno::qt_property( id, f, v);
}

bool QRegistroRapidoAlumno::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
