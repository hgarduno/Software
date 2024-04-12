/****************************************************************************
** QFamilias meta object code from reading C++ file 'IMP_Familias.h'
**
** Created: Thu Apr 11 22:09:38 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_Familias.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QFamilias::className() const
{
    return "QFamilias";
}

QMetaObject *QFamilias::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QFamilias( "QFamilias", &QFamilias::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QFamilias::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QFamilias", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QFamilias::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QFamilias", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QFamilias::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = Familias::staticMetaObject();
    static const QUMethod slot_0 = {"SlotPasaFocoDsc", 0, 0 };
    static const QUMethod slot_1 = {"SlotAnexa", 0, 0 };
    static const QUMethod slot_2 = {"SlotCapturandoDsc", 0, 0 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"SlotCapturandoFamilia", 1, param_slot_3 };
    static const QMetaData slot_tbl[] = {
	{ "SlotPasaFocoDsc()", &slot_0, QMetaData::Private },
	{ "SlotAnexa()", &slot_1, QMetaData::Private },
	{ "SlotCapturandoDsc()", &slot_2, QMetaData::Private },
	{ "SlotCapturandoFamilia(const QString&)", &slot_3, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalTerminar", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalTerminar(QWidget*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QFamilias", parentObject,
	slot_tbl, 4,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QFamilias.setMetaObject( metaObj );
    return metaObj;
}

void* QFamilias::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QFamilias" ) )
	return this;
    return Familias::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalTerminar
void QFamilias::SignalTerminar( QWidget* t0 )
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

bool QFamilias::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotPasaFocoDsc(); break;
    case 1: SlotAnexa(); break;
    case 2: SlotCapturandoDsc(); break;
    case 3: SlotCapturandoFamilia((const QString&)static_QUType_QString.get(_o+1)); break;
    default:
	return Familias::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QFamilias::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalTerminar((QWidget*)static_QUType_ptr.get(_o+1)); break;
    default:
	return Familias::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QFamilias::qt_property( int id, int f, QVariant* v)
{
    return Familias::qt_property( id, f, v);
}

bool QFamilias::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
