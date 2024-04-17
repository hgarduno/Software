/****************************************************************************
** QAdministracionCajas meta object code from reading C++ file 'IMP_AdministracionCajas.h'
**
** Created: Fri Apr 12 21:26:08 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_AdministracionCajas.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QAdministracionCajas::className() const
{
    return "QAdministracionCajas";
}

QMetaObject *QAdministracionCajas::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QAdministracionCajas( "QAdministracionCajas", &QAdministracionCajas::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QAdministracionCajas::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QAdministracionCajas", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QAdministracionCajas::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QAdministracionCajas", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QAdministracionCajas::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = AdministracionCajas::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotSeleccionandoCaja", 4, param_slot_0 };
    static const QUMethod slot_1 = {"SlotPasaFocoRegistrarImporte", 0, 0 };
    static const QUMethod slot_2 = {"SlotRegistrarImporte", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotSeleccionandoCaja(int,int,int,const QPoint&)", &slot_0, QMetaData::Private },
	{ "SlotPasaFocoRegistrarImporte()", &slot_1, QMetaData::Private },
	{ "SlotRegistrarImporte()", &slot_2, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalTerminar", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalTerminar(QWidget*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QAdministracionCajas", parentObject,
	slot_tbl, 3,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QAdministracionCajas.setMetaObject( metaObj );
    return metaObj;
}

void* QAdministracionCajas::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QAdministracionCajas" ) )
	return this;
    return AdministracionCajas::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalTerminar
void QAdministracionCajas::SignalTerminar( QWidget* t0 )
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

bool QAdministracionCajas::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotSeleccionandoCaja((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 1: SlotPasaFocoRegistrarImporte(); break;
    case 2: SlotRegistrarImporte(); break;
    default:
	return AdministracionCajas::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QAdministracionCajas::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalTerminar((QWidget*)static_QUType_ptr.get(_o+1)); break;
    default:
	return AdministracionCajas::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QAdministracionCajas::qt_property( int id, int f, QVariant* v)
{
    return AdministracionCajas::qt_property( id, f, v);
}

bool QAdministracionCajas::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
