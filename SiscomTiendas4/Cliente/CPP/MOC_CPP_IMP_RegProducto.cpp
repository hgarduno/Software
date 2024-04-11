/****************************************************************************
** QRegProducto meta object code from reading C++ file 'IMP_RegProducto.h'
**
** Created: Thu Apr 11 20:30:21 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_RegProducto.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QRegProducto::className() const
{
    return "QRegProducto";
}

QMetaObject *QRegProducto::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QRegProducto( "QRegProducto", &QRegProducto::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QRegProducto::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRegProducto", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QRegProducto::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRegProducto", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QRegProducto::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = RegProducto::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "CQSisFamilia", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotFamilia", 1, param_slot_0 };
    static const QUMethod slot_1 = {"SlotPasaFocoDescripcion", 0, 0 };
    static const QUMethod slot_2 = {"SlotRegistrar", 0, 0 };
    static const QUMethod slot_3 = {"SlotCambiandoFamilia", 0, 0 };
    static const QUMethod slot_4 = {"SlotCapturandoDsc", 0, 0 };
    static const QUParameter param_slot_5[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"SlotCambiandoClave", 1, param_slot_5 };
    static const QMetaData slot_tbl[] = {
	{ "SlotFamilia(CQSisFamilia*)", &slot_0, QMetaData::Private },
	{ "SlotPasaFocoDescripcion()", &slot_1, QMetaData::Private },
	{ "SlotRegistrar()", &slot_2, QMetaData::Private },
	{ "SlotCambiandoFamilia()", &slot_3, QMetaData::Private },
	{ "SlotCapturandoDsc()", &slot_4, QMetaData::Private },
	{ "SlotCambiandoClave(const QString&)", &slot_5, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalTerminar", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalTerminar(QWidget*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QRegProducto", parentObject,
	slot_tbl, 6,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QRegProducto.setMetaObject( metaObj );
    return metaObj;
}

void* QRegProducto::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QRegProducto" ) )
	return this;
    return RegProducto::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalTerminar
void QRegProducto::SignalTerminar( QWidget* t0 )
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

bool QRegProducto::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotFamilia((CQSisFamilia*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotPasaFocoDescripcion(); break;
    case 2: SlotRegistrar(); break;
    case 3: SlotCambiandoFamilia(); break;
    case 4: SlotCapturandoDsc(); break;
    case 5: SlotCambiandoClave((const QString&)static_QUType_QString.get(_o+1)); break;
    default:
	return RegProducto::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QRegProducto::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalTerminar((QWidget*)static_QUType_ptr.get(_o+1)); break;
    default:
	return RegProducto::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QRegProducto::qt_property( int id, int f, QVariant* v)
{
    return RegProducto::qt_property( id, f, v);
}

bool QRegProducto::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
