/****************************************************************************
** QRegistroClientes meta object code from reading C++ file 'IMP_RegistroClientes.h'
**
** Created: Thu Apr 11 22:09:38 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_RegistroClientes.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QRegistroClientes::className() const
{
    return "QRegistroClientes";
}

QMetaObject *QRegistroClientes::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QRegistroClientes( "QRegistroClientes", &QRegistroClientes::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QRegistroClientes::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRegistroClientes", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QRegistroClientes::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRegistroClientes", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QRegistroClientes::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = RegistroClientes::staticMetaObject();
    static const QUMethod slot_0 = {"SlotPasaFocoAPaterno", 0, 0 };
    static const QUMethod slot_1 = {"SlotPasaFocoAMaterno", 0, 0 };
    static const QUMethod slot_2 = {"SlotPasaFocoRFC", 0, 0 };
    static const QUMethod slot_3 = {"SlotPasaFocoRegistrar", 0, 0 };
    static const QUMethod slot_4 = {"SlotRegistrar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotPasaFocoAPaterno()", &slot_0, QMetaData::Private },
	{ "SlotPasaFocoAMaterno()", &slot_1, QMetaData::Private },
	{ "SlotPasaFocoRFC()", &slot_2, QMetaData::Private },
	{ "SlotPasaFocoRegistrar()", &slot_3, QMetaData::Private },
	{ "SlotRegistrar()", &slot_4, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalTerminar", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalTerminar(QWidget*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QRegistroClientes", parentObject,
	slot_tbl, 5,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QRegistroClientes.setMetaObject( metaObj );
    return metaObj;
}

void* QRegistroClientes::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QRegistroClientes" ) )
	return this;
    return RegistroClientes::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalTerminar
void QRegistroClientes::SignalTerminar( QWidget* t0 )
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

bool QRegistroClientes::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotPasaFocoAPaterno(); break;
    case 1: SlotPasaFocoAMaterno(); break;
    case 2: SlotPasaFocoRFC(); break;
    case 3: SlotPasaFocoRegistrar(); break;
    case 4: SlotRegistrar(); break;
    default:
	return RegistroClientes::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QRegistroClientes::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalTerminar((QWidget*)static_QUType_ptr.get(_o+1)); break;
    default:
	return RegistroClientes::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QRegistroClientes::qt_property( int id, int f, QVariant* v)
{
    return RegistroClientes::qt_property( id, f, v);
}

bool QRegistroClientes::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
