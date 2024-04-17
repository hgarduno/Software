/****************************************************************************
** QRegistroEmpleado meta object code from reading C++ file 'IMP_RegistroEmpleado.h'
**
** Created: Fri Apr 12 21:36:43 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_RegistroEmpleado.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QRegistroEmpleado::className() const
{
    return "QRegistroEmpleado";
}

QMetaObject *QRegistroEmpleado::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QRegistroEmpleado( "QRegistroEmpleado", &QRegistroEmpleado::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QRegistroEmpleado::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRegistroEmpleado", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QRegistroEmpleado::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRegistroEmpleado", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QRegistroEmpleado::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = RegistroEmpleado::staticMetaObject();
    static const QUMethod slot_0 = {"SlotPasaFocoAPaterno", 0, 0 };
    static const QUMethod slot_1 = {"SlotPasaFocoAMaterno", 0, 0 };
    static const QUMethod slot_2 = {"SlotPasaFocoFirma", 0, 0 };
    static const QUMethod slot_3 = {"SlotPasaFocoPassword", 0, 0 };
    static const QUMethod slot_4 = {"SlotPasaFocoRePassword", 0, 0 };
    static const QUMethod slot_5 = {"SlotPasaFocoRegistra", 0, 0 };
    static const QUMethod slot_6 = {"SlotRegistra", 0, 0 };
    static const QUParameter param_slot_7[] = {
	{ 0, &static_QUType_ptr, "PerfilSeguridadProt2", QUParameter::In }
    };
    static const QUMethod slot_7 = {"SlotPerfil", 1, param_slot_7 };
    static const QMetaData slot_tbl[] = {
	{ "SlotPasaFocoAPaterno()", &slot_0, QMetaData::Private },
	{ "SlotPasaFocoAMaterno()", &slot_1, QMetaData::Private },
	{ "SlotPasaFocoFirma()", &slot_2, QMetaData::Private },
	{ "SlotPasaFocoPassword()", &slot_3, QMetaData::Private },
	{ "SlotPasaFocoRePassword()", &slot_4, QMetaData::Private },
	{ "SlotPasaFocoRegistra()", &slot_5, QMetaData::Private },
	{ "SlotRegistra()", &slot_6, QMetaData::Private },
	{ "SlotPerfil(PerfilSeguridadProt2*)", &slot_7, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalTerminar", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalTerminar(QWidget*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QRegistroEmpleado", parentObject,
	slot_tbl, 8,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QRegistroEmpleado.setMetaObject( metaObj );
    return metaObj;
}

void* QRegistroEmpleado::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QRegistroEmpleado" ) )
	return this;
    return RegistroEmpleado::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalTerminar
void QRegistroEmpleado::SignalTerminar( QWidget* t0 )
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

bool QRegistroEmpleado::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotPasaFocoAPaterno(); break;
    case 1: SlotPasaFocoAMaterno(); break;
    case 2: SlotPasaFocoFirma(); break;
    case 3: SlotPasaFocoPassword(); break;
    case 4: SlotPasaFocoRePassword(); break;
    case 5: SlotPasaFocoRegistra(); break;
    case 6: SlotRegistra(); break;
    case 7: SlotPerfil((PerfilSeguridadProt2*)static_QUType_ptr.get(_o+1)); break;
    default:
	return RegistroEmpleado::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QRegistroEmpleado::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalTerminar((QWidget*)static_QUType_ptr.get(_o+1)); break;
    default:
	return RegistroEmpleado::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QRegistroEmpleado::qt_property( int id, int f, QVariant* v)
{
    return RegistroEmpleado::qt_property( id, f, v);
}

bool QRegistroEmpleado::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
