/****************************************************************************
** QRegistroEmpresa meta object code from reading C++ file 'IMP_RegistroEmpresa.h'
**
** Created: Thu Apr 11 20:30:21 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_RegistroEmpresa.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QRegistroEmpresa::className() const
{
    return "QRegistroEmpresa";
}

QMetaObject *QRegistroEmpresa::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QRegistroEmpresa( "QRegistroEmpresa", &QRegistroEmpresa::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QRegistroEmpresa::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRegistroEmpresa", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QRegistroEmpresa::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRegistroEmpresa", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QRegistroEmpresa::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = RegistroEmpresa::staticMetaObject();
    static const QUMethod slot_0 = {"SlotPasaFocoDireccion", 0, 0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotDireccion", 1, param_slot_1 };
    static const QUMethod slot_2 = {"SlotPasaFocoAPaterno", 0, 0 };
    static const QUMethod slot_3 = {"SlotPasaFocoAMaterno", 0, 0 };
    static const QUMethod slot_4 = {"SlotPasaFocoDscContacto", 0, 0 };
    static const QUMethod slot_5 = {"SlotPasaFocoDscTelefono", 0, 0 };
    static const QUMethod slot_6 = {"SlotRegistra", 0, 0 };
    static const QUParameter param_slot_7[] = {
	{ 0, &static_QUType_ptr, "SisMedCom", QUParameter::In }
    };
    static const QUMethod slot_7 = {"SlotMedComunicacion", 1, param_slot_7 };
    static const QUParameter param_slot_8[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_8 = {"SlotTipo", 1, param_slot_8 };
    static const QUParameter param_slot_9[] = {
	{ "pintNFila", &static_QUType_int, 0, QUParameter::In },
	{ "pintNColumna", &static_QUType_int, 0, QUParameter::In },
	{ "pQPPosicion", &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_9 = {"SlotMantenimientoDirecciones", 3, param_slot_9 };
    static const QMetaData slot_tbl[] = {
	{ "SlotPasaFocoDireccion()", &slot_0, QMetaData::Private },
	{ "SlotDireccion(SiscomRegistro3*)", &slot_1, QMetaData::Private },
	{ "SlotPasaFocoAPaterno()", &slot_2, QMetaData::Private },
	{ "SlotPasaFocoAMaterno()", &slot_3, QMetaData::Private },
	{ "SlotPasaFocoDscContacto()", &slot_4, QMetaData::Private },
	{ "SlotPasaFocoDscTelefono()", &slot_5, QMetaData::Private },
	{ "SlotRegistra()", &slot_6, QMetaData::Private },
	{ "SlotMedComunicacion(SisMedCom*)", &slot_7, QMetaData::Private },
	{ "SlotTipo(int)", &slot_8, QMetaData::Private },
	{ "SlotMantenimientoDirecciones(int,int,const QPoint&)", &slot_9, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalTerminar", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalTerminar(QWidget*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QRegistroEmpresa", parentObject,
	slot_tbl, 10,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QRegistroEmpresa.setMetaObject( metaObj );
    return metaObj;
}

void* QRegistroEmpresa::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QRegistroEmpresa" ) )
	return this;
    return RegistroEmpresa::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalTerminar
void QRegistroEmpresa::SignalTerminar( QWidget* t0 )
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

bool QRegistroEmpresa::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotPasaFocoDireccion(); break;
    case 1: SlotDireccion((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    case 2: SlotPasaFocoAPaterno(); break;
    case 3: SlotPasaFocoAMaterno(); break;
    case 4: SlotPasaFocoDscContacto(); break;
    case 5: SlotPasaFocoDscTelefono(); break;
    case 6: SlotRegistra(); break;
    case 7: SlotMedComunicacion((SisMedCom*)static_QUType_ptr.get(_o+1)); break;
    case 8: SlotTipo((int)static_QUType_int.get(_o+1)); break;
    case 9: SlotMantenimientoDirecciones((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+3))); break;
    default:
	return RegistroEmpresa::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QRegistroEmpresa::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalTerminar((QWidget*)static_QUType_ptr.get(_o+1)); break;
    default:
	return RegistroEmpresa::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QRegistroEmpresa::qt_property( int id, int f, QVariant* v)
{
    return RegistroEmpresa::qt_property( id, f, v);
}

bool QRegistroEmpresa::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
