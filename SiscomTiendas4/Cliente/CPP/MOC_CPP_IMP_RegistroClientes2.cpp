/****************************************************************************
** QRegistroClientes2 meta object code from reading C++ file 'IMP_RegistroClientes2.h'
**
** Created: Fri Apr 12 21:36:43 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_RegistroClientes2.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QRegistroClientes2::className() const
{
    return "QRegistroClientes2";
}

QMetaObject *QRegistroClientes2::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QRegistroClientes2( "QRegistroClientes2", &QRegistroClientes2::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QRegistroClientes2::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRegistroClientes2", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QRegistroClientes2::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRegistroClientes2", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QRegistroClientes2::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = RegistroClientes2::staticMetaObject();
    static const QUMethod slot_0 = {"SlotPasaFocoAPaterno", 0, 0 };
    static const QUMethod slot_1 = {"SlotPasaFocoAMaterno", 0, 0 };
    static const QUMethod slot_2 = {"SlotPasaFocoRFC", 0, 0 };
    static const QUMethod slot_3 = {"SlotPasaFocoRegistraGenerales", 0, 0 };
    static const QUMethod slot_4 = {"SlotRegistraG", 0, 0 };
    static const QUMethod slot_5 = {"SlotAnexarDireccion", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotPasaFocoAPaterno()", &slot_0, QMetaData::Private },
	{ "SlotPasaFocoAMaterno()", &slot_1, QMetaData::Private },
	{ "SlotPasaFocoRFC()", &slot_2, QMetaData::Private },
	{ "SlotPasaFocoRegistraGenerales()", &slot_3, QMetaData::Private },
	{ "SlotRegistraG()", &slot_4, QMetaData::Private },
	{ "SlotAnexarDireccion()", &slot_5, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalTerminar", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalTerminar(QWidget*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QRegistroClientes2", parentObject,
	slot_tbl, 6,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QRegistroClientes2.setMetaObject( metaObj );
    return metaObj;
}

void* QRegistroClientes2::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QRegistroClientes2" ) )
	return this;
    return RegistroClientes2::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalTerminar
void QRegistroClientes2::SignalTerminar( QWidget* t0 )
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

bool QRegistroClientes2::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotPasaFocoAPaterno(); break;
    case 1: SlotPasaFocoAMaterno(); break;
    case 2: SlotPasaFocoRFC(); break;
    case 3: SlotPasaFocoRegistraGenerales(); break;
    case 4: SlotRegistraG(); break;
    case 5: SlotAnexarDireccion(); break;
    default:
	return RegistroClientes2::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QRegistroClientes2::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalTerminar((QWidget*)static_QUType_ptr.get(_o+1)); break;
    default:
	return RegistroClientes2::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QRegistroClientes2::qt_property( int id, int f, QVariant* v)
{
    return RegistroClientes2::qt_property( id, f, v);
}

bool QRegistroClientes2::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
